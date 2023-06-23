// GENERATED CODE - DO NOT MODIFY BY HAND

const bindings = @import("root").bun.JSC;
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
pub const BunString = @import("root").bun.String;
pub const JSC__ThrowScope = bJSC__ThrowScope;
pub const JSC__JSObject = bJSC__JSObject;
pub const JSC__VM = bJSC__VM;
pub const JSC__JSGlobalObject = bJSC__JSGlobalObject;
pub const JSC__JSPromise = bJSC__JSPromise;
pub const JSC__JSCell = bJSC__JSCell;
pub const JSC__JSInternalPromise = bJSC__JSInternalPromise;
pub const JSC__Exception = bJSC__Exception;
pub const JSC__JSString = bJSC__JSString;
pub extern fn JSC__JSObject__create(arg0: *bindings.JSGlobalObject, arg1: usize, arg2: ?*anyopaque, ArgFn3: ?*const fn (?*anyopaque, [*c]bindings.JSObject, *bindings.JSGlobalObject) callconv(.C) void) JSC__JSValue;
pub extern fn JSC__JSObject__getArrayLength(arg0: [*c]bindings.JSObject) usize;
pub extern fn JSC__JSObject__getDirect(arg0: [*c]bindings.JSObject, arg1: *bindings.JSGlobalObject, arg2: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSObject__getIndex(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: u32) JSC__JSValue;
pub extern fn JSC__JSObject__putRecord(arg0: [*c]bindings.JSObject, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString, arg3: [*c]ZigString, arg4: usize) void;
pub extern fn ZigString__external(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?*const fn (?*anyopaque, ?*anyopaque, usize) callconv(.C) void) JSC__JSValue;
pub extern fn ZigString__to16BitValue(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toAtomicValue(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toErrorInstance(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalU16(arg0: [*c]const u16, arg1: usize, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalValue(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toExternalValueWithCallback(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject, ArgFn2: ?*const fn (?*anyopaque, ?*anyopaque, usize) callconv(.C) void) JSC__JSValue;
pub extern fn ZigString__toRangeErrorInstance(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toSyntaxErrorInstance(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toTypeErrorInstance(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toValue(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn ZigString__toValueGC(arg0: [*c]const ZigString, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__DOMURL__cast_(JSValue0: JSC__JSValue, arg1: *bindings.VM) ?*bindings.DOMURL;
pub extern fn WebCore__DOMURL__fileSystemPath(arg0: ?*bindings.DOMURL) BunString;
pub extern fn WebCore__DOMURL__href_(arg0: ?*bindings.DOMURL, arg1: [*c]ZigString) void;
pub extern fn WebCore__DOMURL__pathname_(arg0: ?*bindings.DOMURL, arg1: [*c]ZigString) void;
pub extern fn WebCore__DOMFormData__append(arg0: ?*bindings.DOMFormData, arg1: [*c]ZigString, arg2: [*c]ZigString) void;
pub extern fn WebCore__DOMFormData__appendBlob(arg0: ?*bindings.DOMFormData, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString, arg3: ?*anyopaque, arg4: [*c]ZigString) void;
pub extern fn WebCore__DOMFormData__count(arg0: ?*bindings.DOMFormData) usize;
pub extern fn WebCore__DOMFormData__create(arg0: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__DOMFormData__createFromURLQuery(arg0: *bindings.JSGlobalObject, arg1: [*c]ZigString) JSC__JSValue;
pub extern fn WebCore__DOMFormData__fromJS(JSValue0: JSC__JSValue) ?*bindings.DOMFormData;
pub extern fn WebCore__FetchHeaders__append(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]const ZigString, arg3: *bindings.JSGlobalObject) void;
pub extern fn WebCore__FetchHeaders__cast_(JSValue0: JSC__JSValue, arg1: *bindings.VM) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__clone(arg0: ?*bindings.FetchHeaders, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__cloneThis(arg0: ?*bindings.FetchHeaders, arg1: *bindings.JSGlobalObject) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__copyTo(arg0: ?*bindings.FetchHeaders, arg1: [*c]StringPointer, arg2: [*c]StringPointer, arg3: [*c]u8) void;
pub extern fn WebCore__FetchHeaders__count(arg0: ?*bindings.FetchHeaders, arg1: [*c]u32, arg2: [*c]u32) void;
pub extern fn WebCore__FetchHeaders__createEmpty(...) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromJS(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromPicoHeaders_(arg0: ?*const anyopaque) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createFromUWS(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) ?*bindings.FetchHeaders;
pub extern fn WebCore__FetchHeaders__createValue(arg0: *bindings.JSGlobalObject, arg1: [*c]StringPointer, arg2: [*c]StringPointer, arg3: [*c]const ZigString, arg4: u32) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__deref(arg0: ?*bindings.FetchHeaders) void;
pub extern fn WebCore__FetchHeaders__fastGet_(arg0: ?*bindings.FetchHeaders, arg1: u8, arg2: [*c]ZigString) void;
pub extern fn WebCore__FetchHeaders__fastHas_(arg0: ?*bindings.FetchHeaders, arg1: u8) bool;
pub extern fn WebCore__FetchHeaders__fastRemove_(arg0: ?*bindings.FetchHeaders, arg1: u8) void;
pub extern fn WebCore__FetchHeaders__get_(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]ZigString, arg3: *bindings.JSGlobalObject) void;
pub extern fn WebCore__FetchHeaders__has(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) bool;
pub extern fn WebCore__FetchHeaders__isEmpty(arg0: ?*bindings.FetchHeaders) bool;
pub extern fn WebCore__FetchHeaders__put_(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: [*c]const ZigString, arg3: *bindings.JSGlobalObject) void;
pub extern fn WebCore__FetchHeaders__remove(arg0: ?*bindings.FetchHeaders, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) void;
pub extern fn WebCore__FetchHeaders__toJS(arg0: ?*bindings.FetchHeaders, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__FetchHeaders__toUWSResponse(arg0: ?*bindings.FetchHeaders, arg1: bool, arg2: ?*anyopaque) void;
pub extern fn SystemError__toErrorInstance(arg0: [*c]const SystemError, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSCell__getObject(arg0: [*c]bindings.JSCell) [*c]bindings.JSObject;
pub extern fn JSC__JSCell__getType(arg0: [*c]bindings.JSCell) u8;
pub extern fn JSC__JSString__eql(arg0: [*c]const JSC__JSString, arg1: *bindings.JSGlobalObject, arg2: [*c]bindings.JSString) bool;
pub extern fn JSC__JSString__is8Bit(arg0: [*c]const JSC__JSString) bool;
pub extern fn JSC__JSString__iterator(arg0: [*c]bindings.JSString, arg1: *bindings.JSGlobalObject, arg2: ?*anyopaque) void;
pub extern fn JSC__JSString__length(arg0: [*c]const JSC__JSString) usize;
pub extern fn JSC__JSString__toObject(arg0: [*c]bindings.JSString, arg1: *bindings.JSGlobalObject) [*c]bindings.JSObject;
pub extern fn JSC__JSString__toZigString(arg0: [*c]bindings.JSString, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSModuleLoader__evaluate(arg0: *bindings.JSGlobalObject, arg1: [*c]const u8, arg2: usize, arg3: [*c]const u8, arg4: usize, arg5: [*c]const u8, arg6: usize, JSValue7: JSC__JSValue, arg8: [*c]bindings.JSValue) JSC__JSValue;
pub extern fn JSC__JSModuleLoader__loadAndEvaluateModule(arg0: *bindings.JSGlobalObject, arg1: [*c]const BunString) [*c]bindings.JSInternalPromise;
pub extern fn WebCore__AbortSignal__aborted(arg0: ?*bindings.AbortSignal) bool;
pub extern fn WebCore__AbortSignal__abortReason(arg0: ?*bindings.AbortSignal) JSC__JSValue;
pub extern fn WebCore__AbortSignal__addListener(arg0: ?*bindings.AbortSignal, arg1: ?*anyopaque, ArgFn2: ?*const fn (?*anyopaque, JSC__JSValue) callconv(.C) void) ?*bindings.AbortSignal;
pub extern fn WebCore__AbortSignal__cleanNativeBindings(arg0: ?*bindings.AbortSignal, arg1: ?*anyopaque) void;
pub extern fn WebCore__AbortSignal__create(arg0: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__AbortSignal__createAbortError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__AbortSignal__createTimeoutError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__AbortSignal__fromJS(JSValue0: JSC__JSValue) ?*bindings.AbortSignal;
pub extern fn WebCore__AbortSignal__ref(arg0: ?*bindings.AbortSignal) ?*bindings.AbortSignal;
pub extern fn WebCore__AbortSignal__signal(arg0: ?*bindings.AbortSignal, JSValue1: JSC__JSValue) ?*bindings.AbortSignal;
pub extern fn WebCore__AbortSignal__toJS(arg0: ?*bindings.AbortSignal, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn WebCore__AbortSignal__unref(arg0: ?*bindings.AbortSignal) ?*bindings.AbortSignal;
pub extern fn JSC__JSPromise__asValue(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSPromise__create(arg0: *bindings.JSGlobalObject) ?*bindings.JSPromise;
pub extern fn JSC__JSPromise__isHandled(arg0: [*c]const JSC__JSPromise, arg1: *bindings.VM) bool;
pub extern fn JSC__JSPromise__reject(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__rejectAsHandled(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__rejectAsHandledException(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, arg2: [*c]bindings.Exception) void;
pub extern fn JSC__JSPromise__rejectedPromise(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*bindings.JSPromise;
pub extern fn JSC__JSPromise__rejectedPromiseValue(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSPromise__rejectOnNextTickWithHandled(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue, arg3: bool) void;
pub extern fn JSC__JSPromise__rejectWithCaughtException(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, arg2: bJSC__ThrowScope) void;
pub extern fn JSC__JSPromise__resolve(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__resolvedPromise(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*bindings.JSPromise;
pub extern fn JSC__JSPromise__resolvedPromiseValue(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSPromise__resolveOnNextTick(arg0: ?*bindings.JSPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSPromise__result(arg0: ?*bindings.JSPromise, arg1: *bindings.VM) JSC__JSValue;
pub extern fn JSC__JSPromise__setHandled(arg0: ?*bindings.JSPromise, arg1: *bindings.VM) void;
pub extern fn JSC__JSPromise__status(arg0: [*c]const JSC__JSPromise, arg1: *bindings.VM) u32;
pub extern fn JSC__JSInternalPromise__create(arg0: *bindings.JSGlobalObject) [*c]bindings.JSInternalPromise;
pub extern fn JSC__JSInternalPromise__isHandled(arg0: [*c]const JSC__JSInternalPromise, arg1: *bindings.VM) bool;
pub extern fn JSC__JSInternalPromise__reject(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__rejectAsHandled(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__rejectAsHandledException(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.JSGlobalObject, arg2: [*c]bindings.Exception) void;
pub extern fn JSC__JSInternalPromise__rejectedPromise(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) [*c]bindings.JSInternalPromise;
pub extern fn JSC__JSInternalPromise__rejectWithCaughtException(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.JSGlobalObject, arg2: bJSC__ThrowScope) void;
pub extern fn JSC__JSInternalPromise__resolve(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__JSInternalPromise__resolvedPromise(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) [*c]bindings.JSInternalPromise;
pub extern fn JSC__JSInternalPromise__result(arg0: [*c]const JSC__JSInternalPromise, arg1: *bindings.VM) JSC__JSValue;
pub extern fn JSC__JSInternalPromise__setHandled(arg0: [*c]bindings.JSInternalPromise, arg1: *bindings.VM) void;
pub extern fn JSC__JSInternalPromise__status(arg0: [*c]const JSC__JSInternalPromise, arg1: *bindings.VM) u32;
pub extern fn JSC__JSFunction__optimizeSoon(JSValue0: JSC__JSValue) void;
pub extern fn JSC__JSGlobalObject__bunVM(arg0: *bindings.JSGlobalObject) ?*bindings.VirtualMachine;
pub extern fn JSC__JSGlobalObject__createAggregateError(arg0: *bindings.JSGlobalObject, arg1: [*c]*anyopaque, arg2: u16, arg3: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__createSyntheticModule_(arg0: *bindings.JSGlobalObject, arg1: [*c]ZigString, arg2: usize, arg3: [*c]bindings.JSValue, arg4: usize) void;
pub extern fn JSC__JSGlobalObject__deleteModuleRegistryEntry(arg0: *bindings.JSGlobalObject, arg1: [*c]ZigString) void;
pub extern fn JSC__JSGlobalObject__generateHeapSnapshot(arg0: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__getCachedObject(arg0: *bindings.JSGlobalObject, arg1: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__handleRejectedPromises(arg0: *bindings.JSGlobalObject) void;
pub extern fn JSC__JSGlobalObject__putCachedObject(arg0: *bindings.JSGlobalObject, arg1: [*c]const ZigString, JSValue2: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSGlobalObject__queueMicrotaskJob(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue, JSValue3: JSC__JSValue, JSValue4: JSC__JSValue) void;
pub extern fn JSC__JSGlobalObject__reload(arg0: *bindings.JSGlobalObject) void;
pub extern fn JSC__JSGlobalObject__startRemoteInspector(arg0: *bindings.JSGlobalObject, arg1: [*c]u8, arg2: u16) bool;
pub extern fn JSC__JSGlobalObject__vm(arg0: *bindings.JSGlobalObject) *bindings.VM;
pub extern fn JSC__JSMap__create(arg0: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSMap__get_(arg0: ?*bindings.JSMap, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSMap__has(arg0: ?*bindings.JSMap, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) bool;
pub extern fn JSC__JSMap__remove(arg0: ?*bindings.JSMap, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) bool;
pub extern fn JSC__JSMap__set(arg0: ?*bindings.JSMap, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue, JSValue3: JSC__JSValue) void;
pub extern fn JSC__JSValue___then(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue, ArgFn3: ?*const fn (*bindings.JSGlobalObject, *bindings.CallFrame) callconv(.C) JSC__JSValue, ArgFn4: ?*const fn (*bindings.JSGlobalObject, *bindings.CallFrame) callconv(.C) JSC__JSValue) void;
pub extern fn JSC__JSValue__asArrayBuffer_(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: ?*Bun__ArrayBuffer) bool;
pub extern fn JSC__JSValue__asBigIntCompare(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) u8;
pub extern fn JSC__JSValue__asCell(JSValue0: JSC__JSValue) [*c]bindings.JSCell;
pub extern fn JSC__JSValue__asInternalPromise(JSValue0: JSC__JSValue) [*c]bindings.JSInternalPromise;
pub extern fn JSC__JSValue__asNumber(JSValue0: JSC__JSValue) f64;
pub extern fn JSC__JSValue__asObject(JSValue0: JSC__JSValue) bJSC__JSObject;
pub extern fn JSC__JSValue__asPromise(JSValue0: JSC__JSValue) ?*bindings.JSPromise;
pub extern fn JSC__JSValue__asString(JSValue0: JSC__JSValue) [*c]bindings.JSString;
pub extern fn JSC__JSValue__coerceToDouble(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) f64;
pub extern fn JSC__JSValue__coerceToInt32(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) i32;
pub extern fn JSC__JSValue__coerceToInt64(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) i64;
pub extern fn JSC__JSValue__createEmptyArray(arg0: *bindings.JSGlobalObject, arg1: usize) JSC__JSValue;
pub extern fn JSC__JSValue__createEmptyObject(arg0: *bindings.JSGlobalObject, arg1: usize) JSC__JSValue;
pub extern fn JSC__JSValue__createInternalPromise(arg0: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createObject2(arg0: *bindings.JSGlobalObject, arg1: [*c]const ZigString, arg2: [*c]const ZigString, JSValue3: JSC__JSValue, JSValue4: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSValue__createRangeError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createRopeString(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createStringArray(arg0: *bindings.JSGlobalObject, arg1: [*c]const ZigString, arg2: usize, arg3: bool) JSC__JSValue;
pub extern fn JSC__JSValue__createTypeError(arg0: [*c]const ZigString, arg1: [*c]const ZigString, arg2: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__createUninitializedUint8Array(arg0: *bindings.JSGlobalObject, arg1: usize) JSC__JSValue;
pub extern fn JSC__JSValue__deepEquals(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__deepMatch(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject, arg3: bool) bool;
pub extern fn JSC__JSValue__eqlCell(JSValue0: JSC__JSValue, arg1: [*c]bindings.JSCell) bool;
pub extern fn JSC__JSValue__eqlValue(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) bool;
pub extern fn JSC__JSValue__fastGet_(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: u8) JSC__JSValue;
pub extern fn JSC__JSValue__fastGetDirect_(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: u8) JSC__JSValue;
pub extern fn JSC__JSValue__forEach(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?*const fn (*bindings.VM, *bindings.JSGlobalObject, ?*anyopaque, JSC__JSValue) callconv(.C) void) void;
pub extern fn JSC__JSValue__forEachProperty(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?*const fn (*bindings.JSGlobalObject, ?*anyopaque, [*c]ZigString, JSC__JSValue, bool) callconv(.C) void) void;
pub extern fn JSC__JSValue__forEachPropertyOrdered(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: ?*anyopaque, ArgFn3: ?*const fn (*bindings.JSGlobalObject, ?*anyopaque, [*c]ZigString, JSC__JSValue, bool) callconv(.C) void) void;
pub extern fn JSC__JSValue__fromEntries(arg0: *bindings.JSGlobalObject, arg1: [*c]ZigString, arg2: [*c]ZigString, arg3: usize, arg4: bool) JSC__JSValue;
pub extern fn JSC__JSValue__fromInt64NoTruncate(arg0: *bindings.JSGlobalObject, arg1: i64) JSC__JSValue;
pub extern fn JSC__JSValue__fromUInt64NoTruncate(arg0: *bindings.JSGlobalObject, arg1: u64) JSC__JSValue;
pub extern fn JSC__JSValue__getClassName(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__getErrorsProperty(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__getIfPropertyExistsFromPath(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSValue__getIfPropertyExistsImpl(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]const u8, arg3: u32) JSC__JSValue;
pub extern fn JSC__JSValue__getLengthIfPropertyExistsInternal(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) f64;
pub extern fn JSC__JSValue__getNameProperty(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__getPrototype(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__getSymbolDescription(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString) void;
pub extern fn JSC__JSValue__getUnixTimestamp(JSValue0: JSC__JSValue) f64;
pub extern fn JSC__JSValue__isAggregateError(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__isAnyError(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBigInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBigInt32(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isBoolean(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isCallable(JSValue0: JSC__JSValue, arg1: *bindings.VM) bool;
pub extern fn JSC__JSValue__isClass(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__isConstructor(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isCustomGetterSetter(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isError(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isException(JSValue0: JSC__JSValue, arg1: *bindings.VM) bool;
pub extern fn JSC__JSValue__isGetterSetter(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isHeapBigInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isInstanceOf(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isInt32(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isInt32AsAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isIterable(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__isNumber(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isObject(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isPrimitive(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isSameValue(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__isSymbol(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__isTerminationException(JSValue0: JSC__JSValue, arg1: *bindings.VM) bool;
pub extern fn JSC__JSValue__isUInt32AsAnyInt(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__jestDeepEquals(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__jestDeepMatch(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject, arg3: bool) bool;
pub extern fn JSC__JSValue__jestStrictDeepEquals(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__jsBoolean(arg0: bool) JSC__JSValue;
pub extern fn JSC__JSValue__jsDoubleNumber(arg0: f64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNull(...) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromChar(arg0: u8) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromDouble(arg0: f64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromInt64(arg0: i64) JSC__JSValue;
pub extern fn JSC__JSValue__jsNumberFromU16(arg0: u16) JSC__JSValue;
pub extern fn JSC__JSValue__jsonStringify(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: u32, arg3: [*c]ZigString) void;
pub extern fn JSC__JSValue__jsTDZValue(...) JSC__JSValue;
pub extern fn JSC__JSValue__jsType(JSValue0: JSC__JSValue) u8;
pub extern fn JSC__JSValue__jsUndefined(...) JSC__JSValue;
pub extern fn JSC__JSValue__makeWithNameAndPrototype(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque, arg2: ?*anyopaque, arg3: [*c]const ZigString) JSC__JSValue;
pub extern fn JSC__JSValue__parseJSON(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) JSC__JSValue;
pub extern fn JSC__JSValue__put(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]const ZigString, JSValue3: JSC__JSValue) void;
pub extern fn JSC__JSValue__putIndex(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: u32, JSValue3: JSC__JSValue) void;
pub extern fn JSC__JSValue__putRecord(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString, arg3: [*c]ZigString, arg4: usize) void;
pub extern fn JSC__JSValue__strictDeepEquals(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, arg2: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__stringIncludes(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) bool;
pub extern fn JSC__JSValue__symbolFor(arg0: *bindings.JSGlobalObject, arg1: [*c]ZigString) JSC__JSValue;
pub extern fn JSC__JSValue__symbolKeyFor(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigString) bool;
pub extern fn JSC__JSValue__toBoolean(JSValue0: JSC__JSValue) bool;
pub extern fn JSC__JSValue__toBooleanSlow(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) bool;
pub extern fn JSC__JSValue__toError_(JSValue0: JSC__JSValue) JSC__JSValue;
pub extern fn JSC__JSValue__toInt32(JSValue0: JSC__JSValue) i32;
pub extern fn JSC__JSValue__toInt64(JSValue0: JSC__JSValue) i64;
pub extern fn JSC__JSValue__toMatch(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) bool;
pub extern fn JSC__JSValue__toObject(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) [*c]bindings.JSObject;
pub extern fn JSC__JSValue__toString(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) [*c]bindings.JSString;
pub extern fn JSC__JSValue__toStringOrNull(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject) [*c]bindings.JSString;
pub extern fn JSC__JSValue__toUInt64NoTruncate(JSValue0: JSC__JSValue) u64;
pub extern fn JSC__JSValue__toZigException(JSValue0: JSC__JSValue, arg1: *bindings.JSGlobalObject, arg2: [*c]ZigException) void;
pub extern fn JSC__JSValue__toZigString(JSValue0: JSC__JSValue, arg1: [*c]ZigString, arg2: *bindings.JSGlobalObject) void;
pub extern fn JSC__Exception__create(arg0: *bindings.JSGlobalObject, arg1: [*c]bindings.JSObject, StackCaptureAction2: u8) [*c]bindings.Exception;
pub extern fn JSC__Exception__getStackTrace(arg0: [*c]bindings.Exception, arg1: [*c]ZigStackTrace) void;
pub extern fn JSC__Exception__value(arg0: [*c]bindings.Exception) JSC__JSValue;
pub extern fn JSC__VM__blockBytesAllocated(arg0: *bindings.VM) usize;
pub extern fn JSC__VM__clearExecutionTimeLimit(arg0: *bindings.VM) void;
pub extern fn JSC__VM__collectAsync(arg0: *bindings.VM) void;
pub extern fn JSC__VM__create(HeapType0: u8) *bindings.VM;
pub extern fn JSC__VM__deferGC(arg0: *bindings.VM, arg1: ?*anyopaque, ArgFn2: ?*const fn (?*anyopaque) callconv(.C) void) void;
pub extern fn JSC__VM__deinit(arg0: *bindings.VM, arg1: *bindings.JSGlobalObject) void;
pub extern fn JSC__VM__deleteAllCode(arg0: *bindings.VM, arg1: *bindings.JSGlobalObject) void;
pub extern fn JSC__VM__doWork(arg0: *bindings.VM) void;
pub extern fn JSC__VM__drainMicrotasks(arg0: *bindings.VM) void;
pub extern fn JSC__VM__executionForbidden(arg0: *bindings.VM) bool;
pub extern fn JSC__VM__externalMemorySize(arg0: *bindings.VM) usize;
pub extern fn JSC__VM__heapSize(arg0: *bindings.VM) usize;
pub extern fn JSC__VM__holdAPILock(arg0: *bindings.VM, arg1: ?*anyopaque, ArgFn2: ?*const fn (?*anyopaque) callconv(.C) void) void;
pub extern fn JSC__VM__isEntered(arg0: *bindings.VM) bool;
pub extern fn JSC__VM__isJITEnabled(...) bool;
pub extern fn JSC__VM__releaseWeakRefs(arg0: *bindings.VM) void;
pub extern fn JSC__VM__runGC(arg0: *bindings.VM, arg1: bool) JSC__JSValue;
pub extern fn JSC__VM__setExecutionForbidden(arg0: *bindings.VM, arg1: bool) void;
pub extern fn JSC__VM__setExecutionTimeLimit(arg0: *bindings.VM, arg1: f64) void;
pub extern fn JSC__VM__shrinkFootprint(arg0: *bindings.VM) void;
pub extern fn JSC__VM__throwError(arg0: *bindings.VM, arg1: *bindings.JSGlobalObject, JSValue2: JSC__JSValue) void;
pub extern fn JSC__VM__whenIdle(arg0: *bindings.VM, ArgFn1: ?*const fn (...) callconv(.C) void) void;
pub extern fn JSC__ThrowScope__clearException(arg0: [*c]bindings.ThrowScope) void;
pub extern fn JSC__ThrowScope__declare(arg0: *bindings.VM, arg1: [*c]u8, arg2: [*c]u8, arg3: usize) bJSC__ThrowScope;
pub extern fn JSC__ThrowScope__exception(arg0: [*c]bindings.ThrowScope) [*c]bindings.Exception;
pub extern fn JSC__ThrowScope__release(arg0: [*c]bindings.ThrowScope) void;
pub extern fn JSC__CatchScope__clearException(arg0: [*c]bindings.CatchScope) void;
pub extern fn JSC__CatchScope__declare(arg0: *bindings.VM, arg1: [*c]u8, arg2: [*c]u8, arg3: usize) bJSC__CatchScope;
pub extern fn JSC__CatchScope__exception(arg0: [*c]bindings.CatchScope) [*c]bindings.Exception;
pub extern fn FFI__ptr__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__u8__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__u16__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__u32__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__ptr__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__i8__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__i16__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__i32__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__f32__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__f64__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__i64__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__u64__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Reader__intptr__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Crypto__getRandomValues__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Crypto__randomUUID__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Crypto__timingSafeEqual__put(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) void;
pub extern fn Zig__GlobalObject__create(arg0: [*c]JSClassRef, arg1: i32, arg2: ?*anyopaque) *bindings.JSGlobalObject;
pub extern fn Zig__GlobalObject__getModuleRegistryMap(arg0: *bindings.JSGlobalObject) ?*anyopaque;
pub extern fn Zig__GlobalObject__resetModuleRegistryMap(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) bool;
pub extern fn Bun__Path__create(arg0: *bindings.JSGlobalObject, arg1: bool) JSC__JSValue;
pub extern fn ArrayBufferSink__assignToStream(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn ArrayBufferSink__createObject(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn ArrayBufferSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn ArrayBufferSink__fromJS(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn ArrayBufferSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn ArrayBufferSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__assignToStream(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn HTTPSResponseSink__createObject(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn HTTPSResponseSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__fromJS(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn HTTPSResponseSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn HTTPSResponseSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn HTTPResponseSink__assignToStream(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn HTTPResponseSink__createObject(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn HTTPResponseSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn HTTPResponseSink__fromJS(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn HTTPResponseSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn HTTPResponseSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn FileSink__assignToStream(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue, arg2: ?*anyopaque, arg3: [*c]*anyopaque) JSC__JSValue;
pub extern fn FileSink__createObject(arg0: *bindings.JSGlobalObject, arg1: ?*anyopaque) JSC__JSValue;
pub extern fn FileSink__detachPtr(JSValue0: JSC__JSValue) void;
pub extern fn FileSink__fromJS(arg0: *bindings.JSGlobalObject, JSValue1: JSC__JSValue) ?*anyopaque;
pub extern fn FileSink__onClose(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue) void;
pub extern fn FileSink__onReady(JSValue0: JSC__JSValue, JSValue1: JSC__JSValue, JSValue2: JSC__JSValue) void;
pub extern fn ZigException__fromException(arg0: [*c]bindings.Exception) ZigException;
