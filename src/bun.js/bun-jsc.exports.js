const jsc = globalThis[Symbol.for("Bun.lazy")]("bun:jsc");

export const callerSourceOrigin = jsc.callerSourceOrigin;
export const describe = jsc.describe;
export const describeArray = jsc.describeArray;
export const drainMicrotasks = jsc.drainMicrotasks;
export const edenGC = jsc.edenGC;
export const fullGC = jsc.fullGC;
export const gcAndSweep = jsc.gcAndSweep;
export const getRandomSeed = jsc.getRandomSeed;
export const heapSize = jsc.heapSize;
export const heapStats = jsc.heapStats;
export const isRope = jsc.isRope;
export const memoryUsage = jsc.memoryUsage;
export const noFTL = jsc.noFTL;
export const noOSRExitFuzzing = jsc.noOSRExitFuzzing;
export const numberOfDFGCompiles = jsc.numberOfDFGCompiles;
export const optimizeNextInvocation = jsc.optimizeNextInvocation;
export const releaseWeakRefs = jsc.releaseWeakRefs;
export const reoptimizationRetryCount = jsc.reoptimizationRetryCount;
export const setRandomSeed = jsc.setRandomSeed;
export const startRemoteDebugger = jsc.startRemoteDebugger;
export const totalCompileTime = jsc.totalCompileTime;
export const getProtectedObjects = jsc.getProtectedObjects;
export const generateHeapSnapshotForDebugging =
  jsc.generateHeapSnapshotForDebugging;
export default jsc;
