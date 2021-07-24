
#include "ZigGlobalObject.h"
#include "helpers.h"

#include <JavaScriptCore/CallFrameInlines.h>
#include <JavaScriptCore/CatchScope.h>
#include <JavaScriptCore/Completion.h>
#include <JavaScriptCore/Error.h>
#include <JavaScriptCore/Exception.h>
#include <JavaScriptCore/JSContextInternal.h>
#include <JavaScriptCore/JSInternalPromise.h>
#include <JavaScriptCore/JSModuleLoader.h>
#include <JavaScriptCore/JSNativeStdFunction.h>
#include <JavaScriptCore/JSPromise.h>
#include <JavaScriptCore/JSSourceCode.h>
#include <JavaScriptCore/JSValueInternal.h>
#include <JavaScriptCore/JSVirtualMachineInternal.h>
#include <JavaScriptCore/ObjectConstructor.h>
#include <JavaScriptCore/SourceOrigin.h>
#include <JavaScriptCore/Identifier.h>
#include <wtf/URL.h>
#include <JavaScriptCore/ClassInfo.h>
#include <JavaScriptCore/JSString.h>
#include <JavaScriptCore/VM.h>
#include <JavaScriptCore/WasmFaultSignalHandler.h>
#include <JavaScriptCore/JSCast.h>
#include <JavaScriptCore/InitializeThreading.h>

#include <JavaScriptCore/JSLock.h>

using JSGlobalObject = JSC::JSGlobalObject;
using Exception = JSC::Exception;
using JSValue = JSC::JSValue;
using JSString = JSC::JSString;
using JSModuleLoader = JSC::JSModuleLoader;
using JSModuleRecord = JSC::JSModuleRecord;
using Identifier = JSC::Identifier;
using SourceOrigin = JSC::SourceOrigin;
namespace JSCastingHelpers = JSC::JSCastingHelpers;


JSC__JSGlobalObject* Zig__GlobalObject__create(JSC__VM* arg0) {
    // There are assertions that the apiLock is set while the JSGlobalObject is initialized.
    if (arg0 != nullptr) {
        JSC::VM& vm = reinterpret_cast<JSC__VM&>(arg0);
        vm.apiLock().lock();
        Zig::GlobalObject* globalObject = Zig::GlobalObject::create(vm, Zig::GlobalObject::createStructure(vm, JSC::jsNull()));
        vm.apiLock().unlock();
        return static_cast<JSC__JSGlobalObject*>(globalObject);
    }

    JSC::initialize();
    
    JSC::VM& vm = JSC::VM::create(JSC::LargeHeap, nullptr);
    vm.apiLock().lock();


      #if ENABLE(WEBASSEMBLY)
        JSC::Wasm::enableFastMemory();
    #endif

    Zig::GlobalObject* globalObject = Zig::GlobalObject::create(vm, Zig::GlobalObject::createStructure(vm, JSC::jsNull()));
    vm.apiLock().unlock();
    return static_cast<JSC__JSGlobalObject*>(globalObject);
}

namespace Zig {

const JSC::ClassInfo GlobalObject::s_info = { "GlobalObject", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(GlobalObject) };

const JSC::GlobalObjectMethodTable GlobalObject::s_globalObjectMethodTable = {
    &supportsRichSourceInfo,
    &shouldInterruptScript,
    &javaScriptRuntimeFlags,
    nullptr, // queueTaskToEventLoop
nullptr,    // &shouldInterruptScriptBeforeTimeout,
    &moduleLoaderImportModule, // moduleLoaderImportModule
    &moduleLoaderResolve, // moduleLoaderResolve
    &moduleLoaderFetch, // moduleLoaderFetch
    &moduleLoaderCreateImportMetaProperties, // moduleLoaderCreateImportMetaProperties
    &moduleLoaderEvaluate, // moduleLoaderEvaluate
    &promiseRejectionTracker, // promiseRejectionTracker
    &reportUncaughtExceptionAtEventLoop,
    &currentScriptExecutionOwner,
    &scriptExecutionStatus,
    nullptr, // defaultLanguage
    nullptr, // compileStreaming
    nullptr, // instantiateStreaming
};

void GlobalObject::reportUncaughtExceptionAtEventLoop(JSGlobalObject* globalObject, Exception* exception) {
    Zig__GlobalObject__reportUncaughtException(globalObject, exception);
}

void GlobalObject::promiseRejectionTracker(JSGlobalObject* obj, JSC::JSPromise* prom, JSC::JSPromiseRejectionOperation reject) {
    Zig__GlobalObject__promiseRejectionTracker(obj, prom, reject == JSC::JSPromiseRejectionOperation::Reject ? 0 : 1);
}

JSC::Identifier GlobalObject::moduleLoaderResolve(
    JSGlobalObject* globalObject,
    JSModuleLoader* loader,
    JSValue key,
    JSValue referrer,
    JSValue origin
) {
    auto res = Zig__GlobalObject__resolve(
        globalObject,
        loader,
        JSValue::encode(key),
        JSValue::encode(referrer),
        nullptr
    );

   Wrap<JSC::Identifier, bJSC__Identifier> wrapped = Wrap<JSC::Identifier, bJSC__Identifier>(res);
   return *wrapped.cpp;
}

JSC::JSInternalPromise* GlobalObject::moduleLoaderImportModule(JSGlobalObject* globalObject, JSModuleLoader* loader, JSString* specifierValue, JSValue referrer, const SourceOrigin& sourceOrigin) {
    return Zig__GlobalObject__import(
        globalObject,
        loader,
        specifierValue,
        JSC::JSValue::encode(referrer),
        &sourceOrigin
    );
}

JSC::JSInternalPromise* GlobalObject::moduleLoaderFetch(JSGlobalObject* globalObject, JSModuleLoader* loader, JSValue key, JSValue value1, JSValue value2) {
    return Zig__GlobalObject__fetch(
        globalObject,
        loader,
        JSValue::encode(key),
        JSValue::encode(value1),
        JSValue::encode(value2)
    );
}

JSC::JSObject* GlobalObject::moduleLoaderCreateImportMetaProperties(JSGlobalObject* globalObject, JSModuleLoader* loader, JSValue key, JSModuleRecord* record, JSValue val) {
    auto res = Zig__GlobalObject__createImportMetaProperties(
        globalObject,
        loader,
        JSValue::encode(key),
        record,
        JSValue::encode(val)
    );

    return JSValue::decode(res).getObject();
}

JSC::JSValue GlobalObject::moduleLoaderEvaluate(JSGlobalObject* globalObject, JSModuleLoader* moduleLoader, JSValue key, JSValue moduleRecordValue, JSValue scriptFetcher, JSValue sentValue, JSValue resumeMode) {
    auto res = Zig__GlobalObject__eval(
        globalObject,
        moduleLoader,
        JSValue::encode(key),
        JSValue::encode(moduleRecordValue),
        JSValue::encode(scriptFetcher),
        JSValue::encode(sentValue),
        JSValue::encode(resumeMode)
    );

    return JSValue::decode(res);
}

}