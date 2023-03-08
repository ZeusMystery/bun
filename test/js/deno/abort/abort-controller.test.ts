// Updated: Wed, 08 Mar 2023 00:55:15 GMT
// URL: https://raw.githubusercontent.com/denoland/deno/main/cli/tests/unit/abort_controller_test.ts
// Copyright 2018-2023 the Deno authors. All rights reserved. MIT license.

import { assert, assertEquals } from "deno:harness";

Deno.test(function basicAbortController() {
  const controller = new AbortController();
  assert(controller);
  const { signal } = controller;
  assert(signal);
  assertEquals(signal.aborted, false);
  controller.abort();
  assertEquals(signal.aborted, true);
});

Deno.test(function signalCallsOnabort() {
  const controller = new AbortController();
  const { signal } = controller;
  let called = false;
  signal.onabort = evt => {
    assert(evt);
    assertEquals(evt.type, "abort");
    called = true;
  };
  controller.abort();
  assert(called);
});

Deno.test(function signalEventListener() {
  const controller = new AbortController();
  const { signal } = controller;
  let called = false;
  signal.addEventListener("abort", function (ev) {
    assert(this === signal);
    assertEquals(ev.type, "abort");
    called = true;
  });
  controller.abort();
  assert(called);
});

Deno.test(function onlyAbortsOnce() {
  const controller = new AbortController();
  const { signal } = controller;
  let called = 0;
  signal.addEventListener("abort", () => called++);
  signal.onabort = () => {
    called++;
  };
  controller.abort();
  assertEquals(called, 2);
  controller.abort();
  assertEquals(called, 2);
});

Deno.test(function controllerHasProperToString() {
  const actual = Object.prototype.toString.call(new AbortController());
  assertEquals(actual, "[object AbortController]");
});

Deno.test(function abortReason() {
  const signal = AbortSignal.abort("hey!");
  assertEquals(signal.aborted, true);
  assertEquals(signal.reason, "hey!");
});
