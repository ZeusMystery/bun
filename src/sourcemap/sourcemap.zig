pub const VLQ_BASE_SHIFT: u32 = 5;
pub const VLQ_BASE: u32 = 1 << VLQ_BASE_SHIFT;
pub const VLQ_BASE_MASK: u32 = VLQ_BASE - 1;
pub const VLQ_CONTINUATION_BIT: u32 = VLQ_BASE;
pub const VLQ_CONTINUATION_MASK: u32 = 1 << VLQ_CONTINUATION_BIT;
const std = @import("std");
const JSAst = @import("../js_ast.zig");
const BabyList = JSAst.BabyList;
const Logger = @import("../logger.zig");
const strings = @import("../string_immutable.zig");
const MutableString = @import("../string_mutable.zig").MutableString;
const base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const base64_lut: [std.math.maxInt(u8)]u8 = brk: {
    @setEvalBranchQuota(9999);
    var bytes = [_]u8{255} ** std.math.maxInt(u8);

    for (base64) |c, i| {
        bytes[c] = i;
    }

    break :brk bytes;
};
const SourceMap = @This();

// One VLQ value never exceeds 20 bits of data, so 15 is more than enough
pub const VLQ = struct {
    bytes: [15]u8,
    len: u8 = 0,
};

/// Coordinates in source maps are stored using relative offsets for size
/// reasons. When joining together chunks of a source map that were emitted
/// in parallel for different parts of a file, we need to fix up the first
/// segment of each chunk to be relative to the end of the previous chunk.
pub const SourceMapState = struct {
    /// This isn't stored in the source map. It's only used by the bundler to join
    /// source map chunks together correctly.
    generated_line: i32 = 0,

    /// These are stored in the source map in VLQ format.
    generated_column: i32 = 0,
    source_index: i32 = 0,
    original_line: i32 = 0,
    original_column: i32 = 0,
};

sources: [][]const u8 = &[_][]u8{},
sources_content: [][]SourceContent,
mapping: std.ArrayListUnmanaged(Mapping) = .{},
allocator: std.mem.Allocator,

pub const Mapping = extern struct {
    contents: [5]i32 = undefined,

    pub inline fn generatedLine(mapping: Mapping) i32 {
        return mapping.contents[0];
    }

    pub inline fn generatedColumn(mapping: Mapping) i32 {
        return mapping.contents[1];
    }

    pub inline fn sourceIndex(mapping: Mapping) i32 {
        return mapping.contents[2];
    }

    pub inline fn originalLine(mapping: Mapping) i32 {
        return mapping.contents[3];
    }

    pub inline fn originalColumn(mapping: Mapping) i32 {
        return mapping.contents[4];
    }
};

pub const LineColumnOffset = struct {
    lines: i32 = 0,
    columns: i32 = 0,
};

pub const SourceContent = struct {
    value: []const u16 = &[_]u16{},
    quoted: []const u8 = &[_]u8{},
};

pub fn find(
    this: *const SourceMap,
    line: i32,
    column: i32,
) ?*const Mapping {
    _ = this;
    _ = line;
    _ = column;
}

// A single base 64 digit can contain 6 bits of data. For the base 64 variable
// length quantities we use in the source map spec, the first bit is the sign,
// the next four bits are the actual value, and the 6th bit is the continuation
// bit. The continuation bit tells us whether there are more digits in this
// value following this digit.
//
//   Continuation
//   |    Sign
//   |    |
//   V    V
//   101011
//
pub fn encodeVLQ(
    value: i32,
) VLQ {
    var vlq: i32 = 0;
    var bytes = std.mem.zeroes([15]u8);
    var len: u8 = 0;
    if (value < 0) {
        vlq = ((-value) << 1) | 1;
    } else {
        vlq = value << 1;
    }

    if ((vlq >> 5) == 0) {
        const digit = @intCast(u8, vlq & 31);
        bytes[0] = base64[digit];
        return .{ .bytes = bytes, .len = 1 };
    }

    // i32 contains 32 bits
    // since
    // the maximum possible number is @maxInt(u20)
    //
    while (true) {
        var digit = @intCast(u8, vlq & 31);
        vlq >>= 5;

        // If there are still more digits in this value, we must make sure the
        // continuation bit is marked
        if (vlq != 0) {
            digit |= 32;
        }

        bytes[len] = base64[digit];
        len += 1;

        if (vlq == 0) {
            break;
        }
    }

    return .{ .bytes = bytes, .len = len };
}

pub const VLQResult = struct {
    value: i32 = 0,
    start: usize = 0,
};

fn decodeVLQ(encoded: []const u8, start: usize) VLQResult {
    var shift: i32 = 0;
    var vlq: i32 = 0;
    var len: usize = encoded.len;
    var i: usize = start;

    while (i < len) {
        const index = @as(i32, base64_lut[encoded[i]]);
        if (index == std.math.maxInt(u8)) break;

        // decode a byte
        vlq |= (index & 31) << shift;
        i += 1;
        shift += 5;

        // Stop if there's no continuation bit
        if ((index & 32) == 0) {
            break;
        }
    }

    var value = vlq >> 1;
    if ((vlq & 1) != 0) {
        value = -value;
    }

    return VLQResult{ .start = i, .value = value };
}

pub const LineOffsetTable = struct {

    /// The source map specification is very loose and does not specify what
    /// column numbers actually mean. The popular "source-map" library from Mozilla
    /// appears to interpret them as counts of UTF-16 code units, so we generate
    /// those too for compatibility.
    ///
    /// We keep mapping tables around to accelerate conversion from byte offsets
    /// to UTF-16 code unit counts. However, this mapping takes up a lot of memory
    /// and takes up a lot of memory. Since most JavaScript is ASCII and the
    /// mapping for ASCII is 1:1, we avoid creating a table for ASCII-only lines
    /// as an optimization.
    ///
    columns_for_non_ascii: BabyList(i32) = .{},
    byte_offset_to_first_non_ascii: u32 = 0,
    byte_offset_to_start_of_line: u32 = 0,

    pub const List = std.MultiArrayList(LineOffsetTable);

    pub fn findLine(list: List, loc: Logger.Loc) i32 {
        const byte_offsets_to_start_of_line = list.items(.byte_offset_to_start_of_line);
        var original_line: i32 = 0;
        if (loc.start <= -1) {
            return 0;
        }

        const loc_start = @intCast(u32, loc.start);

        {
            var count = @truncate(u32, byte_offsets_to_start_of_line.len);
            var i: u32 = 0;
            while (count > 0) {
                const step = count / 2;
                i = original_line + step;
                if (byte_offsets_to_start_of_line[i] <= loc_start) {
                    original_line = @intCast(i32, i + 1);
                    count = count - step - 1;
                } else {
                    count = step;
                }
            }
        }

        return original_line - 1;
    }

    pub fn generate(allocator: std.mem.Allocator, contents: []const u8, approximate_line_count: i32) List {
        var list = List{};
        // Preallocate the top-level table using the approximate line count from the lexer
        list.ensureUnusedCapacity(allocator, @intCast(usize, @maximum(approximate_line_count, 1))) catch unreachable;
        var column: i32 = 0;
        var byte_offset_to_first_non_ascii: u32 = 0;
        var column_byte_offset: u32 = 0;
        var line_byte_offset: u32 = 0;

        // the idea here is:
        // we want to avoid re-allocating this array _most_ of the time
        // when lines _do_ have unicode characters, they probably still won't be longer than 255 much
        var stack_fallback = std.heap.stackFallback(@sizeOf(i32) * 256, allocator);
        var columns_for_non_ascii = std.ArrayList(i32).initCapacity(stack_fallback.get(), 120) catch unreachable;
        const reset_end_index = stack_fallback.fixed_buffer_allocator.end_index;
        const columns_for_non_ascii_reset = columns_for_non_ascii;

        var remaining = contents;
        while (remaining.len > 0) {
            // TODO: SIMD
            const len_ = strings.wtf8ByteSequenceLength(remaining[0]);
            const c = strings.decodeWTF8RuneT(remaining.ptr[0..4], len_, i32, 0);

            if (column == 0) {
                line_byte_offset = @truncate(
                    u32,
                    @ptrToInt(remaining.ptr) - @ptrToInt(contents.ptr),
                );
            }

            if (c > 0x7F and columns_for_non_ascii.items.len == 0) {
                // reset the buffers
                columns_for_non_ascii = columns_for_non_ascii_reset;
                stack_fallback.fixed_buffer_allocator.reset();
                stack_fallback.fixed_buffer_allocator.end_index = reset_end_index;

                // we have a non-ASCII character, so we need to keep track of the
                // mapping from byte offsets to UTF-16 code unit counts
                columns_for_non_ascii.appendAssumeCapacity(column);
                column_byte_offset = @intCast(
                    u32,
                    (@ptrToInt(
                        remaining.ptr,
                    ) - @ptrToInt(
                        contents.ptr,
                    )) - line_byte_offset,
                );
                byte_offset_to_first_non_ascii = line_byte_offset;
            }

            // Update the per-byte column offsets
            if (columns_for_non_ascii.items.len > 0) {
                const line_bytes_so_far = @intCast(u32, @truncate(
                    u32,
                    @ptrToInt(remaining.ptr) - @ptrToInt(contents.ptr),
                )) - line_byte_offset;
                try columns_for_non_ascii.ensureUnusedCapacity((line_bytes_so_far - column_byte_offset) + 1);
                while (column_byte_offset <= line_bytes_so_far) : (column_byte_offset += 1) {
                    columns_for_non_ascii.appendAssumeCapacity(column);
                }
            }

            switch (c) {
                '\r', '\n', 0x2028, 0x2029 => {
                    // windows newline
                    if (c == '\r' and remaining.len > 1 and remaining[1] == '\n') {
                        column += 1;
                        remaining = remaining[1..];
                        continue;
                    }
                    var columns_list = columns_for_non_ascii;
                    if (columns_for_non_ascii.items.len > 0 and stack_fallback.fixed_buffer_allocator.ownsSlice(columns_for_non_ascii.items)) {
                        columns_for_non_ascii.items = try allocator.dupe(i32, columns_for_non_ascii.toOwnedSlice());
                        columns_for_non_ascii.capacity = columns_for_non_ascii.items.len;
                    }

                    try list.append(allocator, .{
                        .byte_offset_to_start_of_line = line_byte_offset,
                        .byte_offset_to_first_non_ascii = byte_offset_to_first_non_ascii,
                        .columns_for_non_ascii = BabyList(i32).fromList(columns_list),
                    });
                    column = 0;
                    byte_offset_to_first_non_ascii = 0;
                    column_byte_offset = 0;
                    line_byte_offset = 0;
                    columns_for_non_ascii = columns_for_non_ascii_reset;
                    stack_fallback.fixed_buffer_allocator.reset();
                    stack_fallback.fixed_buffer_allocator.end_index = reset_end_index;
                },
                else => {
                    // Mozilla's "source-map" library counts columns using UTF-16 code units
                    column += @as(i32, @boolToInt(c > 0xFFFF)) + 1;
                },
            }

            remaining = remaining[len_..];
        }

        // Mark the start of the next line
        if (column == 0) {
            line_byte_offset = @intCast(i32, contents.len);
        }

        if (columns_for_non_ascii.items.len > 0) {
            const line_bytes_so_far = @intCast(u32, contents.len) - line_byte_offset;
            try columns_for_non_ascii.ensureUnusedCapacity((line_bytes_so_far - column_byte_offset) + 1);
            while (column_byte_offset <= line_bytes_so_far) : (column_byte_offset += 1) {
                columns_for_non_ascii.appendAssumeCapacity(column);
            }
        }

        {
            var columns_list = columns_for_non_ascii;
            if (columns_for_non_ascii.items.len > 0 and stack_fallback.fixed_buffer_allocator.ownsSlice(columns_for_non_ascii.items)) {
                columns_for_non_ascii.items = try allocator.dupe(i32, columns_for_non_ascii.toOwnedSlice());
                columns_for_non_ascii.capacity = columns_for_non_ascii.items.len;
            }

            try list.append(allocator, .{
                .byte_offset_to_start_of_line = line_byte_offset,
                .byte_offset_to_first_non_ascii = byte_offset_to_first_non_ascii,
                .columns_for_non_ascii = BabyList(i32).fromList(columns_list),
            });
        }

        return list;
    }
};

pub fn appendMappingToBuffer(buffer_: MutableString, last_byte: u8, prev_state: SourceMapState, current_state: SourceMapState) MutableString {
    var buffer = buffer_;
    const needs_comma = last_byte != 0 and last_byte != ';' and last_byte != '"';

    const vlq = [_]VLQ{
        // Record the generated column (the line is recorded using ';' elsewhere)
        encodeVLQ(current_state.generated_column - prev_state.generated_column),
        // Record the generated source
        encodeVLQ(current_state.source_index - prev_state.source_index),
        // Record the original line
        encodeVLQ(current_state.original_line - prev_state.original_line),
        // Record the original column
        encodeVLQ(current_state.original_column - prev_state.original_column),
    };

    // Count exactly how many bytes we need to write
    const total_len = @as(u32, vlq[0].len) +
        @as(u32, vlq[1].len) +
        @as(u32, vlq[2].len) +
        @as(u32, vlq[3].len);
    buffer.growIfNeeded(total_len + @as(u32, @boolToInt(needs_comma))) catch unreachable;

    // Put commas in between mappings
    if (needs_comma) {
        buffer.appendCharAssumeCapacity(',');
    }

    inline for (vlq) |*item| {
        buffer.appendAssumeCapacity(item.bytes[0..item.len]);
    }

    return buffer;
}

pub const Chunk = struct {
    buffer: MutableString,

    /// This end state will be used to rewrite the start of the following source
    /// map chunk so that the delta-encoded VLQ numbers are preserved.
    end_state: SourceMapState = .{},

    /// There probably isn't a source mapping at the end of the file (nor should
    /// there be) but if we're appending another source map chunk after this one,
    /// we'll need to know how many characters were in the last line we generated.
    final_generated_column: i32 = 0,

    /// ignore empty chunks
    should_ignore: bool = true,

    pub const Builder = struct {
        input_source_map: ?*SourceMap = null,
        source_map: MutableString,
        line_offset_tables: LineOffsetTable.List = .{},
        prev_state: SourceMapState = SourceMapState{},
        last_generated_update: u32 = 0,
        generated_column: i32 = 0,
        prev_loc: Logger.Loc = Logger.Loc.Empty,
        has_prev_state: bool = false,

        // This is a workaround for a bug in the popular "source-map" library:
        // https://github.com/mozilla/source-map/issues/261. The library will
        // sometimes return null when querying a source map unless every line
        // starts with a mapping at column zero.
        //
        // The workaround is to replicate the previous mapping if a line ends
        // up not starting with a mapping. This is done lazily because we want
        // to avoid replicating the previous mapping if we don't need to.
        line_starts_with_mapping: bool = false,
        cover_lines_without_mappings: bool = false,

        pub fn generateChunk(b: *Builder, output: []const u8) Chunk {
            b.updateGeneratedLineAndColumn(output);
            return Chunk{
                .buffer = b.source_map,
                .end_state = b.prev_state,
                .final_generated_column = b.generated_column,
                .should_ignore = strings.containsAnyBesidesChar(b.source_map.list.items, ';'),
            };
        }

        // Scan over the printed text since the last source mapping and update the
        // generated line and column numbers
        pub fn updateGeneratedLineAndColumn(b: *Builder, output: []const u8) void {
            const slice = output[b.last_generated_update..];

            var iter = strings.CodepointIterator.init(slice);
            var cursor = strings.CodepointIterator.Cursor{};
            while (iter.next(&cursor)) {
                switch (cursor.c) {
                    '\r', '\n', 0x2028, 0x2029 => {
                        // windows newline
                        if (cursor.c == '\r') {
                            const newline_check = b.last_generated_update + cursor.i + 1;
                            if (newline_check < output.len and output[newline_check] == '\n')
                                continue;
                        }

                        // If we're about to move to the next line and the previous line didn't have
                        // any mappings, add a mapping at the start of the previous line.
                        if (b.cover_lines_without_mappings and !b.line_starts_with_mapping and b.has_prev_state) {
                            b.appendMappingWithoutRemapping(.{
                                .generated_line = b.prev_state.generated_line,
                                .generated_column = 0,
                                .source_index = b.prev_state.source_index,
                                .original_line = b.prev_state.original_line,
                                .original_column = b.prev_state.original_column,
                            });
                        }

                        b.prev_state.generated_line += 1;
                        b.prev_state.generated_column = 0;
                        b.generated_column = 0;
                        b.source_map.appendChar(';') catch unreachable;

                        // This new line doesn't have a mapping yet
                        b.line_starts_with_mapping = false;
                    },
                    else => {
                        // Mozilla's "source-map" library counts columns using UTF-16 code units
                        b.generated_column += @as(i32, @boolToInt(cursor.c > 0xFFFF)) + 1;
                    },
                }
            }

            b.last_generated_update = @truncate(u32, output.len);
        }

        pub fn appendMapping(b: *Builder, current_state_: SourceMapState) void {
            var current_state = current_state_;
            // If the input file had a source map, map all the way back to the original
            if (b.input_source_map) |input| {
                if (input.find(current_state.original_line, current_state.original_column)) |mapping| {
                    current_state.source_index = mapping.sourceIndex();
                    current_state.original_line = mapping.originalLine();
                    current_state.original_column = mapping.originalColumn();
                }
            }

            b.appendMappingWithoutRemapping(current_state);
        }

        pub fn appendMappingWithoutRemapping(b: *Builder, current_state: SourceMapState) void {
            const last_byte: u8 = if (b.source_map.list.items.len > 0)
                b.source_map.list.items[b.source_map.list.items.len - 1]
            else
                0;

            b.source_map = appendMappingToBuffer(b.source_map, last_byte, b.prev_state, current_state);
            b.prev_state = current_state;
            b.has_prev_state = true;
        }

        pub fn addSourceMapping(b: *Builder, loc: Logger.Loc, output: []const u8) void {
            if (b.prev_loc.eql(loc)) {
                return;
            }

            b.prev_loc = loc;
            const list = b.line_offset_tables;
            const original_line = LineOffsetTable.findLine(list, loc);
            const line = list.get(@intCast(usize, @maximum(original_line, 0)));

            // Use the line to compute the column
            var original_column = loc.start - @intCast(i32, line.byte_offset_to_start_of_line);
            if (line.columns_for_non_ascii.len > 0 and original_column >= @intCast(i32, line.byte_offset_to_first_non_ascii)) {
                original_column = line.columns_for_non_ascii.slice()[@intCast(u32, original_column) - line.byte_offset_to_first_non_ascii];
            }

            b.updateGeneratedLineAndColumn(output);

            // If this line doesn't start with a mapping and we're about to add a mapping
            // that's not at the start, insert a mapping first so the line starts with one.
            if (b.cover_lines_without_mappings and !b.line_starts_with_mapping and b.generated_column > 0 and b.has_prev_state) {
                b.appendMappingWithoutRemapping(.{
                    .generated_line = b.prev_state.generated_line,
                    .generated_column = 0,
                    .source_index = b.prev_state.source_index,
                    .original_line = b.prev_state.original_line,
                    .original_column = b.prev_state.original_column,
                });
            }

            b.appendMapping(.{
                .generated_line = b.prev_state.generated_line,
                .generated_column = b.generated_column,
                .source_index = b.prev_state.source_index,
                .original_line = original_line,
                .original_column = b.prev_state.original_column,
            });

            // This line now has a mapping on it, so don't insert another one
            b.line_starts_with_mapping = true;
        }
    };
};
