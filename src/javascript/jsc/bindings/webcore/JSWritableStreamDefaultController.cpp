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
#include "JSWritableStreamDefaultController.h"

#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMBinding.h"
#include "JSDOMBuiltinConstructor.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "WebCoreJSClientData.h"
#include "WritableStreamDefaultControllerBuiltins.h"
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

static JSC_DECLARE_CUSTOM_GETTER(jsWritableStreamDefaultControllerConstructor);

class JSWritableStreamDefaultControllerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSWritableStreamDefaultControllerPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSWritableStreamDefaultControllerPrototype* ptr = new (NotNull, JSC::allocateCell<JSWritableStreamDefaultControllerPrototype>(vm)) JSWritableStreamDefaultControllerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWritableStreamDefaultControllerPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSWritableStreamDefaultControllerPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWritableStreamDefaultControllerPrototype, JSWritableStreamDefaultControllerPrototype::Base);

using JSWritableStreamDefaultControllerDOMConstructor = JSDOMBuiltinConstructor<JSWritableStreamDefaultController>;

template<> const ClassInfo JSWritableStreamDefaultControllerDOMConstructor::s_info = { "WritableStreamDefaultController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWritableStreamDefaultControllerDOMConstructor) };

template<> JSValue JSWritableStreamDefaultControllerDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSWritableStreamDefaultControllerDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "WritableStreamDefaultController"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSWritableStreamDefaultController::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

template<> FunctionExecutable* JSWritableStreamDefaultControllerDOMConstructor::initializeExecutable(VM& vm)
{
    return writableStreamDefaultControllerInitializeWritableStreamDefaultControllerCodeGenerator(vm);
}

/* Hash table for prototype */

static const HashTableValue JSWritableStreamDefaultControllerPrototypeTableValues[] =
{
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWritableStreamDefaultControllerConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "error"_s, static_cast<unsigned>(JSC::PropertyAttribute::Builtin), NoIntrinsic, { (intptr_t)static_cast<BuiltinGenerator>(writableStreamDefaultControllerErrorCodeGenerator), (intptr_t) (0) } },
};

const ClassInfo JSWritableStreamDefaultControllerPrototype::s_info = { "WritableStreamDefaultController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWritableStreamDefaultControllerPrototype) };

void JSWritableStreamDefaultControllerPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSWritableStreamDefaultController::info(), JSWritableStreamDefaultControllerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSWritableStreamDefaultController::s_info = { "WritableStreamDefaultController"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWritableStreamDefaultController) };

JSWritableStreamDefaultController::JSWritableStreamDefaultController(Structure* structure, JSDOMGlobalObject& globalObject)
    : JSDOMObject(structure, globalObject) { }

void JSWritableStreamDefaultController::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));

}

JSObject* JSWritableStreamDefaultController::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSWritableStreamDefaultControllerPrototype::create(vm, &globalObject, JSWritableStreamDefaultControllerPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSWritableStreamDefaultController::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSWritableStreamDefaultController>(vm, globalObject);
}

JSValue JSWritableStreamDefaultController::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWritableStreamDefaultControllerDOMConstructor, DOMConstructorID::WritableStreamDefaultController>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSWritableStreamDefaultController::destroy(JSC::JSCell* cell)
{
    JSWritableStreamDefaultController* thisObject = static_cast<JSWritableStreamDefaultController*>(cell);
    thisObject->JSWritableStreamDefaultController::~JSWritableStreamDefaultController();
}

JSC_DEFINE_CUSTOM_GETTER(jsWritableStreamDefaultControllerConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSWritableStreamDefaultControllerPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSWritableStreamDefaultController::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::GCClient::IsoSubspace* JSWritableStreamDefaultController::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSWritableStreamDefaultController, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForWritableStreamDefaultController.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForWritableStreamDefaultController = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForWritableStreamDefaultController.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForWritableStreamDefaultController = WTFMove(space); }
    );
}


}
