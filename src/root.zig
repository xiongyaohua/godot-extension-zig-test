//! By convention, root.zig is the root source file when making a package.
const std = @import("std");
const Io = std.Io;

/// This is a documentation comment to explain the `printAnotherMessage` function below.
///
/// Accepting an `Io.Writer` instance is a handy way to write reusable code.
pub fn printAnotherMessage(writer: *Io.Writer) Io.Writer.Error!void {
    try writer.print("Run `zig build test` to run the tests.\n", .{});
}

pub export fn add_two(a: i32, b: i32) callconv(.c) i32 {
    return a + b;
}

test "basic add functionality" {
    try std.testing.expect(add_two(3, 7) == 10);
}
