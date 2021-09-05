//-- AUTOGENERATED FILE -- 1630806668
// clang-format: off
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
  #define AUTO_EXTERN_C extern "C"
#else
  #define AUTO_EXTERN_C
#endif
#define ZIG_DECL AUTO_EXTERN_C
#define CPP_DECL AUTO_EXTERN_C
#define CPP_SIZE AUTO_EXTERN_C

#ifndef __cplusplus
typedef void* JSClassRef;
#endif

#ifdef __cplusplus
#include "root.h"
#include <JavaScriptCore/JSClassRef.h>
#endif
#include "headers-handwritten.h"
 typedef struct bJSC__JSModuleRecord { unsigned char bytes[216]; } bJSC__JSModuleRecord;
 typedef char* bJSC__JSModuleRecord_buf;
 typedef struct bJSC__ThrowScope { unsigned char bytes[8]; } bJSC__ThrowScope;
 typedef char* bJSC__ThrowScope_buf;
 typedef struct bJSC__CallFrame { unsigned char bytes[8]; } bJSC__CallFrame;
 typedef char* bJSC__CallFrame_buf;
 typedef struct bJSC__PropertyName { unsigned char bytes[8]; } bJSC__PropertyName;
 typedef char* bJSC__PropertyName_buf;
 typedef struct bJSC__CatchScope { unsigned char bytes[8]; } bJSC__CatchScope;
 typedef char* bJSC__CatchScope_buf;
 typedef struct bWTF__String { unsigned char bytes[8]; } bWTF__String;
 typedef char* bWTF__String_buf;
 typedef struct bWTF__StringView { unsigned char bytes[16]; } bWTF__StringView;
 typedef char* bWTF__StringView_buf;
 typedef struct bJSC__JSModuleLoader { unsigned char bytes[16]; } bJSC__JSModuleLoader;
 typedef char* bJSC__JSModuleLoader_buf;
 typedef struct bJSC__Exception { unsigned char bytes[40]; } bJSC__Exception;
 typedef char* bJSC__Exception_buf;
 typedef struct bJSC__VM { unsigned char bytes[48824]; } bJSC__VM;
 typedef char* bJSC__VM_buf;
 typedef struct bJSC__JSString { unsigned char bytes[16]; } bJSC__JSString;
 typedef char* bJSC__JSString_buf;
 typedef struct bJSC__SourceOrigin { unsigned char bytes[48]; } bJSC__SourceOrigin;
 typedef char* bJSC__SourceOrigin_buf;
 typedef struct bWTF__ExternalStringImpl { unsigned char bytes[32]; } bWTF__ExternalStringImpl;
 typedef char* bWTF__ExternalStringImpl_buf;
 typedef struct bWTF__StringImpl { unsigned char bytes[24]; } bWTF__StringImpl;
 typedef char* bWTF__StringImpl_buf;
 typedef struct bJSC__SourceCode { unsigned char bytes[24]; } bJSC__SourceCode;
 typedef char* bJSC__SourceCode_buf;
 typedef struct bJSC__JSPromise { unsigned char bytes[32]; } bJSC__JSPromise;
 typedef char* bJSC__JSPromise_buf;
 typedef struct bWTF__URL { unsigned char bytes[40]; } bWTF__URL;
 typedef char* bWTF__URL_buf;
 typedef struct bJSC__JSFunction { unsigned char bytes[32]; } bJSC__JSFunction;
 typedef char* bJSC__JSFunction_buf;
 typedef struct bJSC__JSGlobalObject { unsigned char bytes[2400]; } bJSC__JSGlobalObject;
 typedef char* bJSC__JSGlobalObject_buf;
 typedef struct bJSC__JSCell { unsigned char bytes[8]; } bJSC__JSCell;
 typedef char* bJSC__JSCell_buf;
 typedef struct bJSC__JSLock { unsigned char bytes[40]; } bJSC__JSLock;
 typedef char* bJSC__JSLock_buf;
 typedef struct bInspector__ScriptArguments { unsigned char bytes[32]; } bInspector__ScriptArguments;
 typedef char* bInspector__ScriptArguments_buf;
 typedef struct bJSC__JSInternalPromise { unsigned char bytes[32]; } bJSC__JSInternalPromise;
 typedef char* bJSC__JSInternalPromise_buf;
 typedef struct bJSC__JSObject { unsigned char bytes[16]; } bJSC__JSObject;
 typedef char* bJSC__JSObject_buf;
 typedef struct bJSC__Identifier { unsigned char bytes[8]; } bJSC__Identifier;
 typedef char* bJSC__Identifier_buf;

#ifndef __cplusplus
 typedef struct JSC__RegExpPrototype JSC__RegExpPrototype; // JSC::RegExpPrototype
 typedef struct JSC__GeneratorPrototype JSC__GeneratorPrototype; // JSC::GeneratorPrototype
 typedef struct JSC__ArrayIteratorPrototype JSC__ArrayIteratorPrototype; // JSC::ArrayIteratorPrototype
 typedef struct JSC__StringPrototype JSC__StringPrototype; // JSC::StringPrototype
 typedef bWTF__StringView WTF__StringView; // WTF::StringView
 typedef struct JSC__JSPromisePrototype JSC__JSPromisePrototype; // JSC::JSPromisePrototype
 typedef bJSC__CatchScope JSC__CatchScope; // JSC::CatchScope
 typedef bJSC__ThrowScope JSC__ThrowScope; // JSC::ThrowScope
 typedef bJSC__PropertyName JSC__PropertyName; // JSC::PropertyName
 typedef bJSC__JSObject JSC__JSObject; // JSC::JSObject
  typedef ErrorableResolvedSource ErrorableResolvedSource;
  typedef ErrorableZigString ErrorableZigString;
 typedef bWTF__ExternalStringImpl WTF__ExternalStringImpl; // WTF::ExternalStringImpl
 typedef struct JSC__AsyncIteratorPrototype JSC__AsyncIteratorPrototype; // JSC::AsyncIteratorPrototype
 typedef bWTF__StringImpl WTF__StringImpl; // WTF::StringImpl
 typedef bJSC__JSLock JSC__JSLock; // JSC::JSLock
 typedef bJSC__JSModuleLoader JSC__JSModuleLoader; // JSC::JSModuleLoader
 typedef bJSC__VM JSC__VM; // JSC::VM
  typedef JSClassRef JSClassRef;
 typedef struct JSC__AsyncGeneratorPrototype JSC__AsyncGeneratorPrototype; // JSC::AsyncGeneratorPrototype
 typedef struct JSC__AsyncGeneratorFunctionPrototype JSC__AsyncGeneratorFunctionPrototype; // JSC::AsyncGeneratorFunctionPrototype
 typedef bJSC__JSGlobalObject JSC__JSGlobalObject; // JSC::JSGlobalObject
 typedef bJSC__JSFunction JSC__JSFunction; // JSC::JSFunction
 typedef struct JSC__ArrayPrototype JSC__ArrayPrototype; // JSC::ArrayPrototype
 typedef struct JSC__AsyncFunctionPrototype JSC__AsyncFunctionPrototype; // JSC::AsyncFunctionPrototype
 typedef bJSC__Identifier JSC__Identifier; // JSC::Identifier
 typedef bJSC__JSPromise JSC__JSPromise; // JSC::JSPromise
  typedef ZigException ZigException;
 typedef struct JSC__SetIteratorPrototype JSC__SetIteratorPrototype; // JSC::SetIteratorPrototype
 typedef bJSC__SourceCode JSC__SourceCode; // JSC::SourceCode
 typedef bJSC__JSCell JSC__JSCell; // JSC::JSCell
 typedef struct JSC__BigIntPrototype JSC__BigIntPrototype; // JSC::BigIntPrototype
 typedef struct JSC__GeneratorFunctionPrototype JSC__GeneratorFunctionPrototype; // JSC::GeneratorFunctionPrototype
 typedef bJSC__SourceOrigin JSC__SourceOrigin; // JSC::SourceOrigin
  typedef ZigString ZigString;
 typedef bJSC__JSModuleRecord JSC__JSModuleRecord; // JSC::JSModuleRecord
 typedef bWTF__String WTF__String; // WTF::String
 typedef bWTF__URL WTF__URL; // WTF::URL
  typedef int64_t JSC__JSValue;
 typedef struct JSC__IteratorPrototype JSC__IteratorPrototype; // JSC::IteratorPrototype
 typedef bJSC__JSInternalPromise JSC__JSInternalPromise; // JSC::JSInternalPromise
 typedef struct JSC__FunctionPrototype JSC__FunctionPrototype; // JSC::FunctionPrototype
 typedef bInspector__ScriptArguments Inspector__ScriptArguments; // Inspector::ScriptArguments
 typedef bJSC__Exception JSC__Exception; // JSC::Exception
 typedef bJSC__JSString JSC__JSString; // JSC::JSString
 typedef struct JSC__ObjectPrototype JSC__ObjectPrototype; // JSC::ObjectPrototype
 typedef bJSC__CallFrame JSC__CallFrame; // JSC::CallFrame
 typedef struct JSC__MapIteratorPrototype JSC__MapIteratorPrototype; // JSC::MapIteratorPrototype

#endif

#ifdef __cplusplus
  namespace JSC {
    class JSCell;
    class Exception;
    class StringPrototype;
    class JSPromisePrototype;
    class GeneratorFunctionPrototype;
    class ArrayPrototype;
    class JSString;
    class JSObject;
    class AsyncIteratorPrototype;
    class AsyncGeneratorFunctionPrototype;
    class Identifier;
    class JSPromise;
    class RegExpPrototype;
    class AsyncFunctionPrototype;
    class CatchScope;
    class VM;
    class BigIntPrototype;
    class SetIteratorPrototype;
    class ThrowScope;
    class SourceOrigin;
    class AsyncGeneratorPrototype;
    class PropertyName;
    class MapIteratorPrototype;
    class JSModuleRecord;
    class JSInternalPromise;
    class ArrayIteratorPrototype;
    class JSFunction;
    class JSModuleLoader;
    class GeneratorPrototype;
    class JSGlobalObject;
    class SourceCode;
    class JSLock;
    class FunctionPrototype;
    class IteratorPrototype;
    class CallFrame;
    class ObjectPrototype;
  }
  namespace WTF {
    class URL;
    class StringImpl;
    class String;
    class StringView;
    class ExternalStringImpl;
  }
  namespace Inspector {
    class ScriptArguments;
  }

  typedef ErrorableResolvedSource ErrorableResolvedSource;
  typedef ErrorableZigString ErrorableZigString;
  typedef JSClassRef JSClassRef;
  typedef ZigException ZigException;
  typedef ZigString ZigString;
  typedef int64_t JSC__JSValue;
  using JSC__JSCell = JSC::JSCell;
  using JSC__Exception = JSC::Exception;
  using JSC__StringPrototype = JSC::StringPrototype;
  using JSC__JSPromisePrototype = JSC::JSPromisePrototype;
  using JSC__GeneratorFunctionPrototype = JSC::GeneratorFunctionPrototype;
  using JSC__ArrayPrototype = JSC::ArrayPrototype;
  using JSC__JSString = JSC::JSString;
  using JSC__JSObject = JSC::JSObject;
  using JSC__AsyncIteratorPrototype = JSC::AsyncIteratorPrototype;
  using JSC__AsyncGeneratorFunctionPrototype = JSC::AsyncGeneratorFunctionPrototype;
  using JSC__Identifier = JSC::Identifier;
  using JSC__JSPromise = JSC::JSPromise;
  using JSC__RegExpPrototype = JSC::RegExpPrototype;
  using JSC__AsyncFunctionPrototype = JSC::AsyncFunctionPrototype;
  using JSC__CatchScope = JSC::CatchScope;
  using JSC__VM = JSC::VM;
  using JSC__BigIntPrototype = JSC::BigIntPrototype;
  using JSC__SetIteratorPrototype = JSC::SetIteratorPrototype;
  using JSC__ThrowScope = JSC::ThrowScope;
  using JSC__SourceOrigin = JSC::SourceOrigin;
  using JSC__AsyncGeneratorPrototype = JSC::AsyncGeneratorPrototype;
  using JSC__PropertyName = JSC::PropertyName;
  using JSC__MapIteratorPrototype = JSC::MapIteratorPrototype;
  using JSC__JSModuleRecord = JSC::JSModuleRecord;
  using JSC__JSInternalPromise = JSC::JSInternalPromise;
  using JSC__ArrayIteratorPrototype = JSC::ArrayIteratorPrototype;
  using JSC__JSFunction = JSC::JSFunction;
  using JSC__JSModuleLoader = JSC::JSModuleLoader;
  using JSC__GeneratorPrototype = JSC::GeneratorPrototype;
  using JSC__JSGlobalObject = JSC::JSGlobalObject;
  using JSC__SourceCode = JSC::SourceCode;
  using JSC__JSLock = JSC::JSLock;
  using JSC__FunctionPrototype = JSC::FunctionPrototype;
  using JSC__IteratorPrototype = JSC::IteratorPrototype;
  using JSC__CallFrame = JSC::CallFrame;
  using JSC__ObjectPrototype = JSC::ObjectPrototype;
  using WTF__URL = WTF::URL;
  using WTF__StringImpl = WTF::StringImpl;
  using WTF__String = WTF::String;
  using WTF__StringView = WTF::StringView;
  using WTF__ExternalStringImpl = WTF::ExternalStringImpl;
  using Inspector__ScriptArguments = Inspector::ScriptArguments;

#endif


#pragma mark - JSC::JSObject

CPP_DECL JSC__JSValue JSC__JSObject__create(JSC__JSGlobalObject* arg0, size_t arg1, void* arg2, void (* ArgFn3)(void* arg0, JSC__JSObject* arg1, JSC__JSGlobalObject* arg2));
CPP_DECL size_t JSC__JSObject__getArrayLength(JSC__JSObject* arg0);
CPP_DECL JSC__JSValue JSC__JSObject__getDirect(JSC__JSObject* arg0, JSC__JSGlobalObject* arg1, ZigString arg2);
CPP_DECL JSC__JSValue JSC__JSObject__getIndex(JSC__JSObject* arg0, JSC__JSGlobalObject* arg1, uint32_t arg2);
CPP_DECL void JSC__JSObject__putDirect(JSC__JSObject* arg0, JSC__JSGlobalObject* arg1, ZigString arg2, JSC__JSValue JSValue3);
CPP_DECL void JSC__JSObject__putRecord(JSC__JSObject* arg0, JSC__JSGlobalObject* arg1, ZigString* arg2, ZigString* arg3, size_t arg4);
CPP_DECL JSC__JSValue ZigString__toErrorInstance(const ZigString* arg0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSValue ZigString__toValue(ZigString arg0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSValue ZigString__toValueGC(ZigString arg0, JSC__JSGlobalObject* arg1);

#pragma mark - JSC::JSCell

CPP_DECL JSC__JSObject* JSC__JSCell__getObject(JSC__JSCell* arg0);
CPP_DECL bWTF__String JSC__JSCell__getString(JSC__JSCell* arg0, JSC__JSGlobalObject* arg1);
CPP_DECL unsigned char JSC__JSCell__getType(JSC__JSCell* arg0);

#pragma mark - JSC::JSString

CPP_DECL JSC__JSString* JSC__JSString__createFromOwnedString(JSC__VM* arg0, const WTF__String* arg1);
CPP_DECL JSC__JSString* JSC__JSString__createFromString(JSC__VM* arg0, const WTF__String* arg1);
CPP_DECL bool JSC__JSString__eql(const JSC__JSString* arg0, JSC__JSGlobalObject* arg1, JSC__JSString* arg2);
CPP_DECL bool JSC__JSString__is8Bit(const JSC__JSString* arg0);
CPP_DECL size_t JSC__JSString__length(const JSC__JSString* arg0);
CPP_DECL JSC__JSObject* JSC__JSString__toObject(JSC__JSString* arg0, JSC__JSGlobalObject* arg1);
CPP_DECL bWTF__String JSC__JSString__value(JSC__JSString* arg0, JSC__JSGlobalObject* arg1);

#pragma mark - Inspector::ScriptArguments

CPP_DECL JSC__JSValue Inspector__ScriptArguments__argumentAt(Inspector__ScriptArguments* arg0, size_t arg1);
CPP_DECL size_t Inspector__ScriptArguments__argumentCount(Inspector__ScriptArguments* arg0);
CPP_DECL bWTF__String Inspector__ScriptArguments__getFirstArgumentAsString(Inspector__ScriptArguments* arg0);
CPP_DECL bool Inspector__ScriptArguments__isEqual(Inspector__ScriptArguments* arg0, Inspector__ScriptArguments* arg1);
CPP_DECL void Inspector__ScriptArguments__release(Inspector__ScriptArguments* arg0);

#pragma mark - JSC::JSModuleLoader

CPP_DECL bool JSC__JSModuleLoader__checkSyntax(JSC__JSGlobalObject* arg0, const JSC__SourceCode* arg1, bool arg2);
CPP_DECL JSC__JSValue JSC__JSModuleLoader__evaluate(JSC__JSGlobalObject* arg0, const unsigned char* arg1, size_t arg2, const unsigned char* arg3, size_t arg4, JSC__JSValue JSValue5, JSC__JSValue* arg6);
CPP_DECL JSC__JSInternalPromise* JSC__JSModuleLoader__importModule(JSC__JSGlobalObject* arg0, const JSC__Identifier* arg1);
CPP_DECL JSC__JSValue JSC__JSModuleLoader__linkAndEvaluateModule(JSC__JSGlobalObject* arg0, const JSC__Identifier* arg1);
CPP_DECL JSC__JSInternalPromise* JSC__JSModuleLoader__loadAndEvaluateModule(JSC__JSGlobalObject* arg0, ZigString arg1);
CPP_DECL JSC__JSInternalPromise* JSC__JSModuleLoader__loadAndEvaluateModuleEntryPoint(JSC__JSGlobalObject* arg0, const JSC__SourceCode* arg1);

#pragma mark - JSC::JSModuleRecord

CPP_DECL bJSC__SourceCode JSC__JSModuleRecord__sourceCode(JSC__JSModuleRecord* arg0);

#pragma mark - JSC::JSPromise

CPP_DECL bool JSC__JSPromise__isHandled(const JSC__JSPromise* arg0, JSC__VM* arg1);
CPP_DECL void JSC__JSPromise__reject(JSC__JSPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL void JSC__JSPromise__rejectAsHandled(JSC__JSPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL void JSC__JSPromise__rejectAsHandledException(JSC__JSPromise* arg0, JSC__JSGlobalObject* arg1, JSC__Exception* arg2);
CPP_DECL JSC__JSPromise* JSC__JSPromise__rejectedPromise(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1);
CPP_DECL void JSC__JSPromise__rejectWithCaughtException(JSC__JSPromise* arg0, JSC__JSGlobalObject* arg1, bJSC__ThrowScope arg2);
CPP_DECL void JSC__JSPromise__resolve(JSC__JSPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL JSC__JSPromise* JSC__JSPromise__resolvedPromise(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1);
CPP_DECL JSC__JSValue JSC__JSPromise__result(const JSC__JSPromise* arg0, JSC__VM* arg1);
CPP_DECL uint32_t JSC__JSPromise__status(const JSC__JSPromise* arg0, JSC__VM* arg1);

#pragma mark - JSC::JSInternalPromise

CPP_DECL JSC__JSInternalPromise* JSC__JSInternalPromise__create(JSC__JSGlobalObject* arg0);
CPP_DECL bool JSC__JSInternalPromise__isHandled(const JSC__JSInternalPromise* arg0, JSC__VM* arg1);
CPP_DECL void JSC__JSInternalPromise__reject(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL void JSC__JSInternalPromise__rejectAsHandled(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL void JSC__JSInternalPromise__rejectAsHandledException(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, JSC__Exception* arg2);
CPP_DECL JSC__JSInternalPromise* JSC__JSInternalPromise__rejectedPromise(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1);
CPP_DECL void JSC__JSInternalPromise__rejectWithCaughtException(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, bJSC__ThrowScope arg2);
CPP_DECL void JSC__JSInternalPromise__resolve(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2);
CPP_DECL JSC__JSInternalPromise* JSC__JSInternalPromise__resolvedPromise(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1);
CPP_DECL JSC__JSValue JSC__JSInternalPromise__result(const JSC__JSInternalPromise* arg0, JSC__VM* arg1);
CPP_DECL uint32_t JSC__JSInternalPromise__status(const JSC__JSInternalPromise* arg0, JSC__VM* arg1);
CPP_DECL JSC__JSInternalPromise* JSC__JSInternalPromise__then(JSC__JSInternalPromise* arg0, JSC__JSGlobalObject* arg1, JSC__JSFunction* arg2, JSC__JSFunction* arg3);

#pragma mark - JSC::SourceOrigin

CPP_DECL bJSC__SourceOrigin JSC__SourceOrigin__fromURL(const WTF__URL* arg0);

#pragma mark - JSC::SourceCode

CPP_DECL void JSC__SourceCode__fromString(JSC__SourceCode* arg0, const WTF__String* arg1, const JSC__SourceOrigin* arg2, WTF__String* arg3, unsigned char SourceType4);

#pragma mark - JSC::JSFunction

CPP_DECL bWTF__String JSC__JSFunction__calculatedDisplayName(JSC__JSFunction* arg0, JSC__VM* arg1);
CPP_DECL JSC__JSValue JSC__JSFunction__callWithArguments(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__JSValue* arg2, size_t arg3, JSC__Exception** arg4, const unsigned char* arg5);
CPP_DECL JSC__JSValue JSC__JSFunction__callWithArgumentsAndThis(JSC__JSValue JSValue0, JSC__JSValue JSValue1, JSC__JSGlobalObject* arg2, JSC__JSValue* arg3, size_t arg4, JSC__Exception** arg5, const unsigned char* arg6);
CPP_DECL JSC__JSValue JSC__JSFunction__callWithoutAnyArgumentsOrThis(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__Exception** arg2, const unsigned char* arg3);
CPP_DECL JSC__JSValue JSC__JSFunction__callWithThis(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2, JSC__Exception** arg3, const unsigned char* arg4);
CPP_DECL JSC__JSValue JSC__JSFunction__constructWithArguments(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__JSValue* arg2, size_t arg3, JSC__Exception** arg4, const unsigned char* arg5);
CPP_DECL JSC__JSValue JSC__JSFunction__constructWithArgumentsAndNewTarget(JSC__JSValue JSValue0, JSC__JSValue JSValue1, JSC__JSGlobalObject* arg2, JSC__JSValue* arg3, size_t arg4, JSC__Exception** arg5, const unsigned char* arg6);
CPP_DECL JSC__JSValue JSC__JSFunction__constructWithNewTarget(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2, JSC__Exception** arg3, const unsigned char* arg4);
CPP_DECL JSC__JSValue JSC__JSFunction__constructWithoutAnyArgumentsOrNewTarget(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, JSC__Exception** arg2, const unsigned char* arg3);
CPP_DECL JSC__JSFunction* JSC__JSFunction__createFromNative(JSC__JSGlobalObject* arg0, uint16_t arg1, const WTF__String* arg2, void* arg3, JSC__JSValue (* ArgFn4)(void* arg0, JSC__JSGlobalObject* arg1, JSC__CallFrame* arg2));
CPP_DECL bWTF__String JSC__JSFunction__displayName(JSC__JSFunction* arg0, JSC__VM* arg1);
CPP_DECL bWTF__String JSC__JSFunction__getName(JSC__JSFunction* arg0, JSC__VM* arg1);

#pragma mark - JSC::JSGlobalObject

CPP_DECL JSC__ArrayIteratorPrototype* JSC__JSGlobalObject__arrayIteratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__ArrayPrototype* JSC__JSGlobalObject__arrayPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__AsyncFunctionPrototype* JSC__JSGlobalObject__asyncFunctionPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__AsyncGeneratorFunctionPrototype* JSC__JSGlobalObject__asyncGeneratorFunctionPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__AsyncGeneratorPrototype* JSC__JSGlobalObject__asyncGeneratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__AsyncIteratorPrototype* JSC__JSGlobalObject__asyncIteratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__BigIntPrototype* JSC__JSGlobalObject__bigIntPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__booleanPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSValue JSC__JSGlobalObject__createAggregateError(JSC__JSGlobalObject* arg0, void** arg1, uint16_t arg2, ZigString arg3);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__datePrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__errorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__FunctionPrototype* JSC__JSGlobalObject__functionPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__GeneratorFunctionPrototype* JSC__JSGlobalObject__generatorFunctionPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__GeneratorPrototype* JSC__JSGlobalObject__generatorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__IteratorPrototype* JSC__JSGlobalObject__iteratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__jsSetPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__MapIteratorPrototype* JSC__JSGlobalObject__mapIteratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__mapPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__numberPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__ObjectPrototype* JSC__JSGlobalObject__objectPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSPromisePrototype* JSC__JSGlobalObject__promisePrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__RegExpPrototype* JSC__JSGlobalObject__regExpPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__SetIteratorPrototype* JSC__JSGlobalObject__setIteratorPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__StringPrototype* JSC__JSGlobalObject__stringPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__JSObject* JSC__JSGlobalObject__symbolPrototype(JSC__JSGlobalObject* arg0);
CPP_DECL JSC__VM* JSC__JSGlobalObject__vm(JSC__JSGlobalObject* arg0);

#pragma mark - WTF::URL

CPP_DECL bWTF__StringView WTF__URL__encodedPassword(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__encodedUser(WTF__URL* arg0);
CPP_DECL bWTF__String WTF__URL__fileSystemPath(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__fragmentIdentifier(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__fragmentIdentifierWithLeadingNumberSign(WTF__URL* arg0);
CPP_DECL void WTF__URL__fromFileSystemPath(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL bWTF__URL WTF__URL__fromString(bWTF__String arg0, bWTF__String arg1);
CPP_DECL bWTF__StringView WTF__URL__host(WTF__URL* arg0);
CPP_DECL bWTF__String WTF__URL__hostAndPort(WTF__URL* arg0);
CPP_DECL bool WTF__URL__isEmpty(const WTF__URL* arg0);
CPP_DECL bool WTF__URL__isValid(const WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__lastPathComponent(WTF__URL* arg0);
CPP_DECL bWTF__String WTF__URL__password(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__path(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__protocol(WTF__URL* arg0);
CPP_DECL bWTF__String WTF__URL__protocolHostAndPort(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__query(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__queryWithLeadingQuestionMark(WTF__URL* arg0);
CPP_DECL void WTF__URL__setHost(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setHostAndPort(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setPassword(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setPath(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setProtocol(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setQuery(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL void WTF__URL__setUser(WTF__URL* arg0, bWTF__StringView arg1);
CPP_DECL bWTF__String WTF__URL__stringWithoutFragmentIdentifier(WTF__URL* arg0);
CPP_DECL bWTF__StringView WTF__URL__stringWithoutQueryOrFragmentIdentifier(WTF__URL* arg0);
CPP_DECL bWTF__URL WTF__URL__truncatedForUseAsBase(WTF__URL* arg0);
CPP_DECL bWTF__String WTF__URL__user(WTF__URL* arg0);

#pragma mark - WTF::String

CPP_DECL const uint16_t* WTF__String__characters16(WTF__String* arg0);
CPP_DECL const unsigned char* WTF__String__characters8(WTF__String* arg0);
CPP_DECL bWTF__String WTF__String__createFromExternalString(bWTF__ExternalStringImpl arg0);
CPP_DECL void WTF__String__createWithoutCopyingFromPtr(WTF__String* arg0, const unsigned char* arg1, size_t arg2);
CPP_DECL bool WTF__String__eqlSlice(WTF__String* arg0, const unsigned char* arg1, size_t arg2);
CPP_DECL bool WTF__String__eqlString(WTF__String* arg0, const WTF__String* arg1);
CPP_DECL const WTF__StringImpl* WTF__String__impl(WTF__String* arg0);
CPP_DECL bool WTF__String__is16Bit(WTF__String* arg0);
CPP_DECL bool WTF__String__is8Bit(WTF__String* arg0);
CPP_DECL bool WTF__String__isEmpty(WTF__String* arg0);
CPP_DECL bool WTF__String__isExternal(WTF__String* arg0);
CPP_DECL bool WTF__String__isStatic(WTF__String* arg0);
CPP_DECL size_t WTF__String__length(WTF__String* arg0);

#pragma mark - JSC::JSValue

CPP_DECL JSC__JSCell* JSC__JSValue__asCell(JSC__JSValue JSValue0);
CPP_DECL double JSC__JSValue__asNumber(JSC__JSValue JSValue0);
CPP_DECL bJSC__JSObject JSC__JSValue__asObject(JSC__JSValue JSValue0);
CPP_DECL JSC__JSString* JSC__JSValue__asString(JSC__JSValue JSValue0);
CPP_DECL JSC__JSValue JSC__JSValue__createEmptyObject(JSC__JSGlobalObject* arg0, size_t arg1);
CPP_DECL JSC__JSValue JSC__JSValue__createStringArray(JSC__JSGlobalObject* arg0, ZigString* arg1, size_t arg2);
CPP_DECL bool JSC__JSValue__eqlCell(JSC__JSValue JSValue0, JSC__JSCell* arg1);
CPP_DECL bool JSC__JSValue__eqlValue(JSC__JSValue JSValue0, JSC__JSValue JSValue1);
CPP_DECL void JSC__JSValue__forEach(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, void (* ArgFn2)(JSC__VM* arg0, JSC__JSGlobalObject* arg1, JSC__JSValue JSValue2));
CPP_DECL void JSC__JSValue__getClassName(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, ZigString* arg2);
CPP_DECL JSC__JSValue JSC__JSValue__getErrorsProperty(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL void JSC__JSValue__getNameProperty(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, ZigString* arg2);
CPP_DECL JSC__JSValue JSC__JSValue__getPrototype(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bool JSC__JSValue__isAggregateError(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bool JSC__JSValue__isAnyInt(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isBigInt(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isBigInt32(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isBoolean(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isCallable(JSC__JSValue JSValue0, JSC__VM* arg1);
CPP_DECL bool JSC__JSValue__isCell(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isClass(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bool JSC__JSValue__isCustomGetterSetter(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isError(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isException(JSC__JSValue JSValue0, JSC__VM* arg1);
CPP_DECL bool JSC__JSValue__isGetterSetter(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isHeapBigInt(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isInt32(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isInt32AsAnyInt(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isIterable(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bool JSC__JSValue__isNull(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isNumber(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isObject(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isPrimitive(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isString(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isSymbol(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isUInt32AsAnyInt(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isUndefined(JSC__JSValue JSValue0);
CPP_DECL bool JSC__JSValue__isUndefinedOrNull(JSC__JSValue JSValue0);
CPP_DECL JSC__JSValue JSC__JSValue__jsBoolean(bool arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsDoubleNumber(double arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNull();
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromChar(unsigned char arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromDouble(double arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromInt32(int32_t arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromInt64(int64_t arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromU16(uint16_t arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsNumberFromUint64(uint64_t arg0);
CPP_DECL JSC__JSValue JSC__JSValue__jsTDZValue();
CPP_DECL JSC__JSValue JSC__JSValue__jsUndefined();
CPP_DECL void JSC__JSValue__putRecord(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, ZigString* arg2, ZigString* arg3, size_t arg4);
CPP_DECL bool JSC__JSValue__toBoolean(JSC__JSValue JSValue0);
CPP_DECL int32_t JSC__JSValue__toInt32(JSC__JSValue JSValue0);
CPP_DECL JSC__JSObject* JSC__JSValue__toObject(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bJSC__Identifier JSC__JSValue__toPropertyKey(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSValue JSC__JSValue__toPropertyKeyValue(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSString* JSC__JSValue__toString(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSString* JSC__JSValue__toString(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL JSC__JSString* JSC__JSValue__toStringOrNull(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL bWTF__String JSC__JSValue__toWTFString(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1);
CPP_DECL void JSC__JSValue__toZigException(JSC__JSValue JSValue0, JSC__JSGlobalObject* arg1, ZigException* arg2);
CPP_DECL void JSC__JSValue__toZigString(JSC__JSValue JSValue0, ZigString* arg1, JSC__JSGlobalObject* arg2);

#pragma mark - JSC::PropertyName

CPP_DECL bool JSC__PropertyName__eqlToIdentifier(JSC__PropertyName* arg0, const JSC__Identifier* arg1);
CPP_DECL bool JSC__PropertyName__eqlToPropertyName(JSC__PropertyName* arg0, const JSC__PropertyName* arg1);
CPP_DECL const WTF__StringImpl* JSC__PropertyName__publicName(JSC__PropertyName* arg0);
CPP_DECL const WTF__StringImpl* JSC__PropertyName__uid(JSC__PropertyName* arg0);

#pragma mark - JSC::Exception

CPP_DECL JSC__Exception* JSC__Exception__create(JSC__JSGlobalObject* arg0, JSC__JSObject* arg1, unsigned char StackCaptureAction2);
CPP_DECL void JSC__Exception__getStackTrace(JSC__Exception* arg0, ZigStackTrace* arg1);
CPP_DECL JSC__JSValue JSC__Exception__value(JSC__Exception* arg0);

#pragma mark - JSC::VM

CPP_DECL JSC__JSLock* JSC__VM__apiLock(JSC__VM* arg0);
CPP_DECL JSC__VM* JSC__VM__create(unsigned char HeapType0);
CPP_DECL void JSC__VM__deinit(JSC__VM* arg0, JSC__JSGlobalObject* arg1);
CPP_DECL void JSC__VM__deleteAllCode(JSC__VM* arg0, JSC__JSGlobalObject* arg1);
CPP_DECL void JSC__VM__drainMicrotasks(JSC__VM* arg0);
CPP_DECL bool JSC__VM__executionForbidden(JSC__VM* arg0);
CPP_DECL bool JSC__VM__isEntered(JSC__VM* arg0);
CPP_DECL void JSC__VM__setExecutionForbidden(JSC__VM* arg0, bool arg1);
CPP_DECL void JSC__VM__shrinkFootprint(JSC__VM* arg0);
CPP_DECL bool JSC__VM__throwError(JSC__VM* arg0, JSC__JSGlobalObject* arg1, JSC__ThrowScope* arg2, const unsigned char* arg3, size_t arg4);
CPP_DECL void JSC__VM__whenIdle(JSC__VM* arg0, void (* ArgFn1)());

#pragma mark - JSC::ThrowScope

CPP_DECL void JSC__ThrowScope__clearException(JSC__ThrowScope* arg0);
CPP_DECL bJSC__ThrowScope JSC__ThrowScope__declare(JSC__VM* arg0, unsigned char* arg1, unsigned char* arg2, size_t arg3);
CPP_DECL JSC__Exception* JSC__ThrowScope__exception(JSC__ThrowScope* arg0);
CPP_DECL void JSC__ThrowScope__release(JSC__ThrowScope* arg0);

#pragma mark - JSC::CatchScope

CPP_DECL void JSC__CatchScope__clearException(JSC__CatchScope* arg0);
CPP_DECL bJSC__CatchScope JSC__CatchScope__declare(JSC__VM* arg0, unsigned char* arg1, unsigned char* arg2, size_t arg3);
CPP_DECL JSC__Exception* JSC__CatchScope__exception(JSC__CatchScope* arg0);

#pragma mark - JSC::CallFrame

CPP_DECL JSC__JSValue JSC__CallFrame__argument(const JSC__CallFrame* arg0, uint16_t arg1);
CPP_DECL size_t JSC__CallFrame__argumentsCount(const JSC__CallFrame* arg0);
CPP_DECL JSC__JSObject* JSC__CallFrame__jsCallee(const JSC__CallFrame* arg0);
CPP_DECL JSC__JSValue JSC__CallFrame__newTarget(const JSC__CallFrame* arg0);
CPP_DECL JSC__JSValue JSC__CallFrame__setNewTarget(JSC__CallFrame* arg0, JSC__JSValue JSValue1);
CPP_DECL JSC__JSValue JSC__CallFrame__setThisValue(JSC__CallFrame* arg0, JSC__JSValue JSValue1);
CPP_DECL JSC__JSValue JSC__CallFrame__thisValue(const JSC__CallFrame* arg0);
CPP_DECL JSC__JSValue JSC__CallFrame__uncheckedArgument(const JSC__CallFrame* arg0, uint16_t arg1);

#pragma mark - JSC::Identifier

CPP_DECL void JSC__Identifier__deinit(const JSC__Identifier* arg0);
CPP_DECL bool JSC__Identifier__eqlIdent(const JSC__Identifier* arg0, const JSC__Identifier* arg1);
CPP_DECL bool JSC__Identifier__eqlStringImpl(const JSC__Identifier* arg0, const WTF__StringImpl* arg1);
CPP_DECL bool JSC__Identifier__eqlUTF8(const JSC__Identifier* arg0, const unsigned char* arg1, size_t arg2);
CPP_DECL bJSC__Identifier JSC__Identifier__fromSlice(JSC__VM* arg0, const unsigned char* arg1, size_t arg2);
CPP_DECL bJSC__Identifier JSC__Identifier__fromString(JSC__VM* arg0, const WTF__String* arg1);
CPP_DECL bool JSC__Identifier__isEmpty(const JSC__Identifier* arg0);
CPP_DECL bool JSC__Identifier__isNull(const JSC__Identifier* arg0);
CPP_DECL bool JSC__Identifier__isPrivateName(const JSC__Identifier* arg0);
CPP_DECL bool JSC__Identifier__isSymbol(const JSC__Identifier* arg0);
CPP_DECL size_t JSC__Identifier__length(const JSC__Identifier* arg0);
CPP_DECL bool JSC__Identifier__neqlIdent(const JSC__Identifier* arg0, const JSC__Identifier* arg1);
CPP_DECL bool JSC__Identifier__neqlStringImpl(const JSC__Identifier* arg0, const WTF__StringImpl* arg1);
CPP_DECL bWTF__String JSC__Identifier__toString(const JSC__Identifier* arg0);

#pragma mark - WTF::StringImpl

CPP_DECL const uint16_t* WTF__StringImpl__characters16(const WTF__StringImpl* arg0);
CPP_DECL const unsigned char* WTF__StringImpl__characters8(const WTF__StringImpl* arg0);
CPP_DECL bool WTF__StringImpl__is16Bit(const WTF__StringImpl* arg0);
CPP_DECL bool WTF__StringImpl__is8Bit(const WTF__StringImpl* arg0);
CPP_DECL bool WTF__StringImpl__isEmpty(const WTF__StringImpl* arg0);
CPP_DECL bool WTF__StringImpl__isExternal(const WTF__StringImpl* arg0);
CPP_DECL bool WTF__StringImpl__isStatic(const WTF__StringImpl* arg0);
CPP_DECL size_t WTF__StringImpl__length(const WTF__StringImpl* arg0);

#pragma mark - WTF::ExternalStringImpl

CPP_DECL const uint16_t* WTF__ExternalStringImpl__characters16(const WTF__ExternalStringImpl* arg0);
CPP_DECL const unsigned char* WTF__ExternalStringImpl__characters8(const WTF__ExternalStringImpl* arg0);
CPP_DECL bWTF__ExternalStringImpl WTF__ExternalStringImpl__create(const unsigned char* arg0, size_t arg1, void (* ArgFn2)(void* arg0, unsigned char* arg1, size_t arg2));
CPP_DECL bool WTF__ExternalStringImpl__is16Bit(const WTF__ExternalStringImpl* arg0);
CPP_DECL bool WTF__ExternalStringImpl__is8Bit(const WTF__ExternalStringImpl* arg0);
CPP_DECL bool WTF__ExternalStringImpl__isEmpty(const WTF__ExternalStringImpl* arg0);
CPP_DECL size_t WTF__ExternalStringImpl__length(const WTF__ExternalStringImpl* arg0);

#pragma mark - WTF::StringView

CPP_DECL const uint16_t* WTF__StringView__characters16(const WTF__StringView* arg0);
CPP_DECL const unsigned char* WTF__StringView__characters8(const WTF__StringView* arg0);
CPP_DECL void WTF__StringView__from8Bit(WTF__StringView* arg0, const unsigned char* arg1, size_t arg2);
CPP_DECL bool WTF__StringView__is16Bit(const WTF__StringView* arg0);
CPP_DECL bool WTF__StringView__is8Bit(const WTF__StringView* arg0);
CPP_DECL bool WTF__StringView__isEmpty(const WTF__StringView* arg0);
CPP_DECL size_t WTF__StringView__length(const WTF__StringView* arg0);

#pragma mark - Zig::GlobalObject

CPP_DECL JSC__JSGlobalObject* Zig__GlobalObject__create(JSClassRef* arg0, int32_t arg1, void* arg2);
CPP_DECL void* Zig__GlobalObject__getModuleRegistryMap(JSC__JSGlobalObject* arg0);
CPP_DECL bool Zig__GlobalObject__resetModuleRegistryMap(JSC__JSGlobalObject* arg0, void* arg1);

#ifdef __cplusplus

ZIG_DECL JSC__JSValue Zig__GlobalObject__createImportMetaProperties(JSC__JSGlobalObject* arg0, JSC__JSModuleLoader* arg1, JSC__JSValue JSValue2, JSC__JSModuleRecord* arg3, JSC__JSValue JSValue4);
ZIG_DECL void Zig__GlobalObject__fetch(ErrorableResolvedSource* arg0, JSC__JSGlobalObject* arg1, ZigString arg2, ZigString arg3);
ZIG_DECL ErrorableZigString Zig__GlobalObject__import(JSC__JSGlobalObject* arg0, ZigString arg1, ZigString arg2);
ZIG_DECL void Zig__GlobalObject__onCrash();
ZIG_DECL JSC__JSValue Zig__GlobalObject__promiseRejectionTracker(JSC__JSGlobalObject* arg0, JSC__JSPromise* arg1, uint32_t JSPromiseRejectionOperation2);
ZIG_DECL JSC__JSValue Zig__GlobalObject__reportUncaughtException(JSC__JSGlobalObject* arg0, JSC__Exception* arg1);
ZIG_DECL void Zig__GlobalObject__resolve(ErrorableZigString* arg0, JSC__JSGlobalObject* arg1, ZigString arg2, ZigString arg3);

#endif

#ifdef __cplusplus

ZIG_DECL bool Zig__ErrorType__isPrivateData(void* arg0);

#endif
CPP_DECL ZigException ZigException__fromException(JSC__Exception* arg0);

#pragma mark - Zig::ConsoleClient


#ifdef __cplusplus

ZIG_DECL void Zig__ConsoleClient__count(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__countReset(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__messageWithTypeAndLevel(void* arg0, uint32_t arg1, uint32_t arg2, JSC__JSGlobalObject* arg3, JSC__JSValue* arg4, size_t arg5);
ZIG_DECL void Zig__ConsoleClient__profile(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__profileEnd(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__record(void* arg0, JSC__JSGlobalObject* arg1, Inspector__ScriptArguments* arg2);
ZIG_DECL void Zig__ConsoleClient__recordEnd(void* arg0, JSC__JSGlobalObject* arg1, Inspector__ScriptArguments* arg2);
ZIG_DECL void Zig__ConsoleClient__screenshot(void* arg0, JSC__JSGlobalObject* arg1, Inspector__ScriptArguments* arg2);
ZIG_DECL void Zig__ConsoleClient__takeHeapSnapshot(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__time(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__timeEnd(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3);
ZIG_DECL void Zig__ConsoleClient__timeLog(void* arg0, JSC__JSGlobalObject* arg1, const unsigned char* arg2, size_t arg3, Inspector__ScriptArguments* arg4);
ZIG_DECL void Zig__ConsoleClient__timeStamp(void* arg0, JSC__JSGlobalObject* arg1, Inspector__ScriptArguments* arg2);

#endif
