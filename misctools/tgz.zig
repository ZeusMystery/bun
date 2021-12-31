const std = @import("std");

const path_handler = @import("../src/resolver/resolve_path.zig");
const _global = @import("../src/global.zig");
const string = _global.string;
const Output = _global.Output;
const Global = _global.Global;
const Environment = _global.Environment;
const strings = _global.strings;
const MutableString = _global.MutableString;
const stringZ = _global.stringZ;
const default_allocator = _global.default_allocator;
const C = _global.C;

const Archive = @import("../src/libarchive/libarchive.zig").Archive;
const Zlib = @import("../src/zlib.zig");

const RecognizedExtensions = std.ComptimeStringMap(void, .{
    .{ ".tgz", void{} },
    .{ ".tar", void{} },
    .{ ".gz", void{} },
});

var buf: [32 * 1024 * 1024]u8 = undefined;

// zig build-exe -Drelease-fast --main-pkg-path ../ ./tgz.zig ../src/deps/zlib/libz.a ../src/deps/libarchive.a -lc -liconv
// zig build-exe -Drelease-fast --main-pkg-path ../ ./tgz.zig ../src/deps/zlib/libz.a ../src/deps/libarchive.a -lc -liconv
pub fn main() anyerror!void {
    var stdout_ = std.io.getStdOut();
    var stderr_ = std.io.getStdErr();
    var output_source = Output.Source.init(stdout_, stderr_);
    Output.Source.set(&output_source);
    defer Output.flush();
    var args = try std.process.argsAlloc(std.heap.c_allocator);
    if (args.len < 2) {
        Output.prettyErrorln("<r><b>usage<r>: tgz ./tar.gz", .{});
        Output.flush();
        std.os.abort();
    }

    var tarball_path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var basename = std.fs.path.basename(std.mem.span(args[args.len - 1]));
    while (RecognizedExtensions.has(std.fs.path.extension(basename))) {
        basename = basename[0 .. basename.len - std.fs.path.extension(basename).len];
    }

    var parts = [_][]const u8{
        std.mem.span(args[args.len - 1]),
    };

    const tarball_path = path_handler.joinAbsStringBuf(try std.process.getCwdAlloc(std.heap.c_allocator), &tarball_path_buf, &parts, .auto);
    Output.prettyErrorln("Tarball Path: {s}", .{tarball_path});
    var folder = basename;

    // var dir = try std.fs.cwd().makeOpenPath(folder, .{ .iterate = true });

    var tarball = try std.fs.openFileAbsolute(tarball_path, .{ .read = true });

    var tarball_buf_list = std.ArrayListUnmanaged(u8){};

    var file_size = try tarball.getEndPos();
    var file_buf: []u8 = undefined;
    var file_buf_cap: usize = 0;

    if (file_size < buf.len) {
        file_buf = buf[0..try tarball.readAll(&buf)];
        file_buf_cap = buf.len;
    } else {
        file_buf = try tarball.readToEndAlloc(
            std.heap.c_allocator,
            file_size,
        );
        file_buf_cap = file_buf.len;
    }

    if (std.mem.eql(u8, std.fs.path.extension(tarball_path), ".gz") or std.mem.eql(u8, std.fs.path.extension(tarball_path), ".tgz")) {
        tarball_buf_list = try std.ArrayListUnmanaged(u8).initCapacity(std.heap.c_allocator, 1024);
        var gunzip = try Zlib.ZlibReaderArrayList.init(file_buf, &tarball_buf_list, std.heap.c_allocator);
        try gunzip.readAll();
        gunzip.deinit();
        Output.prettyErrorln("Decompressed {d} -> {d}\n", .{ file_buf.len, tarball_buf_list.items.len });
    } else {
        tarball_buf_list = std.ArrayListUnmanaged(u8){ .capacity = file_buf.len, .items = file_buf };
    }

    _ = try Archive.extractToDisk(
        file_buf,
        folder,
        null,
        void,
        void{},
        1,
        false,
        false,
    );
}
