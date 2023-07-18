
// AUTO-GENERATED FILE. DO NOT EDIT.
// Generated by 'make generate-sink' at 2023-07-18T09:07:30.318Z
//
#pragma once

#include "root.h"

#include "JSDOMWrapper.h"
#include "wtf/NeverDestroyed.h"

#include "Sink.h"

extern "C" bool JSSink_isSink(JSC::JSGlobalObject*, JSC::EncodedJSValue);

namespace WebCore {
using namespace JSC;

JSC_DECLARE_HOST_FUNCTION(functionStartDirectStream);
class JSArrayBufferSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSArrayBufferSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::ArrayBufferSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSArrayBufferSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSArrayBufferSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSArrayBufferSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSArrayBufferSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::ArrayBufferSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSArrayBufferSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSArrayBufferSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSArrayBufferSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableArrayBufferSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableArrayBufferSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::ArrayBufferSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableArrayBufferSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableArrayBufferSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableArrayBufferSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionArrayBufferSink__getter);

class JSFileSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSFileSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::FileSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSFileSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSFileSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSFileSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSFileSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::FileSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSFileSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSFileSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSFileSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableFileSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableFileSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::FileSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableFileSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableFileSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableFileSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionFileSink__getter);

class JSHTTPResponseSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSHTTPResponseSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::HTTPResponseSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSHTTPResponseSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSHTTPResponseSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSHTTPResponseSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSHTTPResponseSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::HTTPResponseSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSHTTPResponseSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSHTTPResponseSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSHTTPResponseSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableHTTPResponseSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableHTTPResponseSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::HTTPResponseSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableHTTPResponseSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableHTTPResponseSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableHTTPResponseSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionHTTPResponseSink__getter);

class JSHTTPSResponseSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSHTTPSResponseSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::HTTPSResponseSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSHTTPSResponseSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSHTTPSResponseSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSHTTPSResponseSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSHTTPSResponseSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::HTTPSResponseSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSHTTPSResponseSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSHTTPSResponseSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSHTTPSResponseSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableHTTPSResponseSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableHTTPSResponseSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::HTTPSResponseSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableHTTPSResponseSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableHTTPSResponseSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableHTTPSResponseSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionHTTPSResponseSink__getter);

class JSBrotliDecompressorSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSBrotliDecompressorSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::BrotliDecompressorSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSBrotliDecompressorSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSBrotliDecompressorSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSBrotliDecompressorSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSBrotliDecompressorSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::BrotliDecompressorSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSBrotliDecompressorSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSBrotliDecompressorSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSBrotliDecompressorSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableBrotliDecompressorSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableBrotliDecompressorSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::BrotliDecompressorSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableBrotliDecompressorSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableBrotliDecompressorSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableBrotliDecompressorSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionBrotliDecompressorSink__getter);

class JSBrotliCompressorSinkConstructor final : public JSC::InternalFunction {
public:
    using Base = JSC::InternalFunction;
    static JSBrotliCompressorSinkConstructor* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, JSC::JSObject* prototype);
    static constexpr SinkID Sink = SinkID::BrotliCompressorSink;

    static constexpr unsigned StructureFlags = Base::StructureFlags;
    static constexpr bool needsDestruction = false;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSBrotliCompressorSinkConstructor, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkConstructor = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkConstructor.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkConstructor = std::forward<decltype(space)>(space); });
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::InternalFunctionType, StructureFlags), info());
    }
    void initializeProperties(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);

    // Must be defined for each specialization class.
    static JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES construct(JSC::JSGlobalObject*, JSC::CallFrame*);

private:
    JSBrotliCompressorSinkConstructor(JSC::VM& vm, JSC::Structure* structure, JSC::NativeFunction nativeFunction)
        : Base(vm, structure, nativeFunction, nativeFunction)

    {
    }

    void finishCreation(JSC::VM&, JSC::JSGlobalObject* globalObject, JSC::JSObject* prototype);
};

class JSBrotliCompressorSink final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSBrotliCompressorSink* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::BrotliCompressorSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSBrotliCompressorSink, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSink = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSink.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSink = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSBrotliCompressorSink();

    void* wrapped() const { return m_sinkPtr; }
    DECLARE_VISIT_CHILDREN;

    void detach()
    {
        m_sinkPtr = nullptr;
    }

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void ref();
    void unref();

    void* m_sinkPtr;
    int m_refCount { 1 };

    JSBrotliCompressorSink(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

class JSReadableBrotliCompressorSinkController final : public JSC::JSDestructibleObject {
public:
    using Base = JSC::JSDestructibleObject;
    static JSReadableBrotliCompressorSinkController* create(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::Structure* structure, void* sinkPtr);
    static constexpr SinkID Sink = SinkID::BrotliCompressorSink;

    DECLARE_EXPORT_INFO;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<JSReadableBrotliCompressorSinkController, WebCore::UseCustomHeapCellType::No>(
            vm,
            [](auto& spaces) { return spaces.m_clientSubspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForJSSinkController = std::forward<decltype(space)>(space); },
            [](auto& spaces) { return spaces.m_subspaceForJSSinkController.get(); },
            [](auto& spaces, auto&& space) { spaces.m_subspaceForJSSinkController = std::forward<decltype(space)>(space); });
    }

    static void destroy(JSC::JSCell*);
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }
    static JSObject* createPrototype(VM& vm, JSDOMGlobalObject& globalObject);

    ~JSReadableBrotliCompressorSinkController();

    void* wrapped() const { return m_sinkPtr; }
    void detach();

    void start(JSC::JSGlobalObject* globalObject, JSC::JSValue readableStream, JSC::JSFunction* onPull, JSC::JSFunction* onClose);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

    void* m_sinkPtr;
    mutable WriteBarrier<JSC::JSFunction> m_onPull;
    mutable WriteBarrier<JSC::JSFunction> m_onClose;
    mutable JSC::Weak<JSObject> m_weakReadableStream;

    JSReadableBrotliCompressorSinkController(JSC::VM& vm, JSC::Structure* structure, void* sinkPtr)
        : Base(vm, structure)
    {
        m_sinkPtr = sinkPtr;
    }

    void finishCreation(JSC::VM&);
};

JSC_DECLARE_CUSTOM_GETTER(functionBrotliCompressorSink__getter);

JSObject* createJSSinkPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, WebCore::SinkID sinkID);
JSObject* createJSSinkControllerPrototype(JSC::VM& vm, JSC::JSGlobalObject* globalObject, WebCore::SinkID sinkID);
Structure* createJSSinkControllerStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, WebCore::SinkID sinkID);
} // namespace WebCore
