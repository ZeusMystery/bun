import type { BunFile } from 'bun';
import { version } from '../modules/bun.js';
import './console.js';
import './process.js';
import os from 'node:os';

//? NodeJS Blob doesn't implement these, so we need to polyfill them.
Blob.prototype.json = async function json<T>(this: Blob): Promise<T> {
    try {
        return JSON.parse(await this.text()) as T;
    } catch (err) {
        Error.captureStackTrace(err as Error, json);
        throw err;
    }
};
Reflect.set(Blob.prototype, 'readable', undefined /*satisfies BunFile['readable']*/);
Reflect.set(Blob.prototype, 'lastModified', -1 satisfies BunFile['lastModified']);
Reflect.set(Blob.prototype, 'exists', (async function exists() {
    return true;
}) satisfies BunFile['exists']);
Reflect.set(Blob.prototype, 'writer', (function writer() {
    throw new TypeError('Blob is detached');
}) satisfies BunFile['writer']);

//? navigator global object polyfill
Reflect.set(globalThis, 'navigator', {
    userAgent: `Bun/${version}`,
    hardwareConcurrency: os.cpus().length,
});

//? method only available in Bun
// this isn't quite accurate, but it shouldn't break anything and is currently here just for matching bun and node types
const ReadableStreamDefaultReaderPrototype = Object.getPrototypeOf(new ReadableStream().getReader());
Reflect.set(
    ReadableStreamDefaultReaderPrototype, 'readMany',
    function readMany(this: ReadableStreamDefaultReader): Promise<ReadableStreamDefaultReadManyResult<any>> {
        return new Promise((resolve, reject) => {
            const result: ReadableStreamDefaultReadManyResult<any> = {
                value: [],
                size: 0,
                done: true
            };
            this.read().then(({ done, value }) => {
                if (done) resolve(result);
                else {
                    result.value.push(value);
                    result.size = value.length;
                    result.done = false;
                    resolve(result);
                }
            }, reject);
        });
    }
);
