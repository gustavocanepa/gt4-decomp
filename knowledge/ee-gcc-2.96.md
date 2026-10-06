How Sony's ee-gcc 2.96 (PS2 Emotion Engine, -O2 -G0) shapes code (valid for any game built with it):
- Register allocation and instruction order follow statement order: if only a few instructions
  differ, try reordering statements, introducing or removing a temporary, a pointer variable for a
  sub-struct, an inline helper, a different loop form, or signed/unsigned types.
- Arguments arrive in $a0-$a3 then $t0-$t3 (8 integer registers), floats in $f12-$f19. A register
  that is not written before a call still holds the caller's own argument: the callee receives it
  unchanged, so pass that parameter through. Read which registers each call actually sets.
- Tail calls (C++ front end): a function ending in `j callee` (a jump, after restoring $ra) returns
  that callee's result: write `return callee(...);` with a non-void return type. A final
  `jal callee` followed by the epilogue means the result is not returned (a plain call).
- 64-bit `sd`/`ld` save and restore registers; struct copies of 8-byte aligned data use `ld`/`sd`
  pairs (declare such structs with __attribute__((aligned(8))) or 64-bit members).
- `beql`/`bnel` (branch likely) come from the compiler, not from special source constructs.
