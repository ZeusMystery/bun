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
const Joiner = @import("../string_joiner.zig");
const JSPrinter = @import("../js_printer.zig");
const URL = @import("../query_string_map.zig").URL;
const FileSystem = @import("../fs.zig").FileSystem;

const SourceMap = @This();

const vlq_max_in_bytes = 8;
pub const VLQ = struct {
    // We only need to worry about i32
    // That means the maximum VLQ-encoded value is 8 bytes
    // because there are only 4 bits of number inside each VLQ value
    // and it expects i32
    // therefore, it can never be more than 32 bits long
    // I believe the actual number is 7 bytes long, however we can add an extra byte to be more cautious
    bytes: [vlq_max_in_bytes]u8,
    len: u4 = 0,
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
mapping: Mapping.List = .{},
allocator: std.mem.Allocator,

pub const Mapping = struct {
    generated: LineColumnOffset,
    original: LineColumnOffset,
    source_index: i32,

    pub const List = std.MultiArrayList(Mapping);

    pub inline fn generatedLine(mapping: Mapping) i32 {
        return mapping.generated.lines;
    }

    pub inline fn generatedColumn(mapping: Mapping) i32 {
        return mapping.generated.columns;
    }

    pub inline fn sourceIndex(mapping: Mapping) i32 {
        return mapping.source_index;
    }

    pub inline fn originalLine(mapping: Mapping) i32 {
        return mapping.original.lines;
    }

    pub inline fn originalColumn(mapping: Mapping) i32 {
        return mapping.original.columns;
    }
};

pub const LineColumnOffset = struct {
    lines: i32 = 0,
    columns: i32 = 0,

    pub fn cmp(_: void, a: LineColumnOffset, b: LineColumnOffset) std.math.Order {
        if (a.lines != b.lines) {
            return std.math.order(a.lines, b.lines);
        }

        return std.math.order(a.columns, b.columns);
    }
};

pub const SourceContent = struct {
    value: []const u16 = &[_]u16{},
    quoted: []const u8 = &[_]u8{},
};

pub fn find(
    this: *const SourceMap,
    line: i32,
    column: i32,
) ?Mapping {
    _ = this;
    _ = line;
    _ = column;

    const generated = this.mapping.items(.generated);

    if (std.sort.binarySearch(LineColumnOffset, LineColumnOffset{ .lines = line, .columns = column }, generated, void{}, LineColumnOffset.cmp)) |i| {
        return this.mapping.get(i);
    }

    return null;
}

pub const SourceMapPieces = struct {
    prefix: std.ArrayList(u8),
    mappings: std.ArrayList(u8),
    suffix: std.ArrayList(u8),
};

// -- comment from esbuild --
// Source map chunks are computed in parallel for speed. Each chunk is relative
// to the zero state instead of being relative to the end state of the previous
// chunk, since it's impossible to know the end state of the previous chunk in
// a parallel computation.
//
// After all chunks are computed, they are joined together in a second pass.
// This rewrites the first mapping in each chunk to be relative to the end
// state of the previous chunk.
pub fn appendSourceMapChunk(j: *Joiner, prev_end_state_: SourceMapState, start_state_: SourceMapState, source_map_: MutableString) !void {
    var prev_end_state = prev_end_state_;
    var start_state = start_state_;
    // Handle line breaks in between this mapping and the previous one
    if (start_state.generated_line > 0) {
        j.append(try strings.repeatingAlloc(source_map_.allocator, @intCast(usize, start_state.generated_line), ';'), 0, source_map_.allocator);
        prev_end_state.generated_column = 0;
    }

    var source_map = source_map_.list.items;
    if (strings.indexOfNotChar(source_map, ';')) |semicolons| {
        j.append(source_map[0..semicolons], 0, null);
        source_map = source_map[semicolons..];
        prev_end_state.generated_column = 0;
        start_state.generated_column = 0;
    }

    // Strip off the first mapping from the buffer. The first mapping should be
    // for the start of the original file (the printer always generates one for
    // the start of the file).
    var i: usize = 0;
    const generated_column_ = decodeVLQ(source_map, 0);
    i = generated_column_.start;
    const source_index_ = decodeVLQ(source_map, i);
    i = source_index_.start;
    const original_line_ = decodeVLQ(source_map, i);
    i = original_line_.start;
    const original_column_ = decodeVLQ(source_map, i);
    i = original_column_.start;

    source_map = source_map[i..];

    // Rewrite the first mapping to be relative to the end state of the previous
    // chunk. We now know what the end state is because we're in the second pass
    // where all chunks have already been generated.
    start_state.source_index += source_index_.value;
    start_state.generated_column += generated_column_.value;
    start_state.original_line += original_line_.value;
    start_state.original_column += original_column_.value;

    j.append(
        appendMappingToBuffer(MutableString.initEmpty(source_map.allocator), j.lastByte(), prev_end_state, start_state).list.items,
        0,
        source_map.allocator,
    );

    // Then append everything after that without modification.
    j.append(source_map_.list.items, @truncate(u32, @ptrToInt(source_map.ptr) - @ptrToInt(source_map_.list.items.ptr)), source_map_.allocator);
}

const vlq_lookup_table: [256]VLQ = brk: {
    var entries: [256]VLQ = undefined;
    var i: usize = 0;
    var j: i32 = 0;
    while (i < 256) : (i += 1) {
        entries[i] = encodeVLQ(j);
        j += 1;
    }
    break :brk entries;
};

pub fn encodeVLQWithLookupTable(
    value: i32,
) VLQ {
    return if (value >= 0 and value <= 255)
        vlq_lookup_table[@intCast(usize, value)]
    else
        encodeVLQ(value);
}

test "encodeVLQ" {
    const fixtures = .{
        .{ 2_147_483_647, "+/////D" },
        .{ -2_147_483_647, "//////D" },
        .{ 0, "A" },
        .{ 1, "C" },
        .{ -1, "D" },
        .{ 123, "2H" },
        .{ 123456789, "qxmvrH" },
    };
    inline for (fixtures) |fixture| {
        const result = encodeVLQ(fixture[0]);
        try std.testing.expectEqualStrings(fixture[1], result.bytes[0..result.len]);
    }
}

test "decodeVLQ" {
    const fixtures = .{
        .{ 2_147_483_647, "+/////D" },
        .{ -2_147_483_647, "//////D" },
        .{ 0, "A" },
        .{ 1, "C" },
        .{ -1, "D" },
        .{ 123, "2H" },
        .{ 123456789, "qxmvrH" },
        .{ 8, "Q" },
    };
    inline for (fixtures) |fixture| {
        const result = decodeVLQ(fixture[1], 0);
        try std.testing.expectEqual(
            result.value,
            fixture[0],
        );
    }
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
    var len: u4 = 0;
    var bytes: [vlq_max_in_bytes]u8 = undefined;

    var vlq: u32 = if (value >= 0)
        @bitCast(u32, value << 1)
    else
        @bitCast(u32, (-value << 1) | 1);

    // The max amount of digits a VLQ value for sourcemaps can contain is 9
    // therefore, we can unroll the loop
    comptime var i: usize = 0;
    inline while (i < vlq_max_in_bytes) : (i += 1) {
        var digit = vlq & 31;
        vlq >>= 5;

        // If there are still more digits in this value, we must make sure the
        // continuation bit is marked
        if (vlq != 0) {
            digit |= 32;
        }

        bytes[len] = base64[digit];
        len += 1;

        if (vlq == 0) {
            return .{ .bytes = bytes, .len = len };
        }
    }

    return .{ .bytes = bytes, .len = 0 };
}

pub const VLQResult = struct {
    value: i32 = 0,
    start: usize = 0,
};

const base64_lut: [std.math.maxInt(u7)]u7 = brk: {
    @setEvalBranchQuota(9999);
    var bytes = [_]u7{std.math.maxInt(u7)} ** std.math.maxInt(u7);

    for (base64) |c, i| {
        bytes[c] = i;
    }

    break :brk bytes;
};

pub fn decodeVLQ(encoded: []const u8, start: usize) VLQResult {
    var shift: u8 = 0;
    var vlq: u32 = 0;

    // it will never exceed 9
    // by doing it this way, we can hint to the compiler that it will not exceed 9
    const encoded_ = encoded[start..][0..@minimum(encoded.len - start, comptime (vlq_max_in_bytes + 1))];

    comptime var i: usize = 0;

    inline while (i < vlq_max_in_bytes + 1) : (i += 1) {
        const index = @as(u32, base64_lut[@truncate(u7, encoded_[i])]);

        // decode a byte
        vlq |= (index & 31) << @truncate(u5, shift);
        shift += 5;

        // Stop if there's no continuation bit
        if ((index & 32) == 0) {
            return VLQResult{
                .start = i + start,
                .value = if ((vlq & 1) == 0)
                    @intCast(i32, vlq >> 1)
                else
                    -@intCast(i32, (vlq >> 1)),
            };
        }
    }

    return VLQResult{ .start = start + encoded_.len, .value = 0 };
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
        var original_line: u32 = 0;
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
                    original_line = i + 1;
                    count = count - step - 1;
                } else {
                    count = step;
                }
            }
        }

        return @intCast(i32, original_line) - 1;
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
            const len_ = strings.wtf8ByteSequenceLength(remaining[0]);
            const c = strings.decodeWTF8RuneT(remaining.ptr[0..4], len_, i32, 0);
            const cp_len = @as(usize, len_);

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
                columns_for_non_ascii.ensureUnusedCapacity((line_bytes_so_far - column_byte_offset) + 1) catch unreachable;
                while (column_byte_offset <= line_bytes_so_far) : (column_byte_offset += 1) {
                    columns_for_non_ascii.appendAssumeCapacity(column);
                }
            } else {
                switch (c) {
                    (@maximum('\r', '\n') + 1)...127 => {
                        // skip ahead to the next newline or non-ascii character
                        if (strings.indexOfNewlineOrNonASCIICheckStart(remaining, @as(u32, len_), false)) |j| {
                            column += @intCast(i32, j);
                            remaining = remaining[j..];
                            continue;
                        } else {
                            // if there are no more lines, we are done!
                            column += @intCast(i32, remaining.len);
                            remaining = remaining[remaining.len..];
                        }
                    },
                    else => {},
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
                    if (columns_for_non_ascii.items.len > 0 and stack_fallback.fixed_buffer_allocator.ownsSlice(std.mem.sliceAsBytes(columns_for_non_ascii.items))) {
                        columns_for_non_ascii.items = allocator.dupe(i32, columns_for_non_ascii.toOwnedSlice()) catch unreachable;
                        columns_for_non_ascii.capacity = columns_for_non_ascii.items.len;
                    }

                    list.append(allocator, .{
                        .byte_offset_to_start_of_line = line_byte_offset,
                        .byte_offset_to_first_non_ascii = byte_offset_to_first_non_ascii,
                        .columns_for_non_ascii = BabyList(i32).fromList(columns_list),
                    }) catch unreachable;
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

            remaining = remaining[cp_len..];
        }

        // Mark the start of the next line
        if (column == 0) {
            line_byte_offset = @intCast(u32, contents.len);
        }

        if (columns_for_non_ascii.items.len > 0) {
            const line_bytes_so_far = @intCast(u32, contents.len) - line_byte_offset;
            columns_for_non_ascii.ensureUnusedCapacity((line_bytes_so_far - column_byte_offset) + 1) catch unreachable;
            while (column_byte_offset <= line_bytes_so_far) : (column_byte_offset += 1) {
                columns_for_non_ascii.appendAssumeCapacity(column);
            }
        }

        {
            var columns_list = columns_for_non_ascii;
            if (columns_for_non_ascii.items.len > 0 and stack_fallback.fixed_buffer_allocator.ownsSlice(std.mem.sliceAsBytes(columns_for_non_ascii.items))) {
                columns_for_non_ascii.items = allocator.dupe(i32, columns_for_non_ascii.toOwnedSlice()) catch unreachable;
                columns_for_non_ascii.capacity = columns_for_non_ascii.items.len;
            }

            list.append(allocator, .{
                .byte_offset_to_start_of_line = line_byte_offset,
                .byte_offset_to_first_non_ascii = byte_offset_to_first_non_ascii,
                .columns_for_non_ascii = BabyList(i32).fromList(columns_list),
            }) catch unreachable;
        }

        return list;
    }
};

pub fn appendSourceMappingURLRemote(
    origin: URL,
    source: Logger.Source,
    asset_prefix_path: []const u8,
    comptime Writer: type,
    writer: Writer,
) !void {
    try writer.writeAll("\n//# sourceMappingURL=");
    try writer.writeAll(strings.withoutTrailingSlash(origin.href));
    if (asset_prefix_path.len > 0)
        try writer.writeAll(asset_prefix_path);
    if (source.path.pretty.len > 0 and source.path.pretty[0] != '/') {
        try writer.writeAll("/");
    }
    try writer.writeAll(source.path.pretty);
    try writer.writeAll(".map");
}

pub fn appendMappingToBuffer(buffer_: MutableString, last_byte: u8, prev_state: SourceMapState, current_state: SourceMapState) MutableString {
    var buffer = buffer_;
    const needs_comma = last_byte != 0 and last_byte != ';' and last_byte != '"';

    const vlq = [_]VLQ{
        // Record the generated column (the line is recorded using ';' elsewhere)
        encodeVLQWithLookupTable(current_state.generated_column - prev_state.generated_column),
        // Record the generated source
        encodeVLQWithLookupTable(current_state.source_index - prev_state.source_index),
        // Record the original line
        encodeVLQWithLookupTable(current_state.original_line - prev_state.original_line),
        // Record the original column
        encodeVLQWithLookupTable(current_state.original_column - prev_state.original_column),
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

    comptime var i: usize = 0;
    inline while (i < vlq.len) : (i += 1) {
        buffer.appendAssumeCapacity(vlq[i].bytes[0..vlq[i].len]);
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

    pub fn printSourceMapContents(
        chunk: Chunk,
        source: Logger.Source,
        mutable: MutableString,
        comptime ascii_only: bool,
    ) !MutableString {
        var output = mutable;

        // attempt to pre-allocate

        var filename_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
        var filename = source.path.text;
        if (strings.hasPrefix(source.path.text, FileSystem.instance.top_level_dir)) {
            filename = filename[FileSystem.instance.top_level_dir.len - 1 ..];
        } else if (filename.len > 0 and filename[0] != '/') {
            filename_buf[0] = '/';
            @memcpy(filename_buf[1..], filename.ptr, filename.len);
            filename = filename_buf[0 .. filename.len + 1];
        }

        output.growIfNeeded(
            filename.len + 2 + source.contents.len + chunk.buffer.list.items.len + 32 + 39 + 29 + 22 + 20,
        ) catch unreachable;
        try output.append("{\n  \"version\":3,\n  \"sources\": [");

        output = try JSPrinter.quoteForJSON(filename, output, ascii_only);

        try output.append("],\n  \"sourcesContent\": [");
        output = try JSPrinter.quoteForJSON(source.contents, output, ascii_only);
        try output.append("],\n  \"mappings\": ");
        output = try JSPrinter.quoteForJSON(chunk.buffer.list.items, output, ascii_only);
        try output.append(", \"names\": []\n}");

        return output;
    }

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
                .should_ignore = !strings.containsAnyBesidesChar(b.source_map.list.items, ';'),
            };
        }

        // Scan over the printed text since the last source mapping and update the
        // generated line and column numbers
        pub fn updateGeneratedLineAndColumn(b: *Builder, output: []const u8) void {
            const slice = output[b.last_generated_update..];
            var needs_mapping = b.cover_lines_without_mappings and !b.line_starts_with_mapping and b.has_prev_state;

            var i: usize = 0;
            const n = @intCast(usize, slice.len);
            var c: i32 = 0;
            while (i < n) {
                const len = strings.wtf8ByteSequenceLength(slice[i]);
                c = strings.decodeWTF8RuneT(slice[i..].ptr[0..4], len, i32, strings.unicode_replacement);
                i += @as(usize, len);

                switch (c) {
                    14...127 => {
                        if (strings.indexOfNewlineOrNonASCII(slice, @intCast(u32, i))) |j| {
                            b.generated_column += @intCast(i32, (@as(usize, j) - i) + 1);
                            i = j;
                            continue;
                        } else {
                            b.generated_column += @intCast(i32, slice[i..].len);
                            i = n;
                            break;
                        }
                    },
                    '\r', '\n', 0x2028, 0x2029 => {
                        // windows newline
                        if (c == '\r') {
                            const newline_check = b.last_generated_update + i;
                            if (newline_check < output.len and output[newline_check] == '\n') {
                                continue;
                            }
                        }

                        // If we're about to move to the next line and the previous line didn't have
                        // any mappings, add a mapping at the start of the previous line.
                        if (needs_mapping) {
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

                        needs_mapping = b.cover_lines_without_mappings and !b.line_starts_with_mapping and b.has_prev_state;
                    },

                    else => {
                        // Mozilla's "source-map" library counts columns using UTF-16 code units
                        b.generated_column += @as(i32, @boolToInt(c > 0xFFFF)) + 1;
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
            // exclude generated code from source
            if (b.prev_loc.eql(loc) or loc.start == Logger.Loc.Empty.start) {
                return;
            }

            b.prev_loc = loc;
            const list = b.line_offset_tables;
            const original_line = LineOffsetTable.findLine(list, loc);
            const line = list.get(@intCast(usize, @maximum(original_line, 0)));

            // Use the line to compute the column
            var original_column = loc.start - @intCast(i32, line.byte_offset_to_start_of_line);
            if (line.columns_for_non_ascii.len > 0 and original_column >= @intCast(i32, line.byte_offset_to_first_non_ascii)) {
                original_column = line.columns_for_non_ascii.ptr[@intCast(u32, original_column) - line.byte_offset_to_first_non_ascii];
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
