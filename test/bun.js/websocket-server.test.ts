import { file, serve } from "bun";
import { afterEach, describe, it, expect } from "bun:test";
import { readFileSync, writeSync } from "fs";
import { gcTick } from "gc";
import { resolve } from "path";

var port = 4321;
function getPort() {
  if (port > 4444) {
    port = 4321;
  }

  return port++;
}

describe("websocket server", () => {
  it("can do hello world", async () => {
    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {},
        message(ws, msg) {
          ws.send("hello world");
        },
      },
      fetch(req, server) {
        if (
          server.upgrade(req, {
            data: "hello world",

            // check that headers works
            headers: {
              "x-a": "text/plain",
            },
          })
        ) {
          if (server.upgrade(req)) {
            throw new Error("should not upgrade twice");
          }
          return;
        }

        return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      const websocket = new WebSocket(`ws://localhost:${server.port}`);
      websocket.onopen = () => {
        websocket.send("hello world");
      };
      websocket.onmessage = (e) => {
        try {
          expect(e.data).toBe("hello world");
          resolve();
        } catch (r) {
          reject(r);
          return;
        } finally {
          server?.stop();
          websocket.close();
        }
      };
      websocket.onerror = (e) => {
        reject(e);
      };
    });
  });

  it("binaryType works", async () => {
    var done = false;
    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {
          ws.send(ws.data);
        },
        message(ws, msg) {
          if (ws.binaryType === "uint8array") {
            expect(ws.binaryType).toBe("uint8array");
            ws.binaryType = "arraybuffer";
            expect(ws.binaryType).toBe("arraybuffer");
            expect(msg instanceof Uint8Array).toBe(true);
          } else {
            expect(ws.binaryType).toBe("arraybuffer");
            expect(msg instanceof ArrayBuffer).toBe(true);
            done = true;
          }

          ws.send("hello world");
        },
      },
      fetch(req, server) {
        if (server.upgrade(req, { data: "hello world" })) {
          if (server.upgrade(req)) {
            throw new Error("should not upgrade twice");
          }
          return;
        }

        return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      var counter = 0;
      const websocket = new WebSocket(`ws://localhost:${server.port}`);
      websocket.onopen = () => {
        websocket.send(Buffer.from("hello world"));
      };
      websocket.onmessage = (e) => {
        try {
          expect(e.data).toBe("hello world");

          if (counter++ > 0) {
            server?.stop();
            websocket.close();
            resolve(done);
          }
          websocket.send(Buffer.from("oaksd"));
        } catch (r) {
          server?.stop();
          websocket.close();
          reject(r);
          return;
        } finally {
        }
      };
      websocket.onerror = (e) => {
        reject(e);
      };
    });
  });

  it("does not upgrade for non-websocket connections", async () => {
    await new Promise(async (resolve, reject) => {
      var server = serve({
        port: getPort(),
        websocket: {
          open(ws) {
            ws.send("hello world");
          },
          message(ws, msg) {},
        },
        fetch(req, server) {
          if (server.upgrade(req)) {
            reject("should not upgrade");
          }

          return new Response("success");
        },
      });

      const response = await fetch(`http://localhost:${server.port}`);
      expect(await response.text()).toBe("success");
      resolve();
      server.stop();
    });
  });

  it("does not upgrade for non-websocket servers", async () => {
    await new Promise(async (resolve, reject) => {
      var server = serve({
        port: getPort(),

        fetch(req, server) {
          try {
            server.upgrade(req);
            reject("should not upgrade");
          } catch (e) {
            resolve();
          }

          return new Response("success");
        },
      });

      const response = await fetch(`http://localhost:${server.port}`);
      expect(await response.text()).toBe("success");
      resolve();
      server.stop();
    });
  });

  it("async can do hello world", async () => {
    var server = serve({
      port: getPort(),
      websocket: {
        async open(ws) {
          ws.send("hello world");
        },
        message(ws, msg) {},
      },
      async fetch(req, server) {
        await 1;
        if (server.upgrade(req)) return;

        return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      const websocket = new WebSocket(`ws://localhost:${server.port}`);

      websocket.onmessage = (e) => {
        try {
          expect(e.data).toBe("hello world");
          resolve();
        } catch (r) {
          reject(r);
          return;
        } finally {
          server?.stop();
          websocket.close();
        }
      };
      websocket.onerror = (e) => {
        reject(e);
      };
    });
  });

  it("can do hello world corked", async () => {
    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {
          ws.send("hello world");
        },
        message(ws, msg) {
          ws.cork(() => {
            ws.send("hello world");
          });
        },
      },
      fetch(req, server) {
        if (server.upgrade(req)) return;

        return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      const websocket = new WebSocket(`ws://localhost:${server.port}`);

      websocket.onmessage = (e) => {
        try {
          expect(e.data).toBe("hello world");
          resolve();
        } catch (r) {
          reject(r);
          return;
        } finally {
          server?.stop();
          websocket.close();
        }
      };
      websocket.onerror = (e) => {
        reject(e);
      };
    });
  });

  it("can do some back and forth", async () => {
    var dataCount = 0;
    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {},
        message(ws, msg) {
          if (msg === "first") {
            ws.send("first");
            return;
          }
          ws.send(`counter: ${dataCount++}`);
        },
      },
      fetch(req, server) {
        if (
          server.upgrade(req, {
            count: 0,
          })
        )
          return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      const websocket = new WebSocket(`ws://localhost:${server.port}`);
      websocket.onerror = (e) => {
        reject(e);
      };

      var counter = 0;
      websocket.onopen = () => websocket.send("first");
      websocket.onmessage = (e) => {
        try {
          switch (counter++) {
            case 0: {
              expect(e.data).toBe("first");
              websocket.send("where are the loops");
              break;
            }
            case 1: {
              expect(e.data).toBe("counter: 0");
              websocket.send("br0ther may i have some loops");
              break;
            }
            case 2: {
              expect(e.data).toBe("counter: 1");
              websocket.send("br0ther may i have some loops");
              break;
            }
            case 3: {
              expect(e.data).toBe("counter: 2");
              resolve();
              break;
            }
          }
        } catch (r) {
          reject(r);
          console.error(r);
          server?.stop();
          console.log("i am closing!");
          websocket.close();
          return;
        } finally {
        }
      };
    });
  });

  it("send rope strings", async () => {
    var ropey = "hello world".repeat(10);
    var sendQueue = [];
    for (var i = 0; i < 100; i++) {
      sendQueue.push(ropey + " " + i);
    }

    var serverCounter = 0;
    var clientCounter = 0;

    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {},
        message(ws, msg) {
          ws.send(sendQueue[serverCounter++] + " ");
          gcTick();
        },
      },
      fetch(req, server) {
        if (
          server.upgrade(req, {
            data: { count: 0 },
          })
        )
          return;

        return new Response("noooooo hello world");
      },
    });

    await new Promise((resolve, reject) => {
      const websocket = new WebSocket(`ws://localhost:${server.port}`);
      websocket.onerror = (e) => {
        reject(e);
      };

      var counter = 0;
      websocket.onopen = () => websocket.send("first");
      websocket.onmessage = (e) => {
        try {
          const expected = sendQueue[clientCounter++] + " ";
          expect(e.data).toBe(expected);
          websocket.send("next");
          if (clientCounter === sendQueue.length) {
            websocket.close();
            resolve();
          }
        } catch (r) {
          reject(r);
          console.error(r);
          server?.stop();
          websocket.close();
          return;
        } finally {
        }
      };
    });

    server?.stop();
  });

  // this test sends 100 messages to 10 connected clients via pubsub
  it("pub/sub", async () => {
    var ropey = "hello world".repeat(10);
    var sendQueue = [];
    for (var i = 0; i < 100; i++) {
      sendQueue.push(ropey + " " + i);
      gcTick();
    }
    var serverCounter = 0;
    var clientCount = 0;
    var server = serve({
      port: getPort(),
      websocket: {
        open(ws) {
          ws.subscribe("test");
          gcTick();
          if (!ws.isSubscribed("test")) {
            throw new Error("not subscribed");
          }
          ws.unsubscribe("test");
          if (ws.isSubscribed("test")) {
            throw new Error("subscribed");
          }
          ws.subscribe("test");
          clientCount++;
          if (clientCount === 10)
            setTimeout(() => ws.publish("test", "hello world"), 1);
        },
        message(ws, msg) {
          if (serverCounter < sendQueue.length)
            ws.publish("test", sendQueue[serverCounter++] + " ");
        },
      },
      fetch(req, server) {
        gcTick();

        if (
          server.upgrade(req, {
            data: { count: 0 },
          })
        )
          return;
        return new Response("noooooo hello world");
      },
    });

    const connections = new Array(10);
    const websockets = new Array(connections.length);
    var doneCounter = 0;
    await new Promise((done) => {
      for (var i = 0; i < connections.length; i++) {
        var j = i;
        var resolve, reject, resolveConnection, rejectConnection;
        connections[j] = new Promise((res, rej) => {
          resolveConnection = res;
          rejectConnection = rej;
        });
        websockets[j] = new Promise((res, rej) => {
          resolve = res;
          reject = rej;
        });
        gcTick();
        const websocket = new WebSocket(`ws://localhost:${server.port}`);
        websocket.onerror = (e) => {
          reject(e);
        };
        websocket.onclose = () => {
          doneCounter++;
          if (doneCounter === connections.length) {
            done();
          }
        };
        var hasOpened = false;
        websocket.onopen = () => {
          if (!hasOpened) {
            hasOpened = true;
            resolve(websocket);
          }
        };

        let clientCounter = -1;
        var hasSentThisTick = false;

        websocket.onmessage = (e) => {
          gcTick();

          if (!hasOpened) {
            hasOpened = true;
            resolve(websocket);
          }

          if (e.data === "hello world") {
            clientCounter = 0;
            websocket.send("first");
            return;
          }

          try {
            expect(!!sendQueue.find((a) => a + " " === e.data)).toBe(true);

            if (!hasSentThisTick) {
              websocket.send("second");
              hasSentThisTick = true;
              queueMicrotask(() => {
                hasSentThisTick = false;
              });
            }

            gcTick();

            if (clientCounter++ === sendQueue.length - 1) {
              websocket.close();
              resolveConnection();
            }
          } catch (r) {
            console.error(r);
            server?.stop();
            websocket.close();
            rejectConnection(r);
            gcTick();
            return;
          } finally {
          }
        };
      }
    });
    server?.stop();
    expect(serverCounter).toBe(sendQueue.length);
  });
});
