const std = @import("std");
pub const Environment = @import("env.zig");

pub const use_mimalloc = !Environment.isTest;

/// For sizes less than 8 MB, allocate via mimalloc
pub const default_allocator: std.mem.Allocator = if (!use_mimalloc)
    std.heap.c_allocator
else
    @import("./memory_allocator.zig").c_allocator;

/// For sizes larger than 8 MB, allocate via mmap() instead of malloc().
pub const huge_allocator: std.mem.Allocator = if (!use_mimalloc)
    std.heap.c_allocator
else
    @import("./memory_allocator.zig").huge_allocator;

/// For sizes larger than 8 MB, allocate via mmap() instead of malloc().
/// For sizes less than 8 MB, allocate via mimalloc
pub const auto_allocator: std.mem.Allocator = if (!use_mimalloc)
    std.heap.c_allocator
else
    @import("./memory_allocator.zig").auto_allocator;

pub const huge_allocator_threshold: comptime_int = @import("./memory_allocator.zig").huge_threshold;

pub const C = @import("c.zig");

pub const FeatureFlags = @import("feature_flags.zig");
const root = @import("root");
pub const meta = @import("./meta.zig");
pub const ComptimeStringMap = @import("./comptime_string_map.zig").ComptimeStringMap;
pub const base64 = @import("./base64/base64.zig");
pub const path = @import("./resolver/resolve_path.zig");
pub const fmt = struct {
    pub usingnamespace std.fmt;

    pub const SizeFormatter = struct {
        value: usize = 0,
        pub fn format(self: SizeFormatter, comptime _: []const u8, _: fmt.FormatOptions, writer: anytype) !void {
            const math = std.math;
            const value = self.value;
            if (value == 0) {
                return writer.writeAll("0 KB");
            }

            const mags_si = " KMGTPEZY";
            const mags_iec = " KMGTPEZY";

            const log2 = math.log2(value);
            const magnitude = math.min(log2 / comptime math.log2(1000), mags_si.len - 1);
            const new_value = math.lossyCast(f64, value) / math.pow(f64, 1000, math.lossyCast(f64, magnitude));
            const suffix = switch (1000) {
                1000 => mags_si[magnitude],
                1024 => mags_iec[magnitude],
                else => unreachable,
            };

            if (suffix == ' ') {
                try fmt.formatFloatDecimal(new_value / 1000.0, .{ .precision = 2 }, writer);
                return writer.writeAll(" KB");
            } else {
                try fmt.formatFloatDecimal(new_value, .{ .precision = if (std.math.approxEqAbs(f64, new_value, @trunc(new_value), 0.100)) @as(usize, 0) else @as(usize, 2) }, writer);
            }

            const buf = switch (1000) {
                1000 => &[_]u8{ ' ', suffix, 'B' },
                1024 => &[_]u8{ ' ', suffix, 'i', 'B' },
                else => unreachable,
            };
            return writer.writeAll(buf);
        }
    };

    pub fn size(value: anytype) SizeFormatter {
        return switch (@TypeOf(value)) {
            f64, f32, f128 => SizeFormatter{
                .value = @floatToInt(u64, value),
            },
            else => SizeFormatter{ .value = @intCast(u64, value) },
        };
    }
};

pub const Output = @import("./output.zig");
pub const Global = @import("./__global.zig");

pub const FileDescriptorType = if (Environment.isBrowser) u0 else std.os.fd_t;

// When we are on a computer with an absurdly high number of max open file handles
// such is often the case with macOS
// As a useful optimization, we can store file descriptors and just keep them open...forever
pub const StoredFileDescriptorType = if (Environment.isWindows or Environment.isBrowser) u0 else std.os.fd_t;

pub const StringTypes = @import("string_types.zig");
pub const stringZ = StringTypes.stringZ;
pub const string = StringTypes.string;
pub const CodePoint = StringTypes.CodePoint;
pub const PathString = StringTypes.PathString;
pub const HashedString = StringTypes.HashedString;
pub const strings = @import("string_immutable.zig");
pub const MutableString = @import("string_mutable.zig").MutableString;
pub const RefCount = @import("./ref_count.zig").RefCount;

pub inline fn constStrToU8(s: []const u8) []u8 {
    return @intToPtr([*]u8, @ptrToInt(s.ptr))[0..s.len];
}

pub const MAX_PATH_BYTES: usize = if (Environment.isWasm) 1024 else std.fs.MAX_PATH_BYTES;

pub inline fn cast(comptime To: type, value: anytype) To {
    return @ptrCast(To, @alignCast(@alignOf(To), value));
}

extern fn strlen(ptr: [*c]const u8) usize;
pub fn indexOfSentinel(comptime Elem: type, comptime sentinel: Elem, ptr: [*:sentinel]const Elem) usize {
    if (comptime Elem == u8 and sentinel == 0) {
        return strlen(ptr);
    } else {
        var i: usize = 0;
        while (ptr[i] != sentinel) {
            i += 1;
        }
        return i;
    }
}

pub fn len(value: anytype) usize {
    return switch (@typeInfo(@TypeOf(value))) {
        .Array => |info| info.len,
        .Vector => |info| info.len,
        .Pointer => |info| switch (info.size) {
            .One => switch (@typeInfo(info.child)) {
                .Array => value.len,
                else => @compileError("invalid type given to std.mem.len"),
            },
            .Many => {
                const sentinel_ptr = info.sentinel orelse
                    @compileError("length of pointer with no sentinel");
                const sentinel = @ptrCast(*const info.child, sentinel_ptr).*;

                return indexOfSentinel(info.child, sentinel, value);
            },
            .C => {
                std.debug.assert(value != null);
                return indexOfSentinel(info.child, 0, value);
            },
            .Slice => value.len,
        },
        .Struct => |info| if (info.is_tuple) {
            return info.fields.len;
        } else @compileError("invalid type given to std.mem.len"),
        else => @compileError("invalid type given to std.mem.len"),
    };
}

pub fn span(ptr: anytype) std.mem.Span(@TypeOf(ptr)) {
    if (@typeInfo(@TypeOf(ptr)) == .Optional) {
        if (ptr) |non_null| {
            return span(non_null);
        } else {
            return null;
        }
    }
    const Result = std.mem.Span(@TypeOf(ptr));
    const l = len(ptr);
    const ptr_info = @typeInfo(Result).Pointer;
    if (ptr_info.sentinel) |s_ptr| {
        const s = @ptrCast(*const ptr_info.child, s_ptr).*;
        return ptr[0..l :s];
    } else {
        return ptr[0..l];
    }
}

pub const IdentityContext = @import("./identity_context.zig").IdentityContext;
pub const ArrayIdentityContext = @import("./identity_context.zig").ArrayIdentityContext;
pub const BabyList = @import("./baby_list.zig").BabyList;
pub const ByteList = BabyList(u8);

pub fn DebugOnly(comptime Type: type) type {
    if (comptime Environment.isDebug) {
        return Type;
    }

    return void;
}

pub fn DebugOnlyDefault(comptime val: anytype) if (Environment.isDebug) @TypeOf(val) else void {
    if (comptime Environment.isDebug) {
        return val;
    }

    return {};
}
