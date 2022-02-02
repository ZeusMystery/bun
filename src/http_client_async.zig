const picohttp = @import("picohttp");
const _global = @import("./global.zig");
const string = _global.string;
const Output = _global.Output;
const Global = _global.Global;
const Environment = _global.Environment;
const strings = _global.strings;
const MutableString = _global.MutableString;
const FeatureFlags = _global.FeatureFlags;
const stringZ = _global.stringZ;
const C = _global.C;
const std = @import("std");
const URL = @import("./query_string_map.zig").URL;
const Method = @import("./http/method.zig").Method;
const Api = @import("./api/schema.zig").Api;
const Lock = @import("./lock.zig").Lock;
const HTTPClient = @This();
const Zlib = @import("./zlib.zig");
const StringBuilder = @import("./string_builder.zig");
const AsyncIO = @import("io");
const ThreadPool = @import("thread_pool");
const boring = @import("boringssl");
pub const NetworkThread = @import("./network_thread.zig");
const ObjectPool = @import("./pool.zig").ObjectPool;
const SOCK = os.SOCK;
const Arena = @import("./mimalloc_arena.zig").Arena;
const AsyncMessage = @import("./http/async_message.zig");
const AsyncBIO = @import("./http/async_bio.zig");
const AsyncSocket = @import("./http/async_socket.zig");
const ZlibPool = @import("./http/zlib.zig");
const URLBufferPool = ObjectPool([4096]u8, null, false);

// This becomes Arena.allocator
pub var default_allocator: std.mem.Allocator = undefined;
pub var default_arena: Arena = undefined;

pub fn onThreadStart() void {
    default_arena = Arena.init() catch unreachable;
    default_allocator = default_arena.allocator();
    NetworkThread.address_list_cached = NetworkThread.AddressListCache.init(default_allocator);
    AsyncIO.global = AsyncIO.init(1024, 0) catch |err| {
        Output.prettyErrorln("<r><red>error<r>: Failed to initialize network thread: <red><b>{s}<r>.\nHTTP requests will not work. Please file an issue and run strace().", .{@errorName(err)});
        Output.flush();
        os.exit(1);
    };

    AsyncIO.global_loaded = true;
    NetworkThread.global.pool.io = &AsyncIO.global;
    Global.setThreadName("HTTP");
}

pub inline fn getAllocator() std.mem.Allocator {
    return default_allocator;
}

pub const Headers = @import("./http/headers.zig");

pub const SOCKET_FLAGS: u32 = if (Environment.isLinux)
    SOCK.CLOEXEC | os.MSG.NOSIGNAL
else
    SOCK.CLOEXEC;

pub const OPEN_SOCKET_FLAGS = SOCK.CLOEXEC;

pub const extremely_verbose = Environment.isDebug;

fn writeRequest(
    comptime Writer: type,
    writer: Writer,
    request: picohttp.Request,
    body: string,
    // header_hashes: []u64,
) !void {
    _ = writer.write(request.method);
    _ = writer.write(" ");
    _ = writer.write(request.path);
    _ = writer.write(" HTTP/1.1\r\n");

    for (request.headers) |header| {
        _ = writer.write(header.name);
        _ = writer.write(": ");
        _ = writer.write(header.value);
        _ = writer.write("\r\n");
    }

    _ = writer.write("\r\n");

    if (body.len > 0) {
        _ = writer.write(body);
    }
}

method: Method,
header_entries: Headers.Entries,
header_buf: string,
url: URL,
allocator: std.mem.Allocator,
verbose: bool = Environment.isTest,
tcp_client: tcp.Client = undefined,
body_size: u32 = 0,
read_count: u32 = 0,
remaining_redirect_count: i8 = 127,
redirect: ?*URLBufferPool.Node = null,
disable_shutdown: bool = true,
timeout: usize = 0,
progress_node: ?*std.Progress.Node = null,
socket: AsyncSocket.SSL = undefined,
gzip_elapsed: u64 = 0,
stage: Stage = Stage.pending,

/// Some HTTP servers (such as npm) report Last-Modified times but ignore If-Modified-Since.
/// This is a workaround for that.
force_last_modified: bool = false,
if_modified_since: string = "",
request_content_len_buf: ["-4294967295".len]u8 = undefined,
request_headers_buf: [128]picohttp.Header = undefined,
response_headers_buf: [128]picohttp.Header = undefined,

pub fn init(
    allocator: std.mem.Allocator,
    method: Method,
    url: URL,
    header_entries: Headers.Entries,
    header_buf: string,
) !HTTPClient {
    return HTTPClient{
        .allocator = allocator,
        .method = method,
        .url = url,
        .header_entries = header_entries,
        .header_buf = header_buf,
        .socket = undefined,
    };
}

pub fn deinit(this: *HTTPClient) !void {
    if (this.redirect) |redirect| {
        redirect.release();
        this.redirect = null;
    }
}

const Stage = enum(u8) {
    pending,
    connect,
    request,
    response,
    done,
};

// threadlocal var resolver_cache
const tcp = std.x.net.tcp;
const ip = std.x.net.ip;

const IPv4 = std.x.os.IPv4;
const IPv6 = std.x.os.IPv6;
const Socket = std.x.os.Socket;
const os = std.os;

// lowercase hash header names so that we can be sure
pub fn hashHeaderName(name: string) u64 {
    var hasher = std.hash.Wyhash.init(0);
    var remain: string = name;
    var buf: [32]u8 = undefined;
    var buf_slice: []u8 = std.mem.span(&buf);

    while (remain.len > 0) {
        var end = std.math.min(hasher.buf.len, remain.len);

        hasher.update(strings.copyLowercase(std.mem.span(remain[0..end]), buf_slice));
        remain = remain[end..];
    }

    return hasher.final();
}

const host_header_hash = hashHeaderName("Host");
const connection_header_hash = hashHeaderName("Connection");

pub const Encoding = enum {
    identity,
    gzip,
    deflate,
    brotli,
    chunked,
};

const content_encoding_hash = hashHeaderName("Content-Encoding");
const transfer_encoding_header = hashHeaderName("Transfer-Encoding");

const host_header_name = "Host";
const content_length_header_name = "Content-Length";
const content_length_header_hash = hashHeaderName("Content-Length");
const connection_header = picohttp.Header{ .name = "Connection", .value = "close" };
const accept_header = picohttp.Header{ .name = "Accept", .value = "*/*" };
const accept_header_hash = hashHeaderName("Accept");

const accept_encoding_no_compression = "identity";
const accept_encoding_compression = "deflate, gzip";
const accept_encoding_header_compression = picohttp.Header{ .name = "Accept-Encoding", .value = accept_encoding_compression };
const accept_encoding_header_no_compression = picohttp.Header{ .name = "Accept-Encoding", .value = accept_encoding_no_compression };

const accept_encoding_header = if (FeatureFlags.disable_compression_in_http_client)
    accept_encoding_header_no_compression
else
    accept_encoding_header_compression;

const accept_encoding_header_hash = hashHeaderName("Accept-Encoding");

const user_agent_header = picohttp.Header{ .name = "User-Agent", .value = "bun.js " ++ Global.package_json_version };
const user_agent_header_hash = hashHeaderName("User-Agent");
const location_header_hash = hashHeaderName("Location");

pub fn headerStr(this: *const HTTPClient, ptr: Api.StringPointer) string {
    return this.header_buf[ptr.offset..][0..ptr.length];
}

pub const HeaderBuilder = @import("./http/header_builder.zig");

pub const HTTPChannel = @import("./sync.zig").Channel(*AsyncHTTP, .{ .Static = 1000 });
// 32 pointers much cheaper than 1000 pointers
const SingleHTTPChannel = struct {
    const SingleHTTPCHannel_ = @import("./sync.zig").Channel(*AsyncHTTP, .{ .Static = 8 });
    channel: SingleHTTPCHannel_,
    pub fn reset(_: *@This()) void {}
    pub fn init() SingleHTTPChannel {
        return SingleHTTPChannel{ .channel = SingleHTTPCHannel_.init() };
    }
};

pub const HTTPChannelContext = struct {
    http: AsyncHTTP = undefined,
    channel: *HTTPChannel,

    pub fn callback(http: *AsyncHTTP, sender: *AsyncHTTP.HTTPSender) void {
        var this: *HTTPChannelContext = @fieldParentPtr(HTTPChannelContext, "http", http);
        this.channel.writeItem(http) catch unreachable;
        sender.onFinish();
    }
};

pub const AsyncHTTP = struct {
    request: ?picohttp.Request = null,
    response: ?picohttp.Response = null,
    request_headers: Headers.Entries = Headers.Entries{},
    response_headers: Headers.Entries = Headers.Entries{},
    response_buffer: *MutableString,
    request_body: *MutableString,
    allocator: std.mem.Allocator,
    request_header_buf: string = "",
    method: Method = Method.GET,
    max_retry_count: u32 = 0,
    url: URL,

    /// Timeout in nanoseconds
    timeout: usize = 0,

    response_encoding: Encoding = Encoding.identity,
    redirect_count: u32 = 0,
    retries_count: u32 = 0,
    verbose: bool = false,

    client: HTTPClient = undefined,
    err: ?anyerror = null,

    state: AtomicState = AtomicState.init(State.pending),
    elapsed: u64 = 0,
    gzip_elapsed: u64 = 0,

    /// Callback runs when request finishes
    /// Executes on the network thread
    callback: ?CompletionCallback = null,
    callback_ctx: ?*anyopaque = null,

    pub const CompletionCallback = fn (this: *AsyncHTTP, sender: *HTTPSender) void;
    pub var active_requests_count = std.atomic.Atomic(u32).init(0);
    pub var max_simultaneous_requests: u16 = 32;

    pub const State = enum(u32) {
        pending = 0,
        scheduled = 1,
        sending = 2,
        success = 3,
        fail = 4,
    };
    const AtomicState = std.atomic.Atomic(State);

    pub fn init(
        allocator: std.mem.Allocator,
        method: Method,
        url: URL,
        headers: Headers.Entries,
        headers_buf: string,
        response_buffer: *MutableString,
        request_body: *MutableString,
        timeout: usize,
    ) !AsyncHTTP {
        var this = AsyncHTTP{
            .allocator = allocator,
            .url = url,
            .method = method,
            .request_headers = headers,
            .request_header_buf = headers_buf,
            .request_body = request_body,
            .response_buffer = response_buffer,
        };
        this.client = try HTTPClient.init(allocator, method, url, headers, headers_buf);
        this.client.timeout = timeout;
        this.timeout = timeout;
        return this;
    }

    pub fn schedule(this: *AsyncHTTP, allocator: std.mem.Allocator, batch: *ThreadPool.Batch) void {
        std.debug.assert(NetworkThread.global_loaded.load(.Monotonic) == 1);
        var sender = HTTPSender.get(this, allocator);
        this.state.store(.scheduled, .Monotonic);
        batch.push(ThreadPool.Batch.from(&sender.task));
    }

    fn sendSyncCallback(this: *AsyncHTTP, sender: *HTTPSender) void {
        var single_http_channel = @ptrCast(*SingleHTTPChannel, @alignCast(@alignOf(*SingleHTTPChannel), this.callback_ctx.?));
        single_http_channel.channel.writeItem(this) catch unreachable;
        sender.release();
    }

    pub fn sendSync(this: *AsyncHTTP, comptime _: bool) anyerror!picohttp.Response {
        if (this.callback_ctx == null) {
            var ctx = try _global.default_allocator.create(SingleHTTPChannel);
            ctx.* = SingleHTTPChannel.init();
            this.callback_ctx = ctx;
        } else {
            var ctx = @ptrCast(*SingleHTTPChannel, @alignCast(@alignOf(*SingleHTTPChannel), this.callback_ctx.?));
            ctx.* = SingleHTTPChannel.init();
        }

        this.callback = sendSyncCallback;

        var batch = NetworkThread.Batch{};
        this.schedule(_global.default_allocator, &batch);
        NetworkThread.global.pool.schedule(batch);
        while (true) {
            var data = @ptrCast(*SingleHTTPChannel, @alignCast(@alignOf(*SingleHTTPChannel), this.callback_ctx.?));
            var async_http: *AsyncHTTP = data.channel.readItem() catch unreachable;
            if (async_http.err) |err| {
                return err;
            }

            return async_http.response.?;
        }

        unreachable;
    }

    var http_sender_head: std.atomic.Atomic(?*HTTPSender) = std.atomic.Atomic(?*HTTPSender).init(null);

    pub const HTTPSender = struct {
        task: ThreadPool.Task = .{ .callback = callback },
        frame: @Frame(AsyncHTTP.do) = undefined,
        http: *AsyncHTTP = undefined,

        next: ?*HTTPSender = null,

        pub fn get(http: *AsyncHTTP, allocator: std.mem.Allocator) *HTTPSender {
            @fence(.Acquire);

            var head_ = http_sender_head.load(.Monotonic);

            if (head_ == null) {
                var new_head = allocator.create(HTTPSender) catch unreachable;
                new_head.* = HTTPSender{};
                new_head.next = null;
                new_head.task = .{ .callback = callback };
                new_head.http = http;
                return new_head;
            }

            http_sender_head.store(head_.?.next, .Monotonic);

            head_.?.* = HTTPSender{};
            head_.?.next = null;
            head_.?.task = .{ .callback = callback };
            head_.?.http = http;

            return head_.?;
        }

        pub fn release(this: *HTTPSender) void {
            @fence(.Acquire);
            this.task = .{ .callback = callback };
            this.http = undefined;
            this.next = http_sender_head.swap(this, .Monotonic);
        }

        pub fn callback(task: *ThreadPool.Task) void {
            var this = @fieldParentPtr(HTTPSender, "task", task);
            this.frame = async AsyncHTTP.do(this);
        }

        pub fn onFinish(this: *HTTPSender) void {
            this.release();
        }
    };

    pub fn do(sender: *HTTPSender) void {
        outer: {
            var this = sender.http;
            this.err = null;
            this.state.store(.sending, .Monotonic);
            var timer = std.time.Timer.start() catch @panic("Timer failure");
            defer this.elapsed = timer.read();
            _ = active_requests_count.fetchAdd(1, .Monotonic);

            this.response = await this.client.sendAsync(this.request_body.list.items, this.response_buffer) catch |err| {
                _ = active_requests_count.fetchSub(1, .Monotonic);
                this.state.store(.fail, .Monotonic);
                this.err = err;

                if (sender.http.max_retry_count > sender.http.retries_count) {
                    sender.http.retries_count += 1;
                    NetworkThread.global.pool.schedule(ThreadPool.Batch.from(&sender.task));
                    return;
                }
                break :outer;
            };

            this.redirect_count = @intCast(u32, @maximum(127 - this.client.remaining_redirect_count, 0));
            this.state.store(.success, .Monotonic);
            this.gzip_elapsed = this.client.gzip_elapsed;
            _ = active_requests_count.fetchSub(1, .Monotonic);
        }

        if (sender.http.callback) |callback| {
            callback(sender.http, sender);
        }
    }
};

pub fn buildRequest(this: *HTTPClient, body_len: usize) picohttp.Request {
    var header_count: usize = 0;
    var header_entries = this.header_entries.slice();
    var header_names = header_entries.items(.name);
    var header_values = header_entries.items(.value);
    var request_headers_buf = &this.request_headers_buf;

    var override_accept_encoding = false;
    var override_accept_header = false;

    var override_user_agent = false;
    for (header_names) |head, i| {
        const name = this.headerStr(head);
        // Hash it as lowercase
        const hash = hashHeaderName(name);

        // Skip host and connection header
        // we manage those
        switch (hash) {
            host_header_hash,
            connection_header_hash,
            content_length_header_hash,
            => continue,
            hashHeaderName("if-modified-since") => {
                if (this.force_last_modified and this.if_modified_since.len == 0) {
                    this.if_modified_since = this.headerStr(header_values[i]);
                }
            },
            accept_header_hash => {
                override_accept_header = true;
            },
            else => {},
        }

        override_user_agent = override_user_agent or hash == user_agent_header_hash;

        override_accept_encoding = override_accept_encoding or hash == accept_encoding_header_hash;

        request_headers_buf[header_count] = (picohttp.Header{
            .name = name,
            .value = this.headerStr(header_values[i]),
        });

        // header_name_hashes[header_count] = hash;

        // // ensure duplicate headers come after each other
        // if (header_count > 2) {
        //     var head_i: usize = header_count - 1;
        //     while (head_i > 0) : (head_i -= 1) {
        //         if (header_name_hashes[head_i] == header_name_hashes[header_count]) {
        //             std.mem.swap(picohttp.Header, &header_name_hashes[header_count], &header_name_hashes[head_i + 1]);
        //             std.mem.swap(u64, &request_headers_buf[header_count], &request_headers_buf[head_i + 1]);
        //             break;
        //         }
        //     }
        // }
        header_count += 1;
    }

    // request_headers_buf[header_count] = connection_header;
    // header_count += 1;

    if (!override_user_agent) {
        request_headers_buf[header_count] = user_agent_header;
        header_count += 1;
    }

    if (!override_accept_header) {
        request_headers_buf[header_count] = accept_header;
        header_count += 1;
    }

    request_headers_buf[header_count] = picohttp.Header{
        .name = host_header_name,
        .value = this.url.hostname,
    };
    header_count += 1;

    if (!override_accept_encoding) {
        request_headers_buf[header_count] = accept_encoding_header;
        header_count += 1;
    }

    if (body_len > 0) {
        request_headers_buf[header_count] = picohttp.Header{
            .name = content_length_header_name,
            .value = std.fmt.bufPrint(&this.request_content_len_buf, "{d}", .{body_len}) catch "0",
        };
        header_count += 1;
    }

    return picohttp.Request{
        .method = @tagName(this.method),
        .path = this.url.pathname,
        .minor_version = 1,
        .headers = request_headers_buf[0..header_count],
    };
}

pub fn connect(
    this: *HTTPClient,
    comptime ConnectType: type,
    connector: ConnectType,
) !void {
    const port = this.url.getPortAuto();

    try connector.connect(this.url.hostname, port);
    var client = std.x.net.tcp.Client{ .socket = std.x.os.Socket.from(this.socket.socket.socket) };
    // client.setQuickACK(true) catch {};

    this.tcp_client = client;
    if (this.timeout > 0) {
        client.setReadTimeout(@truncate(u32, this.timeout / std.time.ns_per_ms)) catch {};
        client.setWriteTimeout(@truncate(u32, this.timeout / std.time.ns_per_ms)) catch {};
    }
}

pub fn sendAsync(this: *HTTPClient, body: []const u8, body_out_str: *MutableString) @Frame(HTTPClient.send) {
    return async this.send(body, body_out_str);
}

pub fn send(this: *HTTPClient, body: []const u8, body_out_str: *MutableString) !picohttp.Response {
    defer if (@enumToInt(this.stage) > @enumToInt(Stage.pending)) this.socket.deinit();
    // this prevents stack overflow
    redirect: while (this.remaining_redirect_count >= -1) {
        if (@enumToInt(this.stage) > @enumToInt(Stage.pending)) this.socket.deinit();

        this.stage = Stage.pending;
        body_out_str.reset();

        if (this.url.isHTTPS()) {
            return this.sendHTTPS(body, body_out_str) catch |err| {
                switch (err) {
                    error.Redirect => {
                        this.remaining_redirect_count -= 1;

                        continue :redirect;
                    },
                    else => return err,
                }
            };
        } else {
            return this.sendHTTP(body, body_out_str) catch |err| {
                switch (err) {
                    error.Redirect => {
                        this.remaining_redirect_count -= 1;

                        continue :redirect;
                    },
                    else => return err,
                }
            };
        }
    }

    return error.TooManyRedirects;
}

const Task = ThreadPool.Task;

pub fn sendHTTP(this: *HTTPClient, body: []const u8, body_out_str: *MutableString) !picohttp.Response {
    this.socket = AsyncSocket.SSL{
        .socket = try AsyncSocket.init(&AsyncIO.global, 0, default_allocator),
    };
    this.stage = Stage.connect;
    var socket = &this.socket.socket;
    try this.connect(*AsyncSocket, socket);
    this.stage = Stage.request;
    defer this.socket.close();
    var request = buildRequest(this, body.len);
    if (this.verbose) {
        Output.prettyErrorln("{s}", .{request});
    }

    try writeRequest(@TypeOf(socket), socket, request, body);
    _ = try socket.send();
    this.stage = Stage.response;
    if (this.progress_node == null) {
        return this.processResponse(
            false,
            @TypeOf(socket),
            socket,
            body_out_str,
        );
    } else {
        return this.processResponse(
            true,
            @TypeOf(socket),
            socket,
            body_out_str,
        );
    }
}

pub fn processResponse(this: *HTTPClient, comptime report_progress: bool, comptime Client: type, client: Client, body_out_str: *MutableString) !picohttp.Response {
    defer if (this.verbose) Output.flush();
    var response: picohttp.Response = undefined;
    var request_message = AsyncMessage.get(default_allocator);
    defer request_message.release();
    var request_buffer: []u8 = request_message.buf;
    var read_length: usize = 0;
    {
        var read_headers_up_to: usize = 0;

        var req_buf_read: usize = std.math.maxInt(usize);
        defer this.read_count += @intCast(u32, read_length);

        restart: while (req_buf_read != 0) {
            req_buf_read = try client.read(request_buffer, read_length);
            read_length += req_buf_read;
            if (comptime report_progress) {
                this.progress_node.?.activate();
                this.progress_node.?.setCompletedItems(read_length);
                this.progress_node.?.context.maybeRefresh();
            }

            var request_body = request_buffer[0..read_length];
            read_headers_up_to = if (read_headers_up_to > read_length) read_length else read_headers_up_to;

            response = picohttp.Response.parseParts(request_body, &this.response_headers_buf, &read_headers_up_to) catch |err| {
                switch (err) {
                    error.ShortRead => {
                        continue :restart;
                    },
                    else => {
                        return err;
                    },
                }
            };
            break :restart;
        }
    }
    if (read_length == 0) {
        return error.NoData;
    }

    body_out_str.reset();
    var content_length: u32 = 0;
    var encoding = Encoding.identity;
    var transfer_encoding = Encoding.identity;

    var location: string = "";

    var pretend_its_304 = false;

    for (response.headers) |header| {
        switch (hashHeaderName(header.name)) {
            content_length_header_hash => {
                content_length = std.fmt.parseInt(u32, header.value, 10) catch 0;
                try body_out_str.inflate(content_length);
                body_out_str.list.expandToCapacity();
                this.body_size = content_length;
            },
            content_encoding_hash => {
                if (strings.eqlComptime(header.value, "gzip")) {
                    encoding = Encoding.gzip;
                } else if (strings.eqlComptime(header.value, "deflate")) {
                    encoding = Encoding.deflate;
                } else if (!strings.eqlComptime(header.value, "identity")) {
                    return error.UnsupportedContentEncoding;
                }
            },
            transfer_encoding_header => {
                if (strings.eqlComptime(header.value, "gzip")) {
                    transfer_encoding = Encoding.gzip;
                } else if (strings.eqlComptime(header.value, "deflate")) {
                    transfer_encoding = Encoding.deflate;
                } else if (strings.eqlComptime(header.value, "identity")) {
                    transfer_encoding = Encoding.identity;
                } else if (strings.eqlComptime(header.value, "chunked")) {
                    transfer_encoding = Encoding.chunked;
                } else {
                    return error.UnsupportedTransferEncoding;
                }
            },
            location_header_hash => {
                location = header.value;
            },
            hashHeaderName("Last-Modified") => {
                if (this.force_last_modified and response.status_code > 199 and response.status_code < 300 and this.if_modified_since.len > 0) {
                    if (strings.eql(this.if_modified_since, header.value)) {
                        pretend_its_304 = true;
                    }
                }
            },

            else => {},
        }
    }

    if (this.verbose) {
        Output.prettyErrorln("Response: {s}", .{response});
    }

    if (location.len > 0 and this.remaining_redirect_count > 0) {
        switch (response.status_code) {
            302, 301, 307, 308, 303 => {
                if (strings.indexOf(location, "://")) |i| {
                    var url_buf = this.redirect orelse URLBufferPool.get(default_allocator);

                    const protocol_name = location[0..i];
                    if (strings.eqlComptime(protocol_name, "http") or strings.eqlComptime(protocol_name, "https")) {} else {
                        return error.UnsupportedRedirectProtocol;
                    }

                    std.mem.copy(u8, &url_buf.data, location);
                    this.url = URL.parse(url_buf.data[0..location.len]);
                    this.redirect = url_buf;
                } else {
                    var url_buf = URLBufferPool.get(default_allocator);
                    const original_url = this.url;
                    this.url = URL.parse(std.fmt.bufPrint(
                        &url_buf.data,
                        "{s}://{s}{s}",
                        .{ original_url.displayProtocol(), original_url.displayHostname(), location },
                    ) catch return error.RedirectURLTooLong);

                    if (this.redirect) |red| {
                        red.release();
                    }

                    this.redirect = url_buf;
                }

                // Ensure we don't up ove

                // https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/303
                if (response.status_code == 303) {
                    this.method = .GET;
                }

                return error.Redirect;
            },
            else => {},
        }
    }

    body_getter: {
        if (pretend_its_304) {
            response.status_code = 304;
        }

        if (response.status_code == 304) break :body_getter;

        if (transfer_encoding == Encoding.chunked) {
            var decoder = std.mem.zeroes(picohttp.phr_chunked_decoder);
            var buffer_: *MutableString = body_out_str;

            switch (encoding) {
                Encoding.gzip, Encoding.deflate => {
                    if (!ZlibPool.loaded) {
                        ZlibPool.instance = ZlibPool.init(default_allocator);
                        ZlibPool.loaded = true;
                    }

                    buffer_ = try ZlibPool.instance.get();
                },
                else => {},
            }

            var buffer = buffer_.*;

            var last_read: usize = 0;
            {
                var remainder = request_buffer[@intCast(usize, response.bytes_read)..read_length];
                last_read = remainder.len;
                try buffer.inflate(std.math.max(remainder.len, 2048));
                buffer.list.expandToCapacity();
                std.mem.copy(u8, buffer.list.items, remainder);
            }

            // set consume_trailer to 1 to discard the trailing header
            // using content-encoding per chunk is not supported
            decoder.consume_trailer = 1;

            // these variable names are terrible
            // it's copypasta from https://github.com/h2o/picohttpparser#phr_decode_chunked
            // (but ported from C -> zig)
            var rret: usize = 0;
            var rsize: usize = last_read;
            var pret: isize = picohttp.phr_decode_chunked(&decoder, buffer.list.items.ptr, &rsize);
            var total_size = rsize;

            while (pret == -2) {
                if (buffer.list.items[total_size..].len < @intCast(usize, decoder.bytes_left_in_chunk) or buffer.list.items[total_size..].len < 512) {
                    try buffer.inflate(std.math.max(total_size * 2, 1024));
                    buffer.list.expandToCapacity();
                }

                rret = try client.read(buffer.list.items, total_size);

                if (rret == 0) {
                    return error.ChunkedEncodingError;
                }

                rsize = rret;
                pret = picohttp.phr_decode_chunked(&decoder, buffer.list.items[total_size..].ptr, &rsize);
                if (pret == -1) return error.ChunkedEncodingParseError;

                total_size += rsize;

                if (comptime report_progress) {
                    this.progress_node.?.activate();
                    this.progress_node.?.setCompletedItems(total_size);
                    this.progress_node.?.context.maybeRefresh();
                }
            }

            buffer.list.shrinkRetainingCapacity(total_size);
            buffer_.* = buffer;

            switch (encoding) {
                Encoding.gzip, Encoding.deflate => {
                    var gzip_timer = std.time.Timer.start() catch @panic("Timer failure");
                    body_out_str.list.expandToCapacity();
                    defer ZlibPool.instance.put(buffer_) catch unreachable;
                    ZlibPool.decompress(buffer.list.items, body_out_str) catch |err| {
                        Output.prettyErrorln("<r><red>Zlib error<r>", .{});
                        Output.flush();
                        return err;
                    };
                    this.gzip_elapsed = gzip_timer.read();
                },
                else => {},
            }

            if (comptime report_progress) {
                this.progress_node.?.activate();
                this.progress_node.?.setCompletedItems(body_out_str.list.items.len);
                this.progress_node.?.context.maybeRefresh();
            }

            this.body_size = @intCast(u32, body_out_str.list.items.len);
            return response;
        }

        if (content_length > 0) {
            var remaining_content_length = content_length;
            var remainder = request_buffer[@intCast(usize, response.bytes_read)..read_length];
            remainder = remainder[0..std.math.min(remainder.len, content_length)];
            var buffer_: *MutableString = body_out_str;

            switch (encoding) {
                Encoding.gzip, Encoding.deflate => {
                    if (!ZlibPool.loaded) {
                        ZlibPool.instance = ZlibPool.init(default_allocator);
                        ZlibPool.loaded = true;
                    }

                    buffer_ = try ZlibPool.instance.get();
                    if (buffer_.list.capacity < remaining_content_length) {
                        try buffer_.list.ensureUnusedCapacity(buffer_.allocator, remaining_content_length);
                    }
                    buffer_.list.items = buffer_.list.items.ptr[0..remaining_content_length];
                },
                else => {},
            }
            var buffer = buffer_.*;

            var body_size: usize = 0;
            if (remainder.len > 0) {
                std.mem.copy(u8, buffer.list.items, remainder);
                body_size = remainder.len;
                this.read_count += @intCast(u32, body_size);
                remaining_content_length -= @intCast(u32, remainder.len);
            }

            while (remaining_content_length > 0) {
                const size = @intCast(u32, try client.read(
                    buffer.list.items,
                    body_size,
                ));
                this.read_count += size;
                if (size == 0) break;

                body_size += size;
                remaining_content_length -= size;

                if (comptime report_progress) {
                    this.progress_node.?.activate();
                    this.progress_node.?.setCompletedItems(body_size);
                    this.progress_node.?.context.maybeRefresh();
                }
            }

            if (comptime report_progress) {
                this.progress_node.?.activate();
                this.progress_node.?.setCompletedItems(body_size);
                this.progress_node.?.context.maybeRefresh();
            }

            buffer.list.shrinkRetainingCapacity(body_size);
            buffer_.* = buffer;

            switch (encoding) {
                Encoding.gzip, Encoding.deflate => {
                    var gzip_timer = std.time.Timer.start() catch @panic("Timer failure");
                    body_out_str.list.expandToCapacity();
                    defer ZlibPool.instance.put(buffer_) catch unreachable;
                    ZlibPool.decompress(buffer.list.items, body_out_str) catch |err| {
                        Output.prettyErrorln("<r><red>Zlib error<r>", .{});
                        Output.flush();
                        return err;
                    };
                    this.gzip_elapsed = gzip_timer.read();
                },
                else => {},
            }
        }
    }

    if (comptime report_progress) {
        this.progress_node.?.activate();
        this.progress_node.?.setCompletedItems(body_out_str.list.items.len);
        this.progress_node.?.context.maybeRefresh();
    }

    return response;
}

pub fn sendHTTPS(this: *HTTPClient, body_str: []const u8, body_out_str: *MutableString) !picohttp.Response {
    this.socket = try AsyncSocket.SSL.init(default_allocator, &AsyncIO.global);
    var socket = &this.socket;
    this.stage = Stage.connect;
    try this.connect(*AsyncSocket.SSL, socket);
    this.stage = Stage.request;
    defer this.socket.close();

    var request = buildRequest(this, body_str.len);
    if (this.verbose) {
        Output.prettyErrorln("{s}", .{request});
    }

    try writeRequest(@TypeOf(socket), socket, request, body_str);
    _ = try socket.send();

    this.stage = Stage.response;

    if (this.progress_node == null) {
        return this.processResponse(
            false,
            @TypeOf(socket),
            socket,
            body_out_str,
        );
    } else {
        return this.processResponse(
            true,
            @TypeOf(socket),
            socket,
            body_out_str,
        );
    }
}

// // zig test src/http_client.zig --test-filter "sendHTTP - only" -lc -lc++ /Users/jarred/Code/bun/src/deps/zlib/libz.a /Users/jarred/Code/bun/src/deps/picohttpparser.o --cache-dir /Users/jarred/Code/bun/zig-cache --global-cache-dir /Users/jarred/.cache/zig --name bun --pkg-begin clap /Users/jarred/Code/bun/src/deps/zig-clap/clap.zig --pkg-end --pkg-begin picohttp /Users/jarred/Code/bun/src/deps/picohttp.zig --pkg-end --pkg-begin iguanaTLS /Users/jarred/Code/bun/src/deps/iguanaTLS/src/main.zig --pkg-end -I /Users/jarred/Code/bun/src/deps -I /Users/jarred/Code/bun/src/deps/mimalloc -I /usr/local/opt/icu4c/include  -L src/deps/mimalloc -L /usr/local/opt/icu4c/lib --main-pkg-path /Users/jarred/Code/bun --enable-cache -femit-bin=zig-out/bin/test --test-no-exec
// test "sendHTTP - only" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     // headers.appendHeader("X-What", "ok", true, true, false);
//     headers.appendHeader("Accept-Encoding", "identity", true, true, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("http://example.com/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.sendHTTP("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqual(body_out_str.list.items.len, 1256);
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }

// // zig test src/http_client.zig --test-filter "sendHTTP - gzip" -lc -lc++ /Users/jarred/Code/bun/src/deps/zlib/libz.a /Users/jarred/Code/bun/src/deps/picohttpparser.o --cache-dir /Users/jarred/Code/bun/zig-cache --global-cache-dir /Users/jarred/.cache/zig --name bun --pkg-begin clap /Users/jarred/Code/bun/src/deps/zig-clap/clap.zig --pkg-end --pkg-begin picohttp /Users/jarred/Code/bun/src/deps/picohttp.zig --pkg-end --pkg-begin iguanaTLS /Users/jarred/Code/bun/src/deps/iguanaTLS/src/main.zig --pkg-end -I /Users/jarred/Code/bun/src/deps -I /Users/jarred/Code/bun/src/deps/mimalloc -I /usr/local/opt/icu4c/include  -L src/deps/mimalloc -L /usr/local/opt/icu4c/lib --main-pkg-path /Users/jarred/Code/bun --enable-cache -femit-bin=zig-out/bin/test --test-no-exec
// test "sendHTTP - gzip" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     // headers.appendHeader("X-What", "ok", true, true, false);
//     headers.appendHeader("Accept-Encoding", "gzip", true, true, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("http://example.com/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.sendHTTP("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }

// // zig test src/http_client.zig --test-filter "sendHTTPS - identity" -lc -lc++ /Users/jarred/Code/bun/src/deps/zlib/libz.a /Users/jarred/Code/bun/src/deps/picohttpparser.o --cache-dir /Users/jarred/Code/bun/zig-cache --global-cache-dir /Users/jarred/.cache/zig --name bun --pkg-begin clap /Users/jarred/Code/bun/src/deps/zig-clap/clap.zig --pkg-end --pkg-begin picohttp /Users/jarred/Code/bun/src/deps/picohttp.zig --pkg-end --pkg-begin iguanaTLS /Users/jarred/Code/bun/src/deps/iguanaTLS/src/main.zig --pkg-end -I /Users/jarred/Code/bun/src/deps -I /Users/jarred/Code/bun/src/deps/mimalloc -I /usr/local/opt/icu4c/include  -L src/deps/mimalloc -L /usr/local/opt/icu4c/lib --main-pkg-path /Users/jarred/Code/bun --enable-cache -femit-bin=zig-out/bin/test --test-no-exec
// test "sendHTTPS - identity" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     headers.appendHeader("X-What", "ok", true, true, false);
//     headers.appendHeader("Accept-Encoding", "identity", true, true, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("https://example.com/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.sendHTTPS("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }

// test "sendHTTPS - gzip" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     headers.appendHeader("Accept-Encoding", "gzip", false, false, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("https://example.com/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.sendHTTPS("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }

// // zig test src/http_client.zig --test-filter "sendHTTPS - deflate" -lc -lc++ /Users/jarred/Code/bun/src/deps/zlib/libz.a /Users/jarred/Code/bun/src/deps/picohttpparser.o --cache-dir /Users/jarred/Code/bun/zig-cache --global-cache-dir /Users/jarred/.cache/zig --name bun --pkg-begin clap /Users/jarred/Code/bun/src/deps/zig-clap/clap.zig --pkg-end --pkg-begin picohttp /Users/jarred/Code/bun/src/deps/picohttp.zig --pkg-end --pkg-begin iguanaTLS /Users/jarred/Code/bun/src/deps/iguanaTLS/src/main.zig --pkg-end -I /Users/jarred/Code/bun/src/deps -I /Users/jarred/Code/bun/src/deps/mimalloc -I /usr/local/opt/icu4c/include  -L src/deps/mimalloc -L /usr/local/opt/icu4c/lib --main-pkg-path /Users/jarred/Code/bun --enable-cache -femit-bin=zig-out/bin/test
// test "sendHTTPS - deflate" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     headers.appendHeader("Accept-Encoding", "deflate", false, false, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("https://example.com/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.sendHTTPS("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }

// // zig test src/http_client.zig --test-filter "sendHTTP" -lc -lc++ /Users/jarred/Code/bun/src/deps/zlib/libz.a /Users/jarred/Code/bun/src/deps/picohttpparser.o --cache-dir /Users/jarred/Code/bun/zig-cache --global-cache-dir /Users/jarred/.cache/zig --name bun --pkg-begin clap /Users/jarred/Code/bun/src/deps/zig-clap/clap.zig --pkg-end --pkg-begin picohttp /Users/jarred/Code/bun/src/deps/picohttp.zig --pkg-end --pkg-begin iguanaTLS /Users/jarred/Code/bun/src/deps/iguanaTLS/src/main.zig --pkg-end -I /Users/jarred/Code/bun/src/deps -I /Users/jarred/Code/bun/src/deps/mimalloc -I /usr/local/opt/icu4c/include  -L src/deps/mimalloc -L /usr/local/opt/icu4c/lib --main-pkg-path /Users/jarred/Code/bun --enable-cache -femit-bin=zig-out/bin/test

// test "send - redirect" {
//     Output.initTest();
//     defer Output.flush();

//     var headers = try std.heap.c_allocator.create(Headers);
//     headers.* = Headers{
//         .entries = @TypeOf(headers.entries){},
//         .buf = @TypeOf(headers.buf){},
//         .used = 0,
//         .allocator = std.heap.c_allocator,
//     };

//     headers.appendHeader("Accept-Encoding", "gzip", false, false, false);

//     var client = HTTPClient.init(
//         std.heap.c_allocator,
//         .GET,
//         URL.parse("https://www.bun.sh/"),
//         headers.entries,
//         headers.buf.items,
//     );
//     try std.testing.expectEqualStrings(client.url.hostname, "www.bun.sh");
//     var body_out_str = try MutableString.init(std.heap.c_allocator, 0);
//     var response = try client.send("", &body_out_str);
//     try std.testing.expectEqual(response.status_code, 200);
//     try std.testing.expectEqual(client.url.hostname, "bun.sh");
//     try std.testing.expectEqualStrings(body_out_str.list.items, @embedFile("fixtures_example.com.html"));
// }
