/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSWorker.h"

#include "ActiveDOMObject.h"
#include "EventNames.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertAny.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertDictionary.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertObject.h"
#include "JSDOMConvertSequences.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSEventListener.h"
#include "StructuredSerializeOptions.h"
#include "JSWorkerOptions.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/IteratorOperations.h>
#include <JavaScriptCore/JSArray.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>

namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_terminate);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_postMessage);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_unref);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_ref);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsWorkerConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onmessage);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onmessage);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onmessageerror);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onmessageerror);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onerror);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onerror);

class JSWorkerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSWorkerPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSWorkerPrototype* ptr = new (NotNull, JSC::allocateCell<JSWorkerPrototype>(vm)) JSWorkerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWorkerPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSWorkerPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWorkerPrototype, JSWorkerPrototype::Base);

using JSWorkerDOMConstructor = JSDOMConstructor<JSWorker>;

template<> EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSWorkerDOMConstructor::construct(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    VM& vm = lexicalGlobalObject->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* castedThis = jsCast<JSWorkerDOMConstructor*>(callFrame->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    auto* context = castedThis->scriptExecutionContext();
    if (UNLIKELY(!context))
        return throwConstructorScriptExecutionContextUnavailableError(*lexicalGlobalObject, throwScope, "Worker");
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto scriptUrl = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);

    auto options = WorkerOptions {};
    options.bun.unref = true;

    if (JSObject* optionsObject = JSC::jsDynamicCast<JSC::JSObject*>(argument1.value())) {
        if (auto nameValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "name"_s))) {
            if (nameValue.isString()) {
                options.name = nameValue.toWTFString(lexicalGlobalObject);
                RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            }
        }

        if (auto* bunObject = optionsObject) {
            if (auto miniModeValue = bunObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "smol"_s))) {
                options.bun.mini = miniModeValue.toBoolean(lexicalGlobalObject);
                RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            }

            if (auto ref = bunObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "ref"_s))) {
                options.bun.unref = !ref.toBoolean(lexicalGlobalObject);
                RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            }
        }
    }

    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = Worker::create(*context, WTFMove(scriptUrl), WTFMove(options));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    static_assert(TypeOrExceptionOrUnderlyingType<decltype(object)>::isRef);
    auto jsValue = toJSNewlyCreated<IDLInterface<Worker>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, WTFMove(object));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});

    auto& impl = jsCast<JSWorker*>(jsValue)->wrapped();
    if (!impl.updatePtr()) {
        throwVMError(lexicalGlobalObject, throwScope, "Failed to start Worker thread"_s);
        return encodedJSValue();
    }

    setSubclassStructureIfNeeded<Worker>(lexicalGlobalObject, callFrame, asObject(jsValue));
    RETURN_IF_EXCEPTION(throwScope, {});

    return JSValue::encode(jsValue);
}
JSC_ANNOTATE_HOST_FUNCTION(JSWorkerDOMConstructorConstruct, JSWorkerDOMConstructor::construct);

template<> const ClassInfo JSWorkerDOMConstructor::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorkerDOMConstructor) };

template<> JSValue JSWorkerDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEventTarget::getConstructor(vm, &globalObject);
}

template<> void JSWorkerDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(1), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "Worker"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSWorker::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSWorkerPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsWorkerConstructor, 0 } },
    { "onmessage"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onmessage, setJSWorker_onmessage } },
    { "onmessageerror"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onmessageerror, setJSWorker_onmessageerror } },
    { "onerror"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onerror, setJSWorker_onerror } },
    { "terminate"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_terminate, 0 } },
    { "postMessage"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_postMessage, 1 } },
    { "ref"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_ref, 0 } },
    { "unref"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_unref, 0 } },
};

const ClassInfo JSWorkerPrototype::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorkerPrototype) };

void JSWorkerPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSWorker::info(), JSWorkerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSWorker::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorker) };

JSWorker::JSWorker(Structure* structure, JSDOMGlobalObject& globalObject, Ref<Worker>&& impl)
    : JSEventTarget(structure, globalObject, WTFMove(impl))
{
}

// static_assert(std::is_base_of<ActiveDOMObject, Worker>::value, "Interface is marked as [ActiveDOMObject] but implementation class does not subclass ActiveDOMObject.");

JSObject* JSWorker::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    auto* structure = JSWorkerPrototype::createStructure(vm, &globalObject, JSEventTarget::prototype(vm, globalObject));
    structure->setMayBePrototype(true);
    return JSWorkerPrototype::create(vm, &globalObject, structure);
}

JSObject* JSWorker::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSWorker>(vm, globalObject);
}

JSValue JSWorker::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWorkerDOMConstructor, DOMConstructorID::Worker>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorkerConstructor, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSWorkerPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSWorker::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsWorker_onmessageGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().messageEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onmessage, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onmessageGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onmessageSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().messageEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onmessage, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onmessageSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsWorker_onmessageerrorGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().messageerrorEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onmessageerror, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onmessageerrorGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onmessageerrorSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().messageerrorEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onmessageerror, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onmessageerrorSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsWorker_onerrorGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().errorEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onerror, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onerrorGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onerrorSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().errorEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onerror, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onerrorSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_terminateBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.terminate(); })));
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_terminate, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_terminateBody>(*lexicalGlobalObject, *callFrame, "terminate");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessage1Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto message = convert<IDLAny>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto transfer = convert<IDLSequence<IDLObject>>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.postMessage(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), WTFMove(message), WTFMove(transfer)); })));
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessage2Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto message = convert<IDLAny>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);
    JSValue optionsValue = argument1.value();
    StructuredSerializeOptions options;
    if (optionsValue.isObject()) {
        JSObject* optionsObject = asObject(optionsValue);
        if (auto transferListValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "transfer"_s))) {
            auto transferList = convert<IDLSequence<IDLObject>>(*lexicalGlobalObject, transferListValue);
            RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            options.transfer = WTFMove(transferList);
        }
    }

    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.postMessage(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), WTFMove(message), WTFMove(options)); })));
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessageOverloadDispatcher(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    size_t argsCount = std::min<size_t>(2, callFrame->argumentCount());
    if (argsCount == 1) {
        RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    if (argsCount == 2) {
        JSValue distinguishingArg = callFrame->uncheckedArgument(1);
        if (distinguishingArg.isUndefined())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
        if (distinguishingArg.isUndefinedOrNull())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
        {
            bool success = hasIteratorMethod(lexicalGlobalObject, distinguishingArg);
            RETURN_IF_EXCEPTION(throwScope, {});
            if (success)
                RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage1Body(lexicalGlobalObject, callFrame, castedThis)));
        }
        if (distinguishingArg.isObject())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    return argsCount < 1 ? throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject)) : throwVMTypeError(lexicalGlobalObject, throwScope);
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_postMessage, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_postMessageOverloadDispatcher>(*lexicalGlobalObject, *callFrame, "postMessage");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_refBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    castedThis->wrapped().setKeepAlive(true);
    return JSValue::encode(jsUndefined());
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_ref, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_refBody>(*lexicalGlobalObject, *callFrame, "ref");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_unrefBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    castedThis->wrapped().setKeepAlive(false);
    return JSValue::encode(jsUndefined());
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_unref, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_unrefBody>(*lexicalGlobalObject, *callFrame, "unref");
}

JSC::GCClient::IsoSubspace* JSWorker::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSWorker, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForWorker.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForWorker = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForWorker.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForWorker = std::forward<decltype(space)>(space); });
}

void JSWorker::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSWorker*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url "_s + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSWorkerOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    auto* jsWorker = jsCast<JSWorker*>(handle.slot()->asCell());
    auto& wrapped = jsWorker->wrapped();
    if (wrapped.hasPendingActivity()) {
        if (UNLIKELY(reason))
            *reason = "ActiveDOMObject with pending activity";
        return true;
    }
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSWorkerOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsWorker = static_cast<JSWorker*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsWorker->wrapped(), jsWorker);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable : 4483)
extern "C" {
extern void (*const __identifier("??_7Worker@WebCore@@6B@")[])();
}
#else
extern "C" {
extern void* _ZTVN7WebCore6WorkerE[];
}
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<Worker>&& impl)
{

    if constexpr (std::is_polymorphic_v<Worker>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7Worker@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore6WorkerE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // Worker has subclasses. If Worker has subclasses that get passed
        // to toJS() we currently require Worker you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<Worker>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, Worker& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

Worker* JSWorker::toWrapped(JSC::VM&, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSWorker*>(value))
        return &wrapper->wrapped();
    return nullptr;
}
}
