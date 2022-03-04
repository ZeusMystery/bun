const std = @import("std");
const Lock = @import("./lock.zig").Lock;
const _global = @import("./global.zig");
const string = _global.string;
const Output = _global.Output;
const Global = _global.Global;
const Environment = _global.Environment;
const strings = _global.strings;
const MutableString = _global.MutableString;
const stringZ = _global.stringZ;
const default_allocator = _global.default_allocator;
const C = _global.C;

const Blob = @This();

ptr: [*]const u8,
len: usize,

pub const Map = struct {
    const MapContext = struct {
        pub fn hash(_: @This(), s: u64) u32 {
            return @truncate(u32, s);
        }
        pub fn eql(_: @This(), a: u64, b: u64, _: usize) bool {
            return a == b;
        }
    };

    const HashMap = std.ArrayHashMap(u64, Blob, MapContext, false);
    lock: Lock,
    map: HashMap,
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator) Map {
        return Map{
            .lock = Lock.init(),
            .map = HashMap.init(allocator),
            .allocator = allocator,
        };
    }

    pub fn get(this: *Map, key: string) ?Blob {
        this.lock.lock();
        defer this.lock.unlock();
        return this.map.get(std.hash.Wyhash.hash(0, key));
    }

    pub fn put(this: *Map, key: string, blob: Blob) !void {
        this.lock.lock();
        defer this.lock.unlock();

        return try this.map.put(std.hash.Wyhash.hash(0, key), blob);
    }

    pub fn reset(this: *Map) !void {
        this.lock.lock();
        defer this.lock.unlock();
        this.map.clearRetainingCapacity();
    }
};

pub const Group = struct {
    persistent: Map,
    temporary: Map,
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator) !*Group {
        var group = try allocator.create(Group);
        group.* = Group{ .persistent = Map.init(allocator), .temporary = Map.init(allocator), .allocator = allocator };
        return group;
    }

    pub fn get(this: *Group, key: string) ?Blob {
        return this.temporary.get(key) orelse this.persistent.get(key);
    }
};
