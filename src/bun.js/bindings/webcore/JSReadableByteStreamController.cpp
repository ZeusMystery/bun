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
#include "JSReadableByteStreamController.h"

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

static JSC_DECLARE_CUSTOM_GETTER(jsReadableByteStreamControllerConstructor);

class JSReadableByteStreamControllerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSReadableByteStreamControllerPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSReadableByteStreamControllerPrototype* ptr = new (NotNull, JSC::allocateCell<JSReadableByteStreamControllerPrototype>(vm)) JSReadableByteStreamControllerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSReadableByteStreamControllerPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSReadableByteStreamControllerPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSReadableByteStreamControllerPrototype, JSReadableByteStreamControllerPrototype::Base);

using JSReadableByteStreamControllerDOMConstructor = JSDOMBuiltinConstructor<JSReadableByteStreamController>;

template<> const ClassInfo JSReadableByteStreamControllerDOMConstructor::s_info = { "ReadableByteStreamController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableByteStreamControllerDOMConstructor) };

template<> JSValue JSReadableByteStreamControllerDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSReadableByteStreamControllerDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(3), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "ReadableByteStreamController"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSReadableByteStreamController::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

template<> FunctionExecutable* JSReadableByteStreamControllerDOMConstructor::initializeExecutable(VM& vm)
{
    return readableByteStreamControllerInitializeReadableByteStreamControllerCodeGenerator(vm);
}

/* Hash table for prototype */

static const HashTableValue JSReadableByteStreamControllerPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsReadableByteStreamControllerConstructor, 0 } },
    { "byobRequest"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::Accessor | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinAccessorType, readableByteStreamControllerByobRequestCodeGenerator, 0 } },
    { "desiredSize"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::Accessor | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinAccessorType, readableByteStreamControllerDesiredSizeCodeGenerator, 0 } },
    { "enqueue"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinGeneratorType, readableByteStreamControllerEnqueueCodeGenerator, 0 } },
    { "close"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinGeneratorType, readableByteStreamControllerCloseCodeGenerator, 0 } },
    { "error"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::Builtin), NoIntrinsic, { HashTableValue::BuiltinGeneratorType, readableByteStreamControllerErrorCodeGenerator, 0 } },
};

const ClassInfo JSReadableByteStreamControllerPrototype::s_info = { "ReadableByteStreamController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableByteStreamControllerPrototype) };

void JSReadableByteStreamControllerPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSReadableByteStreamController::info(), JSReadableByteStreamControllerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSReadableByteStreamController::s_info = { "ReadableByteStreamController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSReadableByteStreamController) };

JSReadableByteStreamController::JSReadableByteStreamController(Structure* structure, JSDOMGlobalObject& globalObject)
    : JSDOMObject(structure, globalObject)
{
}

void JSReadableByteStreamController::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSReadableByteStreamController::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSReadableByteStreamControllerPrototype::create(vm, &globalObject, JSReadableByteStreamControllerPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSReadableByteStreamController::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSReadableByteStreamController>(vm, globalObject);
}

JSValue JSReadableByteStreamController::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSReadableByteStreamControllerDOMConstructor, DOMConstructorID::ReadableByteStreamController>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSReadableByteStreamController::destroy(JSC::JSCell* cell)
{
    JSReadableByteStreamController* thisObject = static_cast<JSReadableByteStreamController*>(cell);
    thisObject->JSReadableByteStreamController::~JSReadableByteStreamController();
}

JSC_DEFINE_CUSTOM_GETTER(jsReadableByteStreamControllerConstructor, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSReadableByteStreamControllerPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSReadableByteStreamController::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::GCClient::IsoSubspace* JSReadableByteStreamController::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSReadableByteStreamController, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForReadableByteStreamController.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForReadableByteStreamController = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForReadableByteStreamController.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForReadableByteStreamController = std::forward<decltype(space)>(space); });
}
}
