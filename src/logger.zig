const std = @import("std");
const strings = @import("strings.zig");

const expect = std.testing.expect;
const assert = std.debug.assert;
const ArrayList = std.ArrayList;

pub const Kind = enum {
    err,
    warn,
    note,
    debug,

    pub fn string(self: Kind) []const u8 {
        return switch (self) {
            .err => "error",
            .warn => "warn",
            .note => "note",
            .debug => "debug",
        };
    }
};

pub const Loc = i32;

pub const Location = struct {
    file: []u8,
    namespace: []u8 = "file",
    line: i32 = 1, // 1-based
    column: i32 = 0, // 0-based, in bytes
    length: u32 = 0, // in bytes
    line_text: ?[]u8,
    suggestion: ?[]u8,

    pub fn init(file: []u8, namespace: []u8, line: i32, column: i32, length: u32, line_text: ?[]u8, suggestion: ?[]u8) Location {
        return Location{
            .file = file,
            .namespace = namespace,
            .line = line,
            .column = column,
            .length = length,
            .line_text = line_text,
            .suggestion = suggestion,
        };
    }

    pub fn init_file(file: []u8, line: i32, column: i32, length: u32, line_text: ?[]u8, suggestion: ?[]u8) Location {
        var namespace = "file".*;

        return Location{
            .file = file,
            .namespace = &namespace,
            .line = line,
            .column = column,
            .length = length,
            .line_text = line_text,
            .suggestion = suggestion,
        };
    }
};

pub const Data = struct { text: []u8, location: *Location };

pub const Msg = struct {
    kind: Kind = Kind.err,
    data: Data,
};

pub const Range = struct { start: u32 = 0, len: i32 = 0 };

pub const Log = struct {
    debug: bool = false,
    warnings: u8 = 0,
    errors: u8 = 0,
    msgs: ArrayList(Msg),

    // TODO:
    pub fn add_msg(self: *Log, msg: Msg) !void {
        try self.msgs.append(msg);
    }

    // TODO:
    pub fn add_err(self: *Log, msg: Msg) !void {
        // try self.msgs.append(msg);
    }

    // TODO:
    pub fn print(self: *Log, to: anytype) !void {
        for (self.msgs.items) |msg| {
            try std.fmt.format(to, "\n\n{s}: {s}\n{s}\n{s}:{}:{}", .{ msg.kind.string(), msg.data.text, msg.data.location.line_text, msg.data.location.file, msg.data.location.line, msg.data.location.column });
        }
    }
};

pub const Source = struct { index: u32 = 0, contents: []u8,

// An identifier that is mixed in to automatically-generated symbol names to
// improve readability. For example, if the identifier is "util" then the
// symbol for an "export default" statement will be called "util_default".
identifier_name: []u8 };

test "print msg" {
    var log = Log{ .msgs = ArrayList(Msg).init(std.testing.allocator) };
    defer log.msgs.deinit();
    var filename = "test.js".*;
    var syntax = "for(i = 0;)".*;
    var err = "invalid syntax".*;
    var namespace = "file".*;

    try log.add_msg(Msg{
        .kind = .err,
        .data = Data{ .location = &Location.init_file(&filename, 1, 3, 0, &syntax, ""), .text = &err },
    });

    const stdout = std.io.getStdOut().writer();

    try log.print(stdout);
}
