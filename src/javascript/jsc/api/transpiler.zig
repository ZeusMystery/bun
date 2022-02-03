const std = @import("std");
const Api = @import("../../../api/schema.zig").Api;
const FilesystemRouter = @import("../../../router.zig");
const http = @import("../../../http.zig");
const JavaScript = @import("../javascript.zig");
const QueryStringMap = @import("../../../query_string_map.zig").QueryStringMap;
const CombinedScanner = @import("../../../query_string_map.zig").CombinedScanner;
const _global = @import("../../../global.zig");
const string = _global.string;
const JSC = @import("javascript_core");
const js = JSC.C;
const WebCore = @import("../webcore/response.zig");
const Bundler = @import("../../../bundler.zig");
const options = @import("../../../options.zig");
const VirtualMachine = JavaScript.VirtualMachine;
const ScriptSrcStream = std.io.FixedBufferStream([]u8);
const ZigString = JSC.ZigString;
const Fs = @import("../../../fs.zig");
const Base = @import("../base.zig");
const getAllocator = Base.getAllocator;
const JSObject = JSC.JSObject;
const JSError = Base.JSError;
const JSValue = JSC.JSValue;
const JSGlobalObject = JSC.JSGlobalObject;
const strings = @import("strings");
const NewClass = Base.NewClass;
const To = Base.To;
const Request = WebCore.Request;
const d = Base.d;
const FetchEvent = WebCore.FetchEvent;
const MacroMap = @import("../../../resolver/package_json.zig").MacroMap;
const TSConfigJSON = @import("../../../resolver/tsconfig_json.zig").TSConfigJSON;
const PackageJSON = @import("../../../resolver/package_json.zig").PackageJSON;
const logger = @import("../../../logger.zig");
const Loader = options.Loader;
const Platform = options.Platform;
const JSAst = @import("../../../js_ast.zig");
const Transpiler = @This();
const JSParser = @import("../../../js_parser.zig");
const JSPrinter = @import("../../../js_printer.zig");
const ScanPassResult = JSParser.ScanPassResult;
const Mimalloc = @import("../../../mimalloc_arena.zig");
bundler: Bundler.Bundler,
arena: std.heap.ArenaAllocator,
transpiler_options: TranspilerOptions,
scan_pass_result: ScanPassResult,
buffer_writer: ?JSPrinter.BufferWriter = null,

pub const Class = NewClass(
    Transpiler,
    .{ .name = "Transpiler" },
    .{
        .scanImports = .{
            .rfn = scanImports,
        },
        .scan = .{
            .rfn = scan,
        },
        .transform = .{
            .rfn = transform,
        },
        .transformSync = .{
            .rfn = transformSync,
        },
        .finalize = finalize,
    },
    .{},
);

pub const TranspilerConstructor = NewClass(
    void,
    .{ .name = "Transpiler" },
    .{
        .constructor = .{ .rfn = constructor },
    },
    .{},
);

const default_transform_options: Api.TransformOptions = brk: {
    var opts = std.mem.zeroes(Api.TransformOptions);
    opts.disable_hmr = true;
    opts.platform = Api.Platform.browser;
    opts.serve = false;

    break :brk opts;
};

const TranspilerOptions = struct {
    transform: Api.TransformOptions = default_transform_options,
    default_loader: options.Loader = options.Loader.jsx,
    macro_map: MacroMap = MacroMap{},
    tsconfig: ?*TSConfigJSON = null,
    tsconfig_buf: []const u8 = "",
    macros_buf: []const u8 = "",
    log: logger.Log,
    pending_tasks: u32 = 0,
};

// Mimalloc gets unstable if we try to move this to a different thread
// threadlocal var transform_buffer: _global.MutableString = undefined;
// threadlocal var transform_buffer_loaded: bool = false;

// This is going to be hard to not leak
pub const TransformTask = struct {
    input_code: ZigString = ZigString.init(""),
    protected_input_value: JSC.JSValue = @intToEnum(JSC.JSValue, 0),
    output_code: ZigString = ZigString.init(""),
    bundler: Bundler.Bundler = undefined,
    log: logger.Log,
    err: ?anyerror = null,
    macro_map: MacroMap = MacroMap{},
    tsconfig: ?*TSConfigJSON = null,
    loader: Loader,
    global: *JSGlobalObject,

    pub const AsyncTransformTask = JSC.ConcurrentPromiseTask(TransformTask);
    pub const AsyncTransformEventLoopTask = AsyncTransformTask.EventLoopTask;

    pub fn create(transpiler: *Transpiler, protected_input_value: JSC.C.JSValueRef, globalThis: *JSGlobalObject, input_code: ZigString, loader: Loader) !*AsyncTransformTask {
        var transform_task = try _global.default_allocator.create(TransformTask);
        transform_task.* = .{
            .input_code = input_code,
            .protected_input_value = if (protected_input_value != null) JSC.JSValue.fromRef(protected_input_value) else @intToEnum(JSC.JSValue, 0),
            .bundler = undefined,
            .global = globalThis,
            .macro_map = transpiler.transpiler_options.macro_map,
            .tsconfig = transpiler.transpiler_options.tsconfig,
            .log = logger.Log.init(_global.default_allocator),
            .loader = loader,
        };
        transform_task.bundler = transpiler.bundler;
        transform_task.bundler.linker.resolver = &transform_task.bundler.resolver;

        transform_task.bundler.setLog(&transform_task.log);
        transform_task.bundler.setAllocator(_global.default_allocator);
        return try AsyncTransformTask.createOnJSThread(_global.default_allocator, globalThis, transform_task);
    }

    pub fn run(this: *TransformTask) void {
        const name = this.loader.stdinName();
        const source = logger.Source.initPathString(name, this.input_code.slice());

        JSAst.Stmt.Data.Store.create(_global.default_allocator);
        JSAst.Expr.Data.Store.create(_global.default_allocator);

        var arena = Mimalloc.Arena.init() catch unreachable;

        const allocator = arena.allocator();

        defer {
            JSAst.Stmt.Data.Store.reset();
            JSAst.Expr.Data.Store.reset();
            arena.deinit();
        }

        this.bundler.setAllocator(allocator);
        const jsx = if (this.tsconfig != null)
            this.tsconfig.?.mergeJSX(this.bundler.options.jsx)
        else
            this.bundler.options.jsx;

        const parse_options = Bundler.Bundler.ParseOptions{
            .allocator = allocator,
            .macro_remappings = this.macro_map,
            .dirname_fd = 0,
            .file_descriptor = null,
            .loader = this.loader,
            .jsx = jsx,
            .path = source.path,
            .virtual_source = &source,
            // .allocator = this.
        };

        const parse_result = this.bundler.parse(parse_options, null) orelse {
            this.err = error.ParseError;
            return;
        };
        defer {
            if (parse_result.ast.symbol_pool) |pool| {
                pool.release();
            }
        }
        if (parse_result.empty) {
            this.output_code = ZigString.init("");
            return;
        }

        var global_allocator = arena.backingAllocator();
        var buffer_writer = JSPrinter.BufferWriter.init(global_allocator) catch |err| {
            this.err = err;
            return;
        };
        buffer_writer.buffer.list.ensureTotalCapacity(global_allocator, 512) catch unreachable;
        buffer_writer.reset();

        // defer {
        //     transform_buffer = buffer_writer.buffer;
        // }

        var printer = JSPrinter.BufferPrinter.init(buffer_writer);
        const printed = this.bundler.print(parse_result, @TypeOf(&printer), &printer, .esm_ascii) catch |err| {
            this.err = err;
            return;
        };

        if (printed > 0) {
            buffer_writer = printer.ctx;
            buffer_writer.buffer.list.items = buffer_writer.written;

            var output = JSC.ZigString.init(buffer_writer.written);
            output.mark();
            this.output_code = output;
        } else {
            this.output_code = ZigString.init("");
        }
    }

    pub fn then(this: *TransformTask, promise: *JSC.JSInternalPromise) void {
        if (this.log.hasAny() or this.err != null) {
            const error_value: JSValue = brk: {
                if (this.err) |err| {
                    if (!this.log.hasAny()) {
                        break :brk JSC.JSValue.fromRef(JSC.BuildError.create(
                            this.global,
                            _global.default_allocator,
                            logger.Msg{
                                .data = logger.Data{ .text = std.mem.span(@errorName(err)) },
                            },
                        ));
                    }
                }

                break :brk this.log.toJS(this.global, _global.default_allocator, "Transform failed");
            };

            promise.reject(this.global, error_value);
            return;
        }

        finish(this.output_code, this.global, promise);

        if (@enumToInt(this.protected_input_value) != 0) {
            this.protected_input_value = @intToEnum(JSC.JSValue, 0);
        }
        this.deinit();
    }

    noinline fn finish(code: ZigString, global: *JSGlobalObject, promise: *JSC.JSInternalPromise) void {
        promise.resolve(global, code.toValueGC(global));
    }

    pub fn deinit(this: *TransformTask) void {
        var should_cleanup = false;
        defer if (should_cleanup) _global.Global.mimalloc_cleanup(false);

        this.log.deinit();
        if (this.input_code.isGloballyAllocated()) {
            this.input_code.deinitGlobal();
        }

        if (this.output_code.isGloballyAllocated()) {
            should_cleanup = this.output_code.len > 512_000;
            this.output_code.deinitGlobal();
        }

        _global.default_allocator.destroy(this);
    }
};

fn transformOptionsFromJSC(ctx: JSC.C.JSContextRef, temp_allocator: std.mem.Allocator, args: *JSC.Node.ArgumentsSlice, exception: JSC.C.ExceptionRef) TranspilerOptions {
    var globalThis = ctx.ptr();
    const object = args.next() orelse return TranspilerOptions{ .log = logger.Log.init(temp_allocator) };
    if (object.isUndefinedOrNull()) return TranspilerOptions{ .log = logger.Log.init(temp_allocator) };

    args.eat();
    var allocator = args.arena.allocator();

    var transpiler = TranspilerOptions{
        .default_loader = .jsx,
        .transform = default_transform_options,
        .log = logger.Log.init(allocator),
    };
    transpiler.log.level = .warn;

    if (!object.isObject()) {
        JSC.throwInvalidArguments("Expected an object", .{}, ctx, exception);
        return transpiler;
    }

    if (object.getIfPropertyExists(ctx.ptr(), "define")) |define| {
        define: {
            if (define.isUndefinedOrNull()) {
                break :define;
            }

            if (!define.isObject()) {
                JSC.throwInvalidArguments("define must be an object", .{}, ctx, exception);
                return transpiler;
            }

            var array = JSC.C.JSObjectCopyPropertyNames(globalThis.ref(), define.asObjectRef());
            defer JSC.C.JSPropertyNameArrayRelease(array);
            const count = JSC.C.JSPropertyNameArrayGetCount(array);
            // cannot be a temporary because it may be loaded on different threads.
            var map_entries = allocator.alloc([]u8, count * 2) catch unreachable;
            var names = map_entries[0..count];

            var values = map_entries[count..];

            var i: usize = 0;
            while (i < count) : (i += 1) {
                var property_name_ref = JSC.C.JSPropertyNameArrayGetNameAtIndex(
                    array,
                    i,
                );
                defer JSC.C.JSStringRelease(property_name_ref);
                const prop: []const u8 = JSC.C.JSStringGetCharacters8Ptr(property_name_ref)[0..JSC.C.JSStringGetLength(property_name_ref)];
                const property_value: JSC.JSValue = JSC.JSValue.fromRef(
                    JSC.C.JSObjectGetProperty(
                        globalThis.ref(),
                        define.asObjectRef(),
                        property_name_ref,
                        null,
                    ),
                );
                const value_type = property_value.jsType();

                if (!value_type.isStringLike()) {
                    JSC.throwInvalidArguments("define \"{s}\" must be a JSON string", .{prop}, ctx, exception);
                    return transpiler;
                }
                names[i] = allocator.dupe(u8, prop) catch unreachable;
                var val = JSC.ZigString.init("");
                property_value.toZigString(&val, globalThis);
                if (val.len == 0) {
                    val = JSC.ZigString.init("\"\"");
                }
                values[i] = std.fmt.allocPrint(allocator, "{}", .{val}) catch unreachable;
            }
            transpiler.transform.define = Api.StringMap{
                .keys = names,
                .values = values,
            };
        }
    }

    if (object.get(globalThis, "external")) |external| {
        external: {
            if (external.isUndefinedOrNull()) break :external;

            const toplevel_type = external.jsType();
            if (toplevel_type.isStringLike()) {
                var zig_str = JSC.ZigString.init("");
                external.toZigString(&zig_str, globalThis);
                if (zig_str.len == 0) break :external;
                var single_external = allocator.alloc(string, 1) catch unreachable;
                single_external[0] = std.fmt.allocPrint(allocator, "{}", .{external}) catch unreachable;
                transpiler.transform.external = single_external;
            } else if (toplevel_type.isArray()) {
                const count = external.getLengthOfArray(globalThis);
                if (count == 0) break :external;

                var externals = allocator.alloc(string, count) catch unreachable;
                var iter = external.arrayIterator(globalThis);
                var i: usize = 0;
                while (iter.next()) |entry| {
                    if (!entry.jsType().isStringLike()) {
                        JSC.throwInvalidArguments("external must be a string or string[]", .{}, ctx, exception);
                        return transpiler;
                    }

                    var zig_str = JSC.ZigString.init("");
                    entry.toZigString(&zig_str, globalThis);
                    if (zig_str.len == 0) continue;
                    externals[i] = std.fmt.allocPrint(allocator, "{}", .{external}) catch unreachable;
                    i += 1;
                }

                transpiler.transform.external = externals[0..i];
            } else {
                JSC.throwInvalidArguments("external must be a string or string[]", .{}, ctx, exception);
                return transpiler;
            }
        }
    }

    if (object.get(globalThis, "loader")) |loader| {
        if (Loader.fromJS(globalThis, loader, exception)) |resolved| {
            if (!resolved.isJavaScriptLike()) {
                JSC.throwInvalidArguments("only JavaScript-like loaders supported for now", .{}, ctx, exception);
                return transpiler;
            }

            transpiler.default_loader = resolved;
        }

        if (exception.* != null) {
            return transpiler;
        }
    }

    if (object.get(globalThis, "platform")) |platform| {
        if (Platform.fromJS(globalThis, platform, exception)) |resolved| {
            transpiler.transform.platform = resolved.toAPI();
        }

        if (exception.* != null) {
            return transpiler;
        }
    }

    if (object.get(globalThis, "tsconfig")) |tsconfig| {
        tsconfig: {
            if (tsconfig.isUndefinedOrNull()) break :tsconfig;
            const kind = tsconfig.jsType();
            var out = JSC.ZigString.init("");

            if (kind.isArray()) {
                JSC.throwInvalidArguments("tsconfig must be a string or object", .{}, ctx, exception);
                return transpiler;
            }

            if (!kind.isStringLike()) {
                tsconfig.jsonStringify(globalThis, 0, &out);
            } else {
                tsconfig.toZigString(&out, globalThis);
            }

            if (out.len == 0) break :tsconfig;
            transpiler.tsconfig_buf = std.fmt.allocPrint(allocator, "{}", .{out}) catch unreachable;

            // TODO: JSC -> Ast conversion
            if (TSConfigJSON.parse(
                allocator,
                &transpiler.log,
                logger.Source.initPathString("tsconfig.json", transpiler.tsconfig_buf),
                &VirtualMachine.vm.bundler.resolver.caches.json,
                true,
            ) catch null) |parsed_tsconfig| {
                transpiler.tsconfig = parsed_tsconfig;
            }
        }
    }

    if (object.getIfPropertyExists(globalThis, "macro")) |macros| {
        macros: {
            if (macros.isUndefinedOrNull()) break :macros;
            const kind = macros.jsType();
            const is_object = kind.isObject();
            if (!(kind.isStringLike() or is_object)) {
                JSC.throwInvalidArguments("macro must be an object", .{}, ctx, exception);
                return transpiler;
            }

            var out: ZigString = ZigString.init("");
            // TODO: write a converter between JSC types and Bun AST types
            if (is_object) {
                macros.jsonStringify(globalThis, 0, &out);
            } else {
                macros.toZigString(&out, globalThis);
            }

            if (out.len == 0) break :macros;
            transpiler.macros_buf = std.fmt.allocPrint(allocator, "{}", .{out}) catch unreachable;
            const source = logger.Source.initPathString("macros.json", transpiler.macros_buf);
            const json = (VirtualMachine.vm.bundler.resolver.caches.json.parseJSON(
                &transpiler.log,
                source,
                allocator,
            ) catch null) orelse break :macros;
            transpiler.macro_map = PackageJSON.parseMacrosJSON(allocator, json, &transpiler.log, &source);
        }
    }

    return transpiler;
}

pub fn constructor(
    ctx: js.JSContextRef,
    _: js.JSObjectRef,
    arguments: []const js.JSValueRef,
    exception: js.ExceptionRef,
) js.JSObjectRef {
    var temp = std.heap.ArenaAllocator.init(getAllocator(ctx));
    var args = JSC.Node.ArgumentsSlice.init(@ptrCast([*]const JSC.JSValue, arguments.ptr)[0..arguments.len]);
    defer temp.deinit();
    const transpiler_options: TranspilerOptions = if (arguments.len > 0)
        transformOptionsFromJSC(ctx, temp.allocator(), &args, exception)
    else
        TranspilerOptions{ .log = logger.Log.init(getAllocator(ctx)) };

    if (exception.* != null) {
        return null;
    }

    if ((transpiler_options.log.warnings + transpiler_options.log.errors) > 0) {
        var out_exception = transpiler_options.log.toJS(ctx.ptr(), getAllocator(ctx), "Failed to create transpiler");
        exception.* = out_exception.asObjectRef();
        return null;
    }

    var log = getAllocator(ctx).create(logger.Log) catch unreachable;
    log.* = transpiler_options.log;
    var bundler = Bundler.Bundler.init(
        getAllocator(ctx),
        log,
        transpiler_options.transform,
        null,
        JavaScript.VirtualMachine.vm.bundler.env,
    ) catch |err| {
        if ((log.warnings + log.errors) > 0) {
            var out_exception = log.toJS(ctx.ptr(), getAllocator(ctx), "Failed to create transpiler");
            exception.* = out_exception.asObjectRef();
            return null;
        }

        JSC.throwInvalidArguments("Error creating transpiler: {s}", .{@errorName(err)}, ctx, exception);
        return null;
    };

    bundler.configureLinkerWithAutoJSX(false);
    bundler.configureDefines() catch |err| {
        if ((log.warnings + log.errors) > 0) {
            var out_exception = log.toJS(ctx.ptr(), getAllocator(ctx), "Failed to load define");
            exception.* = out_exception.asObjectRef();
            return null;
        }

        JSC.throwInvalidArguments("Failed to load define: {s}", .{@errorName(err)}, ctx, exception);
        return null;
    };

    if (transpiler_options.macro_map.count() > 0) {
        bundler.options.macro_remap = transpiler_options.macro_map;
    }

    var transpiler = getAllocator(ctx).create(Transpiler) catch unreachable;
    transpiler.* = Transpiler{
        .transpiler_options = transpiler_options,
        .bundler = bundler,
        .arena = args.arena,
        .scan_pass_result = ScanPassResult.init(getAllocator(ctx)),
    };

    return Class.make(ctx, transpiler);
}

pub fn finalize(
    this: *Transpiler,
) void {
    this.bundler.log.deinit();
    this.scan_pass_result.named_imports.deinit();
    this.scan_pass_result.import_records.deinit();
    this.scan_pass_result.used_symbols.deinit();
    if (this.buffer_writer != null) {
        this.buffer_writer.?.buffer.deinit();
    }

    // _global.default_allocator.free(this.transpiler_options.tsconfig_buf);
    // _global.default_allocator.free(this.transpiler_options.macros_buf);
    this.arena.deinit();
}

fn getParseResult(this: *Transpiler, allocator: std.mem.Allocator, code: []const u8, loader: ?Loader) ?Bundler.ParseResult {
    const name = this.transpiler_options.default_loader.stdinName();
    const source = logger.Source.initPathString(name, code);

    const jsx = if (this.transpiler_options.tsconfig != null)
        this.transpiler_options.tsconfig.?.mergeJSX(this.bundler.options.jsx)
    else
        this.bundler.options.jsx;

    const parse_options = Bundler.Bundler.ParseOptions{
        .allocator = allocator,
        .macro_remappings = this.transpiler_options.macro_map,
        .dirname_fd = 0,
        .file_descriptor = null,
        .loader = loader orelse this.transpiler_options.default_loader,
        .jsx = jsx,
        .path = source.path,
        .virtual_source = &source,
        // .allocator = this.
    };

    return this.bundler.parse(parse_options, null);
}

pub fn scan(
    this: *Transpiler,
    ctx: js.JSContextRef,
    _: js.JSObjectRef,
    _: js.JSObjectRef,
    arguments: []const js.JSValueRef,
    exception: js.ExceptionRef,
) JSC.C.JSObjectRef {
    var args = JSC.Node.ArgumentsSlice.init(@ptrCast([*]const JSC.JSValue, arguments.ptr)[0..arguments.len]);
    defer args.arena.deinit();
    const code_arg = args.next() orelse {
        JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code_holder = JSC.Node.StringOrBuffer.fromJS(ctx.ptr(), code_arg, exception) orelse {
        if (exception.* == null) JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code = code_holder.slice();
    args.eat();
    const loader: ?Loader = brk: {
        if (args.next()) |arg| {
            args.eat();
            break :brk Loader.fromJS(ctx.ptr(), arg, exception);
        }

        break :brk null;
    };

    if (exception.* != null) return null;

    defer {
        JSAst.Stmt.Data.Store.reset();
        JSAst.Expr.Data.Store.reset();
    }

    const parse_result = getParseResult(this, args.arena.allocator(), code, loader) orelse {
        if ((this.bundler.log.warnings + this.bundler.log.errors) > 0) {
            var out_exception = this.bundler.log.toJS(ctx.ptr(), getAllocator(ctx), "Parse error");
            exception.* = out_exception.asObjectRef();
            return null;
        }

        JSC.throwInvalidArguments("Failed to parse", .{}, ctx, exception);
        return null;
    };
    defer {
        if (parse_result.ast.symbol_pool) |symbols| {
            symbols.release();
        }
    }

    if ((this.bundler.log.warnings + this.bundler.log.errors) > 0) {
        var out_exception = this.bundler.log.toJS(ctx.ptr(), getAllocator(ctx), "Parse error");
        exception.* = out_exception.asObjectRef();
        return null;
    }

    const exports_label = JSC.ZigString.init("exports");
    const imports_label = JSC.ZigString.init("imports");
    const named_imports_value = namedImportsToJS(
        ctx.ptr(),
        parse_result.ast.import_records,
        exception,
    );
    if (exception.* != null) return null;
    var named_exports_value = namedExportsToJS(
        ctx.ptr(),
        parse_result.ast.named_exports,
    );
    return JSC.JSValue.createObject2(ctx.ptr(), &imports_label, &exports_label, named_imports_value, named_exports_value).asObjectRef();
}

// pub fn build(
//     this: *Transpiler,
//     ctx: js.JSContextRef,
//     _: js.JSObjectRef,
//     _: js.JSObjectRef,
//     arguments: []const js.JSValueRef,
//     exception: js.ExceptionRef,
// ) JSC.C.JSObjectRef {}

pub fn transform(
    this: *Transpiler,
    ctx: js.JSContextRef,
    _: js.JSObjectRef,
    _: js.JSObjectRef,
    arguments: []const js.JSValueRef,
    exception: js.ExceptionRef,
) JSC.C.JSObjectRef {
    var args = JSC.Node.ArgumentsSlice.init(@ptrCast([*]const JSC.JSValue, arguments.ptr)[0..arguments.len]);
    defer args.arena.deinit();
    const code_arg = args.next() orelse {
        JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code_holder = JSC.Node.StringOrBuffer.fromJS(ctx.ptr(), code_arg, exception) orelse {
        if (exception.* == null) JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code = code_holder.slice();
    args.eat();
    const loader: ?Loader = brk: {
        if (args.next()) |arg| {
            args.eat();
            break :brk Loader.fromJS(ctx.ptr(), arg, exception);
        }

        break :brk null;
    };

    if (exception.* != null) return null;
    if (code_holder == .string) {
        JSC.C.JSValueProtect(ctx, arguments[0]);
    }

    var task = TransformTask.create(this, if (code_holder == .string) arguments[0] else null, ctx.ptr(), ZigString.init(code), loader orelse this.transpiler_options.default_loader) catch return null;
    task.schedule();
    return task.promise.asObjectRef();
}

pub fn transformSync(
    this: *Transpiler,
    ctx: js.JSContextRef,
    _: js.JSObjectRef,
    _: js.JSObjectRef,
    arguments: []const js.JSValueRef,
    exception: js.ExceptionRef,
) JSC.C.JSObjectRef {
    var args = JSC.Node.ArgumentsSlice.init(@ptrCast([*]const JSC.JSValue, arguments.ptr)[0..arguments.len]);
    defer args.arena.deinit();
    const code_arg = args.next() orelse {
        JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code_holder = JSC.Node.StringOrBuffer.fromJS(ctx.ptr(), code_arg, exception) orelse {
        if (exception.* == null) JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code = code_holder.slice();
    JSC.C.JSValueProtect(ctx, arguments[0]);
    defer JSC.C.JSValueUnprotect(ctx, arguments[0]);
    var arena = Mimalloc.Arena.init() catch unreachable;
    this.bundler.setAllocator(arena.allocator());
    var log = logger.Log.init(arena.backingAllocator());
    this.bundler.setLog(&log);
    defer {
        this.bundler.setLog(&this.transpiler_options.log);
        this.bundler.setAllocator(_global.default_allocator);
        arena.deinit();
    }

    args.eat();
    const loader: ?Loader = brk: {
        if (args.next()) |arg| {
            args.eat();
            break :brk Loader.fromJS(ctx.ptr(), arg, exception);
        }

        break :brk null;
    };

    if (exception.* != null) return null;

    defer {
        JSAst.Stmt.Data.Store.reset();
        JSAst.Expr.Data.Store.reset();
    }

    const parse_result = getParseResult(this, arena.allocator(), code, loader) orelse {
        if ((this.bundler.log.warnings + this.bundler.log.errors) > 0) {
            var out_exception = this.bundler.log.toJS(ctx.ptr(), getAllocator(ctx), "Parse error");
            exception.* = out_exception.asObjectRef();
            return null;
        }

        JSC.throwInvalidArguments("Failed to parse", .{}, ctx, exception);
        return null;
    };
    defer {
        if (parse_result.ast.symbol_pool) |symbols| {
            symbols.release();
        }
    }

    if ((this.bundler.log.warnings + this.bundler.log.errors) > 0) {
        var out_exception = this.bundler.log.toJS(ctx.ptr(), getAllocator(ctx), "Parse error");
        exception.* = out_exception.asObjectRef();
        return null;
    }

    var buffer_writer = this.buffer_writer orelse brk: {
        var writer = JSPrinter.BufferWriter.init(arena.backingAllocator()) catch {
            JSC.throwInvalidArguments("Failed to create BufferWriter", .{}, ctx, exception);
            return null;
        };
        writer.buffer.growIfNeeded(code.len) catch unreachable;
        writer.buffer.list.expandToCapacity();
        break :brk writer;
    };

    defer {
        this.buffer_writer = buffer_writer;
    }

    buffer_writer.reset();
    var printer = JSPrinter.BufferPrinter.init(buffer_writer);
    _ = this.bundler.print(parse_result, @TypeOf(&printer), &printer, .esm_ascii) catch |err| {
        JSC.JSError(_global.default_allocator, "Failed to print code: {s}", .{@errorName(err)}, ctx, exception);
        return null;
    };

    // TODO: benchmark if pooling this way is faster or moving is faster
    buffer_writer = printer.ctx;
    var out = JSC.ZigString.init(buffer_writer.written);
    out.mark();

    return out.toValueGC(ctx.ptr()).asObjectRef();
}

fn namedExportsToJS(global: *JSGlobalObject, named_exports: JSAst.Ast.NamedExports) JSC.JSValue {
    if (named_exports.count() == 0)
        return JSC.JSValue.fromRef(JSC.C.JSObjectMakeArray(global.ref(), 0, null, null));

    var named_exports_iter = named_exports.iterator();
    var stack_fallback = std.heap.stackFallback(@sizeOf(JSC.ZigString) * 32, getAllocator(global.ref()));
    var allocator = stack_fallback.get();
    var names = allocator.alloc(
        JSC.ZigString,
        named_exports.count(),
    ) catch unreachable;
    defer allocator.free(names);
    var i: usize = 0;
    while (named_exports_iter.next()) |entry| {
        names[i] = JSC.ZigString.init(entry.key_ptr.*);
        i += 1;
    }
    JSC.ZigString.sortAsc(names[0..i]);
    return JSC.JSValue.createStringArray(global, names.ptr, names.len, true);
}

const ImportRecord = @import("../../../import_record.zig").ImportRecord;

fn namedImportsToJS(
    global: *JSGlobalObject,
    import_records: []const ImportRecord,
    exception: JSC.C.ExceptionRef,
) JSC.JSValue {
    var stack_fallback = std.heap.stackFallback(@sizeOf(JSC.C.JSObjectRef) * 32, getAllocator(global.ref()));
    var allocator = stack_fallback.get();

    var i: usize = 0;
    const path_label = JSC.ZigString.init("path");
    const kind_label = JSC.ZigString.init("kind");
    var array_items = allocator.alloc(
        JSC.C.JSValueRef,
        import_records.len,
    ) catch unreachable;
    defer allocator.free(array_items);

    for (import_records) |record| {
        if (record.is_internal) continue;

        const path = JSC.ZigString.init(record.path.text).toValueGC(global);
        const kind = JSC.ZigString.init(record.kind.label()).toValue(global);
        array_items[i] = JSC.JSValue.createObject2(global, &path_label, &kind_label, path, kind).asObjectRef();
        i += 1;
    }

    return JSC.JSValue.fromRef(JSC.C.JSObjectMakeArray(global.ref(), i, array_items.ptr, exception));
}

pub fn scanImports(
    this: *Transpiler,
    ctx: js.JSContextRef,
    _: js.JSObjectRef,
    _: js.JSObjectRef,
    arguments: []const js.JSValueRef,
    exception: js.ExceptionRef,
) JSC.C.JSObjectRef {
    var args = JSC.Node.ArgumentsSlice.init(@ptrCast([*]const JSC.JSValue, arguments.ptr)[0..arguments.len]);
    const code_arg = args.next() orelse {
        JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };

    const code_holder = JSC.Node.StringOrBuffer.fromJS(ctx.ptr(), code_arg, exception) orelse {
        if (exception.* == null) JSC.throwInvalidArguments("Expected a string or Uint8Array", .{}, ctx, exception);
        return null;
    };
    args.eat();
    const code = code_holder.slice();

    var loader: Loader = this.transpiler_options.default_loader;
    if (args.next()) |arg| {
        if (Loader.fromJS(ctx.ptr(), arg, exception)) |_loader| {
            loader = _loader;
        }
        args.eat();
    }

    if (!loader.isJavaScriptLike()) {
        JSC.throwInvalidArguments("Only JavaScript-like files support this fast path", .{}, ctx, exception);
        return null;
    }

    if (exception.* != null) return null;

    const source = logger.Source.initPathString(loader.stdinName(), code);
    var bundler = &this.bundler;
    const jsx = if (this.transpiler_options.tsconfig != null)
        this.transpiler_options.tsconfig.?.mergeJSX(this.bundler.options.jsx)
    else
        this.bundler.options.jsx;

    var opts = JSParser.Parser.Options.init(jsx, loader);
    if (this.bundler.macro_context == null) {
        this.bundler.macro_context = JSAst.Macro.MacroContext.init(&this.bundler);
    }
    opts.macro_context = &this.bundler.macro_context.?;
    var log = logger.Log.init(getAllocator(ctx));
    defer log.deinit();

    defer {
        JSAst.Stmt.Data.Store.reset();
        JSAst.Expr.Data.Store.reset();
    }

    bundler.resolver.caches.js.scan(
        bundler.allocator,
        &this.scan_pass_result,
        opts,
        bundler.options.define,
        &log,
        &source,
    ) catch |err| {
        defer this.scan_pass_result.reset();
        if ((log.warnings + log.errors) > 0) {
            var out_exception = log.toJS(ctx.ptr(), getAllocator(ctx), "Failed to scan imports");
            exception.* = out_exception.asObjectRef();
            return null;
        }

        JSC.throwInvalidArguments("Failed to scan imports: {s}", .{@errorName(err)}, ctx, exception);
        return null;
    };

    defer this.scan_pass_result.reset();

    if ((log.warnings + log.errors) > 0) {
        var out_exception = log.toJS(ctx.ptr(), getAllocator(ctx), "Failed to scan imports");
        exception.* = out_exception.asObjectRef();
        return null;
    }

    const named_imports_value = namedImportsToJS(
        ctx.ptr(),
        this.scan_pass_result.import_records.items,
        exception,
    );
    if (exception.* != null) return null;
    return named_imports_value.asObjectRef();
}
