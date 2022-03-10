import {
__HMRClient as Bun
} from "http://localhost:3000/bun:wrap";
import {
__FastRefreshModule as FastHMR
} from "http://localhost:3000/bun:wrap";
import {
__FastRefreshRuntime as FastRefresh
} from "http://localhost:3000/bun:wrap";
Bun.activate(true);

var hmr = new FastHMR(635901064, "void-shouldnt-delete-call-expressions.js", FastRefresh), exports = hmr.exports;
(hmr._load = function() {
  var was_called = false;
  function thisShouldBeCalled() {
    was_called = true;
  }
  thisShouldBeCalled();
  function test() {
    if (!was_called)
      throw new Error("Expected thisShouldBeCalled to be called");
    return testDone(import.meta.url);
  }
  hmr.exportAll({
    test: () => test
  });
})();
var $$hmr_test = hmr.exports.test;
hmr._update = function(exports) {
  $$hmr_test = exports.test;
};

export {
  $$hmr_test as test
};

//# sourceMappingURL=http://localhost:3000/void-shouldnt-delete-call-expressions.js.map
