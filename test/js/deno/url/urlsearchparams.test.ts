// @bun-known-failing-on-windows: 32 failing
// GENERATED - DO NOT EDIT
// Copyright 2018+ the Deno authors. All rights reserved. MIT license.
// https://raw.githubusercontent.com/denoland/deno/main/cli/tests/unit/url_search_params_test.ts
import { createDenoTest } from "deno:harness";
const { test, assert, assertEquals } = createDenoTest(import.meta.path);
test(function urlSearchParamsWithMultipleSpaces() {
    const init = {
        str: "this string has spaces in it"
    };
    const searchParams = new URLSearchParams(init).toString();
    assertEquals(searchParams, "str=this+string+has+spaces+in+it");
});
test(function urlSearchParamsWithExclamation() {
    const init = [
        [
            "str",
            "hello, world!"
        ]
    ];
    const searchParams = new URLSearchParams(init).toString();
    assertEquals(searchParams, "str=hello%2C+world%21");
});
test(function urlSearchParamsWithQuotes() {
    const init = [
        [
            "str",
            "'hello world'"
        ]
    ];
    const searchParams = new URLSearchParams(init).toString();
    assertEquals(searchParams, "str=%27hello+world%27");
});
test(function urlSearchParamsWithBraket() {
    const init = [
        [
            "str",
            "(hello world)"
        ]
    ];
    const searchParams = new URLSearchParams(init).toString();
    assertEquals(searchParams, "str=%28hello+world%29");
});
test(function urlSearchParamsWithTilde() {
    const init = [
        [
            "str",
            "hello~world"
        ]
    ];
    const searchParams = new URLSearchParams(init).toString();
    assertEquals(searchParams, "str=hello%7Eworld");
});
test(function urlSearchParamsInitString() {
    const init = "c=4&a=2&b=3&%C3%A1=1";
    const searchParams = new URLSearchParams(init);
    assert(init === searchParams.toString(), "The init query string does not match");
});
test(function urlSearchParamsInitStringWithPlusCharacter() {
    let params = new URLSearchParams("q=a+b");
    assertEquals(params.toString(), "q=a+b");
    assertEquals(params.get("q"), "a b");
    params = new URLSearchParams("q=a+b+c");
    assertEquals(params.toString(), "q=a+b+c");
    assertEquals(params.get("q"), "a b c");
});
test(function urlSearchParamsInitStringWithMalformedParams() {
    let params = new URLSearchParams("id=0&value=%");
    assert(params != null, "constructor returned non-null value.");
    assert(params.has("id"), 'Search params object has name "id"');
    assert(params.has("value"), 'Search params object has name "value"');
    assertEquals(params.get("id"), "0");
    assertEquals(params.get("value"), "%");
    params = new URLSearchParams("b=%2sf%2a");
    assert(params != null, "constructor returned non-null value.");
    assert(params.has("b"), 'Search params object has name "b"');
    assertEquals(params.get("b"), "%2sf*");
    params = new URLSearchParams("b=%2%2af%2a");
    assert(params != null, "constructor returned non-null value.");
    assert(params.has("b"), 'Search params object has name "b"');
    assertEquals(params.get("b"), "%2*f*");
    params = new URLSearchParams("b=%%2a");
    assert(params != null, "constructor returned non-null value.");
    assert(params.has("b"), 'Search params object has name "b"');
    assertEquals(params.get("b"), "%*");
});
test(function urlSearchParamsInitIterable() {
    const init = [
        [
            "a",
            "54"
        ],
        [
            "b",
            "true"
        ]
    ];
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.toString(), "a=54&b=true");
});
test(function urlSearchParamsInitRecord() {
    const init = {
        a: "54",
        b: "true"
    };
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.toString(), "a=54&b=true");
});
test(function urlSearchParamsInit() {
    const params1 = new URLSearchParams("a=b");
    assertEquals(params1.toString(), "a=b");
    const params2 = new URLSearchParams(params1);
    assertEquals(params2.toString(), "a=b");
});
test(function urlSearchParamsAppendSuccess() {
    const searchParams = new URLSearchParams();
    searchParams.append("a", "true");
    assertEquals(searchParams.toString(), "a=true");
});
test(function urlSearchParamsDeleteSuccess() {
    const init = "a=54&b=true";
    const searchParams = new URLSearchParams(init);
    searchParams.delete("b");
    assertEquals(searchParams.toString(), "a=54");
});
test(function urlSearchParamsGetAllSuccess() {
    const init = "a=54&b=true&a=true";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.getAll("a"), [
        "54",
        "true"
    ]);
    assertEquals(searchParams.getAll("b"), [
        "true"
    ]);
    assertEquals(searchParams.getAll("c"), []);
});
test(function urlSearchParamsGetSuccess() {
    const init = "a=54&b=true&a=true";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.get("a"), "54");
    assertEquals(searchParams.get("b"), "true");
    assertEquals(searchParams.get("c"), null);
});
test(function urlSearchParamsHasSuccess() {
    const init = "a=54&b=true&a=true";
    const searchParams = new URLSearchParams(init);
    assert(searchParams.has("a"));
    assert(searchParams.has("b"));
    assert(!searchParams.has("c"));
});
test(function urlSearchParamsSetReplaceFirstAndRemoveOthers() {
    const init = "a=54&b=true&a=true";
    const searchParams = new URLSearchParams(init);
    searchParams.set("a", "false");
    assertEquals(searchParams.toString(), "a=false&b=true");
});
test(function urlSearchParamsSetAppendNew() {
    const init = "a=54&b=true&a=true";
    const searchParams = new URLSearchParams(init);
    searchParams.set("c", "foo");
    assertEquals(searchParams.toString(), "a=54&b=true&a=true&c=foo");
});
test(function urlSearchParamsSortSuccess() {
    const init = "c=4&a=2&b=3&a=1";
    const searchParams = new URLSearchParams(init);
    searchParams.sort();
    assertEquals(searchParams.toString(), "a=2&a=1&b=3&c=4");
});
test(function urlSearchParamsForEachSuccess() {
    const init = [
        [
            "a",
            "54"
        ],
        [
            "b",
            "true"
        ]
    ];
    const searchParams = new URLSearchParams(init);
    let callNum = 0;
    searchParams.forEach((value, key, parent)=>{
        assertEquals(searchParams, parent);
        assertEquals(value, init[callNum][1]);
        assertEquals(key, init[callNum][0]);
        callNum++;
    });
    assertEquals(callNum, init.length);
});
test(function urlSearchParamsMissingName() {
    const init = "=4";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.get(""), "4");
    assertEquals(searchParams.toString(), "=4");
});
test(function urlSearchParamsMissingValue() {
    const init = "4=";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.get("4"), "");
    assertEquals(searchParams.toString(), "4=");
});
test(function urlSearchParamsMissingEqualSign() {
    const init = "4";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.get("4"), "");
    assertEquals(searchParams.toString(), "4=");
});
test(function urlSearchParamsMissingPair() {
    const init = "c=4&&a=54&";
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.toString(), "c=4&a=54");
});
test(function urlSearchParamsForShortEncodedChar() {
    const init = {
        linefeed: "\n",
        tab: "\t"
    };
    const searchParams = new URLSearchParams(init);
    assertEquals(searchParams.toString(), "linefeed=%0A&tab=%09");
});
test(function urlSearchParamsShouldThrowTypeError() {
    let hasThrown = 0;
    try {
        new URLSearchParams([
            [
                "1"
            ]
        ]);
        hasThrown = 1;
    } catch (err) {
        if (err instanceof TypeError) {
            hasThrown = 2;
        } else {
            hasThrown = 3;
        }
    }
    assertEquals(hasThrown, 2);
    try {
        new URLSearchParams([
            [
                "1",
                "2",
                "3"
            ]
        ]);
        hasThrown = 1;
    } catch (err) {
        if (err instanceof TypeError) {
            hasThrown = 2;
        } else {
            hasThrown = 3;
        }
    }
    assertEquals(hasThrown, 2);
});
test(function urlSearchParamsAppendArgumentsCheck() {
    const methodRequireOneParam = [
        "delete",
        "getAll",
        "get",
        "has",
        "forEach"
    ];
    const methodRequireTwoParams = [
        "append",
        "set"
    ];
    methodRequireOneParam.concat(methodRequireTwoParams).forEach((method: string)=>{
        const searchParams = new URLSearchParams();
        let hasThrown = 0;
        try {
            (searchParams as any)[method]();
            hasThrown = 1;
        } catch (err) {
            if (err instanceof TypeError) {
                hasThrown = 2;
            } else {
                hasThrown = 3;
            }
        }
        assertEquals(hasThrown, 2);
    });
    methodRequireTwoParams.forEach((method: string)=>{
        const searchParams = new URLSearchParams();
        let hasThrown = 0;
        try {
            (searchParams as any)[method]("foo");
            hasThrown = 1;
        } catch (err) {
            if (err instanceof TypeError) {
                hasThrown = 2;
            } else {
                hasThrown = 3;
            }
        }
        assertEquals(hasThrown, 2);
    });
});
test(function urlSearchParamsDeletingAppendedMultiple() {
    const params = new URLSearchParams();
    params.append("first", (1 as unknown) as string);
    assert(params.has("first"));
    assertEquals(params.get("first"), "1");
    params.delete("first");
    assertEquals(params.has("first"), false);
    params.append("first", (1 as unknown) as string);
    params.append("first", (10 as unknown) as string);
    params.delete("first");
    assertEquals(params.has("first"), false);
});
test(function urlSearchParamsCustomSymbolIterator() {
    const params = new URLSearchParams();
    params[Symbol.iterator] = function*(): IterableIterator<[string, string]> {
        yield [
            "a",
            "b"
        ];
    };
    const params1 = new URLSearchParams((params as unknown) as string[][]);
    assertEquals(params1.get("a"), "b");
});
test(function urlSearchParamsCustomSymbolIteratorWithNonStringParams() {
    const params = {};
    (params as any)[Symbol.iterator] = function*(): IterableIterator<[number, number]> {
        yield [
            1,
            2
        ];
    };
    const params1 = new URLSearchParams((params as unknown) as string[][]);
    assertEquals(params1.get("1"), "2");
});
test(function urlSearchParamsOverridingAppendNotChangeConstructorAndSet() {
    let overridedAppendCalled = 0;
    class CustomSearchParams extends URLSearchParams {
        append(name: string, value: string) {
            ++overridedAppendCalled;
            super.append(name, value);
        }
    }
    new CustomSearchParams("foo=bar");
    new CustomSearchParams([
        [
            "foo",
            "bar"
        ]
    ]);
    new CustomSearchParams(new CustomSearchParams({
        foo: "bar"
    }));
    new CustomSearchParams().set("foo", "bar");
    assertEquals(overridedAppendCalled, 0);
});
test(function urlSearchParamsOverridingEntriesNotChangeForEach() {
    class CustomSearchParams extends URLSearchParams {
        *entries(): IterableIterator<[string, string]> {
            yield* [];
        }
    }
    let loopCount = 0;
    const params = new CustomSearchParams({
        foo: "bar"
    });
    params.forEach(()=>void ++loopCount);
    assertEquals(loopCount, 1);
});
