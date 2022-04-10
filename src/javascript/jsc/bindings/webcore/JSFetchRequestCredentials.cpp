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
#include "JSFetchRequestCredentials.h"

#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSString.h>
#include <wtf/NeverDestroyed.h>


namespace WebCore {
using namespace JSC;

String convertEnumerationToString(FetchRequestCredentials enumerationValue)
{
    static const NeverDestroyed<String> values[] = {
        MAKE_STATIC_STRING_IMPL("omit"),
        MAKE_STATIC_STRING_IMPL("same-origin"),
        MAKE_STATIC_STRING_IMPL("include"),
    };
    static_assert(static_cast<size_t>(FetchRequestCredentials::Omit) == 0, "FetchRequestCredentials::Omit is not 0 as expected");
    static_assert(static_cast<size_t>(FetchRequestCredentials::SameOrigin) == 1, "FetchRequestCredentials::SameOrigin is not 1 as expected");
    static_assert(static_cast<size_t>(FetchRequestCredentials::Include) == 2, "FetchRequestCredentials::Include is not 2 as expected");
    ASSERT(static_cast<size_t>(enumerationValue) < WTF_ARRAY_LENGTH(values));
    return values[static_cast<size_t>(enumerationValue)];
}

template<> JSString* convertEnumerationToJS(JSGlobalObject& lexicalGlobalObject, FetchRequestCredentials enumerationValue)
{
    return jsStringWithCache(lexicalGlobalObject.vm(), convertEnumerationToString(enumerationValue));
}

template<> std::optional<FetchRequestCredentials> parseEnumeration<FetchRequestCredentials>(JSGlobalObject& lexicalGlobalObject, JSValue value)
{
    auto stringValue = value.toWTFString(&lexicalGlobalObject);
    if (stringValue == "omit")
        return FetchRequestCredentials::Omit;
    if (stringValue == "same-origin")
        return FetchRequestCredentials::SameOrigin;
    if (stringValue == "include")
        return FetchRequestCredentials::Include;
    return std::nullopt;
}

template<> const char* expectedEnumerationValues<FetchRequestCredentials>()
{
    return "\"omit\", \"same-origin\", \"include\"";
}

} // namespace WebCore
