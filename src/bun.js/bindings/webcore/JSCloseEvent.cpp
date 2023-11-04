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
#include "JSCloseEvent.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMWrapperCache.h"
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

template<> CloseEvent::Init convertDictionary<CloseEvent::Init>(JSGlobalObject& lexicalGlobalObject, JSValue value)
{
    VM& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool isNullOrUndefined = value.isUndefinedOrNull();
    auto* object = isNullOrUndefined ? nullptr : value.getObject();
    if (UNLIKELY(!isNullOrUndefined && !object)) {
        throwTypeError(&lexicalGlobalObject, throwScope);
        return {};
    }
    CloseEvent::Init result;
    JSValue bubblesValue;
    if (isNullOrUndefined)
        bubblesValue = jsUndefined();
    else {
        bubblesValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "bubbles"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!bubblesValue.isUndefined()) {
        result.bubbles = convert<IDLBoolean>(lexicalGlobalObject, bubblesValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.bubbles = false;
    JSValue cancelableValue;
    if (isNullOrUndefined)
        cancelableValue = jsUndefined();
    else {
        cancelableValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "cancelable"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!cancelableValue.isUndefined()) {
        result.cancelable = convert<IDLBoolean>(lexicalGlobalObject, cancelableValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.cancelable = false;
    JSValue composedValue;
    if (isNullOrUndefined)
        composedValue = jsUndefined();
    else {
        composedValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "composed"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!composedValue.isUndefined()) {
        result.composed = convert<IDLBoolean>(lexicalGlobalObject, composedValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.composed = false;
    JSValue codeValue;
    if (isNullOrUndefined)
        codeValue = jsUndefined();
    else {
        codeValue = object->get(&lexicalGlobalObject, WebCore::builtinNames(vm).codePublicName());
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!codeValue.isUndefined()) {
        result.code = convert<IDLUnsignedShort>(lexicalGlobalObject, codeValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.code = 0;
    JSValue reasonValue;
    if (isNullOrUndefined)
        reasonValue = jsUndefined();
    else {
        reasonValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "reason"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!reasonValue.isUndefined()) {
        result.reason = convert<IDLUSVString>(lexicalGlobalObject, reasonValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.reason = emptyString();
    JSValue wasCleanValue;
    if (isNullOrUndefined)
        wasCleanValue = jsUndefined();
    else {
        wasCleanValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "wasClean"_s));
        RETURN_IF_EXCEPTION(throwScope, {});
    }
    if (!wasCleanValue.isUndefined()) {
        result.wasClean = convert<IDLBoolean>(lexicalGlobalObject, wasCleanValue);
        RETURN_IF_EXCEPTION(throwScope, {});
    } else
        result.wasClean = false;
    return result;
}

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsCloseEventConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsCloseEvent_wasClean);
static JSC_DECLARE_CUSTOM_GETTER(jsCloseEvent_code);
static JSC_DECLARE_CUSTOM_GETTER(jsCloseEvent_reason);

class JSCloseEventPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSCloseEventPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSCloseEventPrototype* ptr = new (NotNull, JSC::allocateCell<JSCloseEventPrototype>(vm)) JSCloseEventPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSCloseEventPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSCloseEventPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSCloseEventPrototype, JSCloseEventPrototype::Base);

using JSCloseEventDOMConstructor = JSDOMConstructor<JSCloseEvent>;

template<> JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSCloseEventDOMConstructor::construct(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    VM& vm = lexicalGlobalObject->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* castedThis = jsCast<JSCloseEventDOMConstructor*>(callFrame->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto type = convert<IDLAtomStringAdaptor<IDLDOMString>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);
    auto eventInitDict = convert<IDLDictionary<CloseEvent::Init>>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = CloseEvent::create(WTFMove(type), WTFMove(eventInitDict));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    static_assert(TypeOrExceptionOrUnderlyingType<decltype(object)>::isRef);
    auto jsValue = toJSNewlyCreated<IDLInterface<CloseEvent>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, WTFMove(object));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    setSubclassStructureIfNeeded<CloseEvent>(lexicalGlobalObject, callFrame, asObject(jsValue));
    RETURN_IF_EXCEPTION(throwScope, {});
    return JSValue::encode(jsValue);
}
JSC_ANNOTATE_HOST_FUNCTION(JSCloseEventDOMConstructorConstruct, JSCloseEventDOMConstructor::construct);

template<> const ClassInfo JSCloseEventDOMConstructor::s_info = { "CloseEvent"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSCloseEventDOMConstructor) };

template<> JSValue JSCloseEventDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEvent::getConstructor(vm, &globalObject);
}

template<> void JSCloseEventDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(1), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "CloseEvent"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSCloseEvent::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSCloseEventPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsCloseEventConstructor, 0 } },
    { "wasClean"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsCloseEvent_wasClean, 0 } },
    { "code"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsCloseEvent_code, 0 } },
    { "reason"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsCloseEvent_reason, 0 } },
};

const ClassInfo JSCloseEventPrototype::s_info = { "CloseEvent"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSCloseEventPrototype) };

void JSCloseEventPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSCloseEvent::info(), JSCloseEventPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSCloseEvent::s_info = { "CloseEvent"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSCloseEvent) };

JSCloseEvent::JSCloseEvent(Structure* structure, JSDOMGlobalObject& globalObject, Ref<CloseEvent>&& impl)
    : JSEvent(structure, globalObject, WTFMove(impl))
{
}

void JSCloseEvent::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));

    // static_assert(!std::is_base_of<ActiveDOMObject, CloseEvent>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");
}

JSObject* JSCloseEvent::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSCloseEventPrototype::create(vm, &globalObject, JSCloseEventPrototype::createStructure(vm, &globalObject, JSEvent::prototype(vm, globalObject)));
}

JSObject* JSCloseEvent::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSCloseEvent>(vm, globalObject);
}

JSValue JSCloseEvent::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCloseEventDOMConstructor, DOMConstructorID::CloseEvent>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsCloseEventConstructor, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSCloseEventPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSCloseEvent::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsCloseEvent_wasCleanGetter(JSGlobalObject& lexicalGlobalObject, JSCloseEvent& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLBoolean>(lexicalGlobalObject, throwScope, impl.wasClean())));
}

JSC_DEFINE_CUSTOM_GETTER(jsCloseEvent_wasClean, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSCloseEvent>::get<jsCloseEvent_wasCleanGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsCloseEvent_codeGetter(JSGlobalObject& lexicalGlobalObject, JSCloseEvent& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLUnsignedShort>(lexicalGlobalObject, throwScope, impl.code())));
}

JSC_DEFINE_CUSTOM_GETTER(jsCloseEvent_code, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSCloseEvent>::get<jsCloseEvent_codeGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsCloseEvent_reasonGetter(JSGlobalObject& lexicalGlobalObject, JSCloseEvent& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLUSVString>(lexicalGlobalObject, throwScope, impl.reason())));
}

JSC_DEFINE_CUSTOM_GETTER(jsCloseEvent_reason, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSCloseEvent>::get<jsCloseEvent_reasonGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

JSC::GCClient::IsoSubspace* JSCloseEvent::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSCloseEvent, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForCloseEvent.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForCloseEvent = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForCloseEvent.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForCloseEvent = std::forward<decltype(space)>(space); });
}

void JSCloseEvent::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSCloseEvent*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable : 4483)
extern "C" {
extern void (*const __identifier("??_7CloseEvent@WebCore@@6B@")[])();
}
#else
extern "C" {
extern void* _ZTVN7WebCore10CloseEventE[];
}
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<CloseEvent>&& impl)
{

    if constexpr (std::is_polymorphic_v<CloseEvent>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7CloseEvent@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore10CloseEventE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // CloseEvent has subclasses. If CloseEvent has subclasses that get passed
        // to toJS() we currently require CloseEvent you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<CloseEvent>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, CloseEvent& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

}
