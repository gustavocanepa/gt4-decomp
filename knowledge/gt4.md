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
- The game code was compiled with `-fno-exceptions` (only 53 library functions, from 0x596fa0 on, have exception frames), and so are our sources: constructors/destructors and RAII helpers no longer drag in exception cleanup, so real C++ classes can be used where the original used them.
- A load right after a constructor call landing in $v1 instead of $v0 means the constructor is declared returning a pointer (it returns `this`), even when the result is ignored.
- Virtual call wrapped as `static inline s32 vcall(VObj *o) { VEntry *e = ...; return e->fn((char *)o + e->delta); }` keeps the object in $a1 and the entry in $v1, as in the original; written inline it uses $v1/$v0.
- Two temporaries of different types sharing one stack slot: a `union` of both declared at function scope (block-scoped variables never share a slot).
- An 8-byte, 4-aligned struct returned in $v0 and copied into a member with ldl/ldr: `P8 r = f(x); self->m = r;` (assigning `self->m = f(x);` adds a stack temp and copy).
- A 4-byte temp whose address is held in an $s register in a call's delay slot, followed by a `this != &tmp` check: assign `pt = &t;` before the call and go through `pt`.
- SGI STL in this game: `uninitialized_copy` goes through `value_type(&r)` (taking an address, returning 0), which leaves a dead 16-byte stack store; rb-tree iterators are built with inline `ctor(&j, y)` and compared with inline `eq(&a, &b)`; returned pairs built through a pointer to the temp let two `__insert` calls share one `jal`.
- After a store through a vector element, `finish` is reloaded only when the element type is a struct (not for scalars or pointers).
- 0/1 tests with the default arm first (`beqz; beq 1; b`) are a `switch` with `default`; an if/else-if chain gives `bnel` instead. Inline `c_str()`: `len == 0 ? "" : (p[len] = 0, p)`.
- A method returning a struct by value (hidden pointer): `Str t = e->fn(obj); Str *pt = &t;` builds the result in the named local; assigning to an existing local goes through a temp plus `ldl`/`sdl` copy.
- Calling a pointer-to-member through a smart-pointer holder is one full expression, `*arg0 = (Holder(arg1).get()->*pmf)();` (Holder's constructor and destructor are the two calls; the return temp gets the lower stack slot). Named locals reverse the slots.
- A lock guard pair at sp+0/sp+4 reloaded for a final call is a small class with an inline destructor (`~Guard() { f(conn, arg); }`) used with early returns (GameSpy code, e.g. 004f47f0).
- Rb-tree `insert_unique`: all returns share one return label only when it returns a non-POD pair by value (`Pair(Node *const &, const bool &)` with a copy constructor; `bool` is 4 bytes here). Rb-tree `find`: `It r; r.node = (j.node == hdr(t) || less(k, j.node->value)) ? hdr(t) : j.node; return r;`.
- Vector `_M_insert_aux`: `finish` is reloaded after `construct` only when the element type can alias the `T *` field (e.g. `struct T { T *p; }`); the `if (p)` before constructing is a real placement `operator new(unsigned, void *) throw()`; `destroy` goes through `destroy_aux(first, last, value_type(&first))`; inline `deallocate(p, eos - start)` computes `n` before the null test.
- Calls that return `this` (e.g. func_0015F3E0, func_001792D8, func_001A5D20) are declared returning a pointer: the next handle load then lands in $v1 like the original.
- Two values with unrelated roles in one $s register: one variable reused for both roles.
- Open: library code at 0x596fa0 and above (SGI STL rb-tree/vector, 005d5940, 005d5df0, 005d5f80, 005efcd8) frees stack temporaries at the end of each statement and reuses their slots, while our compile keeps them to the end of the function. Not caused by -fexceptions (checked); possibly other flags or another compiler build for the libraries.
- A declared but unused local array still takes its own 16-byte stack slot: an unexplained 0x10 gap between temporaries is a `s32 spare[4];` at that spot (a single store to it stays in the code).
- `char buf[64] = "x";` compiles to `lb`/`sb` byte copies from rodata, then an inlined `memset(buf + 2, 0, 0x3E)` call (func_005A48D8).
- A value computed only at the call site (`f(&h, vcall() != 0 ? -1 : g(o))`) puts `li -1` straight into $a1 before the `bnez`; assigning `v = -1;` before the test needs an extra saved register.
- Arguments the original loads before an inner call and keeps in $s registers (`f(h0.p, b.p, g(c.p))`) are loaded into locals first, in the original's order.
