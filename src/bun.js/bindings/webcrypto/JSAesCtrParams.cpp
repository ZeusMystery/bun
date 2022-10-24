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

#if ENABLE(WEB_CRYPTO)

#include "JSAesCtrParams.h"

#include "JSDOMConvertBufferSource.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMConvertUnion.h"
#include <JavaScriptCore/JSCInlines.h>
#include <variant>


namespace WebCore {
using namespace JSC;

#if ENABLE(WEB_CRYPTO)

template<> CryptoAlgorithmAesCtrParams convertDictionary<CryptoAlgorithmAesCtrParams>(JSGlobalObject& lexicalGlobalObject, JSValue value)
{
    VM& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool isNullOrUndefined = value.isUndefinedOrNull();
    auto* object = isNullOrUndefined ? nullptr : value.getObject();
    if (UNLIKELY(!isNullOrUndefined && !object)) {
        throwTypeError(&lexicalGlobalObject, throwScope);
        return { };
    }
    CryptoAlgorithmAesCtrParams result;
    JSValue nameValue;
    if (isNullOrUndefined)
        nameValue = jsUndefined();
    else {
        nameValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "name"_s));
        RETURN_IF_EXCEPTION(throwScope, { });
    }
    if (!nameValue.isUndefined()) {
        result.name = convert<IDLDOMString>(lexicalGlobalObject, nameValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "name", "AesCtrParams", "DOMString");
        return { };
    }
    JSValue counterValue;
    if (isNullOrUndefined)
        counterValue = jsUndefined();
    else {
        counterValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "counter"_s));
        RETURN_IF_EXCEPTION(throwScope, { });
    }
    if (!counterValue.isUndefined()) {
        result.counter = convert<IDLUnion<IDLArrayBufferView, IDLArrayBuffer>>(lexicalGlobalObject, counterValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "counter", "AesCtrParams", "(ArrayBufferView or ArrayBuffer)");
        return { };
    }
    JSValue lengthValue;
    if (isNullOrUndefined)
        lengthValue = jsUndefined();
    else {
        lengthValue = object->get(&lexicalGlobalObject, Identifier::fromString(vm, "length"_s));
        RETURN_IF_EXCEPTION(throwScope, { });
    }
    if (!lengthValue.isUndefined()) {
        result.length = convert<IDLEnforceRangeAdaptor<IDLOctet>>(lexicalGlobalObject, lengthValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else {
        throwRequiredMemberTypeError(lexicalGlobalObject, throwScope, "length", "AesCtrParams", "octet");
        return { };
    }
    return result;
}

#endif

} // namespace WebCore

#endif // ENABLE(WEB_CRYPTO)
