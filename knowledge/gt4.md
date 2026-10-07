Known facts about Gran Turismo 4's code (learned while matching; add new ones as they are found):
- Game code is C++; old g++ ABI. Virtual calls look like: vtbl = *(obj+k); entry = vtbl + 8*i;
  delta = (short)entry[0]; fn = entry[4]; fn(obj + delta, ...). Write them in C style with a
  struct VEntry { short delta; short index; R (*fn)(...); }.
- Strings keep their length 16 bytes before the text.
- sqrt is inline asm: __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)).
- Numbers may be stored as full-width EUC digits (0xA3B0 + digit).
- Constructors: `r = base_ctor(self); self->vtbl = D_xxxxxxxx; return r;` (vtable pointer often
  at offset 4, after the first member).

## Rules confirmed on 128-512 byte functions

- Pointer-to-member calls (`lh` delta/index, `ld` of the vtable entry, `slti` + `movz` choosing the target) only match with real C++ syntax: `typedef R (Obj::*PM)(args);`, the PMF passed by value (it arrives in a register such as $t0 and is spilled to sp+0), called as `(get(h)->*pmf)(...)`, with the object read once through a small `static inline` accessor before the index test. Emulating it by hand in C does not match.
- Argument evaluation order is visible: when the this-adjustment is computed before a temporary built for an argument, put the argument's construct-and-test in an inline function called inside the argument list.
- `size = q->cap + 0x10;` written before a call keeps `cap` in a saved register (`lw s0` in the delay slot, `addiu s0, s0, 0x10` after the call); passing `cap + 0x10` inline computes it into $a1 instead. This is the string-release pattern; its 4th argument is `func_005C11A8()->name`.
- A value loaded into $v1 and then copied to $v0 comes from reading it through a small inline accessor; iterator results written as one ternary stored once (`ret->node = (eq || cmp < 0) ? hdr(t) : j.node;`). Iterator and string temporaries take 16-byte stack slots (pad such structs to 0x10); stack slots follow declaration order.
- `if (f() < 0)` written directly is predicted unlikely (`bgezl`, else-body in the delay slot); moving the test into `static inline bool less(...) { return f(...) < 0; }` gives plain `bgez` + `b`. Seen in SGI STL `lower_bound`: `len` and `middle` stay in memory because `distance`/`advance` are inline helpers taking pointers, and `middle = first` is initialised at its declaration.
