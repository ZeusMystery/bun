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
#include "JSAbortSignal.h"

#include "ActiveDOMObject.h"
#include "EventNames.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSAbortAlgorithm.h"
#include "JSAbortSignal.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertAny.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertCallbacks.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSEventListener.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapAnalyzer.h>
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

static JSC_DECLARE_HOST_FUNCTION(jsAbortSignalConstructorFunction_whenSignalAborted);
static JSC_DECLARE_HOST_FUNCTION(jsAbortSignalConstructorFunction_abort);
static JSC_DECLARE_HOST_FUNCTION(jsAbortSignalConstructorFunction_timeout);
static JSC_DECLARE_HOST_FUNCTION(jsAbortSignalPrototypeFunction_throwIfAborted);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsAbortSignalConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsAbortSignal_aborted);
static JSC_DECLARE_CUSTOM_GETTER(jsAbortSignal_reason);
static JSC_DECLARE_CUSTOM_GETTER(jsAbortSignal_onabort);
static JSC_DECLARE_CUSTOM_SETTER(setJSAbortSignal_onabort);

class JSAbortSignalPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSAbortSignalPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSAbortSignalPrototype* ptr = new (NotNull, JSC::allocateCell<JSAbortSignalPrototype>(vm)) JSAbortSignalPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSAbortSignalPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSAbortSignalPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSAbortSignalPrototype, JSAbortSignalPrototype::Base);

using JSAbortSignalDOMConstructor = JSDOMConstructorNotConstructable<JSAbortSignal>;

/* Hash table for constructor */

static const HashTableValue JSAbortSignalConstructorTableValues[] = {
    { "whenSignalAborted"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(jsAbortSignalConstructorFunction_whenSignalAborted), (intptr_t)(2) } },
    { "abort"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(jsAbortSignalConstructorFunction_abort), (intptr_t)(0) } },
    { "timeout"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(jsAbortSignalConstructorFunction_timeout), (intptr_t)(1) } },
};

template<> const ClassInfo JSAbortSignalDOMConstructor::s_info = { "AbortSignal"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSAbortSignalDOMConstructor) };

template<> JSValue JSAbortSignalDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEventTarget::getConstructor(vm, &globalObject);
}

template<> void JSAbortSignalDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "AbortSignal"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSAbortSignal::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
    reifyStaticProperties(vm, JSAbortSignal::info(), JSAbortSignalConstructorTableValues, *this);
    if (!(jsCast<JSDOMGlobalObject*>(&globalObject)->scriptExecutionContext()->isDocument() || jsCast<JSDOMGlobalObject*>(&globalObject)->scriptExecutionContext()->isWorkerGlobalScope())) {
        auto propertyName = Identifier::fromString(vm, reinterpret_cast<const LChar*>("timeout"), strlen("timeout"));
        VM::DeletePropertyModeScope scope(vm, VM::DeletePropertyMode::IgnoreConfigurable);
        DeletePropertySlot slot;
        JSObject::deleteProperty(this, &globalObject, propertyName, slot);
    }
}

/* Hash table for prototype */

static const HashTableValue JSAbortSignalPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t) static_cast<PropertySlot::GetValueFunc>(jsAbortSignalConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "aborted"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t) static_cast<PropertySlot::GetValueFunc>(jsAbortSignal_aborted), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "reason"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t) static_cast<PropertySlot::GetValueFunc>(jsAbortSignal_reason), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "onabort"_s, static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t) static_cast<PropertySlot::GetValueFunc>(jsAbortSignal_onabort), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSAbortSignal_onabort) } },
    { "throwIfAborted"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t) static_cast<RawNativeFunction>(jsAbortSignalPrototypeFunction_throwIfAborted), (intptr_t)(0) } },
};

const ClassInfo JSAbortSignalPrototype::s_info = { "AbortSignal"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSAbortSignalPrototype) };

void JSAbortSignalPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSAbortSignal::info(), JSAbortSignalPrototypeTableValues, *this);
    putDirect(vm, static_cast<JSVMClientData*>(vm.clientData)->builtinNames().whenSignalAbortedPrivateName(), JSFunction::create(vm, globalObject(), 0, String(), jsAbortSignalConstructorFunction_whenSignalAborted, ImplementationVisibility::Public), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSAbortSignal::s_info = { "AbortSignal"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSAbortSignal) };

JSAbortSignal::JSAbortSignal(Structure* structure, JSDOMGlobalObject& globalObject, Ref<AbortSignal>&& impl)
    : JSEventTarget(structure, globalObject, WTFMove(impl))
{
}

void JSAbortSignal::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSAbortSignal::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSAbortSignalPrototype::create(vm, &globalObject, JSAbortSignalPrototype::createStructure(vm, &globalObject, JSEventTarget::prototype(vm, globalObject)));
}

JSObject* JSAbortSignal::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSAbortSignal>(vm, globalObject);
}

JSValue JSAbortSignal::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSAbortSignalDOMConstructor, DOMConstructorID::AbortSignal>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsAbortSignalConstructor, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSAbortSignalPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSAbortSignal::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsAbortSignal_abortedGetter(JSGlobalObject& lexicalGlobalObject, JSAbortSignal& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLBoolean>(lexicalGlobalObject, throwScope, impl.aborted())));
}

JSC_DEFINE_CUSTOM_GETTER(jsAbortSignal_aborted, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSAbortSignal>::get<jsAbortSignal_abortedGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsAbortSignal_reasonGetter(JSGlobalObject& lexicalGlobalObject, JSAbortSignal& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLAny>(lexicalGlobalObject, throwScope, impl.reason())));
}

JSC_DEFINE_CUSTOM_GETTER(jsAbortSignal_reason, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSAbortSignal>::get<jsAbortSignal_reasonGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsAbortSignal_onabortGetter(JSGlobalObject& lexicalGlobalObject, JSAbortSignal& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().abortEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsAbortSignal_onabort, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSAbortSignal>::get<jsAbortSignal_onabortGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSAbortSignal_onabortSetter(JSGlobalObject& lexicalGlobalObject, JSAbortSignal& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().abortEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSAbortSignal_onabort, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSAbortSignal>::set<setJSAbortSignal_onabortSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSC::EncodedJSValue jsAbortSignalConstructorFunction_whenSignalAbortedBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    if (UNLIKELY(callFrame->argumentCount() < 2))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto object = convert<IDLInterface<AbortSignal>>(*lexicalGlobalObject, argument0.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentTypeError(lexicalGlobalObject, scope, 0, "object", "AbortSignal", "whenSignalAborted", "AbortSignal"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto algorithm = convert<IDLCallbackFunction<JSAbortAlgorithm>>(*lexicalGlobalObject, argument1.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentMustBeFunctionError(lexicalGlobalObject, scope, 1, "algorithm", "AbortSignal", "whenSignalAborted"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLBoolean>(*lexicalGlobalObject, throwScope, AbortSignal::whenSignalAborted(*object, algorithm.releaseNonNull()))));
}

JSC_DEFINE_HOST_FUNCTION(jsAbortSignalConstructorFunction_whenSignalAborted, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSAbortSignal>::callStatic<jsAbortSignalConstructorFunction_whenSignalAbortedBody, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, *callFrame, "whenSignalAborted");
}

static inline JSC::EncodedJSValue jsAbortSignalConstructorFunction_abortBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto* context = jsCast<JSDOMGlobalObject*>(lexicalGlobalObject)->scriptExecutionContext();
    if (UNLIKELY(!context))
        return JSValue::encode(jsUndefined());
    EnsureStillAliveScope argument0 = callFrame->argument(0);
    auto reason = convert<IDLAny>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJSNewlyCreated<IDLInterface<AbortSignal>>(*lexicalGlobalObject, *jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), throwScope, AbortSignal::abort(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), *context, WTFMove(reason)))));
}

JSC_DEFINE_HOST_FUNCTION(jsAbortSignalConstructorFunction_abort, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSAbortSignal>::callStatic<jsAbortSignalConstructorFunction_abortBody>(*lexicalGlobalObject, *callFrame, "abort");
}

static inline JSC::EncodedJSValue jsAbortSignalConstructorFunction_timeoutBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    auto* context = jsCast<JSDOMGlobalObject*>(lexicalGlobalObject)->scriptExecutionContext();
    if (UNLIKELY(!context))
        return JSValue::encode(jsUndefined());
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto milliseconds = convert<IDLEnforceRangeAdaptor<IDLUnsignedLongLong>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJSNewlyCreated<IDLInterface<AbortSignal>>(*lexicalGlobalObject, *jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), throwScope, AbortSignal::timeout(*context, WTFMove(milliseconds)))));
}

JSC_DEFINE_HOST_FUNCTION(jsAbortSignalConstructorFunction_timeout, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSAbortSignal>::callStatic<jsAbortSignalConstructorFunction_timeoutBody>(*lexicalGlobalObject, *callFrame, "timeout");
}

static inline JSC::EncodedJSValue jsAbortSignalPrototypeFunction_throwIfAbortedBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSAbortSignal>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.throwIfAborted(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsAbortSignalPrototypeFunction_throwIfAborted, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSAbortSignal>::call<jsAbortSignalPrototypeFunction_throwIfAbortedBody>(*lexicalGlobalObject, *callFrame, "throwIfAborted");
}

JSC::GCClient::IsoSubspace* JSAbortSignal::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSAbortSignal, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForAbortSignal.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForAbortSignal = WTFMove(space); },
        [](auto& spaces) { return spaces.m_subspaceForAbortSignal.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForAbortSignal = WTFMove(space); });
}

template<typename Visitor>
void JSAbortSignal::visitChildrenImpl(JSCell* cell, Visitor& visitor)
{
    auto* thisObject = jsCast<JSAbortSignal*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
    thisObject->visitAdditionalChildren(visitor);
}

DEFINE_VISIT_CHILDREN(JSAbortSignal);

template<typename Visitor>
void JSAbortSignal::visitOutputConstraints(JSCell* cell, Visitor& visitor)
{
    auto* thisObject = jsCast<JSAbortSignal*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitOutputConstraints(thisObject, visitor);
    thisObject->visitAdditionalChildren(visitor);
}

template void JSAbortSignal::visitOutputConstraints(JSCell*, AbstractSlotVisitor&);
template void JSAbortSignal::visitOutputConstraints(JSCell*, SlotVisitor&);
void JSAbortSignal::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSAbortSignal*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

void JSAbortSignalOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsAbortSignal = static_cast<JSAbortSignal*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsAbortSignal->wrapped(), jsAbortSignal);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable : 4483)
extern "C" {
extern void (*const __identifier("??_7AbortSignal@WebCore@@6B@")[])();
}
#else
extern "C" {
extern void* _ZTVN7WebCore11AbortSignalE[];
}
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<AbortSignal>&& impl)
{

    if constexpr (std::is_polymorphic_v<AbortSignal>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7AbortSignal@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore11AbortSignalE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // AbortSignal has subclasses. If AbortSignal has subclasses that get passed
        // to toJS() we currently require AbortSignal you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<AbortSignal>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, AbortSignal& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

AbortSignal* JSAbortSignal::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSAbortSignal*>(value))
        return &wrapper->wrapped();
    return nullptr;
}

}
