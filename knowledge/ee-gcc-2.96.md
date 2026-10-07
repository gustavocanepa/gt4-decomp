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
- Return values: if a callee's result stays in $v0 until the end while later temporaries use $v1,
  the function returns that result (keep it in a variable and return it). Old g++ constructors do
  this: call the base constructor, store the vtable pointer, return what the base constructor
  returned (`this`).
- Counted loops: write the loop the way a programmer would, e.g. `for (i = 0; i < 125; i++)
  v = f(&obj->elems[i], v);` over an array (or `p++` as its own statement). The compiler itself
  turns it into a down-counting register plus a pointer stride; reproducing that counter by hand
  with do/while or `p++` inside the call puts the decrement in the wrong slot.
