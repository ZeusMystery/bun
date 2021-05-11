usingnamespace @import("../global.zig");
const std = @import("std");
const options = @import("../options.zig");
const log = @import("../logger.zig");
const cache = @import("../cache.zig");
const logger = @import("../logger.zig");
const js_ast = @import("../js_ast.zig");
const alloc = @import("../alloc.zig");

const PathsMap = std.StringHashMap([]string);

pub const TSConfigJSON = struct {
    abs_path: string,

    // The absolute path of "compilerOptions.baseUrl"
    base_url: ?string = null,

    // This is used if "Paths" is non-nil. It's equal to "BaseURL" except if
    // "BaseURL" is missing, in which case it is as if "BaseURL" was ".". This
    // is to implement the "paths without baseUrl" feature from TypeScript 4.1.
    // More info: https://github.com/microsoft/TypeScript/issues/31869
    base_url_for_paths = "",

    // The verbatim values of "compilerOptions.paths". The keys are patterns to
    // match and the values are arrays of fallback paths to search. Each key and
    // each fallback path can optionally have a single "*" wildcard character.
    // If both the key and the value have a wildcard, the substring matched by
    // the wildcard is substituted into the fallback path. The keys represent
    // module-style path names and the fallback paths are relative to the
    // "baseUrl" value in the "tsconfig.json" file.
    paths: PathsMap,

    jsx: options.JSX.Pragma = options.JSX.Pragma{},

    use_define_for_class_fields: ?bool = null,

    preserve_imports_not_used_as_values: bool = false,

    pub const ImportsNotUsedAsValue = enum {
        preserve,
        err,
        remove,
        invalid,

        pub const List = std.ComptimeStringMap(ImportsNotUsedAsValue, .{
            .{ "preserve", ImportsNotUsedAsValue.preserve },
            .{ "error", ImportsNotUsedAsValue.err },
            .{ "remove", ImportsNotUsedAsValue.remove },
        });
    };

    pub fn parse(
        allocator: *std.mem.Allocator,
        log: *logger.Log,
        source: logger.Source,
        opts: options.TransformOptions,
        json_cache: *cache.Cache.Json,
    ) anyerror!?*TSConfigJSON {
        // Unfortunately "tsconfig.json" isn't actually JSON. It's some other
        // format that appears to be defined by the implementation details of the
        // TypeScript compiler.
        //
        // Attempt to parse it anyway by modifying the JSON parser, but just for
        // these particular files. This is likely not a completely accurate
        // emulation of what the TypeScript compiler does (e.g. string escape
        // behavior may also be different).
        const json: js_ast.Expr = (json_cache.parseTSConfig(log, opts, source, allocator) catch null) orelse return null;

        var result: TSConfigJSON = TSConfigJSON{ .abs_path = source.key_path.text, .paths = PathsMap.init(allocator) };
        errdefer allocator.free(result.paths);
        if (extends != null) {
            if (json.getProperty("extends")) |extends_value| {
                log.addWarning(&source, extends_value.loc, "\"extends\" is not implemented yet") catch unreachable;
                // if ((extends_value.expr.getString(allocator) catch null)) |str| {
                //     if (extends(str, source.rangeOfString(extends_value.loc))) |base| {
                //         result.jsx = base.jsx;
                //         result.base_url_for_paths = base.base_url_for_paths;
                //         result.use_define_for_class_fields = base.use_define_for_class_fields;
                //         result.preserve_imports_not_used_as_values = base.preserve_imports_not_used_as_values;
                //         //  https://github.com/microsoft/TypeScript/issues/14527#issuecomment-284948808
                //         result.paths = base.paths;
                //     }
                // }
            }
        }

        // Parse "compilerOptions"
        if (json.getProperty("compilerOptions")) |compiler_opts| {
            // Parse "baseUrl"
            if (compiler_opts.expr.getProperty("baseUrl")) |base_url_prop| {
                // maybe we should add a warning when it exists but the value is an array or osmething invalid?
                if ((base_url_prop.expr.getString(allocator) catch null)) |base_url| {
                    result.base_url = base_url;
                }
            }

            // Parse "jsxFactory"
            if (compiler_opts.expr.getProperty("jsxFactory")) |jsx_prop| {
                if (jsx_prop.expr.getString(allocator)) |str| {
                    result.jsx.factory = try parseMemberExpressionForJSX(log, source, jsx_prop.loc, str, allocator);
                }
            }

            // Parse "jsxFragmentFactory"
            if (compiler_opts.expr.getProperty("jsxFactory")) |jsx_prop| {
                if (jsx_prop.expr.getString(allocator)) |str| {
                    result.jsx.fragment = try parseMemberExpressionForJSX(log, source, jsx_prop.loc, str, allocator);
                }
            }

            // Parse "jsxImportSource"
            if (compiler_opts.expr.getProperty("jsxImportSource")) |jsx_factory_prop| {
                if (jsx_prop.expr.getString(allocator)) |str| {
                    result.jsx.import_source = str;
                }
            }

            // Parse "useDefineForClassFields"
            if (compiler_opts.expr.getProperty("useDefineForClassFields")) |use_define_value_prop| {
                if (use_define_value_prop.expr.getBool()) |val| {
                    result.use_define_for_class_fields = val;
                }
            }

            // Parse "importsNotUsedAsValues"
            if (compiler_opts.expr.getProperty("importsNotUsedAsValues")) |imports_not_used_as_values_prop| {
                // This should never allocate since it will be utf8
                if ((jsx_prop.expr.getString(allocator) catch null)) |str| {
                    switch (ImportsNotUsedAsValue.List.get(str) orelse ImportsNotUsedAsValue.invalid) {
                        .preserve, .err => {
                            result.preserve_imports_not_used_as_values = true;
                        },
                        .remove => {},
                        else => {
                            log.addRangeWarningFmt(source, source.rangeOfString(imports_not_used_as_values_prop.loc), allocator, "Invalid value \"{s}\" for \"importsNotUsedAsValues\"", .{str}) catch {};
                        },
                    }
                }
            }

            // Parse "paths"
            if (compiler_opts.expr.getProperty("paths")) |paths_prop| {
                switch (paths_prop.expr.data) {
                    .e_object => |paths| {
                        result.base_url_for_paths = result.base_url orelse ".";
                        result.paths = PathsMap.init(allocator);
                        for (paths.properties) |property| {
                            const key_prop = property.key orelse continue;
                            const key = (key_prop.getString(allocator) catch null) orelse continue;

                            if (!TSConfigJSON.isValidTSConfigPathNoBaseURLPattern(key, log, source, key_prop.loc)) {
                                continue;
                            }

                            const value_prop = property.value orelse continue;

                            // The "paths" field is an object which maps a pattern to an
                            // array of remapping patterns to try, in priority order. See
                            // the documentation for examples of how this is used:
                            // https://www.typescriptlang.org/docs/handbook/module-resolution.html#path-mapping.
                            //
                            // One particular example:
                            //
                            //   {
                            //     "compilerOptions": {
                            //       "baseUrl": "projectRoot",
                            //       "paths": {
                            //         "*": [
                            //           "*",
                            //           "generated/*"
                            //         ]
                            //       }
                            //     }
                            //   }
                            //
                            // Matching "folder1/file2" should first check "projectRoot/folder1/file2"
                            // and then, if that didn't work, also check "projectRoot/generated/folder1/file2".
                            switch (value_prop.data) {
                                .e_array => |array| {
                                    if (array.items.len > 0) {
                                        var paths = allocator.alloc(string, array.items.len) catch unreachable;
                                        errdefer allocator.free(paths);
                                        var count: usize = 0;
                                        for (array.items) |expr| {
                                            if ((expr.getString(allocator) catch null)) |str| {
                                                if (TSConfigJSON.isValidTSConfigPathPattern(str, log, source, loc, allocator) and
                                                    (has_base_url or
                                                    TSConfigJSON.isValidTSConfigPathNoBaseURLPattern(
                                                    str,
                                                    log,
                                                    source,
                                                    loc,
                                                ))) {
                                                    paths[count] = str;
                                                    count += 1;
                                                }
                                            }
                                        }
                                        if (count > 0) {
                                            result.paths.put(
                                                key,
                                                paths[0..count],
                                            ) catch unreachable;
                                        }
                                    }
                                },
                                else => {
                                    log.addRangeWarningFmt(
                                        source,
                                        log,
                                        allocator,
                                        "Substitutions for pattern \"{s}\" should be an array",
                                        .{key},
                                    ) catch {};
                                },
                            }
                        }
                    },
                    else => {},
                }
            }
        }

        var _result = allocator.create(TSConfigJSON) catch unreachable;
        _result.* = result;
        return _result;
    }

    pub fn isValidTSConfigPathPattern(text: string, log: *logger.Log, source: *logger.Source, loc: logger.Loc, allocator: *std.mem.Allocator) bool {
        var found_asterisk = false;
        for (text) |c, i| {
            if (c == '*') {
                if (found_asterisk) {
                    const r = source.rangeOfString(loc);
                    log.addRangeWarningFmt(source, r, allocator, "Invalid pattern \"{s}\", must have at most one \"*\" character", .{text}) catch {};
                    return false;
                }
                found_asterisk = true;
            }
        }

        return true;
    }

    pub fn parseMemberExpressionForJSX(log: *logger.Log, source: *logger.Source, loc: logger.Loc, text: string, allocator: *std.mem.Allocator) ![]string {
        if (text.len == 0) {
            return &([_]string{});
        }
        const parts_count = std.mem.count(u8, text, ".");
        const parts = allocator.alloc(string, parts_count) catch unreachable;
        var iter = std.mem.tokenize(text, ".");
        var i: usize = 0;
        while (iter.next()) |part| {
            if (!js_lexer.isIdentifier(part)) {
                const warn = source.rangeOfString(loc);
                log.addRangeWarningFmt(source, warn, allocator, "Invalid JSX member expression: \"{s}\"", .{part}) catch {};
                return &([_]string{});
            }
            parts[i] = part;
            i += 1;
        }

        return parts;
    }

    pub fn isSlash(c: u8) bool {
        return c == '/' or c == '\\';
    }

    pub fn isValidTSConfigPathNoBaseURLPattern(text: string, log: logger.Log, source: *logger.Source, loc: logger.Loc) bool {
        var c0: u8 = 0;
        var c1: u8 = 0;
        var c2: u8 = 0;
        const n = text.len;

        switch (n) {
            0 => {
                return false;
            },
            // Relative "." or ".."

            1 => {
                return text[0] == '.';
            },
            // "..", ".\", "./"
            2 => {
                return text[0] == '.' and (text[1] == '.' or text[1] == '\\' or text[1] == '/');
            },
            else => {
                c0 = text[0];
                c1 = text[1];
                c2 = text[2];
            },
        }

        // Relative "./" or "../" or ".\\" or "..\\"
        if (c0 == '.' and (TSConfigJSON.isSlash(c1) or (c1 == '.' and TSConfigJSON.isSlash(c2)))) {
            return true;
        }

        // Absolute DOS "c:/" or "c:\\"
        if (c1 == ':' and TSConfigJSON.isSlash(c2)) {
            switch (c0) {
                'a'...'z', 'A'...'Z' => {
                    return true;
                },
                else => {},
            }
        }

        const r = source.rangeOfString(loc);
        log.addRangeWarningFmt(source, r, allocator, "Non-relative path \"{s}\" is not allowed when \"baseUrl\" is not set (did you forget a leading \"./\"?)", .{text}) catch {};
        return false;
    }
};

test "tsconfig.json" {
    try alloc.setup(std.heap.c_allocator);
}
