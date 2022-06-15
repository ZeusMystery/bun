
// AUTO-GENERATED FILE. DO NOT EDIT.
// Generated by /Users/jarred/Code/bun/src/javascript/jsc/generate-JSSink.js at 2022-06-14T08:19:26.544Z
// To regenerate this file, run:
//
//  bun src/javascript/jsc/generate-JSSink.js
//
#include "root.h"
#include "JSSink.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
// #include "JSBlob.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include "JavaScriptCore/FunctionPrototype.h"
#include "JavaScriptCore/HeapAnalyzer.h"

#include "JavaScriptCore/JSDestructibleObjectHeapCellType.h"
#include "JavaScriptCore/SlotVisitorMacros.h"
#include "JavaScriptCore/SubspaceInlines.h"
#include "wtf/GetPtr.h"
#include "wtf/PointerPreparations.h"
#include "wtf/URL.h"
#include "JavaScriptCore/BuiltinNames.h"

#include "JSBufferEncodingType.h"
#include "JSBufferPrototypeBuiltins.h"
#include "JSBufferConstructorBuiltins.h"
#include "JavaScriptCore/JSBase.h"
#if ENABLE(MEDIA_SOURCE)
#include "BufferMediaSource.h"
#include "JSMediaSource.h"
#endif

// #include "JavaScriptCore/JSTypedArrayViewPrototype.h"
#include "JavaScriptCore/JSArrayBufferViewInlines.h"

namespace WebCore {
using namespace JSC;

JSC_DEFINE_CUSTOM_GETTER(functionArrayBufferSink__getter, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, JSC::PropertyName))
{
    auto& vm = lexicalGlobalObject->vm();
    Zig::GlobalObject* globalObject = reinterpret_cast<Zig::GlobalObject*>(lexicalGlobalObject);

    return JSC::JSValue::encode(globalObject->ArrayBufferSink());
}

JSC_DEFINE_CUSTOM_GETTER(functionReadableArrayBufferSinkController__getter, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, JSC::PropertyName))
{
    auto& vm = lexicalGlobalObject->vm();
    Zig::GlobalObject* globalObject = reinterpret_cast<Zig::GlobalObject*>(lexicalGlobalObject);

    return JSC::JSValue::encode(globalObject->ArrayBufferSinkController());
}

JSC_DECLARE_HOST_FUNCTION(functionReadableArrayBufferSinkController__run);
JSC_DEFINE_HOST_FUNCTION(functionReadableArrayBufferSinkController__run, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    auto& vm = lexicalGlobalObject->vm();
    Zig::GlobalObject* globalObject = reinterpret_cast<Zig::GlobalObject*>(lexicalGlobalObject);
    auto scope = DECLARE_THROW_SCOPE(vm);

    if (callFrame->argumentCount() < 6) {
        throwException(callFrame, scope, createNotEnoughArgumentsError(callFrame));
        return JSC::JSValue::encode(JSC::jsUndefined());
    }

    WebCore::JSReadableStream* readableStream = JSC::jsDynamicCast<WebCore::JSReadableStream*>(vm, callFrame->argument(0));
    if (!readableStream) {
        throwException(callFrame, scope, createTypeError(callFrame, "first argument is not a ReadableStream"));
        return JSC::JSValue::encode(JSC::jsUndefined());
    }

    void* sinkPtr = reinterpret_cast<void*>(bitwise_cast<uintptr_t>(callFrame->argument(1).toDouble(globalObject)));
    JSObject* startFunctionObj = callFrame->argument(2).getObject();
    JSObject* pullFunctionObj = callFrame->argument(3).getObject();
    JSObject* cancelFunctionObj = callFrame->argument(4).getObject();

    JSFunction* pullFunction = pullFunctionObj != nullptr && startFunctionObj->isCallbable() ? JSC::jsCast<JSFunction*>(pullFunctionObj) : nullptr;
    JSFunction* cancelFunction = cancelFunctionObj != nullptr && startFunctionObj->isCallbable() ? JSC::jsCast<JSFunction*>(cancelFunctionObj) : nullptr;
}

static const HashTableValue JSArrayBufferSinkPrototypeTableValues[]
    = {
          { "close"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__close), (intptr_t)(0) } },
          { "closeWithError"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__closeWithError), (intptr_t)(1) } },
          { "drain"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__drain), (intptr_t)(1) } },
          { "end"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__end), (intptr_t)(0) } },
          { "start"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__start), (intptr_t)(1) } },
          { "write"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(ArrayBufferSink__write), (intptr_t)(1) } },
      };

#pragma mark - ArrayBufferSink

class JSArrayBufferSinkPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;

    static JSArrayBufferSinkPrototype* create(JSC::VM& vm, JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSArrayBufferSinkPrototype* ptr = new (NotNull, JSC::allocateCell<JSArrayBufferSinkPrototype>(vm)) JSArrayBufferSinkPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm, globalObject);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSArrayBufferSinkPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
        : Base(vm, structure)
    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject*);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSArrayBufferSinkPrototype, JSArrayBufferSinkPrototype::Base);

class JSReadableArrayBufferSinkControllerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;

    static JSReadableArrayBufferSinkControllerPrototype* create(JSC::VM& vm, JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSReadableArrayBufferSinkControllerPrototype* ptr = new (NotNull, JSC::allocateCell<JSReadableArrayBufferSinkControllerPrototype>(vm)) JSReadableArrayBufferSinkControllerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm, globalObject);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSReadableArrayBufferSinkControllerPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
        : Base(vm, structure)
    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject*);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSReadableArrayBufferSinkControllerPrototype, JSReadableArrayBufferSinkControllerPrototype::Base);

// Classes without streams
const ClassInfo JSArrayBufferSinkPrototype::s_info = { "ArrayBufferSink"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSArrayBufferSinkPrototype) };
const ClassInfo JSArrayBufferSink::s_info = { "ArrayBufferSink"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSArrayBufferSink) };
const ClassInfo JSArrayBufferSinkConstructor::s_info = { "ArrayBufferSink"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSArrayBufferSinkConstructor) };

// Classes with streams
const ClassInfo JSReadableArrayBufferSinkControllerPrototype::s_info = { "ReadableArrayBufferSinkController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableArrayBufferSinkControllerPrototype) };
const ClassInfo JSReadableArrayBufferSinkController::s_info = { "ReadableArrayBufferSinkController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableArrayBufferSinkController) };
const ClassInfo JSReadableArrayBufferSinkControllerConstructor::s_info = { "ReadableArrayBufferSinkController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableArrayBufferSinkControllerConstructor) };

JSArrayBufferSink::~JSArrayBufferSink()
{
    if (m_sinkPtr) {
        ArrayBufferSink__finalize(m_sinkPtr);
    }
}

JSReadableArrayBufferSinkController::~JSReadableArrayBufferSinkController()
{
    if (m_sinkPtr) {
        ArrayBufferSink__finalizeController(m_sinkPtr);
    }
}

JSArrayBufferSinkConstructor* JSArrayBufferSinkConstructor::create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSObject* prototype)
{
    JSArrayBufferSinkConstructor* ptr = new (NotNull, JSC::allocateCell<JSArrayBufferSinkConstructor>(vm)) JSArrayBufferSinkConstructor(vm, structure, ArrayBufferSink__construct);
    ptr->finishCreation(vm, globalObject, prototype);
    return ptr;
}

JSReadableArrayBufferSinkControllerConstructor* JSReadableArrayBufferSinkControllerConstructor::create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSObject* prototype)
{
    JSReadableArrayBufferSinkControllerConstructor* ptr = new (NotNull, JSC::allocateCell<JSReadableArrayBufferSinkControllerConstructor>(vm)) JSReadableArrayBufferSinkControllerConstructor(vm, structure, ArrayBufferSink__constructController);
    ptr->finishCreation(vm, globalObject, prototype);
    return ptr;
}

JSArrayBufferSink* JSArrayBufferSink::create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr)
{
    JSArrayBufferSink* ptr = new (NotNull, JSC::allocateCell<JSArrayBufferSink>(vm)) JSArrayBufferSink(vm, structure, sinkPtr);
    ptr->finishCreation(vm);
    return ptr;
}

JSReadableArrayBufferSinkController* JSReadableArrayBufferSinkController::create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr)
{
    JSReadableArrayBufferSinkController* ptr = new (NotNull, JSC::allocateCell<JSReadableArrayBufferSinkController>(vm)) JSReadableArrayBufferSinkController(vm, structure, sinkPtr);
    ptr->finishCreation(vm);
    return ptr;
}

void JSArrayBufferSinkConstructor::finishCreation(VM& vm, JSC::JSGlobalObject* globalObject, JSObject* prototype)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    initializeProperties(vm, globalObject, prototype);
}

void JSReadableArrayBufferSinkControllerConstructor::finishCreation(VM& vm, JSC::JSGlobalObject* globalObject, JSObject* prototype)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    initializeProperties(vm, globalObject, prototype);
}

JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSArrayBufferSinkConstructor::construct(JSC::JSGlobalObject* globalObject, JSC::CallFrame* callFrame)
{
    return ArrayBufferSink__construct(globalObject, callFrame);
}

JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSReadableArrayBufferSinkController::construct(JSC::JSGlobalObject* globalObject, JSC::CallFrame* callFrame)
{
    return ArrayBufferSink__constructController(globalObject, callFrame);
}

void JSArrayBufferSinkConstructor::initializeProperties(VM& vm, JSC::JSGlobalObject* globalObject, JSObject* prototype)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "ArrayBufferSink"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

void JSReadableArrayBufferSinkControllerConstructor::initializeProperties(VM& vm, JSC::JSGlobalObject* globalObject, JSObject* prototype)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "ArrayBufferSink"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

void JSArrayBufferSinkPrototype::finishCreation(JSC::VM& vm, JSC::JSGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSArrayBufferSink::info(), JSArrayBufferSinkPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

void JSReadableArrayBufferSinkControllerPrototype::finishCreation(JSC::VM& vm, JSC::JSGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSReadableArrayBufferSinkControllerPrototype::info(), ReadableArrayBufferSinkControllerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

void JSArrayBufferSink::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

void ReadableArrayBufferSinkController::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

template<typename Visitor>
void JSReadableArrayBufferSinkController::visitChildrenImpl(JSCell* cell, Visitor& visitor)
{
    auto* thisObject = jsCast<JSReadableArrayBufferSinkController*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
    visitor.append(thisObject->m_pull);
    visitor.append(thisObject->m_close);
    visitor.append(thisObject->m_start);
}

DEFINE_VISIT_CHILDREN(JSReadableArrayBufferSinkController);

void JSArrayBufferSink::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSArrayBufferSink*>(cell);
    if (void* wrapped = thisObject->wrapped()) {
        analyzer.setWrappedObjectForCell(cell, wrapped);
        // if (thisObject->scriptExecutionContext())
        //     analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    }
    Base::analyzeHeap(cell, analyzer);
}

void JSReadableArrayBufferSinkController::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSReadableArrayBufferSinkController*>(cell);
    if (void* wrapped = thisObject->wrapped()) {
        analyzer.setWrappedObjectForCell(cell, wrapped);
        // if (thisObject->scriptExecutionContext())
        //     analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    }
    Base::analyzeHeap(cell, analyzer);
}

void JSArrayBufferSink::destroy(JSCell* cell)
{
    static_cast<JSArrayBufferSink*>(cell)->JSArrayBufferSink::~JSArrayBufferSink();
}

void JSReadableArrayBufferSinkController::destroy(JSCell* cell)
{
    static_cast<JSReadableArrayBufferSinkController*>(cell)->JSReadableArrayBufferSinkController::~JSReadableArrayBufferSinkController();
}

JSObject* createJSSinkPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, SinkID sinkID)
{
    switch (sinkID) {

    case ArrayBufferSink:
        return JSArrayBufferSinkPrototype::create(vm, globalObject, JSArrayBufferSinkPrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));

    default:
        RELEASE_ASSERT_NOT_REACHED();
    }
}
JSObject* createJSSinkControllerPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, SinkID sinkID)
{
    switch (sinkID) {

    case ArrayBufferSink:
        return JSReadableArrayBufferSinkControllerPrototype::create(vm, globalObject, JSReadableArrayBufferSinkControllerPrototype::createStructure(vm, globalObject, globalObject->objectPrototype()));

    default:
        RELEASE_ASSERT_NOT_REACHED();
    }
}
} // namespace WebCore

extern "C" JSC__JSValue ArrayBufferSink__createObject(JSC__JSGlobalObject* arg0, void* sinkPtr)
{
    auto& vm = arg0->vm();
    Zig::GlobalObject* globalObject = reinterpret_cast<Zig::GlobalObject*>(arg0);
    JSC::JSValue prototype = globalObject->ArrayBufferSinkPrototype();
    JSC::Structure* structure = WebCore::JSArrayBufferSink::createStructure(vm, globalObject, prototype);
    return JSC::JSValue::encode(WebCore::JSArrayBufferSink::create(vm, globalObject, structure, sinkPtr));
}

extern "C" JSC__JSValue ArrayBufferSink__setStreamController(JSC__JSGlobalObject* arg0, JSC__JSValue readableStream, void* sinkPtr)
{
    auto& vm = arg0->vm();
    Zig::GlobalObject* globalObject = reinterpret_cast<Zig::GlobalObject*>(arg0);
    JSC::JSValue prototype = globalObject->ArrayBufferSinkControllerPrototype();
    JSC::Structure* structure = WebCore::JSReadableArrayBufferSinkController::createStructure(vm, globalObject, prototype);
    return JSC::JSValue::encode(WebCore::JSReadableArrayBufferSinkController::create(vm, globalObject, structure, sinkPtr));
}

extern "C" void* ArrayBufferSink__fromJS(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1)
{
    JSC::VM& vm = WebCore::getVM(arg0);
    if (auto* sink = JSC::jsDynamicCast<WebCore::JSArrayBufferSink*>(JSC::JSValue::decode(JSValue1)))
        return sink->wrapped();

    return nullptr;
}

extern "C" void* JSReadableArrayBufferSinkController__fromJS(JSC__JSGlobalObject* arg0, JSC__JSValue JSValue1)
{
    JSC::VM& vm = WebCore::getVM(arg0);
    if (auto* sink = JSC::jsDynamicCast<WebCore::JSReadableArrayBufferSinkController*>(JSC::JSValue::decode(JSValue1)))
        return sink->wrapped();

    return nullptr;
}
