const std = @import("std");
const logger = @import("logger.zig");
const lexer = @import("js_lexer.zig");
const ast = @import("js_ast.zig");
const options = @import("options.zig");
usingnamespace @import("strings.zig");

const TempRef = struct {
    ref: js_ast.Ref,
    value: *js_ast.Expr,
};

const ImportNamespaceCallOrConstruct = struct {
    ref: js_ast.Ref,
    is_construct: bool,
};

const ThenCatchChain = struct {
    next_target: js_ast.E,
    has_multiple_args: bool,
    has_catch: bool,
};

const Map = std.AutoHashMap;

const List = std.ArrayList;

const SymbolUseMap = Map(js_ast.Ref, js_ast.Symbol.Use);
const StringRefMap = std.StringHashMap(js_ast.Ref);
const StringBoolMap = std.StringHashMap(bool);
const RefBoolMap = Map(js_ast.Ref, bool);
const RefRefMap = Map(js_ast.Ref, js_ast.Ref);
const ImportRecord = @import("import_record.zig").ImportRecord;
const ScopeOrder = struct {
    loc: logger.Loc,
    scope: *js_ast.Scope,
};

// This is function-specific information used during parsing. It is saved and
// restored on the call stack around code that parses nested functions and
// arrow expressions.
const FnOrArrowDataParse = struct {
    async_range: logger.Range,
    arrow_arg_errors: void,
    allow_await: bool = false,
    allow_yield: bool = false,
    allow_super_call: bool = false,
    is_top_level: bool = false,
    is_constructor: bool = false,
    is_type_script_declare: bool = false,

    // In TypeScript, forward declarations of functions have no bodies
    allow_missing_body_for_type_script: bool = false,

    // Allow TypeScript decorators in function arguments
    allow_ts_decorators: bool = false,
};

// This is function-specific information used during visiting. It is saved and
// restored on the call stack around code that parses nested functions and
// arrow expressions.
const FnOrArrowDataVisit = struct {
    super_index_ref: *js_ast.Ref,

    is_arrow: bool = false,
    is_async: bool = false,
    is_inside_loop: bool = false,
    is_inside_switch: bool = false,
    is_outside_fn_or_arrow: bool = false,

    // This is used to silence unresolvable imports due to "require" calls inside
    // a try/catch statement. The assumption is that the try/catch statement is
    // there to handle the case where the reference to "require" crashes.
    try_body_count: i32 = 0,
};

// This is function-specific information used during visiting. It is saved and
// restored on the call stack around code that parses nested functions (but not
// nested arrow functions).
const FnOnlyDataVisit = struct {
    // This is a reference to the magic "arguments" variable that exists inside
    // functions in JavaScript. It will be non-nil inside functions and nil
    // otherwise.
    arguments_ref: *js_ast.Ref,

    // Arrow functions don't capture the value of "this" and "arguments". Instead,
    // the values are inherited from the surrounding context. If arrow functions
    // are turned into regular functions due to lowering, we will need to generate
    // local variables to capture these values so they are preserved correctly.
    this_capture_ref: *js_ast.Ref,
    arguments_capture_ref: *js_ast.Ref,

    // Inside a static class property initializer, "this" expressions should be
    // replaced with the class name.
    this_class_static_ref: *js_ast.Ref,

    // If we're inside an async arrow function and async functions are not
    // supported, then we will have to convert that arrow function to a generator
    // function. That means references to "arguments" inside the arrow function
    // will have to reference a captured variable instead of the real variable.
    is_inside_async_arrow_fn: bool = false,

    // If false, the value for "this" is the top-level module scope "this" value.
    // That means it's "undefined" for ECMAScript modules and "exports" for
    // CommonJS modules. We track this information so that we can substitute the
    // correct value for these top-level "this" references at compile time instead
    // of passing the "this" expression through to the output and leaving the
    // interpretation up to the run-time behavior of the generated code.
    //
    // If true, the value for "this" is nested inside something (either a function
    // or a class declaration). That means the top-level module scope "this" value
    // has been shadowed and is now inaccessible.
    is_this_nested: bool = false,
};

const ModuleType = enum { esm };

const PropertyOpts = struct {
    async_range: ?logger.Range,
    is_async: bool = false,
    is_generator: bool = false,

    // Class-related options
    is_static: bool = false,
    is_class: bool = false,
    class_has_extends: bool = false,
    allow_ts_decorators: bool = false,
    ts_decorators: []js_ast.Expr,
};

pub const Parser = struct {
    options: Options,
    lexer: lexer.Lexer,
    log: logger.Log,
    source: logger.Source,
    allocator: *std.mem.Allocator,
    p: ?*P,

    pub const Result = struct { ast: ast.Ast, ok: bool = false };

    const Options = struct {
        jsx: options.JSX,
        asciiOnly: bool = true,
        keepNames: bool = true,
        mangleSyntax: bool = false,
        mangeIdentifiers: bool = false,
        omitRuntimeForTests: bool = false,
        ignoreDCEAnnotations: bool = true,
        preserveUnusedImportsTS: bool = false,
        useDefineForClassFields: bool = false,
        suppressWarningsAboutWeirdCode = true,
        moduleType: ModuleType = ModuleType.esm,
    };

    pub fn parse(self: *Parser) !Result {
        if (self.p == null) {
            self.p = try P.init(allocator, self.log, self.source, self.lexer, &self.options);
        }

        var result: Result = undefined;

        if (self.p) |p| {}

        return result;
    }

    pub fn init(transform: options.TransformOptions, allocator: *std.mem.Allocator) !Parser {
        const log = logger.Log{ .msgs = List(logger.Msg).init(allocator) };
        const source = logger.Source.initFile(transform.entry_point, allocator);
        const lexer = try lexer.Lexer.init(log, source, allocator);
        return Parser{
            .options = Options{
                .jsx = options.JSX{
                    .parse = true,
                    .factory = transform.jsx_factory,
                    .fragment = transform.jsx_fragment,
                },
            },

            .lexer = lexer,
            .source = source,
            .log = log,
            .p = null,
        };
    }
};

const DeferredTsDecorators = struct { values: []js_ast.Expr,

// If this turns out to be a "declare class" statement, we need to undo the
// scopes that were potentially pushed while parsing the decorator arguments.
scopeIndex: usize };

const LexicalDecl = enum(u8) { forbid, allow_all, allow_fn_inside_if, allow_fn_inside_label };

const ParseStatementOptions = struct {
    ts_decorators: *DeferredTsDecorators,
    lexical_decl: LexicalDecl = .forbid,
    is_module_scope: bool = false,
    is_namespace_scope: bool = false,
    is_export: bool = false,
    is_name_optional: bool = false, // For "export default" pseudo-statements,
    is_type_script_declare: bool = false1,
};

// P is for Parser!
const P = struct {
    allocator: *std.mem.Allocator,
    options: Options,
    log: logger.Log,
    source: logger.Source,
    lexer: js_lexer.Lexer,
    allow_in: bool = false,
    allow_private_identifiers: bool = false,
    has_top_level_return: bool = false,
    latest_return_had_semicolon: bool = false,
    has_import_meta: bool = false,
    has_es_module_syntax: bool = false,
    top_level_await_keyword: logger.Range,
    fn_or_arrow_data_parse: FnOrArrowDataParse,
    fn_or_arrow_data_visit: FnOrArrowDataVisit,
    fn_only_data_visit: FnOnlyDataVisit,
    allocated_names: List(string),
    latest_arrow_arg_loc: logger.Loc = -1,
    forbid_suffix_after_as_loc: logger.Loc = -1,
    current_scope: *js_ast.Scope,
    scopes_for_current_part: List(*js_ast.Scope),
    symbols: List(js_ast.Symbol),
    ts_use_counts: List(u32),
    exports_ref: js_ast.Ref = js_ast.Ref.None,
    require_ref: js_ast.Ref = js_ast.Ref.None,
    module_ref: js_ast.Ref = js_ast.Ref.None,
    import_meta_ref: js_ast.Ref = js_ast.Ref.None,
    promise_ref: ?js_ast.Ref = null,

    injected_define_symbols: []js_ast.Ref,
    symbol_uses: SymbolUseMap,
    declared_symbols: List(js_ast.DeclaredSymbol),
    runtime_imports: StringRefMap,
    duplicate_case_checker: void,
    non_bmp_identifiers: StringBoolMap,
    legacy_octal_literals: void,
    // legacy_octal_literals:      map[js_ast.E]logger.Range,

    // For strict mode handling
    hoistedRefForSloppyModeBlockFn: void,

    // For lowering private methods
    weak_map_ref: ?js_ast.Ref,
    weak_set_ref: ?js_ast.Ref,
    private_getters: RefRefMap,
    private_setters: RefRefMap,

    // These are for TypeScript
    should_fold_numeric_constants: bool = false,
    emitted_namespace_vars: RefBoolMap,
    is_exported_inside_namespace: RefRefMap,
    known_enum_values: Map(js_ast.Ref, std.StringHashMap(f64)),
    local_type_names: StringBoolMap,

    // This is the reference to the generated function argument for the namespace,
    // which is different than the reference to the namespace itself:
    //
    //   namespace ns {
    //   }
    //
    // The code above is transformed into something like this:
    //
    //   var ns1;
    //   (function(ns2) {
    //   })(ns1 || (ns1 = {}));
    //
    // This variable is "ns2" not "ns1". It is only used during the second
    // "visit" pass.
    enclosing_namespace_arg_ref: ?js_ast.Ref = null,

    // Imports (both ES6 and CommonJS) are tracked at the top level
    import_records: List(ImportRecord),
    import_records_for_current_part: List(u32),
    export_star_import_records: List(u32),

    // These are for handling ES6 imports and exports
    es6_import_keyword: logger.Range = logger.Range.Empty,
    es6_export_keyword: logger.Range = logger.Range.Empty,
    enclosing_class_keyword: logger.Range = logger.Range.Empty,
    import_items_for_namespace: Map(js_ast.Ref, map(string, js_ast.LocRef)),
    is_import_item: RefBoolMap,
    named_imports: Map(js_ast.Ref, js_ast.NamedImport),
    named_exports: std.StringHashMap(js_ast.NamedExport),
    top_level_symbol_to_parts: Map(js_ast.Ref, List(u32)),
    import_namespace_cc_map: Map(ImportNamespaceCallOrConstruct, bool),

    // The parser does two passes and we need to pass the scope tree information
    // from the first pass to the second pass. That's done by tracking the calls
    // to pushScopeForParsePass() and popScope() during the first pass in
    // scopesInOrder.
    //
    // Then, when the second pass calls pushScopeForVisitPass() and popScope(),
    // we consume entries from scopesInOrder and make sure they are in the same
    // order. This way the second pass can efficiently use the same scope tree
    // as the first pass without having to attach the scope tree to the AST.
    //
    // We need to split this into two passes because the pass that declares the
    // symbols must be separate from the pass that binds identifiers to declared
    // symbols to handle declaring a hoisted "var" symbol in a nested scope and
    // binding a name to it in a parent or sibling scope.
    scopes_in_order: List(ScopeOrder),

    // These properties are for the visit pass, which runs after the parse pass.
    // The visit pass binds identifiers to declared symbols, does constant
    // folding, substitutes compile-time variable definitions, and lowers certain
    // syntactic constructs as appropriate.
    stmt_expr_value: js_ast.E,
    call_target: js_ast.E,
    delete_target: js_ast.E,
    loop_body: js_ast.S,
    module_scope: ?js_ast.Scope = null,
    is_control_flow_dead: bool = false,

    // Inside a TypeScript namespace, an "export declare" statement can be used
    // to cause a namespace to be emitted even though it has no other observable
    // effect. This flag is used to implement this feature.
    //
    // Specifically, namespaces should be generated for all of the following
    // namespaces below except for "f", which should not be generated:
    //
    //   namespace a { export declare const a }
    //   namespace b { export declare let [[b]] }
    //   namespace c { export declare function c() }
    //   namespace d { export declare class d {} }
    //   namespace e { export declare enum e {} }
    //   namespace f { export declare namespace f {} }
    //
    // The TypeScript compiler compiles this into the following code (notice "f"
    // is missing):
    //
    //   var a; (function (a_1) {})(a || (a = {}));
    //   var b; (function (b_1) {})(b || (b = {}));
    //   var c; (function (c_1) {})(c || (c = {}));
    //   var d; (function (d_1) {})(d || (d = {}));
    //   var e; (function (e_1) {})(e || (e = {}));
    //
    // Note that this should not be implemented by declaring symbols for "export
    // declare" statements because the TypeScript compiler doesn't generate any
    // code for these statements, so these statements are actually references to
    // global variables. There is one exception, which is that local variables
    // *should* be declared as symbols because they are replaced with. This seems
    // like very arbitrary behavior but it's what the TypeScript compiler does,
    // so we try to match it.
    //
    // Specifically, in the following code below "a" and "b" should be declared
    // and should be substituted with "ns.a" and "ns.b" but the other symbols
    // shouldn't. References to the other symbols actually refer to global
    // variables instead of to symbols that are exported from the namespace.
    // This is the case as of TypeScript 4.3. I assume this is a TypeScript bug:
    //
    //   namespace ns {
    //     export declare const a
    //     export declare let [[b]]
    //     export declare function c()
    //     export declare class d { }
    //     export declare enum e { }
    //     console.log(a, b, c, d, e)
    //   }
    //
    // The TypeScript compiler compiles this into the following code:
    //
    //   var ns;
    //   (function (ns) {
    //       console.log(ns.a, ns.b, c, d, e);
    //   })(ns || (ns = {}));
    //
    // Relevant issue: https://github.com/evanw/esbuild/issues/1158
    has_non_local_export_declare_inside_namespace: bool = false,

    // This helps recognize the "await import()" pattern. When this is present,
    // warnings about non-string import paths will be omitted inside try blocks.
    await_target: ?js_ast.E = null,

    // This helps recognize the "import().catch()" pattern. We also try to avoid
    // warning about this just like the "try { await import() }" pattern.
    then_catch_chain: ThenCatchChain,

    // Temporary variables used for lowering
    temp_refs_to_declare: List(TempRef),
    temp_ref_count: i32 = 0,

    // When bundling, hoisted top-level local variables declared with "var" in
    // nested scopes are moved up to be declared in the top-level scope instead.
    // The old "var" statements are turned into regular assignments instead. This
    // makes it easier to quickly scan the top-level statements for "var" locals
    // with the guarantee that all will be found.
    relocated_top_level_vars: List(js_ast.LocRef),

    // ArrowFunction is a special case in the grammar. Although it appears to be
    // a PrimaryExpression, it's actually an AssignmentExpression. This means if
    // a AssignmentExpression ends up producing an ArrowFunction then nothing can
    // come after it other than the comma operator, since the comma operator is
    // the only thing above AssignmentExpression under the Expression rule:
    //
    //   AssignmentExpression:
    //     ArrowFunction
    //     ConditionalExpression
    //     LeftHandSideExpression = AssignmentExpression
    //     LeftHandSideExpression AssignmentOperator AssignmentExpression
    //
    //   Expression:
    //     AssignmentExpression
    //     Expression , AssignmentExpression
    //
    after_arrow_body_loc: logger.Loc = -1,

    pub fn deinit(parser: *P) void {
        parser.allocated_names.deinit();
        parser.scopes_for_current_part.deinit();
        parser.symbols.deinit();
        parser.ts_use_counts.deinit();
        parser.declared_symbols.deinit();
        parser.known_enum_values.deinit();
        parser.import_records.deinit();
        parser.import_records_for_current_part.deinit();
        parser.export_star_import_records.deinit();
        parser.import_items_for_namespace.deinit();
        parser.named_imports.deinit();
        parser.top_level_symbol_to_parts.deinit();
        parser.import_namespace_cc_map.deinit();
        parser.scopes_in_order.deinit();
        parser.temp_refs_to_declare.deinit();
        parser.relocated_top_level_vars.deinit();
    }

    pub fn findSymbol(self: *P, loc: logger.Loc, name: string) ?js_ast.Symbol {
        return null;
    }

    pub fn recordUsage(self: *P, ref: *js_ast.Ref) void {
        // The use count stored in the symbol is used for generating symbol names
        // during minification. These counts shouldn't include references inside dead
        // code regions since those will be culled.
        if (!p.is_control_flow_dead) {
            p.symbols[ref.InnerIndex].use_count_estimate += 1;
            var use = p.symbolUses[ref];
            use.count_estimate += 1;
            p.symbolUses.put(ref, use);
        }

        // The correctness of TypeScript-to-JavaScript conversion relies on accurate
        // symbol use counts for the whole file, including dead code regions. This is
        // tracked separately in a parser-only data structure.
        if (p.options.ts.parse) {
            p.tsUseCounts.items[ref.inner_index] += 1;
        }
    }

    pub fn findSymbolHelper(self: *P, loc: logger.Loc, name: string) ?js_ast.Ref {
        if (self.findSymbol(loc, name)) |sym| {
            return sym.ref;
        }

        return null;
    }

    pub fn symbolForDefineHelper(self: *P, i: usize) ?js_ast.Ref {
        if (self.injected_define_symbols.items.len > i) {
            return self.injected_define_symbols.items[i];
        }

        return null;
    }

    pub fn keyNameForError(p: *P, key: js_ast.Expr) string {
        switch (key.data) {
            js_ast.E.String => {
                return p.lexer.raw();
            },
            js_ast.E.PrivateIdentifier => {
                return p.lexer.raw();
                // return p.loadNameFromRef()
            },
            else => {
                return "property";
            },
        }
    }

    pub fn pushScopeForParsePass(p: *P, kind: js_ast.Scope.Kind, loc: logger.Loc) !int {
        var parent = p.current_scope;
        var scope = try p.allocator.create(js_ast.Scope);
        scope.kind = kind;
        scope.parent = parent;
        scope.members = scope.members.init(p.allocator);
        scope.label_ref = null;

        if (parent) |_parent| {
            try _parent.children.append(scope);
            scope.strict_mode = _parent.strict_mode;
        }
        p.current_scope = scope;

        // Enforce that scope locations are strictly increasing to help catch bugs
        // where the pushed scopes are mistmatched between the first and second passes
        if (p.scopes_in_order.items.len > 0) {
            const prev_start = p.scopes_in_order.items[p.scopes_in_order.items.len - 1].loc.start;
            if (prev_start >= loc.start) {
                std.debug.panic("Scope location {i} must be greater than {i}", .{ loc.start, prev_start });
            }
        }

        //       	// Copy down function arguments into the function body scope. That way we get
        // // errors if a statement in the function body tries to re-declare any of the
        // // arguments.
        // if kind == js_ast.ScopeFunctionBody {
        // 	if scope.Parent.Kind != js_ast.ScopeFunctionArgs {
        // 		panic("Internal error")
        // 	}
        // 	for name, member := range scope.Parent.Members {
        // 		// Don't copy down the optional function expression name. Re-declaring
        // 		// the name of a function expression is allowed.
        // 		kind := p.symbols[member.Ref.InnerIndex].Kind
        // 		if kind != js_ast.SymbolHoistedFunction {
        // 			scope.Members[name] = member
        // 		}
        // 	}
        // }
    }

    pub fn init(allocator: *std.mem.Allocator, log: logger.Log, source: logger.Source, lexer: js_lexer.Lexer, options: *Options) !*Parser {
        var parser = try allocator.create(P);
        parser.allocated_names = List(string).init(allocator);
        parser.scopes_for_current_part = List(*js_ast.Scope).init(allocator);
        parser.symbols = List(js_ast.Symbol).init(allocator);
        parser.ts_use_counts = List(u32).init(allocator);
        parser.declared_symbols = List(js_ast.DeclaredSymbol).init(allocator);
        parser.known_enum_values = Map(js_ast.Ref, std.StringHashMap(f64)).init(allocator);
        parser.import_records = List(ImportRecord).init(allocator);
        parser.import_records_for_current_part = List(u32).init(allocator);
        parser.export_star_import_records = List(u32).init(allocator);
        parser.import_items_for_namespace = Map(js_ast.Ref, Map(string, js_ast.LocRef)).init(allocator);
        parser.named_imports = Map(js_ast.Ref, js_ast.NamedImport).init(allocator);
        parser.top_level_symbol_to_parts = Map(js_ast.Ref, List(u32)).init(allocator);
        parser.import_namespace_cc_map = Map(ImportNamespaceCallOrConstruct, bool).init(allocator);
        parser.scopes_in_order = List(ScopeOrder).init(allocator);
        parser.temp_refs_to_declare = List(TempRef).init(allocator);
        parser.relocated_top_level_vars = List(js_ast.LocRef).init(allocator);
        parser.log = log;
        parser.allocator = allocator;
        parser.source = source;
        parser.lexer = lexer;

        return parser;
    }
};
