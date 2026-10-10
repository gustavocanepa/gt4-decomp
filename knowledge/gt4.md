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
- A handle's object loaded from `0($sp)` and offset by a large constant (`->p10 + 0x38CB0`) in $v1/$a0 as in the original: write `ph = tmp; ps = &s;` before the handle constructor (`ps` lands in its delay slot) and read the object through `(*ph)->p10` (solved in 00162498).
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
- An inline wrapper around a call (`static inline void call(char *p, const char *t) { f(p, t); }`, used as `call(base + 0x3A368, c_str(...))`) makes the big-constant add go through $at into the variable's $s register after the inner call, then `move $a0`.
- Block-scoped scalar temporaries in disjoint branches share one stack slot; two adjacent slots (sp+0x30/0x34) need two function-scope locals.
- `addiu s2, sp, 0x20` for `&string` in a later branch's delay slot: `ps = &s;` comes after the calls that build the source, just before the null check.
- Open: `move $a2, $v0` placed in sprintf's (func_0057DA20) delay slot after the $a0/$a1 setup (0013e370) - not reproduced by prototype, literal, local or inline changes.
- Sony SDK code (sce* wrappers, e.g. the sceDbc RPC at 0058ff90) was built by another compiler: it saves callee-saved registers 16 bytes apart (sd at 0x10/0x20/0x30...), restores $ra first and keeps only the `lui` of a global in an $s register. Our compiler cannot produce it; autoloop.other_compiler() keeps such functions out of the queues (270 found).
- Two temporaries whose stack slots differ between branches (sp+0 in one, sp+0x10 in the other): `buf0[4]` at function scope and `buf1[4]` inside the else block. A `blez` to the second block means the first block is `if (arg2 > 0)`.
- In a destructor, `(char *)self + 0x26D80` gives `lui/ori; addu a0, a0, s0` (constant register first); `if (flags & 1) return func_005C1628(self);` gives the sibling `j`.
- An argument register set again in a branch slot after a call belongs to the next call: declare the current callee with fewer arguments (e.g. func_004468F8 takes 2).
- Two calls made before either result is tested: store both results first (`a = f(e); b = g(e); if (a != m || b != m)`); calls inside `||` make the second conditional. A second call-then-test block whose argument move sits in the `jal` delay slot uses a new variable for its result.
- `len = x; if (n < len) len = n;` gives `movn` into len's register (as the original); a `b < a ? b : a` helper gives `movz` into the other operand's register.
- Static init/destroy functions `(init, prio)`: test the priority first, one `if (prio == 0xFFFF && init == 1)` per object (nesting merges the repeated init tests). Array-destroy loops name the global directly (`if (D) { T *q = D + 2; while (q != D) { --q; dtor(q, 2); } }`) to get the original's `beql`/copy.
- String assignment: `if (src != &self->s) { release(dst); copy-construct dst from *src; }`, returning void.
- A `lw; or 0x200000; sw` flag set whose store sits after a neighbouring float store (with the float field reloaded afterwards) is a 1-bit bitfield write (`u32 b:21; u32 dirty:1; self->dirty = 1;`): bitfield accesses alias everything. A plain `flags |= K` hoists the `lw` above the float store.
- A small signed `switch` on a call result with cases 1/2/3 gives a compare tree (`beq 2; slti 3; beq 1 / beq 3`); shared tails between cases come from writing each case in full.
- An array of handle objects declared inside a loop body (`Handle hs[2]` with inline ctor/dtor wrappers around the game's ctor/dtor) reproduces gcc's own vec-init loop (`k = 1; do { ctor(p); p++; } while (--k != -1)`) and vec-delete loop (`while (q != hs) { --q; dtor(q, 2); }`); hand-written loops hoist the constants into extra saved registers.
- An inline `operator=(const Handle &rhs)` used at two sites in a loop gives two hoisted pseudos for `&h` (one feeding `rhs.p` loads, one the compares and call arguments); do not add a `ph = &h;` variable. A later `h.p` read through the second register is an inline accessor call `((Handle *)&h)->get()`.
- Temporaries of different handle types sharing one 16-byte slot in game code: one plain `struct Handle16 h` declared inside the loop body after the array, calling the game's ctors/dtors explicitly; slot order inside a loop follows declaration order.
- Open (004a4550): a base address `0x70002000` (scratchpad) kept in a register across a jump table in the original, constant-propagated into every case by our compile; local pointer, volatile, register and split constants did not help.
- A virtual call's vptr load scheduled after an unrelated float store (`swc1` then `lw vt, 4(obj)`): model the vptr field as a union member (`union { char *vtbl; s32 word; } u;`) so it aliases everything; a plain `char *vtbl` lets the load hoist above the store.
- A struct temporary partly addressed through a register (`swc1 f0, 0($s0)` for `.x`, sp-relative for `.y`/`.z`): assign `pv = &vec;` right after the first value is computed and store all members through `pv`; cse turns the others back into sp-relative stores, and the `addiu s0, sp, off` lands where the assignment sits.
- Several copies of the handle-assign idiom (`if (dst != buf) { new = *buf; retain; old = *dst; release; *dst = new; }`) share function-scope `newVal`/`oldVal` locals; a `static inline` helper gives each site its own pseudo and shifts every saved register.
- A stack array used both as a call argument and as an assign source is held in a pointer local (`arr0 = arr;`), which also gives it an early saved register.
- `bne` vs `bnel` with a saved-register reload in the slot follows from whether that register is dead on the fallthrough path: get the register assignment right and the plain `bne` appears.
- Open (00231508, transform-stack push): `mov.s` copies of address-taken stack locals before their stores, and reloads after a matrix `operator=` join, could not be produced from source.
- A 16-byte stack slot used by a struct in one branch and a handle array in the other: function-scope `union { struct Dst v; s32 arr1[4]; } u;` (block-scoped locals in disjoint branches never share it).
- A hidden-pointer struct return whose callee is solved as `Dst *f(Dst *dst, Src *src)` is called exactly that way, into `&u.v`; `u.v = f(...)` adds ldl/ldr + sdl/sdr temp copies, and an 8-byte POD return goes through $v0 (`dsll32/dsrl32`) instead.
- After an if/else join, a first read of a stack struct through a saved register (`lwc1 0($s0)`) and a second sp-relative (`lwc1 0x14($sp)`) come from `static inline` accessors (`getx(&u.v)`, `gety(&u.v)`); a `pv->x` pointer or a `const Dst &` reference keeps the pointer live for both.
- A float result kept across the next virtual call (`mov.s $f20, $f0` in its delay slot, both stored just before the consumer call): two `f32 x, y` locals assigned from the calls, then `pvec->x = x; pvec->y = y;` with `pvec = &vec;` placed before the first call.
- The "build string from literal, call, destroy" triple (D_00659FA8 rep, func_005C2560 / ref++, func_0057F260, func_005C2630, func_002F3818, --ref / func_00326798) reproduces verbatim from func_002CBB18 with only the string, callback and global addresses changed.
- Handle/holder constructors declared returning `void *` (this) make the next temporary avoid $v0 even when the result is unused (`slti $v1` right after `jal ctor`; `addiu $v1, $s1, off` for the next member's address).
- Two string temporaries in disjoint branches that do NOT share a slot: two function-scope `Str s, s2;` with one shared `Str *ps` pointer (compare the union idiom for ones that do share).
- Float stores grouped per sub-object and never interleaved with neighbouring int stores: the vector types are unions (`union Vec2 { f32 a[2]; }`), which serialises their stores against everything else.
- A zero temp passed by address to a member constructor (`sw $zero, N($sp)` in the `jal` slot) is a pointer-typed local (`Node *z = 0;`), which keeps it ordered after list-node stores through an unknown base.
- An int member store that keeps its source position between a `char *` store and a global load is a union member (`union { s32 i; f32 f; } m90`); a plain `s32` gets hoisted.
- Open (00255298, mWidget constructor): a bitfield and/or chain kept in $v1 with constants in $v0 in the original, swapped in ours; build/auto/agent/00255298.cpp otherwise matches.
- Block-scoped struct locals in sequential blocks never share a stack slot, nor do inline-helper frames (each inlined helper with a local struct adds a 16-byte slot). A layout with gaps (e.g. r3@0x20, r1@0x30, gap, r2@0x50) comes from function-scope declarations in that order with an unused `s32 spare[4];` for the gap.
- A stack object constructed in several sequential blocks through a fresh block-scoped `Reader *pr = &r3;` gives one CSE'd `addiu $s2, $sp, 0x20` and `sw vtbl, 0($s2)` with sp-relative member stores, like an inlined constructor; writing `r3.field` directly makes every store sp-relative.
- A call result tested once per block (`if (ok) return true;`) is a block-scoped `s32 ok` per block; one shared `ok` gets a saved register and shifts the others.
- A string pointer kept in one $s register for the whole function (also used in the release): one function-scope `Str *ps = &s;` assigned right after the early-return check. Do not wrap the build-string idiom in a `static inline` helper (it changes the `r->ref++` code); expand it per block (a macro is fine).
- A member value that must be computed before a vptr store goes into a named local first (`f32 *dst = &self->padRight;`), with the vptr as a union member so the stores keep their order.
- A `const char *src` chosen in two disjoint branches is block-scoped in each branch; one function-scope `src` takes an extra saved register and gets hoisted into a call delay slot.
- A large buffer in one branch overlapped by a handle and a string in the other is one function-scope union of the buffer and a struct of the other branch's locals (padding arrays for the gaps), e.g. `union { char buf[0x100]; struct { s32 arr0[4]; s32 spare[4]; Str s2; } e; } u0;`.
- A handle slot reused first for a temporary holder and then as the destination of the handle-assign idiom is one union reached through a pointer local set at the top of the function.
- `if (f(...) >= 0x100)` on an unsigned-returning callee gives `sltiu; bnez` with the default in the delay slot only when the result is stored first and the default assignment is written after the call.
- The two-callback registration variant is `func_002F3860(obj, &s, fn1, fn2)` (both function pointers loaded with lui/addiu before the jal); the 4-block MActor registration is the func_00308888 template.
- Open (00135348, MCalendar::putRunRaceEvent): a c_str() result kept across the string release is loaded into $a0 and copied into the kept register in the original (shared reload by PRE); ours loads into the kept register and copies to $a0.
- A string temporary sharing its slot with another temp built later is a function-scope `union { Str s; Tmp tmp; } u;`, with `Str` padded to 0x10 so the following locals land at 0x10/0x20/0x30...; a call whose argument comes sp-relative instead of through `Str *ps` is written as `&u.s` at that site.
- `xori $s3, $v0, 1` kept across a string release is `bool miss = !func(...)` with the callee declared returning `bool`.
- An identity-matrix init with an inner pointer `addu v1, base, off` and a separate `addiu off, off, 4` induction variable needs an explicit byte-offset loop: `for (i = 0, m = (char *)self->m, off = 0; i < 4; i++, off += 4) { p = (f32 *)(m + j * 16 + off); *p = 0.0f; if (i == j) *p = 1.0f; }`; `m[j][i]` does not match. Loop-init order decides the prologue order.
- `ld; and MASK64; sd` clears of byte-wide fields are not bitfields (an 8-bit byte-aligned bitfield compiles to `sb`): write `*(u64 *)((char *)self + 0x168) &= 0xFFFFFFFF00FFFFFFul;` in source order among the other member stores.
- A compiler-reversed byte-clear loop (`addiu v1, s4, 0x165; sb; addiu -1; bgez`) is a plain ascending `for (k = 0; k < 6; k++) buf[k] = 0;`; reusing an earlier loop's counter variable lets its `li` fill a preceding call's delay slot.
- `Value args[2]` with an inline constructor and no destructor gives two unrolled ctor calls; the destroy loop is then written by hand, `q = args + 2; while (args != q) { --q; dtor(q, 2); }` (operand order `args != q` gives `beq s3, s0`).
- Two exits from an args block that each destroy the args and the return value, followed by an RAII handle destructor: write the loop and dtor explicitly in both paths; the compiler appends the RAII destructor and cross-jumps the shared `return 0` tails.
- Widget-event stack layout (h@0, symbol/return@0x10 shared, Str@0x20, args@0x30, tmp@0x40, ints@0x50): one `s32 ret[4]` for both the symbol id and the return handle, 16-byte `s32[4]` arrays for h/tmp, scalar ints; BLKmode locals never reuse freed slots, scalars do.
- `if (a < 0 || a >= p->count) return -1;` keeps the second `li -1` as its own `b; li` block; two separate `if (...) return -1;` statements CSE the constant and turn the second test into a `beql` to the epilogue.
- Open: 003f1bd8 (`sb` into `self + 8 + idx * 4 + 0xF8F0` with the original adding the 8 first and using a -0x710($at) displacement) and 002d6f58 (one `beqz` + plain slot vs our `beql`).
- Static-init functions `(init, prio)` of the 72-object header family (155 x 1792 B, 70 x 1692 B, 2-arg ctor and double-registration variants: 244 solved by tools/static_init.py): the header defines 72 globals of a 4-byte class numbered 0..0x47 (8 bytes apart: MIPS DATA_ALIGNMENT puts structs at 8) plus a registration object whose inline ctor calls func_00325010(&tab, &buf, size, cb1, cb2, cb3). Defining them (`Id D_008211D8(0); ...`) compiles byte-identical plus the 32-byte `_GLOBAL_.I.` wrapper, but the objects land in the object's own .data; the hand-written form `if (prio == 0xFFFF && init == 1) ctor(&D_x, n);` per object with `static inline void ctor(Obj *const self, s32 n)` matches with externs. The `const` this-pointer is essential: the tree inliner substitutes a const parameter directly and gives the other one a temporary, so `li value` comes before the `lui` of the address (a non-const `self` reverses them, 211 words off). The priority test reappears every 10 objects because CSE follows at most 10 branches (cse.c PATHLENGTH); do not nest or merge the tests.
- Open (0012c250 and 5 more, 1856-1904 B): the same header plus one global with a real ctor and a dtor (`func_576090(&D)`, `if (prio == 0xFFFF && init == 0) func_5760A8(&D, 2)` after the registration call): 5 words differ, the original materialises `ori $a0, 0xFFFF` one block later (block 0x41 instead of 0x40) and leaves block 0x40's branch unthreaded; condition order and statement order make it worse. Best probe: build/auto/static_init/0012c250.cpp.
- Dtor guard `bnez $s0` + `ld $s0` copied into the slot (instead of `bnel`) = the destructor was compiled earlier in the same translation unit (2026-10-09, 27 solved, e.g. 004440f8): with -fno-exceptions every compiled function becomes TREE_NOTHROW (toplev.c, nothrow_function_p), calls to it get REG_EH_REGION 0, and reorg's liveness scan (resource.c find_dead_or_set_registers, which stops at any call that can throw) then reaches the epilogue's `ld $s0` past the dtor call and finds $s0 dead on the fallthrough. Declare such callees `throw()`; tools/static_init.py tries none, the init == 0 callees, then all callees. A callee in another unit keeps `bnel` (0012c250's dtor at 0x5760A8). General rule for any `bne`/`bnel` + reload near-miss whose fallthrough reaches a call.
- Open (static-init, 8 large ones with a real ctor+dtor global: 0012c250, 001fe7e0, 00208760, 00232470, 00235ed0, 002a3a58, 002b5678, 002b7998; 5 words each): the first `init == 1` test using the shared `1` register (block 0x40 / 0x3F) steals the `ori 0xFFFF` from the next block's filled `bne` (reorg steal_delay_list_from_target) where the original fills its slot from the fallthrough. By reorg.c that needs fill_eager's prediction <= 0 (REG_BR_PROB < 5000; ours 6001 from the NE heuristic) or the next block's `bne` still unfilled at that point; throw() on any subset of callees, -g, sched/cse/gcse/regmove flags and -O1/-O3 do not move it. Probe: build/auto/static_init/0012c250.cpp.
- Registration functions (tools/registration.py, 101 solved from the template): besides the one-callback registrars there is `func_002F3860(obj, &s, cb1, cb2)` with cb2 possibly 0 (`daddu $a3, $zero`), cb1 possibly 0 (`daddu $a2, $zero`, the callback then in $a3) or cb2 == cb1 (`daddu $a3, $a2`); `func_00306780` / `func_002F36E0(obj, &D_global, cb)` register a .bss object without a string (cb may be 0); the parent getter after the class string is any 0-argument function (func_00309CC0, func_00255260, func_002D4670, ...). A callback loaded in the registrar's delay slot shows after the `jal` in the listing. With no method blocks (class + parent + global registrations only) the class string's locals are function-scope, not a block (func_0012B6E8 form). Left: 002ee208 (extra `func_00305550(&D)` call before the class block), 3 others with calls outside the template.
- The script engine is Polyphony's Adhoc (bytecode version 5 in GT4 retail); Nenkai's GTAdhocToolchain and gt-modding-hub document the VM and how native "host methods" are exposed, and the OpenAdhoc GT4 script sources call the natives by name, so they can cross-check config/adhoc_methods.txt (names and facts only; check licences before copying anything).
- Siblings (tools/siblings.py): functions that differ from a matched one only in immediates (flag masks, ids, string addresses) match from the matched source with the values substituted (mSceneViewFace__virtual_72 from __virtual_71 etc.). Structure constants hidden in the source as `r + 1` / `sizeof` (the string Rep's 0x10 vs 0x20 header, 7 functions like 0023a5d0) are not substitutable this way.
- Script-bound accessors (tools/accessors.py, 491 functions): the getter/setter families are one shape, `(s32 *ret, void *ctx, s32 argc, Obj **args)` with `if (argc > 0) {setter} else {getter}` (`blez`), `if (argc == 1)` (`bne a2, 1`), `if (argc >= 2)` (`slti; bnez`) or a getter alone `(s32 *ret)`; handle ctor `func(&buf[, ctx])`, the value through a vcall (slot 0x58 bool, 0x18 string, others int/float), the result wrapped by func_002FE278 (int/bool), func_002F9360 (float), func_00314B20 (string) and assigned with the retain/release idiom, dtors `(&buf, 2)`. Emitting the statements in the original's instruction order reproduces where `p1 = buf1;` and the temporaries go; the handle ctor must be declared returning `void *` when the next load lands in $v1; a stored call result goes through a temporary (`t = vcall(); obj->x = t;`, the lhs address is otherwise evaluated before the call); a masked flag passed as a bool argument needs `t = x & 2; f(p, t != 0)` (inline `(x & 2) != 0` gives `sra/andi`); a load typed `s32` cast to `char *` at use compiles like a pointer.
- Open (005a48d8 memset 728 callers, 005a4724 memcpy 337): newlib-style R5900 loops (pcpyh/pcpyld + sq; lq/sq,
  ld/sd, byte tail). memset looks hand-written (gas `li 0xFFFFFFFF` as lui/ori, unfilled delay slots): an
  asm_functions.txt candidate. memcpy's C (u128 big loop, long middle loop, `while (len--)`) gets every
  instruction but keeps dst0 in $a0 where the original copies it to $t0 first and leaves the byte loop's slot empty.
  2026-10-09: memset is now in asm_functions.txt (pcpyh/pcpyld need inline asm, which the judge rejects; ee-gcc
  2.9-990721 on build/scratch/hc/ms.c reproduces its lui/ori -1, `b`+`sltiu` and `beql`+`sd` shape, but not the extra
  short-loop nops, so the exact compiler is not installed). memcpy: the byte loop puts its short-loop nop in the bne
  delay slot (2.9 habit) yet loads -1 with addiu (2.96 habit); no installed compiler (2.96 with -O1/-O2 minus
  gcse/sched/rerun-cse, -fno-strict-aliasing, nosib; 2.9-990721/991111/991111a/-01) nor newlib's `int len` +
  sizeof-unsigned compares (build/scratch/hc/v/) gets the $t0 home. Likely a later Sony ee-gcc build; leave it.
- Open (00161e00, 00164778 and 2 siblings, 160 B): `obj->p10 + 0x3A368` stored at +0xC keeps the big add in $s0 (`lui/ori/addu`) and a 0xC displacement; ours folds both into one `lui 4; addu; sw -0x5C8C`. Neither a `char *` local nor an inline store helper (`store(base + 0x3A368, v)`) reproduces it from the generator.
- mSceneViewFace event virtuals 73-81 (family 9, 8 x ~800 B): not siblings of the matched 71/72. Each is its own variant: onButtonPress/Release have two extra calls and `return 1` paths instead of the flag test, onActivate/onCancel take three arguments (`Value args[3]` gives gcc's vec-init loop; the third is `self`), onEnter/onLeave/onFocusEnter call func_0022F3A8 before or after, onFocusLeave tests the flag after the early `return 0`. The three-argument attempt (build/scratch/acc/264f60.cpp) is 35 words off: `p0`/`dst` swap their $s homes with the third argument and one delay-slot choice differs. Hand work per function, not a template.
- ee-gcc 2.9 functions (tools/other_compiler.py): 10 of 270 match as m2c drafts (005840c0, 00585fe0, 005b8540-005b8c60: small libgraph-style wrappers); the near misses (build/auto/other/, closest 7-11 words off) are branch polarity and saved-register order, i.e. the same draft problems as everywhere else, so they belong to the permuter / fragments passes once those accept the compiler marker. SDK drafts write hardware registers as `*(void *)0x12001000`, which 2.9 rejects; the tool types them `u32`.

## The ref-counted string is libstdc++ v2's basic_string (gcc 2.96 std/bastring.h)
- func_005C2560 (called from ~3,270 places) is `basic_string<char>::Rep::clone()` and matches when written with the library's own inline helpers, nested as in bastring.h/bastring.cc: `Rep::frob_size()` (16, doubled until it fits), `Rep::create()` (`new (extra) Rep`, `res = extra; ref = 1; selfish = false`), `Rep::operator new` taking the size as a parameter (so `sizeof(Rep) + extra` is computed before the allocator call — the engine's allocator is func_00326750(size, 4, func_005C11A8()->name)), `Rep::copy()` (`if (n) traits::copy(data() + pos, s, n)`) and `data()`. Writing the same logic flat gives the right length but other register homes; each inline level is visible in the allocation.
- Rep header: len @0, res (capacity) @4, ref @8, selfish @0xC (stored as a word), text at +16. So the other hot string helpers (func_005C2630, func_0057F260, func_00326798, func_005C11A8...) are most likely basic_string/Rep members too: decompile them from bastring.h/bastring.cc with the same inline structure.
- func_005C2630 is `basic_string<char>::replace(pos, n1, const char *s, n2)` from bastring.cc, written exactly in the library's order (len, clamp n1, newlen, check_realloc -> Rep::create + three Rep::copy + repup, else Rep::move + Rep::copy; rep()->len = newlen) with the same inline helpers (check_realloc clears `selfish` and tests ref > 1 || s > capacity || excess_slop; release -> Rep::operator delete -> func_00326798(ptr, sizeof(Rep) + res, 4, heap name)). It matches only with `-fno-strict-aliasing` (`/* compiler: ee-gcc2.96-no-strict-aliasing */`): the library reloads `dat` after every store through the Rep, which strict aliasing would CSE away. expat was built the same way, so Sony's libraries (libstdc++, expat, likely the rest of the library region) were compiled with -fno-strict-aliasing — try that flag first on any library-region near miss. `bool` is 4 bytes in this g++ (stored with sw).
- More basic_string<char> members matched (2026-10-09), same recipe: `alloc(size, save)` func_005CB5A0, `replace(pos, n1, n2, c)` func_005CB368, the member template `replace(iterator, iterator, const char *, const char *)` func_005C5028, `resize(n, c)` func_005EE900 (append/erase forwarders to replace(n,c)); second instantiation: Rep::clone func_005D2B58, replace(pos,n1,s,n2) func_005D2C20, replace(n,c) func_00605888, alloc func_00605A98, iterator replace func_00609BB8; allocator-free members `find(const char *, pos, n)` func_005F00D0 / func_0060DEE0, `rfind(char, pos)` func_005DACE0 / func_0060E690, `find(char, pos)` func_0060E700 (identical code per instantiation; told apart by address). The second instantiation's Rep::operator new is `if (n) return func_00575E60(16, n); return 0;` (the `if`/ternary forms match, a `p = 0; if (n) p = ...` form does not) and operator delete is `func_00575DA0(p)`.
- Rep::set(pos, c, n) takes the character BY VALUE and calls `string_char_traits<char>::set(s, const char &c, n)` (memset = func_005A48D8) BY REFERENCE: the by-value copy lives in one stack slot stored right before each memset (`sb $fp, 0($sp)` in the jal delay slot). Only C++ references reproduce it (a C pointer version takes two slots); so replace(n,c) and its relatives must be .cpp.
- Game code calling the members inline: `nilRep.grab()` (D_00659FA8: clone when selfish, else ++ref) + `assign(s, n)` = replace(0, npos, s, n) is the (const char *, n) constructor (func_0016CFB8); a non-const operator[] is `selfish()` -> `unique()` -> alloc(length(), true) then `selfish = 1` (func_0032B928, needs -fno-strict-aliasing even in game code). Finder scripts used: frob_size loop (`bnel` with `sll r,r,1` in the delay slot) over all functions, and an opcode-sequence fuzzy match of a .cpp with every bastring.cc member against unmatched functions of similar length.
- Game functions returning a string built inline (2026-10-09, 13 matched: 0019DAA8, 001F2028, 0030D928, 00316E18, 002A7EB0, 00328508, 002F90B0, 00120020, 00120100, 002457E8, 003262B0, 0030D510, 0030D608): the bastring.h constructors written as small `static inline` helpers in C++ with the default compiler — `(const char *)` = grab + `assign(s, strlen(s))` (func_0057F260 then replace), default ctor = grab alone (the `else` of a null-global check), copy ctor = `rep(src)->grab()`. Finder: build/auto/strwork/find.py (unmatched functions with the D_00659FA8 grab and a replace call, ~340; the short ones are done, the rest add other calls). A float formatted for the string (`lwc1 $f12; jal func_0057FB50`) is fptodp: an explicit `double d = func_0057FB50(f)` with `const char *fmt = D;` assigned first matches with every reloc checked (passing the float to the variadic call also matches but leaves the libcall unchecked). Varargs formatters use `__builtin_va_list` / `__builtin_stdarg_start`. `c_str()` must be written with the library's own nesting (`if (length() == 0) return ""` with "" = D_0069DED8; `terminate()` -> `traits::assign((*rep())[length()], eos())`; `return rep()->data()`) and the caller's test as `!empty()` (bool-returning inline `size() == 0`): then the redundant second length test survives as in the original; flat code lets gcc thread it away. Open: 001F5EC8 (`D_00645570 + 0x60C` is materialised as base `addiu 0x5570` then `addiu 0x60C`; every source form folds it into one `%lo`); 00246F58 (Style ctor with a string member: grab uses $v1/$a1 instead of $a1/$a2 and the flag stores schedule differently whatever the source order).
- String temporaries destroyed in game code (2026-10-09, 14 matched, e.g. 0027D530, 0027C3F8, 0029F7E8, 00234A98; generator build/auto/strwork2/gen.py): the destructor is bastring.h's `rep()->release()` written as nested inlines `destroy(s) -> release(rep(s)) { if (--r->ref == 0) rep_delete(r); } -> deallocate(p, sizeof(Rep) + res) -> func_00326798(p, n, 4, func_005C11A8()->name)` — the same helper set as the returned-string functions plus `copy(dst, src) = grab(rep(src))` and a default `construct(s)`. A value slot or string slot 0x20 bytes wide in the original frame (local at sp, next local at sp+0x20) is reproduced by an array (`s32 v[8]`, `String s[8]`). A callback object whose vtable is stored through a saved register (`sw $s0, 0($s1)`, s1 = &cb) and whose destructor re-stores the vtable then calls the base dtor `(&cb, 0)` is written through `Cb *pcb = &cb; pcb->vtbl = vt; ...; pcb->vtbl = vt; base_dtor(pcb, 0);` (stores through `cb.` directly go sp-relative). Open, same allocation problem as 00246F58: the nil-rep address in `$v1` with the grabbed data in `$a1` (ours `$a1`/`$a2`, e.g. 001F1080, 002DA400 — the class form of grab/ctor/return-by-value changes nothing); grab with `data()` computed only in the else branch and the address kept in `$a0` (0027D708); the copy ctor whose source is reloaded once at the join (00274E90/00274FA8); two `lui` swapped (00212DD0).
- Not found out of line (inlined or unused): find_first_of/last_of/first_not_of/last_not_of, rfind(const char *), compare(const char *), copy(), the first instantiation's find(char) (none of these had a candidate with >0.85 opcode similarity).
- func_0057F260 is strlen hand-written with 128-bit MMI instructions (lq, pceqb, ppac5, plzcw): listed in config/asm_functions.txt, not a C target.

## SGI STL instantiations (tools/stl.py, 2026-10-09)

- The library region's templates are gcc 2.96's own SGI STL (libstdc++ v2 of the 2000-10-03 snapshot, copied verbatim to include/stl) instantiated for the game's types; the whole region was built with `-fno-strict-aliasing` (a `_Rb_tree::_M_insert` only matches with it: with strict aliasing the inlined `_Rb_tree_rebalance`'s colour store is scheduled above the node's pointer stores). The "stack temporaries freed per statement" open issue above was this: the real headers plus that flag reproduce the slot reuse.
- More string-heavy game functions (2026-10-09): 00309D00 is a registration function with a `func_00305550(arg0, &D)` + `func_002F3A30(arg0, 0)` prefix and no class block (tools/registration.py template with those two lines prepended); 0030E100 is the handle form of func_00317C80 (func_00306E00 creates the class into a 16-byte handle, then N `func_003068A8(h, &s, cb)` blocks, each block its own `{ char *v; s32 h = buf0[0]; Str *p = &s1; ... }` scope). Open (2 of 262 differ, a delay-slot swap): 003056D0, a recursive dotted path `r = path(parent(n)) + "." + name(n)` written as a real C++ String class with bastring.h's inline ctor/copy/dtor/operator=/operator+ and `Rep::operator delete(p, size)` under -fno-strict-aliasing (draft build/auto/strwork/p2_003056D0.cpp).
- families 6 and 12 (and their neighbours) are `_Rb_tree<Key, pair<const Key, T>, _Select1st, less<Key>, GameAlloc>` members: `_M_insert` (1 KB, `_Rb_tree_rebalance` inlined), `insert_unique(v)`, `insert_unique(position, v)`, `find`, `lower_bound`, `_M_erase`, `_M_copy`, `erase(key)`, `erase(first, last)` (1.8 KB, `erase(position)` and `_Rb_tree_rebalance_for_erase` inlined), `operator=`. Key = `basic_string<char>` (two instantiations: compare func_005C2A50 / clone func_005C2560, and compare func_00608D98 / clone func_005D2B58 with the second allocator), T = a 4- or 8-byte class with an out-of-line copy constructor, a POD, or a string.
- The allocator is not SGI's: a standard-style class whose `allocate(n)` is `func_00326750(n * sizeof(T), 4, typeid(T).name())` (the getter `func_xxxx()` of the node type's type_info, whose first word is the name: gcc 2.96 puts `_name` before the vtable pointer) and `deallocate` `func_00326798(p, n * sizeof(T), 4, name)`; being a real object it sits at +0 of the tree (`_M_header` at +4, `_M_node_count` at +8, compare at +0xC). The second allocator is `func_00575E60(0x10, size)` / `func_00575DA0`.
- gcc 2.96 emits an explicit instantiation (`template T::iterator T::_M_insert(...)`) in `.gnu.linkonce.t.<mangled>` as a weak function; `-fno-implicit-templates` keeps the callees out of the object, so each member is one source; its calls to other members are relocations against their mangled names (config/stl_symbols.txt gives them addresses, read from the original's `jal` at the same offset).
- The string copy that matches inside templates is the int idiom (`int q = *(int *)&o.p; Rep *r = (Rep *)(q - 0x10); int d = q; if (r->sel != 0) d = (int)clone(r); else r->ref = r->ref + 1; *(int *)&p = d;`): written with pointers (or `r->ref++`) gcc folds `&r->ref` into `q - 8` and materialises it.
- Shared-code members (`find`, `lower_bound`, ...) are identical for every tree with the same key and exist once per mangled name; which copy is which tree's can only be told by callers or by address locality (the tool's tie rules). Most are already matched by hand; `erase(position)`, `clear`, `count`, `equal_range` have no out-of-line copies (inlined into game code, which also inlines `operator[]`).
- Open: `map<Str2, Str2>::_M_insert` (0060e250) differs in 8 instructions: the second string copy's temporary is `$t0` in the original, `$v1` here.
- vector<T> (tools/stl_vector.py, 2026-10-09): the same headers (stl_algobase/alloc/construct/uninitialized/vector.h) and allocators; members are compiled once per element shape with the type_info getter as a placeholder, the image searched for that code, each hit re-instantiated with the getter it calls and judged. Layout: allocator +0, `_M_start` +4, `_M_finish` +8, `_M_end_of_storage` +0xC. Scalar elements copy through `memmove` (func_005A47D4: `__copy_trivial`/`__uninitialized_copy` for POD); `fill`/`fill_n` (uninitialized_fill_n for POD) are out-of-line instantiations next to their vector. Matched: `insert(pos, n, x)` for char/signed char/unsigned short/int/unsigned int/float (508-580 B), `operator=` (304/376 B), `fill`, `fill_n`, a pod1 copy ctor/dtor in game code. Element type is not always knowable: short vs unsigned short, int vs pointer compile identically when nothing loads an element; a callee already named by its matched caller keeps that name (the tool refuses a second type).
- vector of game classes (tools/stl_vector.py `cls_*` shapes, 2026-10-09): the element is a 4-byte class whose copy ctor (and, by flag, dtor `(this, 2)` / operator=) are out of line, written as inline members calling placeholders `stl_cctor`/`stl_dtor`/`stl_assign`/`stl_tf_inner` read back from the original's `jal`s; optionally followed by a vector<unsigned short> member, which matches only wrapped in a struct with implicit copy members (`struct V { vector<U16> v; } v;`: the extra inline level lets loop strength reduction hoist `&cur->v`). Non-POD algorithms are out of line as `__uninitialized_fill_n_aux`/`__uninitialized_copy_aux(..., __false_type)`. Matched: 005c5690, 005c5c18 (element 0x14, copy ctor func_0013BD50). No candidates for the vector members themselves (insert_aux/insert/erase/operator=/dtor) with the c/cd flags. 005c7888 is `__unguarded_insertion_sort_aux` (stl_algo.h, calls `__unguarded_linear_insert` func_005C8950 with a by-value temp) and calls no destructor on the temp: so this element's destructor is trivial, i.e. its inner container is not std::vector (no dtor) - next step: an inner shape with vector's copy ctor but no destructor, then sort helpers.
- The second allocator is SGI `simple_alloc` over memalign with a heap/alignment argument per allocator (two: 0x10 and 0x40): `allocate(n)` = `n == 0 ? 0 : func_00575E60(heap, n * sizeof(T))` (the rb-tree's constant 1 folds the test away), `deallocate(p, n)` = `func_00575DA0(p)` (no size argument).
- Open (vector): `_M_insert_aux`, `reserve`, `erase`, `push_back` found no candidates for scalar shapes (probably inlined into callers, or the elements are classes); most remaining library vector code is for game classes (element 0x14 = { 4-byte class with out-of-line copy ctor func_0013BD50, vector<unsigned short> }, e.g. `__uninitialized_fill_n_aux` 005c5690/005c5c18/005c7888) and needs a class shape with nested vectors. Not started this round: `map<Str2,Str2>::_M_insert` (0060e250) — list/hashtable/deque and 005eecb8 were done in round 3 (below).
- STL round 3 (2026-10-09): **no hashtable/hash_map/hash_set and no deque in the image** (no SGI `__stl_prime_list` in the data, no `_Hashtable_node`/`deque` type strings; the 'hash table' strings belong to the network library). The type-name strings the tf getters point at list every node type: `_List_node<mWidget*>`, `<MEvent>`, `<bool>`, `<MWatcher>`, `<MActor>`, `<bool (*)(RefCounter*)>`, `<HClass>`, `<HThread>`; `_Rb_tree_node<int>` (set<int>), `<HSymID>`, `<pair<const HSymID, HValue>>`, and string-keyed maps. list<T> out-of-line members are only `_List_base::clear` (8 already matched by hand in C, plus 2 new: 0060d8e0 list<pair<Str2,Str2>> and 00608fd0 list<LinkedPtr>, a ring-shared pointer {T *p, prev, next} whose last owner deletes p through a virtual destructor with the vptr at +0x5C); `stl_vector.py -c list` over scalar/POD shapes found nothing else (list code for game classes is inlined into callers). Both list clears use the second allocator.
- The second allocator's free is `func_00575DA0(block)` with no size (was passed a size in stl.py: fixed), and `Str2`'s destructor releases its rep with that same free: with it map<Str2,Str2> `_M_erase` (0060d830) and `_M_copy` (005d2fe8, a different TU: called from 001db2d8) match. map<HSymID, HValue> (getter 005efea0, HValue copy ctor 00323b48, dtor 00323b60): `_M_copy` 005eeb70, `_M_erase` 005eeaf0, `erase(first, last)` 005ef200, `operator=` 005eecb8 (stl.py KNOWN_TREES). set<int> (`_Rb_tree<int, int, _Identity<int>, less<int>, GameAlloc>`, getter 005cb0e0): `_M_insert` 005cad00, `insert_unique` 005cab88 (stl.py's map source with Key/Value/_Identity swapped by hand; a set mode for stl.py is the next step).
- func_00326750 (72 B, 440 callers) is the engine's allocation entry, MATCHED (2026-10-09, nosib): `if (size == 0) return 0; if (align == 4) return func_00326588(size); return memalign(align, size) /* func_00575E60 */;` — func_00326588 takes only the size (it never reads $a1/$a2), so the call passes one argument; with three, align/size get the wrong register homes. Lesson: check what a callee actually reads before trusting the caller's argument registers.

## Sibling calls are a per-function property, not a per-unit flag (2026-10-09)
- tools/region_compiler.py with `ee-gcc2.96-nosib` over 0x100000-0x494578 (6822 functions): 224 matches;
  re-judged with the default profile, 216 of them fail (the original ends in `jal; ld $ra; jr $ra` where
  the default emits `j`). They are spread over 82 of config/units.txt's units, 1-37 per unit, and 71 of
  those units also contain sibling `j` tail calls in other functions (e.g. unit_0046A050: 37 nosib, 72
  with `j`; unit_004271E8: 29 vs 218). No whole unit is no-sibcall: tools must keep trying both
  profiles per function (region_compiler, autoloop), not choose the profile by unit. Units with nosib
  matches and no `j` tail call at all (all small, so not evidence of a unit flag): CarIconMaker,
  unit_00151BB0, mPhotoMapWindow, unit_00265D00, mListItem, unit_002BE7F8, mMoveActor, mRotateActor,
  unit_003A4CF0, unit_003A6878, unit_003C7F78.
- So something in the source suppresses the sibcall in these functions (gcc 2.96 sibcall.c gives up on
  cleanups, addressof, a BLKmode/mismatched return value, args larger than the caller's); the marker
  stands in for that unknown shape, like func_00326750 above.
- Near misses of that run are mostly m2c pointer scaling (an `s32 *`/`f32 *` stepped by the byte
  stride: `p += 4` for `p += 1`, `arg0 + 0xC` on `void **`): 11 fixed by hand. Remaining 1-instruction
  groups: `addu` operand order (~20, `a + b` vs `b + a`), `sltiu 1` vs `xori 1` (`x == 0` vs a bool
  `!`), and a few `beqz`/`beql` delay-slot choices.
- Open big near misses (drafts in build/bigwork/): RaceSolitaire__structor_0 (003E9BF0, 760 B) 26
  off after the vtable address, the dropped `func_00343490(this + off)` / `func_00109A28(this, p)`
  arguments, the virtual call as a VEntry local and statement order: left are the $s3/$s4 homes of
  the constant 1 and `this + 0xE48C`, and member addresses the original computes after a call while
  ours are scheduled above it (inline `this + off` at the call recomputes them: worse). C++ is worse
  (57). func_00361008 (532 B, two float loops over u8 arrays, indexed `x[n - i]` / `x[n + i]`): the
  original derives both destination pointers from one `d + n*4` with a register copy; not found.

## Network: pdistd-http, PDI_NETCNF and the Medius wrappers (2026-10-09)
- pdistd-http and netcnf (0x4e6bd8-0x4f10d0) are C++ built like the libraries: `ee-gcc2.96-no-strict-aliasing`
  where stores through `conn->data` reload the pointer every time (func_004ED588); strings are the
  second basic_string instantiation (nilRep D_00659E20, clone func_005D2B58, replace func_005D2C20,
  operator delete func_00575DA0), header maps are SGI `_Rb_tree::clear()` inline (func_004EA2B8).
- A deleting destructor whose `if (flag & 1) delete` branch is a non-likely `beqz` with the epilogue's
  `ld $s0` stolen into its slot only comes from a real C++ destructor (g++ adds the delete tail):
  name the base class after its destructor's address (`struct func_00578090 { ~func_00578090(); }`
  gives `_$_13func_00578090`, which resolves). func_004ED0C0. `new T` calls `__builtin_new`
  (0x5C1498, now in config/stl_symbols.txt), `delete p` of a polymorphic object is the vtable call.
- Strings copied from literals with `ld`/`sd` (not `ldl`/`ldr`) mean an 8-aligned destination type:
  `struct {...} __attribute__((aligned(8)))` with `strcpy(s->field, "lit")` (func_004EE7C8, 004ED588).
- `ee-gcc2.96-as2004` (formerly `-hilo`, tools/hilo_as.py, now the real 2004 ee-as): the project's gas gives an indexed-global macro's `lui` the
  wrong opcode (`lw rX, 0(rX)` with R_MIPS_HI16) after a `.p2align 3,,7`; the marker writes the
  expansion out. Diff symptom: `! lui $a1, 0x62 | lw $a1, 0x62($a1)`. func_001F6C58.
- Return types again: most near misses here were `$v0`/`$v1` swaps fixed by a callee's void/int
  return (func_004EF570, 004ED980, 004F01E8, 004E7460), or a function declared `int` without a
  return statement (func_004EE7C8).
- Medius wrappers (0x1f0000-0x1f8000): `while (!medius_call(D_00645570, ...)) func_00215298(1);
  return func_001F1368(ctx);`, `if (!func_001F1368(ctx)) return 0;` (the 0 comes back in $v0),
  request structs on the stack initialised field by field before the strncpy calls. Open: unexplained
  stack-slot sharing between a string and a later handle (MNetwork__set_language, disconnect,
  func_001F11E8), the beqz/beql delay-slot choice of func_001F0E98 and func_004EE3D8.

## Shared GT4/Tourist Trophy functions: rules from the first 180 matches (2026-10-09)

Three agents worked through the smallest functions that are identical in GT4 and Tourist Trophy
and were unmatched in both (build/auto/shared_slice*.txt); the CPU tools had failed on all of them.
What repeated:

- **Constructors are real C++ classes.** A base-constructor call followed by member stores whose
  hand-written C plateaus at 2-7 differ (the epilogue restores `ld $s0` then `ld $ra` where ours
  hoists `ld $ra`, or the constants come in another order) matches as a C++ constructor that lets
  the compiler store the vtable pointer itself: 0039A6F8, 00547CE0, 00552730, 003A5288, 0042A918,
  00548458, 00553310. Name the base struct after its constructor (`struct func_005659D8`), a class
  with no known name after its vtable (`struct D_006898F8`, so `_vt$10D_006898F8` resolves through
  tools/symbols.py), or use the known name when `X__vtable` is in symbol_addrs. Still open with the
  same symptom: mCalendar 00132E90 (14 copies), 00415608, 004858A0, 004B1490.
- **Which of `$v0`/`$v1` holds the vtable entry tells the return type of a virtual call:** entry in
  `$v1`, function pointer in `$v0` -> the call's value is returned; the reverse -> a void call.
- **A virtual call whose object lands in `$a2`/`$a3`** takes 2-3 arguments; the other argument
  registers are the caller's own parameters passed through (m2c drafts them as extra arguments).
- **A run of stores before `jr`:** the last store in the source is emitted first, as early as its
  operands allow; move the out-of-place store to the end of the source, or try store permutations.
- **Unused stack space:** a frame 16 bytes larger than the saves with no stack stores is an unused
  local `s32 spare[4]` written once after its last use; a 16-byte slot in a constructor is a
  container member built with a default allocator argument (0020A6C0). Buffer sizes are the frame
  minus the saves (m2c always writes `s8[0x10]`).
- **Early returns:** `li $v0, 0` before the first test with a shared epilogue (or before a null
  test followed by a tail call and a dead `nop`) is `if (!p) return 0; return f(p, ...);`; `&&`
  chains and result variables do not give it.
- **Condition shapes:** `andi 1; beqz` is `(x & 1) == 0` (`!(x & 1)` gives `xori`);
  `nor; srl 31; movn` is `int ok = x >= 0; return ok ? a : b;`; `c.cond; bc1t +2; li 1; li 0` is
  `return a cond b;`.
- **ee-gcc 2.9 code that saves only `$ra` (or nothing)** escapes the 16-byte save-spacing test of
  tools/other_compiler.py: in 0x583540-0x5b73c8 eight such functions matched only with the
  `ee-gcc2.9-991111` marker; the whole range was then swept with tools/region_compiler.py.
- `__builtin_return_address(0)` reads the saved `$ra` slot (`addiu v0, sp, FRAME-0x10; lw a0, 0(v0)`,
  00587440). Copying an aligned 16-byte struct whole gives `ld`/`sd` pairs; member by member gives
  `lq`/`sq`. `*p++` on a signed char array still loads with `lbu`; `p[i] != 0` uses `lb`.
- Generators: the `func_00443ED0` record getters (build/auto/gen_rec_443ed0.py, ~139 call sites
  between 0x43FE00 and 0x44A440) and the `func_005878F8` request family.
- More from the second round: a real C++ copy constructor in game code may need the
  no-strict-aliasing profile (002f9238: the source's float load moved above the vtable store);
  zero stores after a member object's constructor are constructor-body assignments, not the init
  list (00346758); `addiu $s1, this, K` in the base constructor's delay slot is a pointer taken
  before the call, with the base declared returning `Obj*` (0037d288); `mtc1 $zero` + `swc1` is a
  zero passed through a float parameter of an inline setter (00153b08); a global's `lui` kept in
  `$s` across an inner call is the address assigned to a local first (0020eb50); jump-table
  switches match when the cases are rebuilt from the table words (0035fbc8); read-modify-write of a
  word comes from explicit masks, byte-aligned bitfields give `sb` (0039cdf0); a virtual call
  through slot 8 with argument 3, then nulling the pointer, is `delete child; child = 0;`
  (003bfe10). Store order: build/scratch/opus3/perm_fix.py permutes independent store statements
  until the order matches (candidate for tools/near_fix.py).
- Third round (slices to lines ~216-230): g++ 2.96 turns a final call into `j` only when written
  `return f(...)`, even in a void function (a plain trailing call stays `jal`; ee-gcc 2.9 does turn
  it into `j`); a void prototype frees `$v0`, an ignored int result makes the next load avoid `$v0`;
  `for(;;)` with `return` exits stays unrotated while `break` exits move to the bottom; the script
  `Val` unit around 0x47xxxx is no-strict-aliasing code and returns its small value class through
  an inline constructor (`return Val(x);`); placement new keeps its null check only when
  `operator new(size_t, void*)` is `throw()`; a virtual call through `this` in a constructor is
  direct, through a base pointer it uses the vtable; addressed parameters take the lowest stack
  slots; ee-gcc 2.9 code reaches at least 0x5B95A0 (`va_start` under 2.9:
  `__builtin_next_arg(last) - (8 - __builtin_args_info(2)) * 8`). Open families: the 0x70002000
  scratchpad base kept in a register across branches/calls (004a06f0, 004a0890, 004a4c58,
  0049FDA0, 004A40B0, 004A2D20); ee-gcc 2.9 functions whose last call stays `jal` (00583068,
  00582fc0). libio (`_IO_init` 00594fb8 matches) awaits a licence decision (GPLv2 + exception).
  Helpers worth turning into tools: build/scratch/os2b/climb.py (store-order hill climb),
  build/scratch/opus3/perm_fix.py, build/scratch/os1b/callers.py.

## Near twins between the games, as a tool (tools/neartwin.py, 2026-10-09)
- 3,252 open TT functions have a matched GT4 function whose masked words (immediates, offsets and
  addresses hidden) are >= 75% the same (1,393 at ~100%); 1,100 open GT4 functions have such a TT
  twin. The agents' near1/near2 scripts (build/scratch/near1, near2) became tools/neartwin.py; on a
  random sample 41% of the TT pairs and 11% of the GT4 pairs matched by rules alone.
- What the adaptation needs beyond crossgame.py's renames: literals moved by the diff (one occurrence
  of several must be tried in turn: `0xf4` is both a store and a load in one function), a callee of
  one game that stands for two in the other (two handle constructors: rename per call site, not per
  symbol), the inverse permutation of a run of stores, near_fix's passed-through `this` with the
  literal rules re-run afterwards, and the no-sibcall profile for TT's call wrappers of GT4's
  func_001010E0 family (`jal` + epilogue where GT4 has `j`).
- match.suggest_renames must be filtered to real addresses when the twin's code differs at a call
  (otherwise it proposes func_0EC400A0-style nonsense from the instruction delta).
- Still open after the rules: a run of zero stores whose field set changed (the one-to-one literal
  map is wrong under reordering; regenerate the run from the original's offsets), `&p->f` vs `p->g`
  argument shapes, a statement added or removed.
- Round four (2026-10-10): `ee-gcc2.96-no-strict-aliasing` whenever, against the original, float or
  pointer stores move above int stores or a load moves above a store (also in game code); nops inside
  small loops point at the `ee-gcc2.96-as2004` profile (the 2004 assembler); a plain indexed loop
  with a call gives the `lw; nop` preheader and the countdown, a bound read in the condition with
  no call gives `lw; daddu; nop`; registers skipped in a tail call are pass-through parameters; a
  small class returned through a hidden pointer needs a declared copy constructor (a destructor
  alone still returns in v0); old-ABI `dynamic_cast<T&>` is an explicit `__dynamic_cast`, a
  noreturn `__throw_bad_cast` and a real virtual call; in ee-gcc 2.9 `lui 0xFFFF; ori 0xFFFF` is an
  unsigned compare with 0xFFFFFFFF. Store-order search with blocks: build/scratch/os2d/permsearch.py.
- Round five (2026-10-10): when registers are shifted against the original (a temporary in a3,
  saved registers swapped), look for a callee that takes the caller's own parameters unchanged and
  add them — and the reverse, a spurious extra argument swaps saved registers; `lwr` before `lwl`
  means the 2004 assembler (`ee-gcc2.96-as2004`), also for expat's jump tables at .rodata offset 0;
  bool is 4 bytes, a flag stored with sb is unsigned char; an STL tree find returns its iterator in
  v0 when the iterator class has no copy constructor, through a hidden pointer when it has one; a
  countdown loop ending in bgez is a user count-up loop the compiler reversed; one int local reused
  in both branches fixes float register allocation; `float sc[4]` with an inline
  `sincos(const float&)` reproduces the rotation family (0x4251C8...). Switch rules: see
  knowledge/ee-gcc-2.96.md "Switch and jump tables".
- Round six (2026-10-10): a branch whose target skips an argument copy already in its delay slot
  means the callee takes fewer arguments (check its real arity); store order is solved mechanically
  by tagging statements and applying the inverse emission permutation
  (build/scratch/os2e/invperm.py); a `const T&` bound to a by-value return keeps the temporary's
  address in an s-register; by-value argument temporaries sit above the hidden-return temporary,
  an addressed parameter takes sp+0; `int i = 1` used as an index gives `li 4; addu`, a mask kept in
  a variable a shared `li 0x3F`; a one-byte tag struct passed by value is reloaded with lbu, an
  empty struct is passed as 0; a plain trailing call inside a C++ constructor still becomes `j`.
  Register-only differences: use knowledge/gcc296-codegen-map.md and tools/alloc_table.py first.
- Small near misses (Sonnet, 143 matches): an element address in its own local (`e = &t[i]`) flips
  addu to base-first; a literal table address `((T*)0x6211A0)[i]` lets the load fill the jr delay
  slot where an extern array symbol does not (not universal: an extern scalar byte matched once);
  `char *p = D_x; return p + k;` keeps separate lui/addiu; constructors storing the vptr mid-object
  use a base `struct B0 { virtual ~B0(); }`; long long operands fix daddu/and operand order; a stub
  storing every argument register is an unused varargs function; a dead lhu before a word store is
  `(void)*(volatile u16 *)&s->w;`; `for (i = 0; i < n; i++) return &a[i];` explains an unfolded zero
  index. Open: nor-register reuse for long long &=/|=, 2.9 two-operand `mult $zero,v1,a0`.
- Round seven (2026-10-10): `p = base; p += i;` keeps the base in its register (`&base[i]` gives
  the other operand order); try `ee-gcc2.96-no-strict-aliasing` early whenever a load sits after a
  store in the original or locals made from parameters get swapped s-registers; shifts and byte
  stores to the stack without masks are a small byte struct returned in v0 and assigned to a local;
  `mov.s $f12` against integer argument moves follows the declared order of mixed parameters; a copy
  into an s-register right before a loop after the parameter was incremented is an indexed loop
  `list[i]`; an OR with a hoisted -0x8000 is short arithmetic `x | 0x8000`; comparators passed by
  value as one-byte structs need a real member; ee-gcc 2.9 keeps if/else arms in source order and
  `if (!id) id++` gives movz. The retail libgcc fp-bit pack has no guard-bit rounding (modified
  fp-bit, not the snapshot with NO_DENORMALS/NO_NANS).
- Round eight (2026-10-10): the network/UPnP/XML library around 0x52xxxx-0x54xxxx is C, not C++ —
  in C a local whose address is taken goes straight into the argument register; old
  no-strict-aliasing near misses there were artefacts of compiling as C++. Callees defined earlier
  in the same unit need throw(). `if (t == 8) X; else if (t == 7) X;` keeps separate tests (`||`
  folds to a range check). Constant-indexed global pointer tables: one `extern T *D_x;` per element.
  Early exits through `goto out;` to one `return status;`. An int (not unsigned) switch variable
  lets `arr[req - K]` reuse the table's req*4. Two adjacent fields compared with `&&` fold into one
  64-bit compare: write two returns. `__builtin_alloca(n)` matches, a VLA does not. Same stack
  buffer for two handles = one `s32 buf[4]` passed to explicit ctor/dtor calls. Speex (BSD) is
  linked around 0x56b778 (nb_decoder_ctl): a libmatch candidate.
