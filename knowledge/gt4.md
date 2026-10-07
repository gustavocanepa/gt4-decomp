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
- String copy-construct (rep `ref++` or `func_005C2560`) followed by a reload of `s.p` once at the join: read and write the string pointer through `*(s32 *)&s.p`, so the int store can alias it; a plain `char *` member lets the value stay in a register.
- Where a pointer-to-stack-temp assignment sits decides where its `addiu sN, sp, off` lands (after an earlier call, or in a branch delay slot): place `buf0 = buf;` / `ps = &s;` exactly where the original computes it. A 0x10-slot result buffer needs its own pointer variable.
- `d = (char *)(r + 1)` inside the else branch keeps the `addiu` in that branch; initialising `d` at its declaration hoists it above the branch.
- Several string temporaries sharing one stack slot (all at sp+0) come from one `Str s;` declared at function scope and reused; a separate `Str s` per block gets a new slot. Inside a block, declaration order of pointers decides s0/s1.
- A two-way test on 0/1 is `if (a == 0) ... else if (a == 1)` (`bnez`, then `li 1` / `bnel`), not a switch. A gap before a stack temp is matched by sizing the earlier buffer (e.g. `s32[8]` for 0x20 bytes).
- Open: a handle's object loaded from `0($sp)` and offset by a large constant (`->p10 + 0x38CB0`) lands in $v1/$a0 in the original but $v0/$v1 in ours; inline accessors and reordering have not fixed it yet (00161cb0, 00162ec8).
- An 8-byte `{ptr, int}` guard struct handed to a call is passed as its two members (`f(g.p, g.n)`: two `lw`); passing the struct by value packs it with `ldl`/`ldr` into one 64-bit register.
- Float arguments scaled ahead of a run of calls (several `mul.s` into $f12/$f20/$f21 before the first `jal`) come from separate `float h = a * 0.5f;` statements first. Product sums are written unfactored (`sx * cy * cz + cx * sy * sz`); CSE then picks the original temporaries and store order.
- Real constructors/destructors used as RAII helpers make our compile emit exception cleanup (`__rethrow`, `terminate`), which the original lacks there: use C-style calls or inline helpers. Open question: whether the game was built with `-fno-exceptions` (check whether any function in the original has EH tables before changing the flags).
