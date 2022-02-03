const std = @import("std");

fn SinglyLinkedList(comptime T: type, comptime Parent: type) type {
    return struct {
        const Self = @This();

        /// Node inside the linked list wrapping the actual data.
        pub const Node = struct {
            next: ?*Node = null,
            allocator: std.mem.Allocator,
            data: T,

            pub const Data = T;

            /// Insert a new node after the current one.
            ///
            /// Arguments:
            ///     new_node: Pointer to the new node to insert.
            pub fn insertAfter(node: *Node, new_node: *Node) void {
                new_node.next = node.next;
                node.next = new_node;
            }

            /// Remove a node from the list.
            ///
            /// Arguments:
            ///     node: Pointer to the node to be removed.
            /// Returns:
            ///     node removed
            pub fn removeNext(node: *Node) ?*Node {
                const next_node = node.next orelse return null;
                node.next = next_node.next;
                return next_node;
            }

            /// Iterate over the singly-linked list from this node, until the final node is found.
            /// This operation is O(N).
            pub fn findLast(node: *Node) *Node {
                var it = node;
                while (true) {
                    it = it.next orelse return it;
                }
            }

            /// Iterate over each next node, returning the count of all nodes except the starting one.
            /// This operation is O(N).
            pub fn countChildren(node: *const Node) usize {
                var count: usize = 0;
                var it: ?*const Node = node.next;
                while (it) |n| : (it = n.next) {
                    count += 1;
                }
                return count;
            }

            pub inline fn release(node: *Node) void {
                Parent.release(node);
            }
        };

        first: ?*Node = null,

        /// Insert a new node at the head.
        ///
        /// Arguments:
        ///     new_node: Pointer to the new node to insert.
        pub fn prepend(list: *Self, new_node: *Node) void {
            new_node.next = list.first;
            list.first = new_node;
        }

        /// Remove a node from the list.
        ///
        /// Arguments:
        ///     node: Pointer to the node to be removed.
        pub fn remove(list: *Self, node: *Node) void {
            if (list.first == node) {
                list.first = node.next;
            } else {
                var current_elm = list.first.?;
                while (current_elm.next != node) {
                    current_elm = current_elm.next.?;
                }
                current_elm.next = node.next;
            }
        }

        /// Remove and return the first node in the list.
        ///
        /// Returns:
        ///     A pointer to the first node in the list.
        pub fn popFirst(list: *Self) ?*Node {
            const first = list.first orelse return null;
            list.first = first.next;
            return first;
        }

        /// Iterate over all nodes, returning the count.
        /// This operation is O(N).
        pub fn len(list: Self) usize {
            if (list.first) |n| {
                return 1 + n.countChildren();
            } else {
                return 0;
            }
        }
    };
}

const log_allocations = false;

pub fn ObjectPool(
    comptime Type: type,
    comptime Init: (?fn (allocator: std.mem.Allocator) anyerror!Type),
    comptime threadsafe: bool,
    comptime max_count: comptime_int,
) type {
    return struct {
        const Pool = @This();
        const LinkedList = SinglyLinkedList(Type, Pool);
        pub const Node = LinkedList.Node;
        const MaxCountInt = std.math.IntFittingRange(0, max_count);
        const Data = if (threadsafe)
            struct {
                pub threadlocal var list: LinkedList = undefined;
                pub threadlocal var loaded: bool = false;
                pub threadlocal var count: MaxCountInt = 0;
            }
        else
            struct {
                pub var list: LinkedList = undefined;
                pub var loaded: bool = false;
                pub var count: MaxCountInt = 0;
            };

        const data = Data;

        pub fn get(allocator: std.mem.Allocator) *LinkedList.Node {
            if (data.loaded) {
                if (data.list.popFirst()) |node| {
                    if (comptime std.meta.trait.isContainer(Type) and @hasDecl(Type, "reset")) node.data.reset();
                    if (comptime max_count > 0) data.count -|= 1;
                    return node;
                }
            }

            if (comptime log_allocations) std.io.getStdErr().writeAll(comptime std.fmt.comptimePrint("Allocate {s} - {d} bytes\n", .{ @typeName(Type), @sizeOf(Type) })) catch {};

            var new_node = allocator.create(LinkedList.Node) catch unreachable;
            new_node.* = LinkedList.Node{
                .allocator = allocator,
                .data = if (comptime Init) |init_|
                    (init_(
                        allocator,
                    ) catch unreachable)
                else
                    undefined,
            };

            return new_node;
        }

        pub fn release(node: *LinkedList.Node) void {
            if (comptime max_count > 0) {
                if (data.count >= max_count) {
                    if (comptime log_allocations) std.io.getStdErr().writeAll(comptime std.fmt.comptimePrint("Free {s} - {d} bytes\n", .{ @typeName(Type), @sizeOf(Type) })) catch {};
                    if (comptime std.meta.trait.isContainer(Type) and @hasDecl(Type, "deinit")) node.data.deinit();
                    node.allocator.destroy(node);
                    return;
                }
            }

            if (comptime max_count > 0) data.count +|= 1;

            if (data.loaded) {
                data.list.prepend(node);
                return;
            }

            data.list = LinkedList{ .first = node };
            data.loaded = true;
        }
    };
}
