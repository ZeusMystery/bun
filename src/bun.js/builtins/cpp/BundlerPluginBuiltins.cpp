/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2023 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "BundlerPluginBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSObjectInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_bundlerPluginRunOnResolvePluginsCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_bundlerPluginRunOnResolvePluginsCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_bundlerPluginRunOnResolvePluginsCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_bundlerPluginRunOnResolvePluginsCodeLength = 3300;
static const JSC::Intrinsic s_bundlerPluginRunOnResolvePluginsCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_bundlerPluginRunOnResolvePluginsCode =
    "(function (\n" \
    "  specifier,\n" \
    "  inputNamespace,\n" \
    "  importer,\n" \
    "  internalID,\n" \
    "  kindId\n" \
    ") {\n" \
    "  \"use strict\";\n" \
    "\n" \
    "  //\n" \
    "  const kind = [\n" \
    "    \"entry-point\",\n" \
    "    \"import-statement\",\n" \
    "    \"require-call\",\n" \
    "    \"dynamic-import\",\n" \
    "    \"require-resolve\",\n" \
    "    \"import-rule\",\n" \
    "    \"url-token\",\n" \
    "    \"internal\",\n" \
    "  ][kindId];\n" \
    "\n" \
    "  var promiseResult = (async (inputPath, inputNamespace, importer, kind) => {\n" \
    "    var results = this.onResolve.@get(inputNamespace);\n" \
    "    if (!results) {\n" \
    "      this.onResolveAsync(internalID, null, null, null);\n" \
    "      return null;\n" \
    "    }\n" \
    "\n" \
    "    for (let [filter, callback] of results) {\n" \
    "      if (filter.test(inputPath)) {\n" \
    "        var result = callback({\n" \
    "          path: inputPath,\n" \
    "          importer,\n" \
    "          namespace: inputNamespace,\n" \
    "          kind,\n" \
    "        });\n" \
    "\n" \
    "        while (\n" \
    "          result &&\n" \
    "          @isPromise(result) &&\n" \
    "          (@getPromiseInternalField(result, @promiseFieldFlags) &\n" \
    "            @promiseStateMask) ===\n" \
    "            @promiseStateFulfilled\n" \
    "        ) {\n" \
    "          result = @getPromiseInternalField(\n" \
    "            result,\n" \
    "            @promiseFieldReactionsOrResult\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "        if (result && @isPromise(result)) {\n" \
    "          result = await result;\n" \
    "        }\n" \
    "\n" \
    "        if (!result || !@isObject(result)) {\n" \
    "          continue;\n" \
    "        }\n" \
    "\n" \
    "\n" \
    "        var {\n" \
    "          path,\n" \
    "          namespace: userNamespace = inputNamespace,\n" \
    "          external,\n" \
    "        } = result;\n" \
    "        if (\n" \
    "          !(typeof path === \"string\") ||\n" \
    "          !(typeof userNamespace === \"string\")\n" \
    "        ) {\n" \
    "          @throwTypeError(\n" \
    "            \"onResolve plugins must return an object with a string 'path' and string 'loader' field\"\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "        if (!path) {\n" \
    "          continue;\n" \
    "        }\n" \
    "\n" \
    "        if (!userNamespace) {\n" \
    "          userNamespace = inputNamespace;\n" \
    "        }\n" \
    "        if (typeof external !== \"boolean\" && !@isUndefinedOrNull(external)) {\n" \
    "          @throwTypeError(\n" \
    "            'onResolve plugins \"external\" field must be boolean or unspecified'\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "\n" \
    "        if (!external) {\n" \
    "          if (userNamespace === \"file\") {\n" \
    "            //\n" \
    "            \n" \
    "            if (path[0] !== \"/\" || path.includes(\"..\")) {\n" \
    "              @throwTypeError(\n" \
    "                'onResolve plugin \"path\" must be absolute when the namespace is \"file\"'\n" \
    "              );\n" \
    "            }\n" \
    "          }\n" \
    "          if (userNamespace === \"dataurl\") {\n" \
    "            if (!path.startsWith(\"data:\")) {\n" \
    "              @throwTypeError(\n" \
    "                'onResolve plugin \"path\" must start with \"data:\" when the namespace is\"dataurl\"'\n" \
    "              );\n" \
    "            }\n" \
    "          }\n" \
    "        }\n" \
    "        this.onResolveAsync(internalID, path, userNamespace, external);\n" \
    "        return null;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    this.onResolveAsync(internalID, null, null, null);\n" \
    "    return null;\n" \
    "  })(specifier, inputNamespace, importer, kind);\n" \
    "\n" \
    "  while (\n" \
    "    promiseResult &&\n" \
    "    @isPromise(promiseResult) &&\n" \
    "    (@getPromiseInternalField(promiseResult, @promiseFieldFlags) &\n" \
    "      @promiseStateMask) ===\n" \
    "      @promiseStateFulfilled\n" \
    "  ) {\n" \
    "    promiseResult = @getPromiseInternalField(\n" \
    "      promiseResult,\n" \
    "      @promiseFieldReactionsOrResult\n" \
    "    );\n" \
    "  }\n" \
    "\n" \
    "  if (promiseResult && @isPromise(promiseResult)) {\n" \
    "    promiseResult.then(\n" \
    "      () => {},\n" \
    "      (e) => {\n" \
    "        this.addError(internalID, e, 0);\n" \
    "      }\n" \
    "    );\n" \
    "  }\n" \
    "})\n" \
;

const JSC::ConstructAbility s_bundlerPluginRunSetupFunctionCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_bundlerPluginRunSetupFunctionCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_bundlerPluginRunSetupFunctionCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_bundlerPluginRunSetupFunctionCodeLength = 3786;
static const JSC::Intrinsic s_bundlerPluginRunSetupFunctionCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_bundlerPluginRunSetupFunctionCode =
    "(function (setup) {\n" \
    "  \"use strict\";\n" \
    "  var onLoadPlugins = new Map(),\n" \
    "    onResolvePlugins = new Map();\n" \
    "\n" \
    "  function validate(filterObject, callback, map) {\n" \
    "    if (!filterObject || !@isObject(filterObject)) {\n" \
    "      @throwTypeError('Expected an object with \"filter\" RegExp');\n" \
    "    }\n" \
    "\n" \
    "    if (!callback || !@isCallable(callback)) {\n" \
    "      @throwTypeError(\"callback must be a function\");\n" \
    "    }\n" \
    "\n" \
    "    var { filter, namespace = \"file\" } = filterObject;\n" \
    "\n" \
    "    if (!filter) {\n" \
    "      @throwTypeError('Expected an object with \"filter\" RegExp');\n" \
    "    }\n" \
    "\n" \
    "    if (!@isRegExpObject(filter)) {\n" \
    "      @throwTypeError(\"filter must be a RegExp\");\n" \
    "    }\n" \
    "\n" \
    "    if (namespace && !(typeof namespace === \"string\")) {\n" \
    "      @throwTypeError(\"namespace must be a string\");\n" \
    "    }\n" \
    "\n" \
    "    if (namespace?.length ?? 0) {\n" \
    "      namespace = \"file\";\n" \
    "    }\n" \
    "\n" \
    "    if (!/^([/@a-zA-Z0-9_\\\\-]+)$/.test(namespace)) {\n" \
    "      @throwTypeError(\"namespace can only contain @a-zA-Z0-9_\\\\-\");\n" \
    "    }\n" \
    "\n" \
    "    var callbacks = map.@get(namespace);\n" \
    "\n" \
    "    if (!callbacks) {\n" \
    "      map.@set(namespace, [[filter, callback]]);\n" \
    "    } else {\n" \
    "      @arrayPush(callbacks, [filter, callback]);\n" \
    "    }\n" \
    "  }\n" \
    "\n" \
    "  function onLoad(filterObject, callback) {\n" \
    "    validate(filterObject, callback, onLoadPlugins);\n" \
    "  }\n" \
    "\n" \
    "  function onResolve(filterObject, callback) {\n" \
    "    validate(filterObject, callback, onResolvePlugins);\n" \
    "  }\n" \
    "\n" \
    "  function onStart(callback) {\n" \
    "    //\n" \
    "    @throwTypeError(\"On-start callbacks are not implemented yet. See https:/\\/github.com/oven-sh/bun/issues/2771\");\n" \
    "  }\n" \
    "\n" \
    "  function onEnd(callback) {\n" \
    "    @throwTypeError(\"On-end callbacks are not implemented yet. See https:/\\/github.com/oven-sh/bun/issues/2771\");\n" \
    "  }\n" \
    "\n" \
    "  function onDispose(callback) {\n" \
    "    @throwTypeError(\"On-dispose callbacks are not implemented yet. See https:/\\/github.com/oven-sh/bun/issues/2771\");\n" \
    "  }\n" \
    "\n" \
    "  const processSetupResult = () => {\n" \
    "    var anyOnLoad = false,\n" \
    "      anyOnResolve = false;\n" \
    "\n" \
    "    for (var [namespace, callbacks] of onLoadPlugins.entries()) {\n" \
    "      for (var [filter] of callbacks) {\n" \
    "        this.addFilter(filter, namespace, 1);\n" \
    "        anyOnLoad = true;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    for (var [namespace, callbacks] of onResolvePlugins.entries()) {\n" \
    "      for (var [filter] of callbacks) {\n" \
    "        this.addFilter(filter, namespace, 0);\n" \
    "        anyOnResolve = true;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    if (anyOnResolve) {\n" \
    "      var onResolveObject = this.onResolve;\n" \
    "      if (!onResolveObject) {\n" \
    "        this.onResolve = onResolvePlugins;\n" \
    "      } else {\n" \
    "        for (var [namespace, callbacks] of onResolvePlugins.entries()) {\n" \
    "          var existing = onResolveObject.@get(namespace);\n" \
    "\n" \
    "          if (!existing) {\n" \
    "            onResolveObject.@set(namespace, callbacks);\n" \
    "          } else {\n" \
    "            onResolveObject.@set(namespace, existing.concat(callbacks));\n" \
    "          }\n" \
    "        }\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    if (anyOnLoad) {\n" \
    "      var onLoadObject = this.onLoad;\n" \
    "      if (!onLoadObject) {\n" \
    "        this.onLoad = onLoadPlugins;\n" \
    "      } else {\n" \
    "        for (var [namespace, callbacks] of onLoadPlugins.entries()) {\n" \
    "          var existing = onLoadObject.@get(namespace);\n" \
    "\n" \
    "          if (!existing) {\n" \
    "            onLoadObject.@set(namespace, callbacks);\n" \
    "          } else {\n" \
    "            onLoadObject.@set(namespace, existing.concat(callbacks));\n" \
    "          }\n" \
    "        }\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    return anyOnLoad || anyOnResolve;\n" \
    "  };\n" \
    "\n" \
    "  var setupResult = setup({\n" \
    "    onDispose,\n" \
    "    onEnd,\n" \
    "    onLoad,\n" \
    "    onResolve,\n" \
    "    onStart,\n" \
    "  });\n" \
    "\n" \
    "  if (setupResult && @isPromise(setupResult)) {\n" \
    "    if (\n" \
    "      @getPromiseInternalField(setupResult, @promiseFieldFlags) &\n" \
    "      @promiseStateFulfilled\n" \
    "    ) {\n" \
    "      setupResult = @getPromiseInternalField(\n" \
    "        setupResult,\n" \
    "        @promiseFieldReactionsOrResult\n" \
    "      );\n" \
    "    } else {\n" \
    "      return setupResult.@then(processSetupResult);\n" \
    "    }\n" \
    "  }\n" \
    "\n" \
    "  return processSetupResult();\n" \
    "})\n" \
;

const JSC::ConstructAbility s_bundlerPluginRunOnLoadPluginsCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_bundlerPluginRunOnLoadPluginsCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_bundlerPluginRunOnLoadPluginsCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_bundlerPluginRunOnLoadPluginsCodeLength = 2726;
static const JSC::Intrinsic s_bundlerPluginRunOnLoadPluginsCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_bundlerPluginRunOnLoadPluginsCode =
    "(function (internalID, path, namespace, defaultLoaderId) {\n" \
    "  \"use strict\";\n" \
    "\n" \
    "  const LOADERS_MAP = {\n" \
    "    jsx: 0,\n" \
    "    js: 1,\n" \
    "    ts: 2,\n" \
    "    tsx: 3,\n" \
    "    css: 4,\n" \
    "    file: 5,\n" \
    "    json: 6,\n" \
    "    toml: 7,\n" \
    "    wasm: 8,\n" \
    "    napi: 9,\n" \
    "    base64: 10,\n" \
    "    dataurl: 11,\n" \
    "    text: 12,\n" \
    "  };\n" \
    "  const loaderName = [\n" \
    "    \"jsx\",\n" \
    "    \"js\",\n" \
    "    \"ts\",\n" \
    "    \"tsx\",\n" \
    "    \"css\",\n" \
    "    \"file\",\n" \
    "    \"json\",\n" \
    "    \"toml\",\n" \
    "    \"wasm\",\n" \
    "    \"napi\",\n" \
    "    \"base64\",\n" \
    "    \"dataurl\",\n" \
    "    \"text\",\n" \
    "  ][defaultLoaderId];\n" \
    "\n" \
    "  var promiseResult = (async (internalID, path, namespace, defaultLoader) => {\n" \
    "    var results = this.onLoad.@get(namespace);\n" \
    "    if (!results) {\n" \
    "      this.onLoadAsync(internalID, null, null, null);\n" \
    "      return null;\n" \
    "    }\n" \
    "\n" \
    "    for (let [filter, callback] of results) {\n" \
    "      if (filter.test(path)) {\n" \
    "        var result = callback({\n" \
    "          path,\n" \
    "          namespace,\n" \
    "          loader: defaultLoader,\n" \
    "        });\n" \
    "\n" \
    "        while (\n" \
    "          result &&\n" \
    "          @isPromise(result) &&\n" \
    "          (@getPromiseInternalField(result, @promiseFieldFlags) &\n" \
    "            @promiseStateMask) ===\n" \
    "            @promiseStateFulfilled\n" \
    "        ) {\n" \
    "          result = @getPromiseInternalField(\n" \
    "            result,\n" \
    "            @promiseFieldReactionsOrResult\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "        if (result && @isPromise(result)) {\n" \
    "          result = await result;\n" \
    "        }\n" \
    "\n" \
    "        if (!result || !@isObject(result)) {\n" \
    "          continue;\n" \
    "        }\n" \
    "\n" \
    "        var { contents, loader = defaultLoader } = result;\n" \
    "        if (!(typeof contents === \"string\") && !@isTypedArrayView(contents)) {\n" \
    "          @throwTypeError(\n" \
    "            'onLoad plugins must return an object with \"contents\" as a string or Uint8Array'\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "        if (!(typeof loader === \"string\")) {\n" \
    "          @throwTypeError(\n" \
    "            'onLoad plugins must return an object with \"loader\" as a string'\n" \
    "          );\n" \
    "        }\n" \
    "\n" \
    "        const chosenLoader = LOADERS_MAP[loader];\n" \
    "        if (chosenLoader === @undefined) {\n" \
    "          @throwTypeError('Loader \"' + loader + '\" is not supported.');\n" \
    "        }\n" \
    "\n" \
    "        this.onLoadAsync(internalID, contents, chosenLoader);\n" \
    "        return null;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    this.onLoadAsync(internalID, null, null);\n" \
    "    return null;\n" \
    "  })(internalID, path, namespace, loaderName);\n" \
    "\n" \
    "  while (\n" \
    "    promiseResult &&\n" \
    "    @isPromise(promiseResult) &&\n" \
    "    (@getPromiseInternalField(promiseResult, @promiseFieldFlags) &\n" \
    "      @promiseStateMask) ===\n" \
    "      @promiseStateFulfilled\n" \
    "  ) {\n" \
    "    promiseResult = @getPromiseInternalField(\n" \
    "      promiseResult,\n" \
    "      @promiseFieldReactionsOrResult\n" \
    "    );\n" \
    "  }\n" \
    "\n" \
    "  if (promiseResult && @isPromise(promiseResult)) {\n" \
    "    promiseResult.then(\n" \
    "      () => {},\n" \
    "      (e) => {\n" \
    "        this.addError(internalID, e, 1);\n" \
    "      }\n" \
    "    );\n" \
    "  }\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().bundlerPluginBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().bundlerPluginBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_BUNDLERPLUGIN_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
