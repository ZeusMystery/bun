/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
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
#include "ReadableStreamBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_readableStreamInitializeReadableStreamCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamInitializeReadableStreamCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamInitializeReadableStreamCodeLength = 2408;
static const JSC::Intrinsic s_readableStreamInitializeReadableStreamCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamInitializeReadableStreamCode =
    "(function (underlyingSource, strategy)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "     if (underlyingSource === @undefined)\n" \
    "         underlyingSource = { };\n" \
    "     if (strategy === @undefined)\n" \
    "         strategy = { };\n" \
    "\n" \
    "    if (!@isObject(underlyingSource))\n" \
    "        @throwTypeError(\"ReadableStream constructor takes an object as first argument\");\n" \
    "\n" \
    "    if (strategy !== @undefined && !@isObject(strategy))\n" \
    "        @throwTypeError(\"ReadableStream constructor takes an object as second argument, if any\");\n" \
    "\n" \
    "    @putByIdDirectPrivate(this, \"state\", @streamReadable);\n" \
    "    \n" \
    "    @putByIdDirectPrivate(this, \"reader\", @undefined);\n" \
    "    \n" \
    "    @putByIdDirectPrivate(this, \"storedError\", @undefined);\n" \
    "    \n" \
    "    @putByIdDirectPrivate(this, \"disturbed\", false);\n" \
    "    \n" \
    "    //\n" \
    "    @putByIdDirectPrivate(this, \"readableStreamController\", null);\n" \
    "    \n" \
    "\n" \
    "    //\n" \
    "    //\n" \
    "    if (@getByIdDirectPrivate(underlyingSource, \"pull\") !== @undefined) {\n" \
    "        \n" \
    "        const size = @getByIdDirectPrivate(strategy, \"size\");\n" \
    "        const highWaterMark = @getByIdDirectPrivate(strategy, \"highWaterMark\");\n" \
    "        @setupReadableStreamDefaultController(this, underlyingSource, size, highWaterMark !== @undefined ? highWaterMark : 1, @getByIdDirectPrivate(underlyingSource, \"start\"), @getByIdDirectPrivate(underlyingSource, \"pull\"), @getByIdDirectPrivate(underlyingSource, \"cancel\"));\n" \
    "        \n" \
    "        return this;\n" \
    "    }\n" \
    "\n" \
    "    const type = underlyingSource.type;\n" \
    "    const typeString = @toString(type);\n" \
    "\n" \
    "    if (typeString === \"bytes\") {\n" \
    "        //\n" \
    "        //\n" \
    "\n" \
    "        if (strategy.highWaterMark === @undefined)\n" \
    "            strategy.highWaterMark = 0;\n" \
    "        if (strategy.size !== @undefined)\n" \
    "            @throwRangeError(\"Strategy for a ReadableByteStreamController cannot have a size\");\n" \
    "\n" \
    "        let readableByteStreamControllerConstructor = @ReadableByteStreamController;\n" \
    "        \n" \
    "        @putByIdDirectPrivate(this, \"readableStreamController\", new @ReadableByteStreamController(this, underlyingSource, strategy.highWaterMark, @isReadableStream));\n" \
    "    } else if (type === @undefined) {\n" \
    "        if (strategy.highWaterMark === @undefined)\n" \
    "            strategy.highWaterMark = 1;\n" \
    "            \n" \
    "        @setupReadableStreamDefaultController(this, underlyingSource, strategy.size, strategy.highWaterMark, underlyingSource.start, underlyingSource.pull, underlyingSource.cancel);\n" \
    "    } else\n" \
    "        @throwRangeError(\"Invalid type for underlying source\");\n" \
    "\n" \
    "    return this;\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamCreateNativeReadableStreamCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamCreateNativeReadableStreamCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamCreateNativeReadableStreamCodeLength = 2355;
static const JSC::Intrinsic s_readableStreamCreateNativeReadableStreamCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamCreateNativeReadableStreamCode =
    "(function (nativeTag, nativeID) {\n" \
    "    var cached =  globalThis[Symbol.for(\"Bun.nativeReadableStreamPrototype\")] ||= new @Map;\n" \
    "    var Prototype = cached.@get(nativeID);\n" \
    "    if (Prototype === @undefined) {\n" \
    "        var [pull, start, cancel, setClose, deinit] = globalThis[Symbol.for(\"Bun.lazy\")](nativeID);\n" \
    "        var closer = [false];\n" \
    "\n" \
    "        var handleResult = function handleResult(result, controller) {\n" \
    "            if (result && @isPromise(result)) {\n" \
    "                result.then((val) => handleResult(val, controller), err => controller.error(err));\n" \
    "            } else if (result !== false) {\n" \
    "                controller.enqueue(result);\n" \
    "            }\n" \
    "\n" \
    "            if (closer[0] || result === false) {\n" \
    "                new @Promise((resolve, reject) => resolve(controller.close())).then(() => {}, () => {});\n" \
    "                closer[0] = false;\n" \
    "            }\n" \
    "        }\n" \
    "\n" \
    "        Prototype = class NativeReadableStreamSource {\n" \
    "            constructor(tag) {\n" \
    "                this.pull = this.pull_.bind(tag);\n" \
    "                this.start = this.start_.bind(tag);\n" \
    "                this.cancel = this.cancel_.bind(tag);\n" \
    "            }\n" \
    "\n" \
    "            pull;\n" \
    "            start;\n" \
    "            cancel;\n" \
    "            \n" \
    "            pull_(controller) {\n" \
    "                closer[0] = false;\n" \
    "                var result;\n" \
    "\n" \
    "                try {\n" \
    "                    result = pull(this, closer);\n" \
    "                } catch(err) {\n" \
    "                    return controller.error(err);\n" \
    "                }\n" \
    "\n" \
    "                 handleResult(result, controller);\n" \
    "            }\n" \
    "\n" \
    "            start_(controller) {\n" \
    "                setClose(this, controller.close);\n" \
    "                closer[0] = false;\n" \
    "                var result;\n" \
    "\n" \
    "                try {\n" \
    "                    result = start(this, closer);\n" \
    "                } catch(err) {\n" \
    "                    return controller.error(err);\n" \
    "                }\n" \
    "\n" \
    "                 handleResult(result, controller);\n" \
    "            }\n" \
    "\n" \
    "            cancel_(reason) {\n" \
    "                cancel(this, reason);\n" \
    "            }\n" \
    "\n" \
    "            static registry = new FinalizationRegistry(deinit);\n" \
    "        }\n" \
    "        cached.@set(nativeID, Prototype);\n" \
    "    }\n" \
    "    \n" \
    "    var instance = new Prototype(nativeTag);\n" \
    "    Prototype.registry.register(instance, nativeTag);\n" \
    "    var stream = new @ReadableStream(instance);\n" \
    "    @putByIdDirectPrivate(stream, \"bunNativeTag\", nativeID);\n" \
    "    return stream;\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamCancelCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamCancelCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamCancelCodeLength = 324;
static const JSC::Intrinsic s_readableStreamCancelCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamCancelCode =
    "(function (reason)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        return @Promise.@reject(@makeThisTypeError(\"ReadableStream\", \"cancel\"));\n" \
    "\n" \
    "    if (@isReadableStreamLocked(this))\n" \
    "        return @Promise.@reject(@makeTypeError(\"ReadableStream is locked\"));\n" \
    "\n" \
    "    return @readableStreamCancel(this, reason);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamGetReaderCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamGetReaderCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamGetReaderCodeLength = 476;
static const JSC::Intrinsic s_readableStreamGetReaderCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamGetReaderCode =
    "(function (options)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStream\", \"getReader\");\n" \
    "\n" \
    "    const mode = @toDictionary(options, { }, \"ReadableStream.getReader takes an object as first argument\").mode;\n" \
    "    if (mode === @undefined)\n" \
    "        return new @ReadableStreamDefaultReader(this);\n" \
    "\n" \
    "    //\n" \
    "    if (mode == 'byob')\n" \
    "        return new @ReadableStreamBYOBReader(this);\n" \
    "\n" \
    "    @throwTypeError(\"Invalid mode is specified\");\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamPipeThroughCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamPipeThroughCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamPipeThroughCodeLength = 1485;
static const JSC::Intrinsic s_readableStreamPipeThroughCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamPipeThroughCode =
    "(function (streams, options)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    const transforms = streams;\n" \
    "\n" \
    "    const readable = transforms[\"readable\"];\n" \
    "    if (!@isReadableStream(readable))\n" \
    "        throw @makeTypeError(\"readable should be ReadableStream\");\n" \
    "\n" \
    "    const writable = transforms[\"writable\"];\n" \
    "    const internalWritable = @getInternalWritableStream(writable);\n" \
    "    if (!@isWritableStream(internalWritable))\n" \
    "        throw @makeTypeError(\"writable should be WritableStream\");\n" \
    "\n" \
    "    let preventClose = false;\n" \
    "    let preventAbort = false;\n" \
    "    let preventCancel = false;\n" \
    "    let signal;\n" \
    "    if (!@isUndefinedOrNull(options)) {\n" \
    "        if (!@isObject(options))\n" \
    "            throw @makeTypeError(\"options must be an object\");\n" \
    "\n" \
    "        preventAbort = !!options[\"preventAbort\"];\n" \
    "        preventCancel = !!options[\"preventCancel\"];\n" \
    "        preventClose = !!options[\"preventClose\"];\n" \
    "\n" \
    "        signal = options[\"signal\"];\n" \
    "        if (signal !== @undefined && !@isAbortSignal(signal))\n" \
    "            throw @makeTypeError(\"options.signal must be AbortSignal\");\n" \
    "    }\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStream\", \"pipeThrough\");\n" \
    "\n" \
    "    if (@isReadableStreamLocked(this))\n" \
    "        throw @makeTypeError(\"ReadableStream is locked\");\n" \
    "\n" \
    "    if (@isWritableStreamLocked(internalWritable))\n" \
    "        throw @makeTypeError(\"WritableStream is locked\");\n" \
    "\n" \
    "    @readableStreamPipeToWritableStream(this, internalWritable, preventClose, preventAbort, preventCancel, signal);\n" \
    "\n" \
    "    return readable;\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamPipeToCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamPipeToCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamPipeToCodeLength = 1523;
static const JSC::Intrinsic s_readableStreamPipeToCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamPipeToCode =
    "(function (destination)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    //\n" \
    "    //\n" \
    "    let options = arguments[1];\n" \
    "\n" \
    "    let preventClose = false;\n" \
    "    let preventAbort = false;\n" \
    "    let preventCancel = false;\n" \
    "    let signal;\n" \
    "    if (!@isUndefinedOrNull(options)) {\n" \
    "        if (!@isObject(options))\n" \
    "            return @Promise.@reject(@makeTypeError(\"options must be an object\"));\n" \
    "\n" \
    "        try {\n" \
    "            preventAbort = !!options[\"preventAbort\"];\n" \
    "            preventCancel = !!options[\"preventCancel\"];\n" \
    "            preventClose = !!options[\"preventClose\"];\n" \
    "\n" \
    "            signal = options[\"signal\"];\n" \
    "        } catch(e) {\n" \
    "            return @Promise.@reject(e);\n" \
    "        }\n" \
    "\n" \
    "        if (signal !== @undefined && !@isAbortSignal(signal))\n" \
    "            return @Promise.@reject(@makeTypeError(\"options.signal must be AbortSignal\"));\n" \
    "    }\n" \
    "\n" \
    "    const internalDestination = @getInternalWritableStream(destination);\n" \
    "    if (!@isWritableStream(internalDestination))\n" \
    "        return @Promise.@reject(@makeTypeError(\"ReadableStream pipeTo requires a WritableStream\"));\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        return @Promise.@reject(@makeThisTypeError(\"ReadableStream\", \"pipeTo\"));\n" \
    "\n" \
    "    if (@isReadableStreamLocked(this))\n" \
    "        return @Promise.@reject(@makeTypeError(\"ReadableStream is locked\"));\n" \
    "\n" \
    "    if (@isWritableStreamLocked(internalDestination))\n" \
    "        return @Promise.@reject(@makeTypeError(\"WritableStream is locked\"));\n" \
    "\n" \
    "    return @readableStreamPipeToWritableStream(this, internalDestination, preventClose, preventAbort, preventCancel, signal);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamTeeCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamTeeCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamTeeCodeLength = 175;
static const JSC::Intrinsic s_readableStreamTeeCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamTeeCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStream\", \"tee\");\n" \
    "\n" \
    "    return @readableStreamTee(this, false);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamLockedCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamLockedCodeConstructorKind = JSC::ConstructorKind::None;
const int s_readableStreamLockedCodeLength = 178;
static const JSC::Intrinsic s_readableStreamLockedCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamLockedCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStream(this))\n" \
    "        throw @makeGetterTypeError(\"ReadableStream\", \"locked\");\n" \
    "\n" \
    "    return @isReadableStreamLocked(this);\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().readableStreamBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().readableStreamBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_READABLESTREAM_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
