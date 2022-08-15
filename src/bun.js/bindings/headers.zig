// GENERATED CODE - DO NOT MODIFY BY HAND

const bindings = @import("../../jsc.zig");
pub const struct_JSC__CallFrame = bindings.CallFrame;
pub const struct_JSC__StringPrototype = bindings.StringPrototype;
pub const struct_JSC__SetIteratorPrototype = bindings.SetIteratorPrototype;
pub const struct_JSC__RegExpPrototype = bindings.RegExpPrototype;
pub const struct_JSC__ObjectPrototype = bindings.ObjectPrototype;
pub const struct_JSC__MapIteratorPrototype = bindings.MapIteratorPrototype;
pub const struct_JSC__JSPromisePrototype = bindings.JSPromisePrototype;
pub const struct_JSC__IteratorPrototype = bindings.IteratorPrototype;
pub const struct_JSC__GeneratorPrototype = bindings.GeneratorPrototype;
pub const struct_JSC__GeneratorFunctionPrototype = bindings.GeneratorFunctionPrototype;
pub const struct_JSC__FunctionPrototype = bindings.FunctionPrototype;
pub const struct_JSC__BigIntPrototype = bindings.BigIntPrototype;
pub const struct_JSC__AsyncIteratorPrototype = bindings.AsyncIteratorPrototype;
pub const struct_JSC__AsyncGeneratorPrototype = bindings.AsyncGeneratorPrototype;
pub const struct_JSC__AsyncGeneratorFunctionPrototype = bindings.AsyncGeneratorFunctionPrototype;
pub const struct_JSC__AsyncFunctionPrototype = bindings.AsyncFunctionPrototype;
pub const struct_JSC__ArrayPrototype = bindings.ArrayPrototype;

pub const struct_JSC__ArrayIteratorPrototype = bindings.ArrayIteratorPrototype;
pub const bWTF__URL = bindings.URL;
pub const bWTF__StringView = bindings.StringView;
pub const bWTF__StringImpl = bindings.StringImpl;
pub const bWTF__String = bindings.String;
pub const bWTF__ExternalStringImpl = bindings.ExternalStringImpl;
pub const bJSC__VM = bindings.VM;
pub const bJSC__ThrowScope = bindings.ThrowScope;
pub const bJSC__SourceOrigin = bindings.SourceOrigin;
pub const bJSC__SourceCode = bindings.SourceCode;
pub const bJSC__PropertyName = bindings.PropertyName;
pub const bJSC__JSString = bindings.JSString;
pub const bJSC__JSPromise = bindings.JSPromise;
pub const bJSC__JSObject = bindings.JSObject;
pub const bJSC__JSModuleRecord = bindings.JSModuleRecord;
pub const bJSC__JSModuleLoader = bindings.JSModuleLoader;
pub const bJSC__JSLock = bindings.JSLock;
pub const bJSC__JSInternalPromise = bindings.JSInternalPromise;
pub const bJSC__JSGlobalObject = bindings.JSGlobalObject;
pub const bJSC__JSFunction = bindings.JSFunction;
pub const bJSC__JSCell = bindings.JSCell;
pub const bJSC__Identifier = bindings.Identifier;
pub const bJSC__Exception = bindings.Exception;
pub const bJSC__CatchScope = bindings.CatchScope;
pub const bJSC__CallFrame = bindings.CallFrame;
pub const bInspector__ScriptArguments = bindings.ScriptArguments;
pub const JSC__JSValue = bindings.JSValue;

// Inlined types
pub const ZigString = bindings.ZigString;
pub const ZigException = bindings.ZigException;
pub const ResolvedSource = bindings.ResolvedSource;
pub const ZigStackTrace = bindings.ZigStackTrace;
pub const ReturnableException = bindings.ReturnableException;
pub const struct_Zig__JSMicrotaskCallback = bindings.Microtask;
pub const bZig__JSMicrotaskCallback = struct_Zig__JSMicrotaskCallback;
pub const SystemError = bindings.SystemError;
const JSClassRef = bindings.C.JSClassRef;
pub const JSC__CatchScope = bindings.CatchScope;
pub const Bun__Readable = bindings.NodeReadableStream;
pub const Bun__Writable = bindings.NodeWritableStream;
pub const Bun__ArrayBuffer = bindings.ArrayBuffer;
pub const struct_WebCore__DOMURL = bindings.DOMURL;
pub const struct_WebCore__FetchHeaders = bindings.FetchHeaders;
pub const StringPointer = @import("../../api/schema.zig").Api.StringPointer;
pub const struct_VirtualMachine = bindings.VirtualMachine;
pub const ArrayBufferSink = @import("../webcore/streams.zig").ArrayBufferSink;

pub const WebSocketHTTPClient = bindings.WebSocketHTTPClient;
pub const WebSocketHTTPSClient = bindings.WebSocketHTTPSClient;
pub const WebSocketClient = bindings.WebSocketClient;
pub const WebSocketClientTLS = bindings.WebSocketClientTLS;
pub const JSC__PropertyName = bJSC__PropertyName;
pub const JSC__JSObject = bJSC__JSObject;
pub const WTF__ExternalStringImpl = bWTF__ExternalStringImpl;
pub const JSC__JSModuleLoader = bJSC__JSModuleLoader;
pub const JSC__Identifier = bJSC__Identifier;
pub const JSC__JSPromise = bJSC__JSPromise;
pub const JSC__JSCell = bJSC__JSCell;
pub const JSC__SourceOrigin = bJSC__SourceOrigin;
pub const JSC__JSModuleRecord = bJSC__JSModuleRecord;
pub const WTF__String = bWTF__String;
pub const WTF__URL = bWTF__URL;
pub const JSC__JSInternalPromise = bJSC__JSInternalPromise;
pub const WTF__StringView = bWTF__StringView;
pub const JSC__ThrowScope = bJSC__ThrowScope;
pub const WTF__StringImpl = bWTF__StringImpl;
pub const JSC__VM = bJSC__VM;
pub const JSC__JSGlobalObject = bJSC__JSGlobalObject;
pub const JSC__JSFunction = bJSC__JSFunction;
pub const JSC__SourceCode = bJSC__SourceCode;
pub const JSC__Exception = bJSC__Exception;
pub const JSC__JSString = bJSC__JSString;
pub extern fn JSC__JSObject__create(arg0: ?*JSC__JSGlobalObject, arg1: usize, arg2: ?*anyopaque, ArgFn3: ?fn (?*anyopaque, [*c]JSC__JSObject, ?*JSC__JSGlobalObject) callconv(.C) void) JSC__JSValue;
pub extern fn JSC__JSObject__getArrayLength(arg0: [*c]JSC__JSObject) usize;
pub extern fn JSC__JSObject__getDirect(arg0: [*c]JSC__JSObject, arg1: ?*JSC__JSGlobalObject, arg2: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSObject__getIndex(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: u32) JSC__JSValue;
pub extern fn JSC__JSObject__putRecord(arg0: [*c]JSC__JSObject, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString, arg3: [*c]ZigString, arg4: usize) void;
pub extern fn ZigString__external(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?fn (?*anyopaque, ?*anyopaque, usize) callconv(.C) void) JSC__JSValue;
pub extern fn ZigString__to16BitValue(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toErrorInstance(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalU16(arg0: [*c]const u16, arg1: usize, arg2: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalValue(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalValueWithCallback(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject, ArgFn2: ?fn (?*anyopaque, ?*anyopaque, usize) callconv(.C) void) JSC__JSValue;
pub extern fn ZigString__toValue(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toValueGC(arg0: [*c]const ZigString, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__DOMURL__cast_(JSValue0: JSC__JSValue, arg1: [*c]JSC__VM) ?*bindings.DOMURL;
pub extern fn WebCore__DOMURL__href_(arg0: ?*bindings.DOMURL, arg1: [*c]ZigString) void;
pub extern fn WebCore__DOMURL__pathname_(arg0: ?*bindings.DOMURL, arg1: [*c]ZigString) void;
pub extern fn WebCore__FetchHeaders__append(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]const ZigString) void;
pub extern fn WebCore__FetchHeaders__cast_(JSValue0: JSC__JSValue, arg1: [*c]JSC__VM) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__clone(arg0: ?*bindings.FetchHeaders, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__cloneThis(arg0: ?*bindings.FetchHeaders) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__copyTo(arg0: ?*bindings.FetchHeaders, arg1: [*c]StringPointer, arg2: [*c]StringPointer, arg3: [*c]u8) void;
pub extern fn WebCore__FetchHeaders__count(arg0: ?*bindings.FetchHeaders, arg1: [*c]u32, arg2: [*c]u32) void;
pub extern fn WebCore__FetchHeaders__createEmpty(...) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromJS(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromPicoHeaders_(arg0: ?*JSC__JSGlobalObject, arg1: ?*const anyopaque) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromUWS(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createValue(arg0: ?*JSC__JSGlobalObject, arg1: [*c]StringPointer, arg2: [*c]StringPointer, arg3: [*c]const ZigString, arg4: u32) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__deref(arg0: ?*bindings.FetchHeaders) void;
pub extern fn WebCore__FetchHeaders__get_(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]ZigString) void;
pub extern fn WebCore__FetchHeaders__has(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString) bool;
pub extern fn WebCore__FetchHeaders__put_(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]const ZigString) void;
pub extern fn WebCore__FetchHeaders__remove(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString) void;
pub extern fn WebCore__FetchHeaders__toJS(arg0: ?*bindings.FetchHeaders, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__toUWSResponse(arg0: ?*bindings.FetchHeaders, arg1: bool, arg2: ?*anyopaque) void;
pub extern fn SystemError__toErrorInstance(arg0: [*c]const SystemError, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSCell__getObject(arg0: [*c]JSC__JSCell) [*c]JSC__JSObject;
pub extern fn JSC__JSCell__getString(arg0: [*c]JSC__JSCell, arg1: ?*JSC__JSGlobalObject) bWTF__String;
pub extern fn JSC__JSCell__getType(arg0: [*c]JSC__JSCell) u8;
pub extern fn JSC__JSString__createFromOwnedString(arg0: [*c]JSC__VM, arg1: [*c]const WTF__String) [*c]JSC__JSString;
pub extern fn JSC__JSString__createFromString(arg0: [*c]JSC__VM, arg1: [*c]const WTF__String) [*c]JSC__JSString;
pub extern fn JSC__JSString__eql(arg0: [*c]const JSC__JSString, arg1: ?*JSC__JSGlobalObject, arg2: [*c]JSC__JSString) bool;
pub extern fn JSC__JSString__is8Bit(arg0: [*c]const JSC__JSString) bool;
pub extern fn JSC__JSString__iterator(arg0: [*c]JSC__JSString, arg1: ?*JSC__JSGlobalObject, arg2: ?*anyopaque) void;
pub extern fn JSC__JSString__length(arg0: [*c]const JSC__JSString) usize;
pub extern fn JSC__JSString__toObject(arg0: [*c]JSC__JSString, arg1: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSString__value(arg0: [*c]JSC__JSString, arg1: ?*JSC__JSGlobalObject) bWTF__String;
pub extern fn Inspector__ScriptArguments__argumentAt(arg0: [*c]bindings.ScriptArguments, arg1: usize) JSC__JSValue;
pub extern fn Inspector__ScriptArguments__argumentCount(arg0: [*c]bindings.ScriptArguments) usize;
pub extern fn Inspector__ScriptArguments__getFirstArgumentAsString(arg0: [*c]bindings.ScriptArguments) bWTF__String;
pub extern fn Inspector__ScriptArguments__isEqual(arg0: [*c]bindings.ScriptArguments, arg1: [*c]bindings.ScriptArguments) bool;
pub extern fn Inspector__ScriptArguments__release(arg0: [*c]bindings.ScriptArguments) void;
pub extern fn JSC__JSModuleLoader__checkSyntax(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const JSC__SourceCode, arg2: bool) bool;
pub extern fn JSC__JSModuleLoader__evaluate(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const u8, arg2: usize, arg3: [*c]const u8, arg4: usize, JSValue5: JSC__JSValue, arg6: [*c]JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSModuleLoader__importModule(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const JSC__Identifier) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSModuleLoader__linkAndEvaluateModule(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const JSC__Identifier) JSC__JSValue;
pub extern fn JSC__JSModuleLoader__loadAndEvaluateModule(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const ZigString) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSModuleLoader__loadAndEvaluateModuleEntryPoint(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const JSC__SourceCode) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSModuleRecord__sourceCode(arg0: [*c]JSC__JSModuleRecord) bJSC__SourceCode;
pub extern fn JSC__JSPromise__asValue(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSPromise__create(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSPromise;
pub extern fn JSC__JSPromise__isHandled(arg0: [*c]const JSC__JSPromise, arg1: [*c]JSC__VM) bool;
pub extern fn JSC__JSPromise__reject(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__rejectAsHandled(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__rejectAsHandledException(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject, arg2: [*c]JSC__Exception) void;
pub extern fn JSC__JSPromise__rejectedPromise(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) [*c]JSC__JSPromise;
pub extern fn JSC__JSPromise__rejectedPromiseValue(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSPromise__rejectWithCaughtException(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject, arg2: bJSC__ThrowScope) void;
pub extern fn JSC__JSPromise__resolve(arg0: [*c]JSC__JSPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__resolvedPromise(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) [*c]JSC__JSPromise;
pub extern fn JSC__JSPromise__resolvedPromiseValue(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSPromise__result(arg0: [*c]const JSC__JSPromise, arg1: [*c]JSC__VM) JSC__JSValue;
pub extern fn JSC__JSPromise__status(arg0: [*c]const JSC__JSPromise, arg1: [*c]JSC__VM) u32;
pub extern fn JSC__JSInternalPromise__create(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSInternalPromise__isHandled(arg0: [*c]const JSC__JSInternalPromise, arg1: [*c]JSC__VM) bool;
pub extern fn JSC__JSInternalPromise__reject(arg0: [*c]JSC__JSInternalPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__rejectAsHandled(arg0: [*c]JSC__JSInternalPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__rejectAsHandledException(arg0: [*c]JSC__JSInternalPromise, arg1: ?*JSC__JSGlobalObject, arg2: [*c]JSC__Exception) void;
pub extern fn JSC__JSInternalPromise__rejectedPromise(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSInternalPromise__rejectWithCaughtException(arg0: [*c]JSC__JSInternalPromise, arg1: ?*JSC__JSGlobalObject, arg2: bJSC__ThrowScope) void;
pub extern fn JSC__JSInternalPromise__resolve(arg0: [*c]JSC__JSInternalPromise, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__resolvedPromise(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSInternalPromise__result(arg0: [*c]const JSC__JSInternalPromise, arg1: [*c]JSC__VM) JSC__JSValue;
pub extern fn JSC__JSInternalPromise__status(arg0: [*c]const JSC__JSInternalPromise, arg1: [*c]JSC__VM) u32;
pub extern fn JSC__SourceOrigin__fromURL(arg0: [*c]const WTF__URL) bJSC__SourceOrigin;
pub extern fn JSC__SourceCode__fromString(arg0: [*c]JSC__SourceCode, arg1: [*c]const WTF__String, arg2: [*c]const JSC__SourceOrigin, arg3: [*c]WTF__String, SourceType4: u8) void;
pub extern fn JSC__JSFunction__calculatedDisplayName(arg0: [*c]JSC__JSFunction, arg1: [*c]JSC__VM) bWTF__String;
pub extern fn JSC__JSFunction__displayName(arg0: [*c]JSC__JSFunction, arg1: [*c]JSC__VM) bWTF__String;
pub extern fn JSC__JSFunction__getName(arg0: [*c]JSC__JSFunction, arg1: [*c]JSC__VM) bWTF__String;
pub extern fn JSC__JSGlobalObject__arrayIteratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.ArrayIteratorPrototype;
pub extern fn JSC__JSGlobalObject__arrayPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.ArrayPrototype;
pub extern fn JSC__JSGlobalObject__asyncFunctionPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.AsyncFunctionPrototype;
pub extern fn JSC__JSGlobalObject__asyncGeneratorFunctionPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.AsyncGeneratorFunctionPrototype;
pub extern fn JSC__JSGlobalObject__asyncGeneratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.AsyncGeneratorPrototype;
pub extern fn JSC__JSGlobalObject__asyncIteratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.AsyncIteratorPrototype;
pub extern fn JSC__JSGlobalObject__bigIntPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.BigIntPrototype;
pub extern fn JSC__JSGlobalObject__booleanPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__bunVM(arg0: ?*JSC__JSGlobalObject) ?*bindings.VirtualMachine;
pub extern fn JSC__JSGlobalObject__createAggregateError(arg0: ?*JSC__JSGlobalObject, arg1: [*c]*anyopaque, arg2: u16, arg3: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__datePrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__deleteModuleRegistryEntry(arg0: ?*JSC__JSGlobalObject, arg1: [*c]ZigString) void;
pub extern fn JSC__JSGlobalObject__errorPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__functionPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.FunctionPrototype;
pub extern fn JSC__JSGlobalObject__generateHeapSnapshot(arg0: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__generatorFunctionPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.GeneratorFunctionPrototype;
pub extern fn JSC__JSGlobalObject__generatorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.GeneratorPrototype;
pub extern fn JSC__JSGlobalObject__getCachedObject(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__handleRejectedPromises(arg0: ?*JSC__JSGlobalObject) void;
pub extern fn JSC__JSGlobalObject__iteratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.IteratorPrototype;
pub extern fn JSC__JSGlobalObject__jsSetPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__mapIteratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.MapIteratorPrototype;
pub extern fn JSC__JSGlobalObject__mapPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__numberPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__objectPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.ObjectPrototype;
pub extern fn JSC__JSGlobalObject__promisePrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.JSPromisePrototype;
pub extern fn JSC__JSGlobalObject__putCachedObject(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const ZigString, JSValue2: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__regExpPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.RegExpPrototype;
pub extern fn JSC__JSGlobalObject__setIteratorPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.SetIteratorPrototype;
pub extern fn JSC__JSGlobalObject__startRemoteInspector(arg0: ?*JSC__JSGlobalObject, arg1: [*c]u8, arg2: u16) bool;
pub extern fn JSC__JSGlobalObject__stringPrototype(arg0: ?*JSC__JSGlobalObject) ?*bindings.StringPrototype;
pub extern fn JSC__JSGlobalObject__symbolPrototype(arg0: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSGlobalObject__vm(arg0: ?*JSC__JSGlobalObject) [*c]JSC__VM;
pub extern fn WTF__URL__encodedPassword(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__encodedUser(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__fileSystemPath(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__URL__fragmentIdentifier(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__fragmentIdentifierWithLeadingNumberSign(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__fromFileSystemPath(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__fromString(arg0: bWTF__String, arg1: bWTF__String) bWTF__URL;
pub extern fn WTF__URL__host(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__hostAndPort(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__URL__isEmpty(arg0: [*c]const WTF__URL) bool;
pub extern fn WTF__URL__isValid(arg0: [*c]const WTF__URL) bool;
pub extern fn WTF__URL__lastPathComponent(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__password(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__URL__path(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__protocol(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__protocolHostAndPort(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__URL__query(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__queryWithLeadingQuestionMark(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__setHost(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setHostAndPort(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setPassword(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setPath(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setProtocol(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setQuery(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__setUser(arg0: [*c]WTF__URL, arg1: bWTF__StringView) void;
pub extern fn WTF__URL__stringWithoutFragmentIdentifier(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__URL__stringWithoutQueryOrFragmentIdentifier(arg0: [*c]WTF__URL) bWTF__StringView;
pub extern fn WTF__URL__truncatedForUseAsBase(arg0: [*c]WTF__URL) bWTF__URL;
pub extern fn WTF__URL__user(arg0: [*c]WTF__URL) bWTF__String;
pub extern fn WTF__String__characters16(arg0: [*c]WTF__String) [*c]const u16;
pub extern fn WTF__String__characters8(arg0: [*c]WTF__String) [*c]const u8;
pub extern fn WTF__String__createFromExternalString(arg0: bWTF__ExternalStringImpl) bWTF__String;
pub extern fn WTF__String__createWithoutCopyingFromPtr(arg0: [*c]WTF__String, arg1: [*c]const u8, arg2: usize) void;
pub extern fn WTF__String__eqlSlice(arg0: [*c]WTF__String, arg1: [*c]const u8, arg2: usize) bool;
pub extern fn WTF__String__eqlString(arg0: [*c]WTF__String, arg1: [*c]const WTF__String) bool;
pub extern fn WTF__String__impl(arg0: [*c]WTF__String) [*c]const WTF__StringImpl;
pub extern fn WTF__String__is16Bit(arg0: [*c]WTF__String) bool;
pub extern fn WTF__String__is8Bit(arg0: [*c]WTF__String) bool;
pub extern fn WTF__String__isEmpty(arg0: [*c]WTF__String) bool;
pub extern fn WTF__String__isExternal(arg0: [*c]WTF__String) bool;
pub extern fn WTF__String__isStatic(arg0: [*c]WTF__String) bool;
pub extern fn WTF__String__length(arg0: [*c]WTF__String) usize;
pub extern fn JSC__JSValue___then(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?fn (?*anyopaque, ?*JSC__JSGlobalObject, ?*bindings.CallFrame) callconv(.C) void, ArgFn4: ?fn (?*anyopaque, ?*JSC__JSGlobalObject, ?*bindings.CallFrame) callconv(.C) void) void;
pub extern fn JSC__JSValue__asArrayBuffer_(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: ?*Bun__ArrayBuffer) bool;
pub extern fn JSC__JSValue__asCell(JSValue0: JSC__JSValue) [*c]JSC__JSCell;
pub extern fn JSC__JSValue__asInternalPromise(JSValue0: JSC__JSValue) [*c]JSC__JSInternalPromise;
pub extern fn JSC__JSValue__asNumber(JSValue0: JSC__JSValue) f64;
pub extern fn JSC__JSValue__asObject(JSValue0: JSC__JSValue) bJSC__JSObject;
pub extern fn JSC__JSValue__asPromise(JSValue0: JSC__JSValue) [*c]JSC__JSPromise;
pub extern fn JSC__JSValue__asString(JSValue0: JSC__JSValue) [*c]JSC__JSString;
pub extern fn JSC__JSValue__createEmptyObject(arg0: ?*JSC__JSGlobalObject, arg1: usize) JSC__JSValue;
pub extern fn JSC__JSValue__createInternalPromise(arg0: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createObject2(arg0: ?*JSC__JSGlobalObject, arg1: [*c]const ZigString, arg2: [*c]const ZigString, JSValue3: JSC__JSValue, JSValue4: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSValue__createRangeError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createStringArray(arg0: ?*JSC__JSGlobalObject, arg1: [*c]ZigString, arg2: usize, arg3: bool) JSC__JSValue;
pub extern fn JSC__JSValue__createTypeError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createUninitializedUint8Array(arg0: ?*JSC__JSGlobalObject, arg1: usize) JSC__JSValue;
pub extern fn JSC__JSValue__eqlCell(JSValue0: JSC__JSValue, arg1: [*c]JSC__JSCell) bool;
pub extern fn JSC__JSValue__eqlValue(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) bool;
pub extern fn JSC__JSValue__forEach(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?fn ([*c]JSC__VM, ?*JSC__JSGlobalObject, ?*anyopaque, JSC__JSValue) callconv(.C) void) void;
pub extern fn JSC__JSValue__fromEntries(arg0: ?*JSC__JSGlobalObject, arg1: [*c]ZigString, arg2: [*c]ZigString, arg3: usize, arg4: bool) JSC__JSValue;
pub extern fn JSC__JSValue__fromInt64NoTruncate(arg0: ?*JSC__JSGlobalObject, arg1: i64) JSC__JSValue;
pub extern fn JSC__JSValue__fromUInt64NoTruncate(arg0: ?*JSC__JSGlobalObject, arg1: u64) JSC__JSValue;
pub extern fn JSC__JSValue__getClassName(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__getErrorsProperty(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__getIfPropertyExistsImpl(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]const u8, arg3: u32) JSC__JSValue;
pub extern fn JSC__JSValue__getLengthOfArray(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) u32;
pub extern fn JSC__JSValue__getNameProperty(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__getPrototype(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__getSymbolDescription(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__isAggregateError(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) bool;
pub extern fn JSC__JSValue__isAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBigInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBigInt32(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBoolean(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isCallable(JSValue0: JSC__JSValue, arg1: [*c]JSC__VM) bool;
pub extern fn JSC__JSValue__isCell(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isClass(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) bool;
pub extern fn JSC__JSValue__isCustomGetterSetter(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isError(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isException(JSValue0: JSC__JSValue, arg1: [*c]JSC__VM) bool;
pub extern fn JSC__JSValue__isGetterSetter(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isHeapBigInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isInt32(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isInt32AsAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isIterable(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) bool;
pub extern fn JSC__JSValue__isNumber(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isObject(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isPrimitive(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isSameValue(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: ?*JSC__JSGlobalObject) bool;
pub extern fn JSC__JSValue__isString(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isSymbol(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isTerminationException(JSValue0: JSC__JSValue, arg1: [*c]JSC__VM) bool;
pub extern fn JSC__JSValue__isUInt32AsAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__jsBoolean(arg0: bool) JSC__JSValue;
pub extern fn JSC__JSValue__jsDoubleNumber(arg0: f64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNull(...) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromChar(arg0: u8) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromDouble(arg0: f64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromInt64(arg0: i64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromU16(arg0: u16) JSC__JSValue;
pub extern fn JSC__JSValue__jsonStringify(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: u32, arg3: [*c]ZigString) void;
pub extern fn JSC__JSValue__jsTDZValue(...) JSC__JSValue;
pub extern fn JSC__JSValue__jsType(JSValue0: JSC__JSValue) u8;
pub extern fn JSC__JSValue__jsUndefined(...) JSC__JSValue;
pub extern fn JSC__JSValue__makeWithNameAndPrototype(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque, arg2: ?*anyopaque, arg3: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSValue__parseJSON(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__put(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]const ZigString, JSValue3: JSC__JSValue) void;
pub extern fn JSC__JSValue__putRecord(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString, arg3: [*c]ZigString, arg4: usize) void;
pub extern fn JSC__JSValue__symbolFor(arg0: ?*JSC__JSGlobalObject, arg1: [*c]ZigString) JSC__JSValue;
pub extern fn JSC__JSValue__symbolKeyFor(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigString) bool;
pub extern fn JSC__JSValue__toBoolean(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__toInt32(JSValue0: JSC__JSValue) i32;
pub extern fn JSC__JSValue__toInt64(JSValue0: JSC__JSValue) i64;
pub extern fn JSC__JSValue__toObject(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) [*c]JSC__JSObject;
pub extern fn JSC__JSValue__toPropertyKey(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) bJSC__Identifier;
pub extern fn JSC__JSValue__toPropertyKeyValue(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__toString(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) [*c]JSC__JSString;
pub extern fn JSC__JSValue__toStringOrNull(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) [*c]JSC__JSString;
pub extern fn JSC__JSValue__toUInt64NoTruncate(JSValue0: JSC__JSValue) u64;
pub extern fn JSC__JSValue__toWTFString(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject) bWTF__String;
pub extern fn JSC__JSValue__toZigException(JSValue0: JSC__JSValue, arg1: ?*JSC__JSGlobalObject, arg2: [*c]ZigException) void;
pub extern fn JSC__JSValue__toZigString(JSValue0: JSC__JSValue, arg1: [*c]ZigString, arg2: ?*JSC__JSGlobalObject) void;
pub extern fn JSC__PropertyName__eqlToIdentifier(arg0: [*c]JSC__PropertyName, arg1: [*c]const JSC__Identifier) bool;
pub extern fn JSC__PropertyName__eqlToPropertyName(arg0: [*c]JSC__PropertyName, arg1: [*c]const JSC__PropertyName) bool;
pub extern fn JSC__PropertyName__publicName(arg0: [*c]JSC__PropertyName) [*c]const WTF__StringImpl;
pub extern fn JSC__PropertyName__uid(arg0: [*c]JSC__PropertyName) [*c]const WTF__StringImpl;
pub extern fn JSC__Exception__create(arg0: ?*JSC__JSGlobalObject, arg1: [*c]JSC__JSObject, StackCaptureAction2: u8) [*c]JSC__Exception;
pub extern fn JSC__Exception__getStackTrace(arg0: [*c]JSC__Exception, arg1: [*c]ZigStackTrace) void;
pub extern fn JSC__Exception__value(arg0: [*c]JSC__Exception) JSC__JSValue;
pub extern fn JSC__VM__clearExecutionTimeLimit(arg0: [*c]JSC__VM) void;
pub extern fn JSC__VM__create(HeapType0: u8) [*c]JSC__VM;
pub extern fn JSC__VM__deferGC(arg0: [*c]JSC__VM, arg1: ?*anyopaque, ArgFn2: ?fn (?*anyopaque) callconv(.C) void) void;
pub extern fn JSC__VM__deinit(arg0: [*c]JSC__VM, arg1: ?*JSC__JSGlobalObject) void;
pub extern fn JSC__VM__deleteAllCode(arg0: [*c]JSC__VM, arg1: ?*JSC__JSGlobalObject) void;
pub extern fn JSC__VM__doWork(arg0: [*c]JSC__VM) void;
pub extern fn JSC__VM__drainMicrotasks(arg0: [*c]JSC__VM) void;
pub extern fn JSC__VM__executionForbidden(arg0: [*c]JSC__VM) bool;
pub extern fn JSC__VM__holdAPILock(arg0: [*c]JSC__VM, arg1: ?*anyopaque, ArgFn2: ?fn (?*anyopaque) callconv(.C) void) void;
pub extern fn JSC__VM__isEntered(arg0: [*c]JSC__VM) bool;
pub extern fn JSC__VM__isJITEnabled(...) bool;
pub extern fn JSC__VM__releaseWeakRefs(arg0: [*c]JSC__VM) void;
pub extern fn JSC__VM__runGC(arg0: [*c]JSC__VM, arg1: bool) JSC__JSValue;
pub extern fn JSC__VM__setExecutionForbidden(arg0: [*c]JSC__VM, arg1: bool) void;
pub extern fn JSC__VM__setExecutionTimeLimit(arg0: [*c]JSC__VM, arg1: f64) void;
pub extern fn JSC__VM__shrinkFootprint(arg0: [*c]JSC__VM) void;
pub extern fn JSC__VM__throwError(arg0: [*c]JSC__VM, arg1: ?*JSC__JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__VM__whenIdle(arg0: [*c]JSC__VM, ArgFn1: ?fn (...) callconv(.C) void) void;
pub extern fn JSC__ThrowScope__clearException(arg0: [*c]JSC__ThrowScope) void;
pub extern fn JSC__ThrowScope__declare(arg0: [*c]JSC__VM, arg1: [*c]u8, arg2: [*c]u8, arg3: usize) bJSC__ThrowScope;
pub extern fn JSC__ThrowScope__exception(arg0: [*c]JSC__ThrowScope) [*c]JSC__Exception;
pub extern fn JSC__ThrowScope__release(arg0: [*c]JSC__ThrowScope) void;
pub extern fn JSC__CatchScope__clearException(arg0: [*c]JSC__CatchScope) void;
pub extern fn JSC__CatchScope__declare(arg0: [*c]JSC__VM, arg1: [*c]u8, arg2: [*c]u8, arg3: usize) bJSC__CatchScope;
pub extern fn JSC__CatchScope__exception(arg0: [*c]JSC__CatchScope) [*c]JSC__Exception;
pub extern fn JSC__Identifier__deinit(arg0: [*c]const JSC__Identifier) void;
pub extern fn JSC__Identifier__eqlIdent(arg0: [*c]const JSC__Identifier, arg1: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__eqlStringImpl(arg0: [*c]const JSC__Identifier, arg1: [*c]const WTF__StringImpl) bool;
pub extern fn JSC__Identifier__eqlUTF8(arg0: [*c]const JSC__Identifier, arg1: [*c]const u8, arg2: usize) bool;
pub extern fn JSC__Identifier__fromSlice(arg0: [*c]JSC__VM, arg1: [*c]const u8, arg2: usize) bJSC__Identifier;
pub extern fn JSC__Identifier__fromString(arg0: [*c]JSC__VM, arg1: [*c]const WTF__String) bJSC__Identifier;
pub extern fn JSC__Identifier__isEmpty(arg0: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__isNull(arg0: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__isPrivateName(arg0: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__isSymbol(arg0: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__length(arg0: [*c]const JSC__Identifier) usize;
pub extern fn JSC__Identifier__neqlIdent(arg0: [*c]const JSC__Identifier, arg1: [*c]const JSC__Identifier) bool;
pub extern fn JSC__Identifier__neqlStringImpl(arg0: [*c]const JSC__Identifier, arg1: [*c]const WTF__StringImpl) bool;
pub extern fn JSC__Identifier__toString(arg0: [*c]const JSC__Identifier) bWTF__String;
pub extern fn WTF__StringImpl__characters16(arg0: [*c]const WTF__StringImpl) [*c]const u16;
pub extern fn WTF__StringImpl__characters8(arg0: [*c]const WTF__StringImpl) [*c]const u8;
pub extern fn WTF__StringImpl__is16Bit(arg0: [*c]const WTF__StringImpl) bool;
pub extern fn WTF__StringImpl__is8Bit(arg0: [*c]const WTF__StringImpl) bool;
pub extern fn WTF__StringImpl__isEmpty(arg0: [*c]const WTF__StringImpl) bool;
pub extern fn WTF__StringImpl__isExternal(arg0: [*c]const WTF__StringImpl) bool;
pub extern fn WTF__StringImpl__isStatic(arg0: [*c]const WTF__StringImpl) bool;
pub extern fn WTF__StringImpl__length(arg0: [*c]const WTF__StringImpl) usize;
pub extern fn WTF__ExternalStringImpl__characters16(arg0: [*c]const WTF__ExternalStringImpl) [*c]const u16;
pub extern fn WTF__ExternalStringImpl__characters8(arg0: [*c]const WTF__ExternalStringImpl) [*c]const u8;
pub extern fn WTF__ExternalStringImpl__create(arg0: [*c]const u8, arg1: usize, ArgFn2: ?fn (?*anyopaque, [*c]u8, usize) callconv(.C) void) bWTF__ExternalStringImpl;
pub extern fn WTF__ExternalStringImpl__is16Bit(arg0: [*c]const WTF__ExternalStringImpl) bool;
pub extern fn WTF__ExternalStringImpl__is8Bit(arg0: [*c]const WTF__ExternalStringImpl) bool;
pub extern fn WTF__ExternalStringImpl__isEmpty(arg0: [*c]const WTF__ExternalStringImpl) bool;
pub extern fn WTF__ExternalStringImpl__length(arg0: [*c]const WTF__ExternalStringImpl) usize;
pub extern fn WTF__StringView__characters16(arg0: [*c]const WTF__StringView) [*c]const u16;
pub extern fn WTF__StringView__characters8(arg0: [*c]const WTF__StringView) [*c]const u8;
pub extern fn WTF__StringView__from8Bit(arg0: [*c]WTF__StringView, arg1: [*c]const u8, arg2: usize) void;
pub extern fn WTF__StringView__is16Bit(arg0: [*c]const WTF__StringView) bool;
pub extern fn WTF__StringView__is8Bit(arg0: [*c]const WTF__StringView) bool;
pub extern fn WTF__StringView__isEmpty(arg0: [*c]const WTF__StringView) bool;
pub extern fn WTF__StringView__length(arg0: [*c]const WTF__StringView) usize;
pub extern fn FFI__ptr__put(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Zig__GlobalObject__create(arg0: [*c]JSClassRef, arg1: i32, arg2: ?*anyopaque) ?*JSC__JSGlobalObject;
pub extern fn Zig__GlobalObject__getModuleRegistryMap(arg0: ?*JSC__JSGlobalObject) ?*anyopaque;
pub extern fn Zig__GlobalObject__resetModuleRegistryMap(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque) bool;
pub extern fn Bun__Path__create(arg0: ?*JSC__JSGlobalObject, arg1: bool) JSC__JSValue;
pub extern fn ArrayBufferSink__assignToStream(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn ArrayBufferSink__createObject(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn ArrayBufferSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn ArrayBufferSink__fromJS(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn ArrayBufferSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn ArrayBufferSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__assignToStream(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn HTTPSResponseSink__createObject(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn HTTPSResponseSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__fromJS(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn HTTPSResponseSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn HTTPResponseSink__assignToStream(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn HTTPResponseSink__createObject(arg0: ?*JSC__JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn HTTPResponseSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn HTTPResponseSink__fromJS(arg0: ?*JSC__JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn HTTPResponseSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn HTTPResponseSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn ZigException__fromException(arg0: [*c]JSC__Exception) ZigException;
