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
- Signs that a function was written in assembly (none of the gcc profiles emits them; check before spending tries): trapping `daddi`/`dadd`/`dsub`/`add`/`sub` (gcc uses the -u forms), `$at` as an arithmetic scratch outside `lui $at`+`mtc1`/`ori` constant loads, `move` encoded as `or rd, rs, $zero` (gcc's move is `daddu`), `sq` saves of argument registers, `$t0..$tN` allocated strictly in first-use order with `$v0/$v1` unused, empty `jr` delay slots and MIPS I load-delay `nop`s. These signs do not move a function to config/asm_functions.txt: by the owner's decision such functions stay open (knowledge/deferred-to-last.md, which lists the 2026-10-23 finds: the network crypto module 0x545a54-0x546ae0, the float/string helpers 0x57f238-0x57fbe0 and the multi-instruction VU0/MMI bodies).

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

## Findings from the tiered swarm (2026-10-11)
- Table scans as `do { ...; i++; } while (i < N)` with a break give the `bnel` + delay-slot `lw` shape; a `for` adds a bounds check first.
- To keep `lw` (not `lbu`) before an `sb`, pass the value through an inline `put(char *, int)` helper.
- A dead constant store to a vptr slot that a later store overwrites needs a `volatile` pointer to survive.
- `pref`: `__builtin_prefetch` does not exist in 2.96; a single `__asm__ volatile("pref 0x0, 0x40(%0)" : : "r"(p));`.
- Float zero stored to a field becomes `sw $zero` unless written through an `f32 z = 0.0f;` local.
- Static-initialization functions (a0=init, a1=prio): `if (prio == 0xFFFF && init == 1) ctor(&D, ...)` per object, with a `static inline` ctor whose parameters are `T *const self, const X *const s` (the `const`s fix the lui order).
- A virtual call with the vtable temp in `$v1` and the function in `$v0`: declare it returning `int` and `return e->fn(...)`.
- ee-gcc folds `x - (-k)` into `x + k` and `x + c*(-k)` into `x - c*k`; a separate `f32 n = -t;` local keeps a `neg.s`.
- Three adjacent independent zero stores come out rotated: source [a,b,c] is emitted [c,a,b]; write them rotated left by one.
- A switch keeps its binary compare tree only with a separate body per case (`case 0: default:` gives slti/bnez); shared or empty bodies merge into range tests.
- A float field set to 0.0f is `sw $zero` unless written from an `f32 zero = 0.0f;` local (mtc1/swc1); an int 0 into a float slot is `sw $zero` via an `s32` member.
- `goto` into the bottom of a do-while (a priming call shared with the loop body) changes saved-register priority (fixes swapped s0/s1); goto chains match multi-branch returns better than `||`.
- A 2-iteration loop written descending is unrolled; ascending `for (i=0;i<2;i++)` stays a loop that gcc reverses (falling pointer, bgez counter).
- A field reloaded inside a loop that gcc hoists: declare the base parameter `int` instead of a pointer (no known base, no invariant load).
- Double constants load from .rodata in first-use order: write long table inits in the retail store order.
- A literal address `lui` + negative `addiu`: recompute hi/lo before naming D_ (0x560000 - 0x14B0 = 0x55EB50).
- 80+ byte struct copies give the 32-byte unaligned block-move loop; N-byte copies are one `struct { char x[N]; }` assignment (`int x[11]` for 44 bytes: lw/sw tail).
- `class B { char pad[N]; virtual ... }` + `class D : public B` puts the vptr at N; slot k is at 8*(k+1); void virtuals give ptr=$v0/fn=$v1, `s32` virtuals the reverse.
- A stack word read, updated and written back before a call (`sp30 |= 9`) folds to a constant unless the local is `volatile s32`.
- `x = 1; if (a) x = a` gives movn; `a ? a : 1` gives a branch. A constant shared by two stores needs one `int one = 1` used in both.
- Bitfield tests kept as `int fx = s.field; if ((fx & 1) == 0)` keep dsll/dsra32; inline they fold to dsrl, and `!(x & 1)` adds an xori.
- Small whole-struct copies (`struct B2 { char a, b; }`) give lb/lb/sb/sb; per-element char copies give lbu.
- haifa sched1 moves insns between blocks only when the whole function fits one 10-block region; past 10 blocks every block is scheduled alone, so a copy that must land in a branch delay slot from another block cannot come out (004768C0).
- On a sched1 priority tie the insn that frees the most registers (kills its source) goes first; source order decides only after that.
- A "dead" `daddu tN, $zero` before a call is usually an extra 0 argument the callee takes (004801C0: 6th argument).
- `volatile` locals or accesses pin store/load order and keep spills (`volatile f32 spill[4]`; `volatile Q *p` to a freshly allocated struct keeps its stores in source order).
- Halfword fields reached through `union { short h[2]; int w; }` stop a short store / int load reordering.
- `*(Raw *)&loc = *(Raw *)(src + off)` with a char-array struct gives the ldl/ldr/sdl/sdr unaligned copy.
- Hex float literals: compute the mantissa from the bits (0x3E199999 = `0x1.333332p-3f`, mantissa 1.2).
- A call result kept but not returned (`r = f(); ...; return r;`) pushes later temporaries to `$v1`.
- `union { s64 v; char c; }` as an element type aliases everything: the compiler reloads fields after the `sd` (func_004303F8).
- A 64-bit compare (sltu/xor directly on $a1, no zero-extension) means the parameter is `u64`; `u32` adds dsll32/dsrl32.
- Inline memcpy of N bytes then a vtable call with a0=this+adj, a1=dst, a2=this: same shape as func_00430570.
- A record whose fields are all one type (all int, or all one pointer type) keeps source store order; mixed field types let the scheduler reorder stores (0048fb58).
- Static-init guards: each `if (ini == 1)` as its own static inline helper, with `float o = 1.0f, z = 0.0f;` locals, gives retail's mtc1 constants and swc1 zero stores (00486e50, 00489180).
- Inline vbeg/vend helpers fix "begin in a temp, then copied"; declare `end = vend(v)` before `it = vbeg(v)`.
- A delay slot holding a copy of the then-block's first instruction: put that assignment first in the then-arm (00355e88).
- `c ? v : 0` gives movz only when v is loaded unconditionally first; a pass-through tail call needs a non-void return (00354af8).
- Nested tables: `struct{...} arr[i][j][k]` indexed loops reproduce gcc's strength-reduced pointers (00358270).
- Float literals one ulp off (pi/16, pi): write a hex float (`0x1.921fb4p-3f`); the decimal form rounds low.
- beq vs beql: an early `if (cond) return 0;` then a flat body gives plain beq; `if (cond) { body } return 0;` gives beql (0048f790).
- A loop exiting by `return` inside `for(;;)` stays unrotated as in retail; `break` to a shared tail makes gcc rotate it (0047a138).
- A local array initialised from string literals is copied with ldl/ldr/sdl/sdr each time; declare it inside the loop body for a per-iteration copy. Later-declared locals get higher stack offsets.
- The no-strict-aliasing profile fixed a float store/load placement around a call (001d5258).
- A function ending in `j func`: write `{ call(); return; }` inside the if (001d2518).
- A constructor-like callee must be declared returning a value (void*) even when unused; with void, local-alloc swaps $v0/$v1 right after the call (001fa3f0).
- `__builtin_expect(x, v) > 0` changes branch prediction without the dsll32 that `__builtin_expect(x > 0, v)` costs (001fa8d8).
- A retail shared tail `b L; daddu a0,sX` comes from a function-scope pointer set at the end of each branch and used once after the join.
- A local whose address is taken through an inline member or reference (e.g. list::iterator) is spilled to the stack and reloaded after each call, but not before the first.
- `if (x) adj(&x, d)` where adj re-tests `*p`: the second test survives only when x is an int field; through a pointer cast gcc folds it (00491b30).
- A virtual call whose object lands in $a2/$a3 passes the caller's own parameter registers through: add that parameter to the vcall prototype (001cc430).
- A `struct Blob { char d[N]; }` assignment at unknown alignment gives the ldl/ldr/sdl/sdr loop plus an aligned ld/sd loop (001cf400).
- Declaring locals in reverse order of last use changes the temp register assignment (t0/t1/t2) on a pure add chain (00472110).
- A local struct or buffer must be sized to the original frame (e.g. a 32-byte stack struct, `char buf[32]`): often the only mismatch (00485e28, 00493ab0).
- `if (inline_bool_pred()) return;` gets beql to the epilogue (predicted taken); a direct pointer comparison is predicted not taken and fills the slot from the fallthrough (00427698).
- One address register across several blocks: read every use through inline members of the same union member (u.s.c_str(), u.s.release(), u.o.get()) so GCSE merges them (001e4290).
- Aliasing follows declared types: if retail reloads a pointer after a store, give the fields the same type (`int`, or `union {int i; float f;}` call arguments); if it keeps the value in a register, give them different types (003fbab0, 00405668).
- Spring family (unit_003F7150, stack `{float acc; float *vel; float *pos}`): `union P {float *p; int i;}` for vel/pos, locals assigned first, zero stores through a static inline taking 0.0f arguments (no `sw $zero` folding), `float k = w->k` right before its first use (00405668, 004051e0, 00405470).
- `int o1 = 4, o2 = 8;` used as `(float*)((char*)p + o1)` reproduces the `addiu v0,4; addu` pointer idiom (003fd0a0).
- `((unsigned char*)0x006D0E79)[ch]` inside a loop gives retail's in-loop `lui; addu; lbu`; `D_ADDR[ch]` hoists the address into an s-register.
- `memcpy(d, s, 0xD9)` is not inlined at that size; a struct copy of `struct { char d[0xD9]; }` gives the inline ldl/ldr loop (0044B4B8).
- `if (v == 0) return -1; return f(...);` matches where `s32 r = -1; if (v != 0) return f(...); return r;` keeps the -1 before the beqz (00443FB8).
- In the 0x30/0x50-byte copy-in/copy-out functions gcc 2.96 keeps a field-by-field struct copy as lwc1/swc1, but a whole-struct assignment becomes 8-byte ldl/ldr pairs: write the field copies explicitly.
- A packed 8-byte member gives ldl/ldr loads, but the stack store stays an aligned sd unless the destination local is packed too (blocked 00484ff8, 0047d660).
- `(u16)(x & 1)` keeps an extra `andi 0xFFFF`; read the u16 into a `u32` variable and test `(fl >> 1) & 1` for `srl; andi 1` (an `s32` variable gives `sra`) (001cfe20).
- `(t << 9) >> 32` on a 64-bit value folds to one shift; `s32 r = (s32)(t >> 32); return r & 1;` keeps `dsll; dsra32; andi`.
- Signed-shift ternaries become movn only when the default value is written as a separate local (001d0228).
- A virtual call whose object is also the last argument: the entry expression written inline in the argument list is closest (6-7 off); a local entry pointer or inline wrapper copies the object between registers (unit_001C4BE0 family, unsolved).
- A function ending `bne x,K,fail; code=1; ...; beql x,K2` (store in the slot): write `if (v != K2) { if (v != K) goto fail; code = 1; } else code = K;`, not an if/else-if chain.
- Global register order is `floor_log2(refs)*refs/live_length` (gcc global.c), and a pseudo first set from a constant has its live length doubled: when two variables swap $sN homes, add one more set of the right one as a separate `case N: x = K; break;` arm, which cross-jumping merges back (00116e20).
- `-fdelete-null-pointer-checks` removes `if (p)` before a delete once `p->field0` was read through the same pseudo; read through a second pointer assigned before the loop (`T *q = p;`) to keep the check.
- Writing the first copied field through a pointer (`pt->x = q.x`) raises that pointer's priority and fixes an s0/s1 swap with the argument (0048C5E8).
- Retail reloading locals after a pointer store, or keeping `&local` in a callee-saved register: a pseudo from `T *p = &local; p->x = ...` used for one field only; mix `p->x` for the store with plain `local.x` for the reads.
- `if (!x) return 0; ... return 1;` instead of `int res = 0; ... res = 1; return res;` fixes the $v0 allocation; then the declaration order of float locals decides their callee-saved FP registers (004588c0).
- A small `switch (k) { case 1: ...; case 0: ... }` reproduces retail laying case 1's body before case 0's (00462020).

## Rules from the Codex workers (2026-10-12)

- An inline helper taking its operands **by value** (a float add, a pointer advance, a float parameter it updates) fixes float-register allocation and operand order where exchanging the operands in place does not (0042DAE0, 0036A080, 00429AD8).
- An equality result stored in an `int` before it scales an address keeps `sltiu`/`sll`/`addu`; written inline as a boolean expression it becomes a `movn` pointer selection.
- A bit mask passed into an inline conversion helper keeps the `and` and the register compare; a literal mask at the use folds into a zero test.
- Null checks written in the caller around an inline relocation helper (not inside it) keep the forward loop counter and separate read and store cursors.
- A constructor call schedules its destination pointer before the last scalar argument; a struct-return call with the same arguments schedules the hidden buffer pointer last.
- A structure returned through two stack buffers with a copy between them is one temporary initialised, then copied into a second local.
- A named pointer to a local array used only as a call argument moves its initialisation earlier while direct stores to the array stay stack-relative.
- Two allocations whose results share one saved register are two separate inline allocate-and-construct helpers (00377C98).
- Shared argument setup before two calls can be a `switch (r != 0)`; it replaces a `do { } while (0)` wrapper.

- A `long long d[258]` member copied by assignment gives the `ld`/`sd` 32-byte copy loop of a 0x810-byte struct copy (0033D080, 0033C300).
- A value built with `lui`/`ori`/`addu` of `s0+K` that appears after a `jal` was computed before the call in the source: it lives in an `$s` register (003429E0).
- A volatile load of an intermediate pointer (`(*(List *volatile *)&s->list)->count`) stops its reuse for the first loop iteration: the loop reloads it and is entered without the `b` jump (00342768).

- An inline method's local struct (`V3` copy, `Spring`) with one member's address held in a saved register and stored through it: write `f32 *px = &x; *px = o.x;` in the copy constructor.
- `sw $zero` where retail has `swc1 $fN` of a held zero: the compiler propagated the constant across a join; write the whole store in each arm (one call plus store per branch) so cross-jumping merges the tails (00411150).
- `info->ids[idx]` with `u8 ids[]` in the struct gives the index-first `addu` and keeps the pointer in `$a2`; `(Info *)(idx + (s32)info)` then `ent->ids[0]` lands in `$v0` (0040BFE8).
- A 24-byte struct of three `unsigned long long` members each `aligned(4)` gives the `ldl`/`ldr` copies (0040A5A0).

- Two nearby `lui`/`addiu` global addresses a small constant apart are ONE struct global with the second reached through a member (`D_00620938.sub.tab[i]`, calls take `&D`) (003534A0); the same form, `&((Tb *)self->m4)->a[idx * 4]` with `char pad[0xF910]` in `Tb`, fixes an `$at`-against-pseudo constant (0035BF08).
- A dead division keeps its zero check (`beql`, `break 7`) only with a variable divisor (`unsigned three = 3; 100u / three`); a literal divisor folds it away.
- `int r = 0; switch (...) { case: r = ...; break; } return r;` hoists `mtc1 $zero,$f0` to the top with `jr; nop` returns (0034EB00).
- A second test of a byte a call wrote stays separate only when the first test reads it into its own local (`unsigned char f1 = l.flag`); otherwise jump threading merges the two tests (00350C20).

- A callee declared without arguments but called with `$a0` still holding `this` is `f(arg0)`: without the argument the scheduler hoists a later `ori $a0` above the branch (0033C490; the form that had looked like a `nosched1` unit).

- A callee entered with `$a0` untouched and only `$a1`... set passes its first parameters through: add them to the signature (the m2c `void f(void)` draft hides them).

- A switch on cases 0 and 1 with an explicit `case 2:` falling into `default:` gives `beq ==1; slt <2; bne !=0`; without `case 2:` it tests `== 0` first (00381C90).
- A signed `i < N` counter used only by the exit test is reversed to a `bgez` countdown; it stays an up-counter when another induction variable has the same stride (`m[i][k]` and `out[i]`), not with different strides.
- `addiu v,sp,K` pointers held in `$s` registers: `float *py = &v[1];` used only through derefs, each declared where retail first computes it (the position picks the register); index registers holding 4/8 (`addu v,sp,s3`) come from `(&v.x)[iy]` with `int iy = 1` (0037F640, 00384200).
- `func(arg0 + i * 0x370, ...)` in the loop body, not a separate `p += 0x370`, keeps `arg0` in `$s2` (00386BF8).

- `mov.s $fX,$fY` at entry followed by uses of the copy: the parameter is reassigned later in the source; put the reassigned value in a new local and leave the parameter alone (00360980, 003575E0).
- `r = r < v ? v : r` with `r` known to be 0 gives the `slt $v1,$zero,$v0; movz` clamp; `v > 0 ? v : 0` gives `slti`/`movn` (0035FA98).
- A second read of the same field (`s->f` again, not a copied local) becomes a register copy by CSE: retail's `daddu $a2,$a1,$zero` with the compares split over two registers (0035BBD8).

- Where a float parameter sits among the ints of the function's own signature picks the callee-saved float registers (00428B80: `(A *, float, const char *, int, float, int)` fixed an `$f20`/`$f21` swap).
- Unexplained `mov.s` entry copies or a `$t0` setup before a call mean the callee's prototype hides arguments: extra floats passed through `$f12`-`$f15` (0042CF78), the loop variable in a `sprintf` (004311A0).
- A base `addiu` issued before the index `addu` (`addiu v1,s2,0xC; addu s0,v1,v0`): keep the base in its own local, `flags = (int *)((char *)o + 0xC); p = (int *)((char *)flags + off);`.
- `lwu` plus `dsll32`/`dsra32` on a key: the callee's parameter is `int` and the argument is `(int)(unsigned long)field` (00447618).

- An inlined helper with a `&local` out-parameter forces a stack spill: expand it by hand with plain locals.
- A run of bit-field clears is raw word read-modify-write in separate statements (`w = w & ~0xFFu; w = w & 0xFFFF00FFu;`); one expression folds to a single mask and `:8` bit-fields come out as `sb` stores (003FABA0).
- `m != 3 && m == 4` folds to `m == 4`: `switch (m) { case 3: break; case 4: ...; return; }` keeps both compares (004065B8).

- A multiply by a constant done as `mult` with the constant in a register (not shifts and adds), or a threshold constant kept in a saved register: the constant arrives as an inline function's parameter, `static inline body(..., s32 k)` called as `body(x, 3)`.
- An inline `vector<char>` is `Vec v((Vec::size_type)n)` (the size type keeps the range constructor out): it gives the inline `fill_n` call (func_005CDD50, signed char: func_005CDDB8) with `sb $zero, tmp` as the fill value; allocate with `n == 0 ? 0 : func_00575E60(heap, n)`, free with `func_00575DA0(p)` (00332EE0, 00330FD8).

- Two copies of one value in different registers need a shape that keeps two pseudos: `do { a[i] = i + 1; } while (++i < N)`, not `n = i + 1; i = n`; reusing the variable for a second loop gives the same register (003E7538).
- One shared `v0 = 0` exit block is a chain of plain `if (!p) return 0;`; an `r = 0` result variable gets its own register.
- `lwl`/`lwr` for a 4-byte unaligned copy is the assignment of a `struct { char b[4]; }`.

- Two hoisted `base + const` spills in swapped stack slots: gcse numbers its reaching registers by an expression hash over the operand pseudo numbers, so reorder the declarations of the base variables (0035D6B0).
- An inline bounds-checked predicate written `if (i >= n) return false; return tbl[i] > 0;` keeps each `i < n` compare separate (more references to `i` fix its `$s` home) and gives `bnel` + `b`; `&&`, a ternary or `r = false; if (...)` let cse share the flag (0035D6B0).
- A `while` whose body breaks early is laid out break-test-last when that jump is within 30 RTL insns of the loop start (`expand_end_loop`); inline helpers with parameters add insns and restore retail's `b test; body; test` layout (00122FA8).
- A constructor-like callee with `$v1` used after the call must be declared returning a pointer (0010C0E8).

- `x = 0; if (f & 2) x = 1;` gives `andi; sltu $zero`; `x = (f & 2) != 0` gives `sra; andi 1` (003756D8).
- `int i = 1; float &r = p[i];` gives the `li v1,4; addu t2,s0,v1` reference-register pattern; plain `p[1]` folds to an immediate (00218430).
- `c.le.s`/`bc1t` on a positive test is written `!(f <= 0.0f)`, not `f > 0.0f` (00217B78).

- A swapped `$s0`/`$s1` or `$s1`/`$s2` pair: split the shared variable into one local per block or phase (priority is references over live length; short ranges take the lower register first) (001DCFA8, 001E8CB0).
- One `return ret` after an if/else, with no early returns, gives `ret` the higher `$s` register (0030D390, 0030D200).
- A table read written `((unsigned char *)0x6D0E79)[c]` keeps the base from being hoisted; a local `Test tbl[2] = {{...}, {0, 0, 0}}` compiles to the `ldl`/`ldr` copy (0030CFD0).

- A store then a reload around a call is a declared struct local (gcc 2.96 keeps local structs in memory), declared in address order (first declared sits lowest); `&local.v` passed to a callee or `F *p = &local` held across a call gives the `s0 = sp+N` pointer (00423028).
- A chain of early exits is `if (c1 || c2 || ...) return 0;` with the first load of `*a1` inside the condition; nested `if (!(...))` blocks lay out differently.
- A destructor's member-array delete loop is a `static inline` helper; written in line, the second `self + const` is CSE'd into a saved register (003B9BD8).
- An `$f20`/`$f21` swap after a call: declare the float local that takes `$f21` first (0028FA88, 00425828).

- combine never merges across a call: a `base + const` argument held in a local declared before an earlier call stays its own pseudo, and sched1 issues that argument move ahead of the others (0047D660).
- A value-returning call whose result is unused keeps `$v0` away from the first value loaded after it, which lands in `$v1` (00434770); with void callees the same `$v1`/`$v0` pair needs a fourth quantity in the block, a separate variable rather than a reused one (0038FD48).
- sched2 fills a call's second slot with the earliest-written zero-cost dependent: `flag = 0` written first after the call goes there and reorg moves it into the branch delay slot (003535B0).
- A callee's key parameter declared `unsigned int` and passed directly, not as `(long)(int)k`, removes the sign-extension pair (004458D0).

- An index-first `addu` with the address recomputed after each call is a struct-array member (`self->rows[idx].v[k]`, `Row { float v[4]; }`); `*(float *)(self + off + K)` keeps the sum in one register (003CE178).
- One pointer reused across calls (`p = base + off; ... p = base + off2;`) lives in a saved register; a distinct pointer per use stays in `$v0`.

- A pointer-to-member call (`(obj->*self->pmf)(...)`, `pmf` an 8-byte member) is the `ld -8(vtbl)` / `dsra32` / `bltzl` pattern; delta, index and object are loaded once before the index test only when the instance comes from an inline function call: `static inline Thing *deref(s32 *b) { return (Thing *)*b; }`, `(deref(b)->*pmf)(...)` (003207C8).
- The stack pop (`--count`) is an inline `s32 n = s->count - 1; s32 *a = s->arr; s->count = n; return a + n;`; a hoisted `H *ph0 = &h0;` at the top puts `daddu a0,sp,zero` in the prologue.
- An inline virtual call whose result is unused declares `fn` as `void (*)(void *, void *)`; an `s32` return swaps the `lw` `$v0`/`$v1` registers.

- A loop-invariant stack address and `q = arr` issued in the wrong order in the preheader: write `if (n > 0) { q = arr; for (i = n; i != 0; i--) { ... } }`; a plain `for (i = 0; i < n; i++)` hoists the `q` init into the `blez` slot (0013C690).
- Two stack objects sharing one slot are two block-scoped locals (`{ H a; ... } { H b; ... }`), not an array; `x &= 0xFFFF;` as its own statement is the in-place `andi s0,s0` (001403A0).
- An alignment-branch (`(a | b) & 7`) struct copy with `ldl`/`ldr` is the assignment of `struct { s32 d[N]; }`; `char d[N]` gives a `lwl`/`lwr` tail (00145970).

- A float field stored as `0.0f` is `sw $zero`; `mtc1 $zero` plus `swc1` needs `f32 zero = 0.0f; f32 one = 1.0f;` locals (00414D88).
- `base + id * 0x188 + 0x2F0` computed after a call from a register that survived it: `r = call(); off = id * 0x188 + 0x2F0; e = (T *)(base + off);` keeps the multiply after the call (003EF1E8).

- A vptr store at scope end (`sw v0,0($sp)` in a branch delay slot) is a local with an inline destructor (`~Local() { vt = D_...; }`) declared inside the else block (00155B50).
- A `lui`/`addiu` pair with a negative low half names the global one `lui` unit lower: `lui 0x66; addiu -0x4820` is `D_0065B7E0`.
- A sub-object address kept in a saved register across calls (`s2 = this + 0x9C`) is a pointer to that sub-object in use (`Sub *p = (Sub *)&self->f9C`); plain field stores do not make the copy.
- `&h` passed to the next call: use it inline; a predeclared `H *p = &h;` lets the scheduler put the `addiu` ahead of the preceding `jal`, and taking it before a branch hoists it above the call (00189A98, 00188808).

- A pointer expression the original computes twice (`lui`/`ori`/`addu` repeated): write the later use inline, inside the loop body or after the branch; a named local lets CSE merge the copies (003BC208, 003BC960).
- A struct copy is `ldl`/`ldr` for `char[]`, a `lw`/`sw` tail for `s32[]`, `ld`/`sd` for `s64[]`.

- A `switch` keeps the `beq 1; slti 2; beq 2; beq 3` compare tree only when `case 0:` and `case 1:` each have their own full body; fallthrough or `default:` changes the tree (001AAA40).
- A float-register swap in a division: `r = (float)a; r /= (float)b;` (0054EDD0).
- An inline constructor's stores come out rotated by one: for retail order w,x,y,z write x,y,z,w; the same holds for a trailing run of scalar stores.

- A stack object's address kept in a saved register (`daddu sN,sp,0x..`) and read back through it: `T *p = &obj;` with `p->` everywhere, declared inside the `if` or loop body where retail has the `addiu` (002EFD10, 002EDB80).
- Two branches sharing one stack frame layout declare the object once at function scope; a handle or string object with a 0x10-byte gap before the next slot is a 32-byte struct (`pad[7]`), not a dead local (00166100).
- A value loaded into a saved register in the delay slot of the previous call (`lw s0,0(s1)` beside `jal`) is a local hoisted before the call: `Obj *o = *p; f(o, g());`; write first the if/else branch retail lays out first (001627F0, 001621B8).

- A refcounted-string copy (`if (r->sel) d = f(r); else r->ref++;`) with `lw 8(a1)` off a shared base: `char *d = (char *)(r + 1);` first, then `int n = r->ref + 1; r->ref = n;`; `r->ref++` hoists `r + 8` into its own register (002B6F00).
- `(v ^ 3) == 0` gives `xori` (003ED558); swapping the if/else arms turns `beq` into `beql` (002E96C0).

- `p->y = p->x = 0.0f` gives `mtc1 $zero` plus `swc1` where separate `0.0f` stores give `sw $zero`; the chain order sets the store order (002C98F0).
- An inlined rb-tree `it++` through an `It *` is the SGI member form (`while (it->n == y->right) { it->n = y; y = y->parent; }`); 16-byte iterator slots are `struct It { N *n; char pad[12]; }` copied by field; pointer locals for the stack objects give the `$s` homes of map `operator[]` code (003062B0, 00306B08).
- A virtual call that leaves `$a1` as the caller's leftover: declare the entry's `fn` with only the arguments the call sets; an `s32` return puts `fn` in `$v0` (002C95E8).

- `lui`/`lw` constants and stores into a temporary object in retail order: compute the values into locals first (`void *fnp = (void *)func_X; char *t = pb->p + 0x10;`), then store them in that order (001761B8, 00176320).
- A local used several times across calls takes its saved register from an explicit pointer (`Ref *pb = &b;`) declared just before its first use; small struct locals sharing slots are padded to 16 bytes (00174C78).
- An inlined SGI `vector` matches with a small element class that has a user copy constructor and destructor (`Elem(const Elem &)`, `~Elem() {}`) and a `GameAlloc` allocator with a `TypeTag` specialisation: the out-of-line `__uninitialized_copy_aux(..., __false_type)` call and the empty destroy loop (002350C8).

- A stack temporary stored just before a call that takes its address (`sw`, then `daddu $a1,$v0` in the delay slot) is an inline helper that stores and returns the pointer: `static inline int *st(int *p, int v) { *p = v; return p; }`, `f(&r, st(&t, x))`.
- `abs.s` is `__builtin_fabsf(x)`; `x < 0 ? -x : x` compiles to `c.lt.s` and `neg.s`.
- `dsll32; dsra32` on an argument: the local is `long` and the callee's parameter `unsigned int`; `dsll32; dsrl32` on a result: the callee returns `unsigned int` into an `unsigned long`.

- Several loops whose exit test is the same -1 constant: give the inner loop its own counter (`k`, not `i`), or the exited inner counter's register is reused for the outer test and the hoisted -1 register is lost (003CC608).
- `*p = a & mask | v` through an inline helper `setLow(p, v, mask)` keeps the constants in saved registers (003BD808).

- local-alloc with exactly 3 block-local quantities does not sort them (a broken exchange compares quantity numbers): a third pseudo born after the two contested ones, with priority not above the second, leaves the first-born first whatever its priority; with 2 quantities priority decides, with 4 or more it is a real sort (004548A8).
- `throw()` on the last non-sibling callee changes the delay slot of the branch into its block: without it the call ends its basic block, reorg loses liveness at the target and takes a register restore instead of the argument move (00378778).
- A constant folded into a variable index of a flat array (`m[i * 20 + 1]`) comes out index-first (`addu off,base`) and is not merged with the `m[i * 20]` address; struct-field and 2D-array forms fold the constant into the base and come out base-first (0038F2C0).
- A load/store anti-dependence that keeps stores after a load of a global: declare the read-only source `extern const char D_...[]`; the stores go first and the load fills the `jal` slot (001CD088).
- `int c = strcmp(e->name, name); e++; if (c) break;` shortens the end pointer's life by one insn (the copy to `$a0`) and moves it one saved register (004548A8).

- A zero passed by address (`f(x, &zero)`) with its own stack slot per call: the parameter is `const int &` and the call passes a literal 0 (002BCED0).
- Retail's branch layout for a guarded sequence of calls: `if (a != 0 || (f(), g(), h() != 0)) { B } else { A }` with inline helpers in the comma expression; `&&` or early returns lay out differently (002EC260).

- A stack object's address in a saved register with loads through it (`lw s4,0(s5)`): load and store through small `static inline` helpers (`first(s32 *)`, `setp(char **, char *)`) and take `char **ps = s;` just before the first use; plain `s[0]` folds to an `$sp`-relative access.
- A callee whose result is ignored leaves `$v1` for the next value when declared `s32`, not `void` (four fixes in one run: func_00255088, func_00211460, func_0030A678, func_0055A730).

- Bitfield-union decode and encode functions follow statement order (the scheduler keeps the source order): 003A34C0 matched only as lap, point, time; a word read-modify-write that must not become `sb` needs an explicit mask, not a bitfield member.
- A stack array passed by register: `s32 *p = buf;` with `*p` and `p` throughout fixes `lw` and delay-slot differences (001401A8, 001734D8); `__builtin_alloca`, not a VLA (003BB750).

- A local `Rect` zeroed with `mtc1 $zero,$f20` plus `swc1`: build it through an inline helper taking four `0.0f` arguments; direct stores give `sw $zero` (00206888).
- A pointer to a stack local takes the free saved register of a dead parameter only when its declaration sits right before the first call that uses it (00206888, 001E3490, 001DF3F0).
- Array-destroy loops are `do { e -= n; f(e); } while (e != base);` (0032F238).

- An `$a0` setup that belongs in a call's own delay slot: `Type *p = &local;` declared after the preceding call keeps the `addiu` out of that earlier call's slot; declared before it, it is pulled in (00304850, 003136C8).
- Two tail-call arms with the same store in each branch delay slot write the store in both arms; one hoisted store goes before the load instead (00305308).

- A virtual call whose function pointer sits in `$a3`: declare it with a trailing `...` (`void (*fn)(void *, s32, s32, ...)`); a fixed fourth parameter gives `$t0` plus a copy (002907D0).

- A struct-return string slot and a handle slot sharing `sp+0`: one 16-byte `H` struct aliased by reference; two locals make the frame 0x20 larger (0016E108).
- Retail code with no induction pointers where ours strength-reduces the address arithmetic: a `goto top;` loop, not `for (;;)` with `continue` (001C3DE0).
- `sltiu`/`xori` on a mode test: `s32 big = m >= 2;` as its own local (0038B0E0).

- A placement-new null check is `T *pv = &n->v; if (pv) new (pv) T(x);`; `if (&n->v)` folds to `n != -8`.

- A switch on cases {1, 2} that compiles to `beq`/`slti`/`bnel` needs an extra `case 0:` label.
- A callee-saved register swap or an early `v0 = const` often follows the control-flow shape: one return variable with a `goto` join, early returns, and a nested chain each allocate differently; try all three before touching types (network unit, unit_00494578).

- `lbu; sra 1` on a byte is `s32 v = field; v >>= 1;`; `field >> 1` on a `u8` field compiles to `srl` (0044E1E0).
- The `$v0`/`$v1` choice after a call flips with the preceding callee's declared return type in both directions: `void` to `s32` three times, `s32` to `void` once in one run (00124818, 001B5088, 00292208, 00464F38).

- A stack slot shared between a string temporary and a result object comes only from real class temporaries with a destructor: gcc 2.96 allocates named locals in scope order and does not reuse their slots across sibling blocks (0012D680, open).
- A pointer stored to `0($sp)` and never read back is a pointer passed by reference (`T *&first`) into an inline loop helper (00151A58).

- A void function that ends on another void call as a tail call is `return f(...);` (C++ allows it) (004C3E50).

- An array-destroy loop: `if (arr != 0) { q = end; do { --q; vcall; } while (arr != q); }` with a void virtual call and that operand order; for an array inside a sub-object the null test is on `sub + off` (it folds into the `-0x50` compare) (003C3048).
- `min.s`/`max.s` with a shared constant: `maxf(d, -c)` with `c` a variable gives `neg.s` of the same register; a second literal does not.

- A struct with a user copy constructor is 16-byte aligned on the stack, even with one field: keep the class (map find iterators, `Key` and `It` in 00326FD8) to reproduce the frame.
- One `s32 *` variable reused for two roles (`p = &c.v; ... p = (s32 *)&self->f20;`) gives a single `$s1` home where two pointers take two registers (00219570).

- Read a member through memory everywhere and let the compiler make the register copy: the copy then lands before the store; an explicit cached local puts it after (002BA2B0).
- A store to a `const` member in a constructor keeps the epilogue `ld ra` behind it (00386660).
- A register left unset before an indirect call is a passed-through parameter: adding it to the callee's prototype emits no code but changes which saved register each parameter gets (005773B8).
- A local cursor (`const char *p = src;`) declared before `rem = size` gives the entry copy and register homes that a dead `size = 0;` store was faking (00554F60).

- A compare tree that starts with the middle case (`beq x,6`, then `slti x,7`): the switch has one more case with an empty body (`case 7: break;`) (003396E0).
- `__builtin_alloca(n * 4)` gives the array with no stack save and restore; a `T a[n]` VLA adds `sw $sp,4($fp)` / `lw $sp,4($fp)`.

- `if ((char *)e + 4 != 0)` written directly folds to `e != -4` held in `$fp`; the same test through a variable or `&e->arr` does not fold (matters when saved-register pressure decides a spill).

- A pointer stored at `0($sp)` and reloaded after the middle call, between a begin and an end call, is a `struct Guard { Guard(p) calls f(p); ~Guard() calls g(p); }` object in an inner scope (00547860, 00503F48).
- A by-value `struct { char b[8]; }` argument passed on to a callee is `local = result; callee(a, local);` (the `ldl`/`ldr`/`sdl`/`sdr` copy plus `ld $a1`); copying twice does not match (004FF5D8).
- `v0 = 1` in a `beq` delay slot comes from one `if (x == a || x == b || ...) return 1; return 0;`, not from a chain of early returns; the order of the two constants in a `?:` picks `movz` against `movn` (005230A8).

- A callee returning a non-POD (a struct with a user copy constructor) is called in the hidden-pointer form `new (buf) R(f(x))`; a plain POD struct return comes back in `$v0` (0021FC78).
- `__builtin_stdarg_start` placed after the first call, not at the top, when retail sets up the varargs area late (0020D738).

- `func_0057FA48` is the double-to-float libcall: declare the callee that feeds it as returning `double` and write `(f32)call(...)`; never call it yourself (002CC6C8, 00253EC0).
- A float argument's delay-slot placement depends on whether the callee's prototype lists the `u8` before or after the `f32` (003F6C30).
- A temporary and a later local in disjoint brace scopes share one stack slot but keep separate address pseudos: retail's `s3 = s2` pointer copy (002F5920).

- An inline `setv(f32 *p, f32 x, f32 y, f32 z)` called with `0.0f` and `1.0f` hoists the constants into float registers and stores with `swc1`; the same stores written directly give `sw $zero` (003B4B38).
- Fields loaded into locals in source order move their loads next to the first store; a local declared after the first store fixes a prologue schedule (00128800: 14 to 0).

- A float zero kept in a callee-saved `$fN` across calls is a named local `f32 zero = 0.0f;` used for the stores, the compare and the argument; constants hoisted into `$s4`..`$s7` are named locals too, allocated in reverse declaration order.
- A function pointer called through a typed `fn` field of `E { short d; short i; fn }` loads into `$v1`; through a `void *` cast it loads into `$v0`.

- An indirect call whose function-pointer register differs (`$a2` against `$v0`): declare the pointer's return type `int`, not `void` (00531910); a `short` parameter with a sign-extend prologue is `int` in retail (004F7320).
- `a + b` where one operand is a call: split into locals in evaluation order (`h = i / 2; l = strlen(...); return h + l + 1;`) (004B8BF0).

- Alias sets decide load/store order: a field compared with small constants is an `enum`, a handle is a pointer (`void *`), and each has its own alias set, so an `int` load or store stuck on the wrong side of it moves (0051ADA0, 0051A820, 0051D448).
- A caller's own argument passed through to a callee keeps that argument register live: sched1 issues the entry copy later and saved-register ties flip (00521450, 00347618); a parameter moved out of its incoming register for no visible reason means a later call takes that register unchanged (004B1310).
- `abs.s` as single-instruction inline asm costs the scheduler 1 against 4 for `__builtin_fabsf`: a store anti-dependent on its output is no longer pulled ahead of constant loads (001941D8).
- Real class objects (constructor, destructor, `operator=`) for string and handle temporaries remove the doubled life of stack-address pseudos that hand-written pointers leave (002F5920, 0023A178); `n = r->ref + 1; r->ref = n` in both grabs.
- `int r; if (p) { ...; r = load; } else r = 0; return r;` frees `$v0` for the block's temporaries where `return load;` does not (00451050); four separate `if (c) return 0x17;` hoist `v0 = 0x17` (00519968).
- `__builtin_expect` on a pointer test is an inline `bool isNull()` (same prediction, no DI temporary) (00243BF0).

- `(n + 2) * 8` folds into `n * 8 + 16` in address arithmetic; `n + 2` and `n - 1` held in separate `int` variables first keep retail's `addiu; sll; addu; addiu` order.
- A parameter masked at entry (`andi $s0,$a1,0xFFFF`) is declared `unsigned short` or `u8`; one stored with `sh` and tested with a raw `beqz` is a plain `int`.
- Unaligned 4-byte and 2-byte reads and writes are assignments of `struct { signed char c[4]; }` (`lwl`/`lwr` plus `swl`/`swr`) and its 2-byte form (`lb`/`lb`/`sb`/`sb`) (00515318).

- Some network-unit functions are C, not C++: 004F37C0 matched only as a `.c` file (the C++ build gave a `beql` tail that no `throw()` toggle moved).
- A `u16` value is declared `u16` in the parameter itself (the `andi 0xFFFF` happens at entry); `(id & 0xFF)` is written inline at each use (a local is CSE'd into `$a1`); `(u32)tbl + (idx * 16 + 0x50)` keeps the constant on the index.
- Address-taken pair locals are two `int` variables, not `int[2]` (8 bytes less frame) (0051C5D8).

- A switch over a global struct matches only with `G *g = &D_X;` declared first: retail forms the global address once before the compare tree (0053BF40).
- A store that follows a division in retail is written after the division in the source (004C25E0); `new (p) IOVec` placed late reproduces a constructor's store order (0052DE00).

- A float parameter's position in a callee's prototype decides the order of the argument moves: moving the float before the int closed three functions at once (003CBB28 `(float *, float, int, float)`, 003EBA68, 003F59F8).
- For `G = K;` expand emits the address `lui` before the constant; `int k = K; G = k;` with the local written before the store statement flips the tie (00461FF8). A new local set after a call (`Node *n = p - 1;`) cannot be scheduled back above it, where `--n` on the parameter can (00567790).
- A cursor copied from a parameter just before its loop (`s32 *e = enemies;`) is its own short-lived value and ranks above a neighbouring parameter at no cost in code (003BB5A8); a function-scope variable reused for a block's result lands in that variable's register (00376238).
- One level of inlining too many changes allocation: calling `subtract()` directly instead of through `det()` matched 00424200.
- sched1 trace for a one-instruction order residual: `-fsched-verbose=5` prints each insn's priority and dependents; after a `jal` the first instruction is the lowest-position insn the call releases, later cycles sort by priority, then dependents, then position.

## The `c_str()` then release pair (solved 2026-10-13, 0014D9B0, 001A5388, 001A6260, 001A0E48)

Retail has `lw a0; move sN,a0` for the string pointer kept across the release, and reloads `s->p` at the join unless the string sits at `sp+0`. Use these helpers verbatim (`D_EMPTY` is the unit's `""`), profile `ee-gcc2.96-no-strict-aliasing`:

```cpp
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; /* pad to the slot size */ };
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_EMPTY;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
```

- The nested `return rep_data(str_rep(s));` decides the load order: `return s->p;` loads straight into the kept register and gives `lw sN; move a0,sN`.
- Pass the address expression at every call (`c_str(&u.s); release(&u.s);`, `&self->name`): a `Str *ps` variable held before the release merges the load retail keeps separate. A pointer to the handle part goes after the release (`H *ph = &h;`).
- Never write the `""` default first by hand: the plain `c_str` above compiles to retail's `lui; lw; addiu; beqz` form.
- Applied to thirteen kept drafts the same day: nine matched, eight of them by swapping the helper block in and nothing else. A handle initialiser whose result is unused (func_001A5D20, func_001BFEA8) declared `void *` puts the pointer in `$v1` as retail has it.

## Inlined STL map and tree code (solved 2026-10-13: 00327178, 00214690, 00214980, 00209D98)

The real `map` from `include/stl` reproduces retail's frame, slots and registers by itself; no hand-written iterator does (the iterator's user copy constructor and the inliner's handling of `&it` decide them).

- Types: `typedef pair<const Str, T> Value; typedef _Rb_tree_node<Value> Node; typedef _Rb_tree<Str, Value, _Select1st<Value>, less<Str>, GameAlloc<Value> > Tree; typedef map<Str, T, less<Str>, GameAlloc<Value> > Map;`
- Member: `struct Owner { char pad[OFF]; Map m; };`, OFF = the header-load offset minus 4 (allocator +0, `_M_header` +4, count +8). Write `self->m.begin()` at every use, no reference local.
- Out-of-line tree members are bound with an inline forwarding specialisation declared before the first use: `extern "C" void func_005D90F8(Tree *self, Node *x); template <> inline void Tree::_M_erase(Node *x) { func_005D90F8(this, x); }` (same for `find`, `lower_bound`, `insert_unique`, returning `Tree::iterator`). Never `__asm__("func_X")` on the specialisation: it is ignored, the judge still prints MATCH on opcodes and the link would break.
- `it` read as `lw 0($sp)`, 16-byte slots, the header stored to the end slot every iteration: `for (Map::iterator it = self->m.begin(); it != self->m.end(); it++) body;`.
- End stored once before the loop and reloaded: `Map::iterator it = self->m.begin(); Map::iterator end = self->m.end();` in that order, then `for (; it != end && cond; it++) ;`.
- Always a `for` with an empty or break-only body, never `while`: in the `for`, gcse's insertion lands after the loop note, loop.c calls the loop phony and hoists nothing; the `while` hoists `&it` and a copy of `&end` before the loop.
- No end store, every access to `it` through one pointer register, or 4-byte iterator slots: `const_iterator` over a const container (`const Owner *self`).
- A store of `it.n` to a slot just before the increment: `it++` (`++it` has no such store).
- `if (count) { jal erase; hdr->left = hdr; hdr->parent = 0; hdr->right = hdr; count = 0; }` is `self->m.clear();`.
- Handle temporaries 16 bytes apart: each handle class has a declared copy constructor (`HString(const HString &);`); without it the slot is 4 bytes and the frame 0x10 short. A callee returning a class is a real out-of-line member (`HObject push_back(const HString &) __asm__("func_002EEEB0");`).

## A stack object's address: kept in a saved register or recomputed per call (2026-10-13, 004CB618, 004BD038, 0051FAF8)

- What decides it: a pointer to a stack object stays in a saved register (larger frame) when cse1 cannot see `p = sp + N` at the use (a label sits between definition and use; gcse does not propagate `sp + N` either) or when loop.c hoists it; otherwise cse substitutes `sp + N` back and each call gets its own `addiu aN,sp,K`.
- Kept in a saved register: declare `T *p = &obj;` at the function top and use it inside later blocks, across a real if/else join or loop (004BD038: `Req *p = &sp; Req *q = &sp20;`).
- The same effect from a branch that folds only inside cse1: the SGI allocator written `allocate(n) { return n != 0 ? (T *)func_00575E60(0x10, n * sizeof(T)) : 0; }`. With that conditional an inlined `map()` keeps its `_Compare()` temporary in memory with its address in a saved register (`sb zero,0x10(sp)` ... `lbu 0(s2)`, frame 0x20 larger); an unconditional `allocate` folds it away (004CB618, real `map<int,int>` member). Any function with a `func_00575E60(0x10, 0x18)` header allocation takes the real container member plus this allocator.
- Recomputed per call inside a loop: the function is C, not C++. C++ puts `&local` in a pseudo that loop.c hoists into a saved register (frame +0x10); as a `.c` file the address goes straight into the argument register at every call (0051FAF8: same body as `.c`, `struct` keywords, no `extern "C"`; one instruction left there, an as2004 `uld` tail moved into an unfilled `jalr` slot).
- The same holds without a loop: two calls in one block (or on a CSE path) taking `&local` share one pseudo in C++ (cse1 reuses the first argument's register), each gets its own `addiu aN, $sp, K` in C. 2026-10-24: 00540FB8 matched by renaming the C++ draft to `.c` (15 off -> MATCH, default profile); 00523E50 139 -> 1 and 00534E18 16 -> 6 the same way. When a network-unit draft keeps `&local` in `$s` registers, try `.c` first, then `nogcse` (0051D798 stayed C++ with `nogcse`: one call per block).
- Argument null checks in this unit are separate statements, each with its own `return 2;` (`if (self == 0) return 2; if (out == 0) return 2; ...`), not one `a && b && c` / `a || b` condition: that alone closed 00537FC8 (the `li $v0, 2` hoisted to the top and plain `beqz`s to the epilogue) and the last instruction of 00523E50 (a spilled parameter's first use reloads from its stack slot instead of inheriting the incoming register).
- An instruction at the head of a join block that precedes the block's own store was written at the end of both arms: cross-jumping runs after sched2 and puts the merged tail first (004BE698).
- A block temporary in the register a now-dead variable held is that same variable reused (0044FEC0).

## Open blockers by area (swarm, 2026-10-11/12)
- `sll $rd, $rt, 0` (a 64-to-32 truncation, rd != 0) occurs in no linked function of the binary and
  in only seven unmatched ones (0056DF58, 0056E170, 005786F0, 0057F490, 0057F4F8, 0057FAF8,
  005AEDE0): every 2.96 and 2.9 profile truncates or extends with `dsll32`/`dsra32` instead.
  005786F0 matches but for its prologue `daddu; sll 0` (2026-10-31): these need a compiler build or
  a hand-written-asm decision, not more source forms.

- unit_0046A050: family of 11 (0048b450..0048bf60 and 0048af70/ae50/b098): copy a 16-byte return value to a stack temporary, call a helper on it, copy it back field by field; retail keeps the temporary in stack memory and reloads it. Best draft so far is 20 of 38 off; one solution should propagate through siblings.py.
- `vector<u8, Plain alloc>`: use `char` as the element type (the STL has a no-op `_Destroy(char*, char*)`, so the dtor is a plain `if (p) free(p)`); `unsigned char` adds a `sw $a0, N($sp)` spill (001cfe68, 001cf628).
- `explicit vector(size_type n)` gives the exact zero-stores, allocate, `fill_n(&val)` shape; a member array in a struct with an inlined dtor produces the `addiu v0,zero,-0x54 / beq` null check on the array base.
- A dead `sd $v0, 0($sp)` in the delay slot of `jal sprintf` with no $a3 set: `volatile long long keep; keep = t;` then a 3-argument call (001d0698).
- A callee the original knew could not throw needs `throw()` on its prototype (func_005C1628 in 001c8778).
- `throw()` belongs on callees at lower addresses than the caller (same unit, already seen by the compiler); on every callee it can make things much worse (00477890: 1 off with the right ones, 88 off with all).
- A function returning a class by value takes the hidden destination in $a0: `return t;` gives a copy-ctor call into it followed by the dtor; `return Val();` is a plain store.
- By-value arguments whose copy the callee owns get no destructor in the caller: declare such a struct without ctor/dtor and call the copy ctor by hand.
- A virtual call through vtable +0x10 is virtual index 1 (+0x08 is index 0): declare a dummy virtual first.
- `jal` with the argument in the slot and `addiu sN,sp,K` after the call: the pointer to the stack object was assigned after the call; write `s32 nz = f(...) != 0; ph = &h; g(ph, nz);` (001e7c28, 001e7738).
- Inline Str release: `Rep *q = ((Rep **)s)[0] - 1;` instead of `(Rep *)(s->p - 0x10)` removes the CSE of the `s->p` reload after `c_str()`.
- A frame address (`addiu rN,sp,K`) is hoisted out of a loop into one s-register only when several identical blocks share it; a named pointer declared at the top of the loop body gets its own s-register.
- Pure float helpers defined just before the function in the same unit (static in the original) must be declared `throw() __attribute__((const))`: loads then stay cached across their calls, as in retail (0011e450).
- A `beqz p; nop` whose fall-through `li a1, K` was not pulled into the slot, with `jal free` at the branch target, means free is `throw()`: reorg scans past it and treats a1 as live (0010ca50).
- A float `while (a <= b)` comes out as a jump to the bottom test (`c.le.s; bc1t`) by itself: write the plain `while`.
- With -fno-strict-aliasing (the stl or nsa profiles) locals in sibling blocks share stack slots; with the default profile they do not. A struct needs padding to 16 bytes to reuse a leftover slot (001d19f8).
- Constants that reach a loop as inline-function parameters (a multiply by a register, `p += stride` in a register) keep the loop counter and stop the strength-reduce/countdown rewrite.
- gcc 2.96 stores a call's result to a stack temporary before a branch when the function has a local with a dtor; a dead `s32 st[4]; st[0] = r;` at the right point reproduces the slot.
- A large-offset or `0x20($sp)` store/reload of a value in retail is a register spill, not a variable: use a plain local and let the other saved registers fill up (001e8000).
- CSE merges loads of `h.p` across `c_str` and `str_release`; passing the object once as a pointer variable `ph` and once as inline `&h` keeps two separate `lw`s (001e2a30).
- If retail sets $v1 for a temporary right after a call whose result is unused, declare that callee as returning a pointer (001f7860): the reverse of the "declare it void" rule.
- A float constant retail keeps in a callee-saved FPR before the first call is not reproduced by `float z = 0.0f;` alone (gcc rematerializes it); an integer 1 held in a saved register across calls is: name it (`int one = 1;`) and use it in the conditions (00357b98).
- A switch whose compare tree starts `beq k,1; slti k,2` needs the unused `case 2: break;` even when retail only handles 0 and 1 (0035fcc8).
- Declaring `Str *ps = &s;` / `Handle *ph = &h;` after the first call and before the call whose result feeds `src` matches both the register choice and the slot order; declared earlier it lands in another $s register (00188cd8, 00190b50).
- Locals get stack slots in declaration order from sp upward and disjoint-scope handles reuse a slot: place a spare or dead-store local with that (a `volatile` store in a 0x10-byte `Tmp` after the vector reproduced a dead `sw 0x50($sp)`).
- A constant (`-0x200`) retail hoists into $v0 above the first branch in a function that returns through $v0: `s32 r = -0x200; if (o == 0) return r;` with early returns; one `r` assigned in an `||` condition lands in $v1 or $a2 (005704a8).
- A stack struct filled just before a call: read each field into a local first (`s32 x = q->w20;`), then assign `rq.*`; the assignment order then fixes the store order (005706f0).
- `throw()` is per callee and can go either way: on func_005716D8 it turned bnez into retail's bnel, on func_0056EFE8 it undid that (00570250).
- A Vec4 built through an inline 4-float constructor (`Vec4 v(0.0f,0.0f,0.0f,0.0f)`) gives `mtc1 $zero` + `swc1`; plain field stores of 0.0f give `sw $zero`.
- A function-scope local declared after a block-scope local gets the lower stack address: declare the `char buf[]` after the in/out structs to match retail's layout.
- A struct copy whose saved head word spills to `0($sp)` needs that word as a one-field struct local (`struct W{int v;}`), not an int (0018fee8).
- unit_0017FCB0: family 00190ea8, 001917b8, 00190d38, 00191648, 00190a00, 00191310 (2 to 18 off): retail reloads the string pointer into $a0 (`lw $a0,0($sp); daddu $s3,$a0`) and reuses $a0 for the join's `addiu $s1,$a0,-0x10`; drafts give the reverse copy. Reassignment made GCSE hoist the add; markers and throw() changed nothing.
- Two swapped $s homes: read "Register N used R times across L insns" in the `.lreg` dump (`-da`); order is floor_log2(R)*R/L, ties to the lower pseudo. A `return ret;` written twice costs `ret` one ref; an insn between a late pseudo's birth and death moves it by one (00120330).
- sched1 issues pure constant sets in spare ALU slots in source order, so `sw $zero, slot` of a spilled flag shows where it was declared among the constant-initialised locals; argument moves right after a call stay glued to it.
- A value live across a call inside one block (`rec = D->f568; f(rec, g())`) gets $s0 from local-alloc before global runs, pushing every global pseudo up one register.
- PRE's back-edge reload of `p->q` (a `b` over a loop-top `lw`) disappears when the pre-loop read goes through a `T *const &` inline accessor (00119918).
- A `static` helper called once must be `static inline`, or `try` compares the helper's symbol and reports a bogus 100% diff.
- A `sqrt.s` inline asm without a `"memory"` clobber lets ee-gcc forward earlier loads past it; if retail reloads a field after a sqrt, add `: "memory"`.
- An in-place rotation retail keeps in the same registers is `t = ...; a = ...; b = t;` over the same variables; separate `na`/`nb` locals get different $f numbers (00371800).
- Pointers such as `T+4` held in $s registers before a loop come from `f32 *g = (f32 *)((char *)t + 4);` declared inside the loop body: the compiler hoists them into the preheader.
- unit_00364818: 4 of 7 matches needed the no-strict-aliasing marker for a load or store kept in source order across a store of another type.
- A callee declared void that really returns a value changes sched2 even with no temporary after it: the value call sets $v0, earlier $v0 users lose their anti-dependences on later calls and fall behind the prologue saves on the dependents-count tie (00102ec0).
- update_equiv_regs doubles REG_LIVE_LENGTH once per set carrying the same constant (a variable set to 0 twice counts x4); the source order of independent constant inits decides which one sched1 drops into the earlier stall, and so their $s order (00114e38).
- With all nine callee-saved registers taken, the lowest-priority call-crossing local goes to a stack slot and a gcse-hoisted `lui` that loses is rematerialised per use: write a plain local, not a struct member or volatile.
- The `nogcse` profile keeps a preheader reload of `q->p60` in 0011b2d0 and its siblings 00111A40/00114250.
- Out-parameter addresses (`addiu $a1, $sp, 0x10` ...) recomputed at every call inside a loop, where the default profile hoists `&more`/`&arg` into `$s` registers (extra saves, bigger frame), = the `nogcse` profile (network poll loop 0051D798). It does not help when two calls in one block share the address (local CSE still does that: 00523E50 open).
- A `nop` left in a branch slot where ours moves the next block's stack load (`ld $a0, 0($sp)`, a by-value argument) = the loaded local is `volatile` (a `volatile` member is enough; 0051D798).
- A padding `nop` before a label after `b`/`jr` that ours lacks (or the reverse) = one instruction more or less before it: labels after a barrier are `.p2align 3`. Fix the register copy upstream, not the nop (004F7F20: test `self->queue` directly and load the local after the type check, giving retail's `lw $v1; daddu $a2, $v1`).
- A status return whose constant sits in the compare's branch slot (`sltu $v0, room, total; bnez $v0; li $v0, 0x12D`) while ours computes the compare in another register (`$v1`/`$a0`) = the `return K;` is a `goto` to a `K:` label placed after the final `return 0;`. An inline `return K;` sets hard `$v0` before the compare, sched1 hoists it, and local-alloc can no longer give the compared value `$v0` (0052D5A8, 5 -> MATCH). The same draft's first four self guards were one `||` condition (one shared `b; li $v0, 2`), unlike the argument guards after them.
- A call result split right after the `jal` into two stack words (`dsll32 v1,v0,0; dsrl32 v0,v0,0; dsrl32 v1,v1,0; sw v1,K; sw v0,K+4`) and later passed with `ld aN, K(sp)` = the callee returns an 8-byte struct (`struct Id {u32 lo, hi;} f();`) and the call is written straight into the argument list (`api->send(h, f(obj), ...)`). A named local copy (`Id id = f(obj);`) adds a C++ by-value copy (`ldl/ldr` + `sdl/sdr`); a u64 return with `lo`/`hi` assignments gives `dsra32` (00532080).
- The network Packet (`Entry entries[8]; int size, count;`) appears in two variants: a constructor (00527660) or an `init()` called later, with the object declared at the top of the function (it is then at `sp+0`, below later locals, although its `count = size = 0` stores come after a call). `add()` may carry an `if (count < 8)` guard: the first call folds it, the second keeps `slti 8` (00532080).
- Network row tables (0x4BC000-0x4C1000, ids with `(id & 0xFF00) == 0x200` picking the row at +0x40 or +0x50): retail computes `sll v0, i, 4; addiu v0, v0, 0x40; addu v0, t, v0`, i.e. the byte offset first and the base last. That is `static inline Row *row(Table *t, int off) { return (Row *)((char *)t + off); }` called as `row(t, (id & 0xFF) * 16 + 0x40)`; `&t->rows[i]` or an inline cast folds `t + i*16` first (004C0740, 004BE840 matched; 004BF3A8 4, 004C07F8 11, 004BD378 32).
- Prototype parameter order changes instruction order even for floats: `f(Cam*, f32, int)` instead of `(Cam*, int, f32)` moved `mov.s $f12` before `daddu $a1` (00370318).
- Declaration order of float locals is the tie-break for their registers (earlier-declared gets the lower register) (00370640); the order of integer pointer locals never changed anything in unit_00364818.
- `if (b) { if (c1) return 1; if (c2) return 1; }` keeps the second `li s2,2` that a combined `||` drops. A clamp `x = v; if (x < lo) x = lo;` gives movn; `x = (v < lo) ? lo : v` gives movz.
- unit_00101400 (startup): every match so far needs the no-strict-aliasing marker (15 of 16). 00111dc0 and its twin 00113248: `self` scores 10 refs / 40 insns against 8 / 31 for `e = car + 0x20`, so `e` takes $s1 where retail has `self`; 2 off with the last two stores swapped.
- Two pointer locals retail keeps in distinct registers (an `addiu` of base+const each): declare them as local pointers; their declaration order sets the register numbers and the emission order (00366bc8).
- `xori $v,$a,2` followed by beql comes from `(*p ^ 2) != 0`; `*p != 2` gives addiu + beql.
- Early `return r;` with `r` the first-declared `int r = 0` puts the result in $v0 with no copy (0036ae20).
- An inline helper with an `int k` parameter called with a constant makes CSE keep a pseudo holding 1 live across calls (an $s register); bake the constant into the helper (`vcall1`, no `k`) (003a0308: 34 to 13 off).
- `x = x & 0xFF` on a union `{u32 w; u8 b;}` after a `b = 0` store gives `lbu; sw` with no store forwarding; three separate `w &= C` statements keep separate ANDs.
- `xori` + `bnez` on a predicate needs an int helper `(ready() ^ 1) == 0` (0039cfd8).
- A loop-invariant `addiu`/`lui` hoisted from a loop follows the loop-body order: assign the pointer inside the loop at its first use to place it after other hoisted constants (003d5920).
- Replacing a walking `u8 *v++` with `base[0x58 + i]` indexing changes where the hoisted `addiu` lands relative to constant copies (003e3748).
- A void function whose last store leaves a value in $v0 matches when written `return value;`: it reorders the epilogue `ld` restores (00556d80).
- Direct `o->slots[value].state` on a struct array, with no intermediate pointer, fixes an `addu` operand order (00566f90).
- `switch (x) { case 8: return 1; case 9: return 3; }` instead of two ifs changes the compare temporary from $a2 to $a0 and removes a redundant `daddu $a0,$s0` (003a18a8).
- Modifying a parameter (`if (f(self)) arg1 = 1;`) gives `movn $s1,$s3,$v0` with the constant-1 register; a local copy of the parameter or a ternary does not.
- RaceDisplay (unit 0x00396278): the no-strict-aliasing marker was right for 12 of 12 functions.
- A class is passed and returned through a hidden pointer and gets a 16-byte stack slot only when it has a declared copy constructor (a destructor alone stays in $v0 with 4-byte slots); with nsa the freed temporary slots are reused as in retail (0010d8f0, 5232 B).
- `addiu vN, sp, K; move a0, vN` with v0/v1 alternating at each cleanup site is reload materialising one unallocated frame-address pseudo: real destructors and early returns produce it, and cross-jumping merges the cleanup tails only partly, as in retail.
- A float constant keeping its own callee-saved register across a join is a variable cse1 turned into a copy of an earlier zero-initialised variable that is reassigned later in the block; a single `f32 z = 0.0f;` is propagated and merged with the next 0.0f (00105c48).
- loop.c stops hoisting constants out of a loop above about 64 insns: vertices as a float array `v[n*3+k]` (each address its own insn) instead of a Vec3 struct keeps 127.0f/128.0f in the loop (001218c0).
- Two compares on one value up front (`slti x,8` and `slti x,10`): write nested ifs (`if (x<10) { if (x>=8) return 0; }`); `x>=10 || x<8` and `x>=8 && x<10` both merge into addiu/sltiu (003a1ee0).
- A pointer retail computes in a delay slot or recomputes after a call must be defined after that call: take the result into a temporary, then form `Val *v = V(self, off)`.
- sched2 tie by dependents count: a call declared with a value (`int`, `void *`) SETs $v0, so an earlier reader of $v0 loses its anti-dependence on the next $v0 setter after the call (one dependent fewer); declared `void` it only clobbers $v0. Flipping one callee's declared return type flips ties against prologue saves and argument moves (001d1598, 001d42e0: matched by that alone).
- A non-void function that falls off its end has `(clobber $v0)` and `(use $v0)` at the exit: every $v0 reader in the last block gains a dependent (stores of $v0 go ahead of equal stores) and the restores come out `s0, s1, ra`. Return type `int`, body unchanged, no `return` (00555088).
- A hand-rolled counted loop `k = m; q = p; do ... while (--k)` puts a register-killing copy in the preheader that sched1 issues first; the indexed `for (k = 0; k < n - 1; k++) f(&p[k], &p[k + 1])` leaves loop.c's own two inits in loop.c's order (0047ec98, 0047f4c8).
- A constructor's store run (register-fed stores first, then the vtable store, then zero stores ascending) is a real C++ constructor with member initialisers in offset order (`T() __asm__("func_ADDR")`) (002ccaa8).
- `x != 0 ? -2 : 1` or `if (x) return -2; return 1;` gives movz; `x == 0 ? 1 : -2` gives movn. An if-chain `t == 1 ... t == 3` ends in movn, not beq: a `switch` with case 1 then a case 2/3 range reproduces retail's `==1`, `blez`/`slti`, `b` layout.
- A signed `i < 3` loop whose counter is only the test becomes a countdown `bgez`; an unsigned counter keeps the forward counter. `last = n * 2` makes loop.c emit `addiu t0,2; move t3,t0`; `off += 2; last = off` does not.
- A byte clear or set of a 64-bit field is `*(u64*)((char*)self+OFF) = (*(u64*)((char*)self+OFF) & MASK) | BIT`; saving the pointer in a local first changes the code.
- To change the load order of an int and a float argument to one call, move the float earlier in the prototype (arguments are evaluated right to left) (0033e520); a float held in a local across the call goes to $f20, so pass the literal.
- Several `float *` address pseudos retail keeps in s-registers (matrix element pointers): declare them at the top; their s-register order is not the declaration order (003fb4c0, 003fb7c8: unsolved, register-only).
- `(int)u8_field > 0` folds to `!= 0` even through a cast; `int c = f->n; if (c > 0)` keeps the signed compare (lbu + blez) (00450d88). `bool` is 4 bytes in this compiler (lw), so it cannot give lbu.
- A virtual call returning a 12-byte struct uses a separate return-buffer temporary plus a copy into the named `Vec3`: assign into one reused local (`v = vcall(...)`), and declare `float *py = &v.y, *pz = &v.z` inside the loop after the first vcall (hoist order follows first use) (00451d18, 00452008).
- unit_00450248: no-strict-aliasing marker right for 11 of 11; 004524b8/00452808 need a0 moved in the delay slot of `jal func_00450FE0` (unsolved).
- A load that stays out of a jal delay slot (a nop there) means the global it reads is `volatile` in the original (001016e8, D_00617D84).
- `switch(x){case 0: case 1: break; case 7: A; default: B}` keeps bltz, slti/bnez, ==7 with A laid out before B; the equivalent if chain puts B first (0010ed60).
- A virtual call's function-pointer return type (`s32` against `void`) decides the register of the fn pointer (00102b30).
- A float constant and a load swapped between $f1 and $f12: put the multiply inside each branch (`v = 0.5f * load` / `v = load * -0.5f`); merging two operand variables at a join does not match (00453028).
- A struct-return temporary copied with ldl/ldr needs `Vec3 v; v = vcall(...)` (assignment), not `Vec3 v = vcall(...)` (00451EE0).
- An `addu` operand order flips by writing the offset first in the source expression (`e->b*4 + (s32)arg1->p0C`) (00454698).
- A wanted register that is the next argument register after the last one the callee reads, with the draft passing a constant there: the draft invented a trailing argument; drop it (00439288).
- `$v0 = 0` hoisted above the first branch is if-conversion (IF-CASE-1); a loop-pass block move can block it: write the if-chain inside the loop as the `switch` its compare tree shows, with `default: return K;` (0046d960).
- Two float parameters in each other's $f20/$f21: reorder the function's parameters to the callee's order (float position is invisible in the ABI) (00428600).
- Two block temporaries swapped where one feeds a `goto store` join variable: write the store in each arm and delete the label; cross-jumping brings the shared store back (00491418).
- local-alloc orders a block with exactly three quantities by a fixed three-exchange network on quantity numbers, not a priority sort; `f(o, i++)` adds a fourth quantity and switches to the real sort: write `i++` as its own statement (00449fa0).
- A two-quantity block with the wrong priority order: one local for both values that share the register (`float u = 1.0f; s = u - t; ...; u = t * y;`) makes it a global pseudo (0047e4e8; the least natural of these).
- Barrier cautions: a `do { } while (0)` nested loop note stops jump1's exit-test scan and can rotate the enclosing loop; sched2 honours the barrier, so nothing retail hoists into the prologue can sit behind one.
- A callee retail calls with only a0 (or a0-a1) set and the rest passed through needs a short local prototype: `func_00579358(s32)` gave the right `a0=2`; the full 7-argument signature forced extra argument setup.
- A float field store emitted as `swc1 $f0` (zero in an FP register; plain `x = 0.0f` gives `sw $zero`) comes from the chained assignment `s->pos.y = s->pos.x = 0.0f` (00104a60).
- Zero stores and a callee argument through one pointer (`a0` or `v1` = `s0+off`): a local `V2 *p = &self->pos` inside the case block; hoisted above the branch it lands in v1 and costs a daddu (00104b68).
- `a == 1 || a == 2 || x` folds into a range test (`addiu -1; sltiu 2`); `a == 1 || (a == 2 || x)` keeps two branches (beq then beql).
- A float constant used once in a loop that contains calls is hoisted into a saved FPR ($f20); one used twice (a compare and a store) is not: a retail loop with no $f20 save probably uses the constant twice (00361570).
- Indexing global arrays through a struct (`D.a[i]`, `D.x[i]`) matches loop pointer homes and strides far better than raw `char *` plus offsets (0035F808: 102 to 6 off).
- A 2-case `switch` compiles as a plain compare chain; a third `case 2:` falling through to `default:` gives retail's `beq 1; slti 2; beql 0` dispatch and layout (00409258).
- Locals retail keeps at sp+4/sp+8 while all s-registers are busy are spills, not an aggregate: plain scalar locals give the matching prologue, a struct does not (004149D8).
- Identical tails or switch arms merge only in jump2, after allocation: writing each exit or each case label as its own arm raises the refs of every value they touch without changing the code (001e46a8: four early-return sites instead of one `||` chain; 0044a2e0: 23 case labels each with its own body).
- sched2 hoists an instruction on callee-saved registers above calls, so a pre-call position in the listing does not say where the source computed it: compute `p + o1` at its use after the calls; sched1 then keeps it after them and the pre-call slots change (003fe358).
- sched1 issues at most 2 instructions per cycle and one memory instruction per cycle; a store through the frame pointer outranks parameter copies because every later call counts as its dependent.
- Two local quantities with non-overlapping ranges both take the first free register whatever their priority: one local for the earlier value and a later one moves it to global (0055a8b0). A parameter reused as the loop's end pointer avoids a merged $a1 preference (00486388; unnatural).
- Clamp the parameter itself (`if (m4 < arg3) arg3 = 0;`) instead of a second variable when a block-local takes the register a global should have (0055bdf0).
- unit_0034E9A0 (DynamicsConductor), 2026-10-12: what is left after 17 Sonnet and 8 astra matches is float-register homes and saved-register order (0035D248, 0035EFB8, 003598F8, 00360980, 00357D00); Sonnet matched 5 of 17 on its second pass there.
- unit_001DC8F0, 2026-10-13: 001E2CA8, 001E1120, 001E4F58 share `if (n >= K) { A }` ending in `b join` with `lw a0` in the slot plus a separate else block; probably real C++ locals with destructors and shared temporary slots; not reproduced.
- unit_003CCAE0 and unit_003F1660 (float-heavy car and physics code), 2026-10-13: Sonnet matched 4 of 17 fresh functions; the rest end on integer and float register homes (003CD920, 003CD730, 003F3090, 003F38D8, 003F1E60).
- unit_001D72E0 (001D9AE0, 001DA4F0, 001DA628), 2026-10-13: copy-on-write string copies where retail reloads the string pointer around `c_str` and ours merges the load; needs the real `basic_string` template rather than a hand-written struct.
- unit_00494578 (network), small functions, 2026-10-13: after about 250 matches the residue (68 given up in one pass) is register numbering, the 0x70002000 scratchpad base kept in a register (0049FDF0, 004A0BE0, 004A4500, 004A7900, 004A0640, 004AA788, 0049A080, 0049F318), peeled-first-iteration loops (00511EB8, 00512068) and alloc-wrapper layouts (0053DFD8, 0050A440).
- unit_00494578 (network), 257-512 B, 2026-10-13: Sonnet matched 11 of 32; many of the rest are 70 to 130 instructions off because retail keeps stack addresses in extra callee-saved registers (larger frame: 0051DE30, 004BD038, 004C0D78, 004CB618) or builds DMA/GS packets with a fresh pointer copy per element (004A7FA8, 004A9ED8, 0052AB68: probably inlined helpers).
- The scratchpad base family (unit_00494578: 0049FDF0, 004A0BE0, 004A4500, 004A25F0, 004A4C58, 004A7900, 004A0640, 004AA788, 0049A080, 0049F318, 004A9378, 004A2478, 00497518, 004A4F48, 004A4DE0; probably the switch members 004A5FE0, 004A5CC0, 004A4930, 004A4550), 2026-10-13: retail treats the base 0x70002000 as ONE instruction whose value the optimiser cannot see. No pure C form reproduces that: a visible constant is split into `lui`+`ori` before sched1 (4 references instead of 2, so local-alloc and the scheduler change), CSE folds `base + 0x50` into `ori 0x2050`, combine folds a single use into `lui $at` plus displacement, and gcse copies it into every block; a `long`, a symbol (`lui %hi`/`addiu %lo`) and `volatile Spr *` all fail. The four smallest members print MATCH in the judge with `Spr *p; __asm__("li %0, 0x70002000" : "=r"(p));` as the first statement (not submitted: one-instruction asm that hides a constant is the maintainer's call, like `nosched1`).

## Profile and form lessons from the 2026-10-17 rounds (three Sonnet workers, ~130 matches)

Try the compiler profile before rewriting code; most closures were a profile, not a source edit.

- Soft-float newlib/libm/stdio (fdlibm: sin, cos, tan, atan, exp, log, pow, fmod, sqrt, floor, ceil, scalbn, modf, vfprintf `cvt`, `exponent`): write the public source verbatim as plain C and use `/* compiler: ee-gcc2.96-nsa-g */`. The original leaves `nop` in the `jal` delay slot of every soft-float libcall (`-g` line notes stop reorg filling it). Unary minus on a double is `dpsub(0, x)`: plain `-x` is right; never call the libcall by address (it becomes a sibling `j`). Hardware-float `*f.c` functions use the same marker.
- SDK glue, 0x5AEF80-0x5B9A20 and similar (ring buffers, linked-list unlink, RPC send wrappers, `0x1000Fxxx` polling loops, tiny int wrappers): `/* compiler: ee-gcc2.9-991111 */`, often as `.cpp`. Signs: extra or unfilled nops, 16-byte register-save spacing, an `int` wrapper that must return the callee's result so the call stays a `jal` instead of a sibling `j`.
- `bnez` against `bnel` in C-library code (mprec.c `_multadd`, `_pow5mult`): the real file defined its callees earlier in the same translation unit. Compile as `.cpp` and put `throw()` on the prototypes of ALL preceding same-file callees at once (Balloc, Bfree, multadd, i2b, multiply), not one at a time.
- libgcc2: `find_exception_handler` is the real 2000-10-03 source (`gcc/libgcc2.c`), including the `else pc--` and the `if (tab[pos].start_region != (void *) -1) pos++` guard on the rethrow path; a draft written from memory missed both and sat 52 instructions off. `__divdi3`/`__udivdi3` are the `__umoddi3.c` unit with `L_divdi3`/`L_udivdi3` (clz table at 2A28/2C28/2D28). Constructor-list loops: count `unsigned long`, index `int`, test `!= 0`. `(int)d` calls 0057FA98, `(long)d` calls `__fixdfdi`: the callee tells which cast the original used.
- libio members (constructors, destructors, `operator<<`/`>>`): copy the preprocessed header block from a sibling libio `.cpp` (e.g. func_00593570.cpp), derive the class or add the member with `__asm__("func_ADDR")` on its declaration, define only the member under test (a second definition makes the judge compare the wrong function). `/* compiler: ee-gcc2.96-exceptions */` when the original has unwind cleanup regions calling 005BD7A0. Examples: the filebuf and stdiobuf constructors (00596FC0, 00597028, 005970A0, 0059BB00), whose base-destructor + `__rethrow` + `terminate` tail several tiers had called impossible; a caller of a constructor needs its mangled name (`__7filebufi`) and libc names (`fileno`) in config/libs/libio_symbols.txt, or the reference cannot be checked or linked.
- libio functions whose .cc file already has a matched sibling can be written without the snapshot: take that sibling's source up to its function (the preprocessed libio headers of the same file, with its profile: isgetline.cc is `ee-gcc2.96-g`, iostream.cc default) and add the libio 2.8 function. `istream::gets` (005939F0) and iostream.cc's static `write_int` (00592418, 944 B) matched that way; write_int is the later version whose output half checks every write (`_IO_padn(...) < padding`, `_IO_putc(sign < 0 ? '-' : '+', sbuf) < 0`, `_IO_sputn`) and ends in `failed: set(ios::badbit); osfx();`. Its string literals must be the address-named data symbols (`D_006CF7A0` for "0123456789ABCDEF0X", `D_006CF798` for ""), or the judge cannot check them and the link places new copies. The judge accepts a call to a libmatch-placed function by its mangled name, but the build leaves the caller out ("references unnamed-address symbols") until that name is listed in config/libs/libio_symbols.txt (gets needed `_sb_readline__FP9streambufRlc = 0x005938B0`).
- A glued neighbour (005A2E68 is `abort` + `abs`; 005BE6D0 follows `fde_merge`): the judge compares the first function the object emits, so define the leased one first.
- Sibling call: a `void` function ending `if (f & 1) f2(this);` only gets the sibling `j` when written `if (f & 1) return f2(this);` with no trailing return. A void wrapper whose last call turns into `j` is matched by returning `int` and returning the call's result.
- Stores to consecutive fields come out rotated against source order (the last source statement is emitted first): to get emitted C,0,10,14,8 write 0,10,14,8,C. Byte-wise unaligned stores go in natural order 0..3; scheduling then gives 3,1,2,0.
- `switch` case labels are laid out in source order. A `u16` read into `int t` tested as `t < 2 && t >= 0` folds to `sltiu`; two statements (`if (t >= 2) return; if (t >= 0)`) keep `slti` + `bltz`.
- The original holds a constant like 1 in a callee-saved register across a loop: declare it (`int busy = 1;`). Take `&p->field` into a local first when the original copies a pointer-derived argument first in the prologue (prologue copies follow first-use order). `x = a; return x` coalesces into the wrong register where the original has `if (cur) return cur;`.
- Float literals: `1.442695f` rounds one ulp low in this compiler; write a double literal or `1.0/6.0` assigned to a float, and compute the polynomial before the range checks. `lwl/lwr` in the wrong order: marker `ee-gcc2.96-nsa-nosib-as2004`. A callee whose result is unused but whose return register shows up in the caller (a vtable address in `v1`) must be declared `int`. A `void f(void)` callee next to a `li a1,-1` in its delay slot means the `li` is the caller's own assignment, not an argument.
- 64-byte-aligned stack scratch: a VLA `char raw[n]` (n a runtime `int`) in an inner scope, aligned by hand with `(raw+0x3F)&~0x3F`; `aligned(64)` and `alloca` do not give the fp/s2 save. `__builtin_alloca((len+15)&~15)` gives the variable-length concat buffer.
- Packed or bitfield request words: a 64-bit `unsigned long` bitfield struct passed as `long` reproduces the `dsll/or/and` chain; a `struct { long v; } __attribute__((packed))` member gives `ldl/ldr/sdl/sdr`; a plain `int[11]` struct assignment gives `lw/sw`.
- Tools: `tools/profile_sweep.py` judges every kept draft under every profile; run it on each batch of new near misses before spending a worker retry. `tools/oracle.py` needs `gdb` in WSL (installed) and the venv python (`~/.local/share/gt4/venv/bin/python`).
