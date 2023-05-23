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
#include "JSReadableStreamBYOBRequest.h"

#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMBuiltinConstructor.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>

namespace WebCore {
using namespace JSC;

// Functions

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsReadableStreamBYOBRequestConstructor);

class JSReadableStreamBYOBRequestPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSReadableStreamBYOBRequestPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSReadableStreamBYOBRequestPrototype* ptr = new (NotNull, JSC::allocateCell<JSReadableStreamBYOBRequestPrototype>(vm)) JSReadableStreamBYOBRequestPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSReadableStreamBYOBRequestPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSReadableStreamBYOBRequestPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSReadableStreamBYOBRequestPrototype, JSReadableStreamBYOBRequestPrototype::Base);

using JSReadableStreamBYOBRequestDOMConstructor = JSDOMBuiltinConstructor<JSReadableStreamBYOBRequest>;

template<> const ClassInfo JSReadableStreamBYOBRequestDOMConstructor::s_info = { "ReadableStreamBYOBRequest"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableStreamBYOBRequestDOMConstructor) };

template<> JSValue JSReadableStreamBYOBRequestDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSReadableStreamBYOBRequestDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(2), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "ReadableStreamBYOBRequest"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSReadableStreamBYOBRequest::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

template<> FunctionExecutable* JSReadableStreamBYOBRequestDOMConstructor::initializeExecutable(VM& vm)
{
    return readableStreamBYOBRequestInitializeReadableStreamBYOBRequestCodeGenerator(vm);
}

/* Hash table for prototype */

static const HashTableValue JSReadableStreamBYOBRequestPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsReadableStreamBYOBRequestConstructor, 0 } },
    { "view"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::Accessor | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinAccessorType, readableStreamBYOBRequestViewCodeGenerator, 0 } },
    { "respond"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinGeneratorType, readableStreamBYOBRequestRespondCodeGenerator, 0 } },
    { "respondWithNewView"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinGeneratorType, readableStreamBYOBRequestRespondWithNewViewCodeGenerator, 0 } },
};

const ClassInfo JSReadableStreamBYOBRequestPrototype::s_info = { "ReadableStreamBYOBRequest"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableStreamBYOBRequestPrototype) };

void JSReadableStreamBYOBRequestPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSReadableStreamBYOBRequest::info(), JSReadableStreamBYOBRequestPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSReadableStreamBYOBRequest::s_info = { "ReadableStreamBYOBRequest"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableStreamBYOBRequest) };

JSReadableStreamBYOBRequest::JSReadableStreamBYOBRequest(Structure* structure, JSDOMGlobalObject& globalObject)
    : JSDOMObject(structure, globalObject)
{
}

void JSReadableStreamBYOBRequest::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSReadableStreamBYOBRequest::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSReadableStreamBYOBRequestPrototype::create(vm, &globalObject, JSReadableStreamBYOBRequestPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSReadableStreamBYOBRequest::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSReadableStreamBYOBRequest>(vm, globalObject);
}

JSValue JSReadableStreamBYOBRequest::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSReadableStreamBYOBRequestDOMConstructor, DOMConstructorID::ReadableStreamBYOBRequest>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSReadableStreamBYOBRequest::destroy(JSC::JSCell* cell)
{
    JSReadableStreamBYOBRequest* thisObject = static_cast<JSReadableStreamBYOBRequest*>(cell);
    thisObject->JSReadableStreamBYOBRequest::~JSReadableStreamBYOBRequest();
}

JSC_DEFINE_CUSTOM_GETTER(jsReadableStreamBYOBRequestConstructor, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSReadableStreamBYOBRequestPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSReadableStreamBYOBRequest::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::GCClient::IsoSubspace* JSReadableStreamBYOBRequest::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSReadableStreamBYOBRequest, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForReadableStreamBYOBRequest.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForReadableStreamBYOBRequest = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForReadableStreamBYOBRequest.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForReadableStreamBYOBRequest = std::forward<decltype(space)>(space); });
}
}
