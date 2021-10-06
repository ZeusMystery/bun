usingnamespace @import("../global.zig");
const std = @import("std");
const options = @import("../options.zig");
const logger = @import("../logger.zig");
const cache = @import("../cache.zig");
const js_ast = @import("../js_ast.zig");
const js_lexer = @import("../js_lexer.zig");
const Api = @import("../api/schema.zig").Api;

pub const Bunfig = struct {
    pub fn parse(allocator: *std.mem.Allocator, path: string, transform: *Api.TransformOptions, log: *logger.Log, comptime required: bool) !void {
        var cwd = std.fs.cwd();
        cwd.openFile(path, .{ .read = true }) catch |err| {
            switch (err) {
                error.FileNotFound => {
                    if (comptime required) {
                        log.addErrorFmt(null, logger.Loc.Empty, allocator, "bunfig \"{s}\" not found", args: anytype)
                    }
                },
            }
        };
    }
};
