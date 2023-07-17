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
#include "JSURLSearchParams.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNullable.h"
#include "JSDOMConvertRecord.h"
#include "JSDOMConvertSequences.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMConvertUnion.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMIterator.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JavaScriptCore/BuiltinNames.h"
#include "JavaScriptCore/FunctionPrototype.h"
#include "JavaScriptCore/HeapAnalyzer.h"
#include "JavaScriptCore/JSArray.h"

#include "JavaScriptCore/JSDestructibleObjectHeapCellType.h"
#include "JavaScriptCore/SlotVisitorMacros.h"
#include "JavaScriptCore/SubspaceInlines.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include "wtf/GetPtr.h"
#include "wtf/PointerPreparations.h"
#include "wtf/URL.h"
#include "wtf/Vector.h"
#include <variant>
#include "GCDefferalContext.h"

namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_append);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_delete);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_get);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_getAll);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_has);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_set);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_sort);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_toJSON);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_entries);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_keys);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_values);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_forEach);
static JSC_DECLARE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_toString);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsURLSearchParamsConstructor);

class JSURLSearchParamsPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSURLSearchParamsPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSURLSearchParamsPrototype* ptr = new (NotNull, JSC::allocateCell<JSURLSearchParamsPrototype>(vm)) JSURLSearchParamsPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSURLSearchParamsPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSURLSearchParamsPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSURLSearchParamsPrototype, JSURLSearchParamsPrototype::Base);

using JSURLSearchParamsDOMConstructor = JSDOMConstructor<JSURLSearchParams>;

template<> EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSURLSearchParamsDOMConstructor::construct(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    VM& vm = lexicalGlobalObject->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* castedThis = jsCast<JSURLSearchParamsDOMConstructor*>(callFrame->jsCallee());
    ASSERT(castedThis);
    EnsureStillAliveScope argument0 = callFrame->argument(0);
    auto init = argument0.value().isUndefined() ? emptyString() : convert<IDLUnion<IDLSequence<IDLSequence<IDLUSVString>>, IDLRecord<IDLUSVString, IDLUSVString>, IDLUSVString>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = URLSearchParams::create(WTFMove(init));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    static_assert(TypeOrExceptionOrUnderlyingType<decltype(object)>::isRef);
    auto jsValue = toJSNewlyCreated<IDLInterface<URLSearchParams>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, WTFMove(object));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    setSubclassStructureIfNeeded<URLSearchParams>(lexicalGlobalObject, callFrame, asObject(jsValue));
    RETURN_IF_EXCEPTION(throwScope, {});
    return JSValue::encode(jsValue);
}
JSC_ANNOTATE_HOST_FUNCTION(JSURLSearchParamsDOMConstructorConstruct, JSURLSearchParamsDOMConstructor::construct);

template<> const ClassInfo JSURLSearchParamsDOMConstructor::s_info = { "URLSearchParams"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSURLSearchParamsDOMConstructor) };

template<> JSValue JSURLSearchParamsDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSURLSearchParamsDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "URLSearchParams"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSURLSearchParams::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

JSC_DEFINE_CUSTOM_GETTER(jsURLSearchParamsPrototype_getLength, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* thisObject = jsDynamicCast<JSURLSearchParams*>(JSValue::decode(thisValue));
    if (UNLIKELY(!thisObject))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(jsNumber(thisObject->wrapped().size()));
}

/* Hash table for prototype */

static const HashTableValue JSURLSearchParamsPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsURLSearchParamsConstructor, 0 } },
    { "append"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_append, 2 } },
    { "delete"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_delete, 1 } },
    { "get"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_get, 1 } },
    { "getAll"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_getAll, 1 } },
    { "has"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_has, 1 } },
    { "set"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_set, 2 } },
    { "sort"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_sort, 0 } },
    { "entries"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_entries, 0 } },
    { "keys"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_keys, 0 } },
    { "values"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_values, 0 } },
    { "forEach"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_forEach, 1 } },
    { "toString"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_toString, 0 } },
    { "toJSON"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsURLSearchParamsPrototypeFunction_toJSON, 0 } },
    { "length"_s, static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsURLSearchParamsPrototype_getLength, 0 } },
};

const ClassInfo JSURLSearchParamsPrototype::s_info = { "URLSearchParams"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSURLSearchParamsPrototype) };

void JSURLSearchParamsPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSURLSearchParams::info(), JSURLSearchParamsPrototypeTableValues, *this);
    putDirect(vm, vm.propertyNames->iteratorSymbol, getDirect(vm, vm.propertyNames->builtinNames().entriesPublicName()), static_cast<unsigned>(JSC::PropertyAttribute::DontEnum));
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSURLSearchParams::s_info = { "URLSearchParams"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSURLSearchParams) };

JSURLSearchParams::JSURLSearchParams(Structure* structure, JSDOMGlobalObject& globalObject, Ref<URLSearchParams>&& impl)
    : JSDOMWrapper<URLSearchParams>(structure, globalObject, WTFMove(impl))
{
}

void JSURLSearchParams::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));

    // static_assert(!std::is_base_of<ActiveDOMObject, URLSearchParams>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");
}

JSObject* JSURLSearchParams::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSURLSearchParamsPrototype::create(vm, &globalObject, JSURLSearchParamsPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSURLSearchParams::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSURLSearchParams>(vm, globalObject);
}

JSValue JSURLSearchParams::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSURLSearchParamsDOMConstructor, DOMConstructorID::URLSearchParams>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSURLSearchParams::destroy(JSC::JSCell* cell)
{
    JSURLSearchParams* thisObject = static_cast<JSURLSearchParams*>(cell);
    thisObject->JSURLSearchParams::~JSURLSearchParams();
}

JSC_DEFINE_CUSTOM_GETTER(jsURLSearchParamsConstructor, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSURLSearchParamsPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSURLSearchParams::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_appendBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 2))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto value = convert<IDLUSVString>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.append(WTFMove(name), WTFMove(value)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_append, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_appendBody>(*lexicalGlobalObject, *callFrame, "append");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_deleteBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.remove(WTFMove(name)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_delete, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_deleteBody>(*lexicalGlobalObject, *callFrame, "delete");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_getBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLNullable<IDLUSVString>>(*lexicalGlobalObject, throwScope, impl.get(WTFMove(name)))));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_get, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_getBody>(*lexicalGlobalObject, *callFrame, "get");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_getAllBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLSequence<IDLUSVString>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.getAll(WTFMove(name)))));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_getAll, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_getAllBody>(*lexicalGlobalObject, *callFrame, "getAll");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_hasBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLBoolean>(*lexicalGlobalObject, throwScope, impl.has(WTFMove(name)))));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_has, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_hasBody>(*lexicalGlobalObject, *callFrame, "has");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_setBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 2))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto name = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto value = convert<IDLUSVString>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.set(WTFMove(name), WTFMove(value)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_set, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_setBody>(*lexicalGlobalObject, *callFrame, "set");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_sortBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.sort(); })));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_sort, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_sortBody>(*lexicalGlobalObject, *callFrame, "sort");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_toStringBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, impl.toString())));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_toString, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_toStringBody>(*lexicalGlobalObject, *callFrame, "toString");
}

static inline JSC::EncodedJSValue jsURLSearchParamsPrototypeFunction_toJSONBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSURLSearchParams>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    auto iter = impl.createIterator();

    JSObject* obj;
    if (impl.size() + 1 < 64) {
        obj = JSC::constructEmptyObject(lexicalGlobalObject, lexicalGlobalObject->objectPrototype(), impl.size() + 1);
    } else {
        obj = JSC::constructEmptyObject(lexicalGlobalObject, lexicalGlobalObject->objectPrototype());
    }

    obj->putDirect(vm, vm.propertyNames->toStringTagSymbol, jsNontrivialString(lexicalGlobalObject->vm(), "URLSearchParams"_s), JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::ReadOnly | 0);

    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    WTF::HashSet<String> seenKeys;
    for (auto entry = iter.next(); entry.has_value(); entry = iter.next()) {
        auto& key = entry.value().key;
        auto& value = entry.value().value;
        auto ident = Identifier::fromString(vm, key);
        if (seenKeys.contains(key)) {
            JSValue jsValue = obj->getDirect(vm, ident);
            if (jsValue.isString()) {
                JSValue stringResult = jsString(vm, value);
                ensureStillAliveHere(stringResult);

                GCDeferralContext deferralContext(lexicalGlobalObject->vm());
                JSC::ObjectInitializationScope initializationScope(lexicalGlobalObject->vm());

                JSC::JSArray* array = JSC::JSArray::tryCreateUninitializedRestricted(
                    initializationScope, &deferralContext,
                    lexicalGlobalObject->arrayStructureForIndexingTypeDuringAllocation(JSC::ArrayWithContiguous),
                    2);

                array->initializeIndex(initializationScope, 0, jsValue);
                array->initializeIndex(initializationScope, 1, stringResult);
                obj->putDirect(vm, ident, array, 0);
            } else if (jsValue.isCell() && jsValue.asCell()->type() == ArrayType) {
                JSC::JSArray* array = jsCast<JSC::JSArray*>(jsValue.getObject());
                array->push(lexicalGlobalObject, jsString(vm, value));
                RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            } else {
                RELEASE_ASSERT_NOT_REACHED();
            }
        } else {
            seenKeys.add(key);
            obj->putDirect(vm, ident, jsString(vm, value), 0);
        }
    }

    RELEASE_AND_RETURN(throwScope, JSValue::encode(obj));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_toJSON, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_toJSONBody>(*lexicalGlobalObject, *callFrame, "toJSON");
}

struct URLSearchParamsIteratorTraits {
    static constexpr JSDOMIteratorType type = JSDOMIteratorType::Map;
    using KeyType = IDLUSVString;
    using ValueType = IDLUSVString;
};

using URLSearchParamsIteratorBase = JSDOMIteratorBase<JSURLSearchParams, URLSearchParamsIteratorTraits>;
class URLSearchParamsIterator final : public URLSearchParamsIteratorBase {
public:
    using Base = URLSearchParamsIteratorBase;
    DECLARE_INFO;

    template<typename, SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<URLSearchParamsIterator, UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForURLSearchParamsIterator.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForURLSearchParamsIterator = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForURLSearchParamsIterator.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForURLSearchParamsIterator = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static URLSearchParamsIterator* create(JSC::VM& vm, JSC::Structure* structure, JSURLSearchParams& iteratedObject, IterationKind kind)
    {
        auto* instance = new (NotNull, JSC::allocateCell<URLSearchParamsIterator>(vm)) URLSearchParamsIterator(structure, iteratedObject, kind);
        instance->finishCreation(vm);
        return instance;
    }

private:
    URLSearchParamsIterator(JSC::Structure* structure, JSURLSearchParams& iteratedObject, IterationKind kind)
        : Base(structure, iteratedObject, kind)
    {
    }
};

using URLSearchParamsIteratorPrototype = JSDOMIteratorPrototype<JSURLSearchParams, URLSearchParamsIteratorTraits>;
JSC_ANNOTATE_HOST_FUNCTION(URLSearchParamsIteratorPrototypeNext, URLSearchParamsIteratorPrototype::next);

template<>
const JSC::ClassInfo URLSearchParamsIteratorBase::s_info = { "URLSearchParams Iterator"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(URLSearchParamsIteratorBase) };
const JSC::ClassInfo URLSearchParamsIterator::s_info = { "URLSearchParams Iterator"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(URLSearchParamsIterator) };

template<>
const JSC::ClassInfo URLSearchParamsIteratorPrototype::s_info = { "URLSearchParams Iterator"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(URLSearchParamsIteratorPrototype) };

static inline EncodedJSValue jsURLSearchParamsPrototypeFunction_entriesCaller(JSGlobalObject*, CallFrame*, JSURLSearchParams* thisObject)
{
    return JSValue::encode(iteratorCreate<URLSearchParamsIterator>(*thisObject, IterationKind::Entries));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_entries, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_entriesCaller>(*lexicalGlobalObject, *callFrame, "entries");
}

static inline EncodedJSValue jsURLSearchParamsPrototypeFunction_keysCaller(JSGlobalObject*, CallFrame*, JSURLSearchParams* thisObject)
{
    return JSValue::encode(iteratorCreate<URLSearchParamsIterator>(*thisObject, IterationKind::Keys));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_keys, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_keysCaller>(*lexicalGlobalObject, *callFrame, "keys");
}

static inline EncodedJSValue jsURLSearchParamsPrototypeFunction_valuesCaller(JSGlobalObject*, CallFrame*, JSURLSearchParams* thisObject)
{
    return JSValue::encode(iteratorCreate<URLSearchParamsIterator>(*thisObject, IterationKind::Values));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_values, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_valuesCaller>(*lexicalGlobalObject, *callFrame, "values");
}

static inline EncodedJSValue jsURLSearchParamsPrototypeFunction_forEachCaller(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame, JSURLSearchParams* thisObject)
{
    return JSValue::encode(iteratorForEach<URLSearchParamsIterator>(*lexicalGlobalObject, *callFrame, *thisObject));
}

JSC_DEFINE_HOST_FUNCTION(jsURLSearchParamsPrototypeFunction_forEach, (JSC::JSGlobalObject * lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSURLSearchParams>::call<jsURLSearchParamsPrototypeFunction_forEachCaller>(*lexicalGlobalObject, *callFrame, "forEach");
}

JSC::GCClient::IsoSubspace* JSURLSearchParams::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSURLSearchParams, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForURLSearchParams.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForURLSearchParams = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForURLSearchParams.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForURLSearchParams = std::forward<decltype(space)>(space); });
}

void JSURLSearchParams::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSURLSearchParams*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    // if (thisObject->scriptExecutionContext())
    //     analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSURLSearchParamsOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSURLSearchParamsOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsURLSearchParams = static_cast<JSURLSearchParams*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsURLSearchParams->wrapped(), jsURLSearchParams);
}

// #if ENABLE(BINDING_INTEGRITY)
// #if PLATFORM(WIN)
// #pragma warning(disable : 4483)
// extern "C" {
// extern void (*const __identifier("??_7URLSearchParams@WebCore@@6B@")[])();
// }
// #else
// extern "C" {
// extern void* _ZTVN7WebCore15URLSearchParamsE[];
// }
// #endif
// #endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<URLSearchParams>&& impl)
{

    //     if constexpr (std::is_polymorphic_v<URLSearchParams>) {
    // #if ENABLE(BINDING_INTEGRITY)
    //         const void* actualVTablePointer = getVTablePointer(impl.ptr());
    // #if PLATFORM(WIN)
    //         void* expectedVTablePointer = __identifier("??_7URLSearchParams@WebCore@@6B@");
    // #else
    //         void* expectedVTablePointer = &_ZTVN7WebCore15URLSearchParamsE[2];
    // #endif

    //         // If you hit this assertion you either have a use after free bug, or
    //         // URLSearchParams has subclasses. If URLSearchParams has subclasses that get passed
    //         // to toJS() we currently require URLSearchParams you to opt out of binding hardening
    //         // by adding the SkipVTableValidation attribute to the interface IDL definition
    //         RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
    // #endif
    // }
    return createWrapper<URLSearchParams>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, URLSearchParams& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

URLSearchParams* JSURLSearchParams::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSURLSearchParams*>(value))
        return &wrapper->wrapped();
    return nullptr;
}
}
