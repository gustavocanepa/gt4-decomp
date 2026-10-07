# Sony ee-gcc 2.96 (build 001003-1), -O2 -G0, C++ front end

How this compiler shapes code. Valid for any game built with it. Each rule: when the assembly
shows X, write Y. "(probe)" marks rules re-checked by compiling the C++ shown with our compiler.

## Basics: types, ABI, reading the listing
- Sizes: char (signed, `lb`), short 16, int 32, `long` 64 (`daddu`/`ld`/`sd`), pointers 32, float
  in FPU, `double` is soft-float. `sizeof(long) == 8` (probe): use `s32`/`int` for 32-bit values.
- Integer args: `$a0-$a3` then `$t0-$t3` (8 registers); a 9th arg goes to `0($sp)` of the caller
  frame. Float args: `$f12, $f13, $f14...` consecutively, independent of the integer count.
- A register not written before a call still holds the caller's own argument: the callee receives
  it unchanged, so pass that parameter through. Read which registers each call actually sets.
- Each file declares its own externs with extern "C": if the caller sets fewer argument registers
  than the callee reads, declare the callee in this file with only the arguments this caller sets.
- `daddu rd, rs, $zero` is a plain register copy (`move`), `daddu rd, $zero, $zero` is `= 0`;
  neither means 64-bit arithmetic. `addiu rd, $zero, K` is `= K`.
- `sd`/`ld` of `$s*`/`$ra` are the prologue/epilogue (64-bit saves), not data. Saves sit above the
  locals: `$s0` lowest, then `$s1`..., `$ra` highest. Bytes below the first save are locals or the
  outgoing stack-argument area (stores to `0($sp)` just before a `jal` = 9th+ argument).
- Frame bigger than C needs = a local array/struct the original declared; frame too big = a local
  or a parameter the original did not have (or a call whose stack argument you invented).
- `beql`/`bnel`/`bgezl` (branch likely) come from the compiler, not from special source constructs.
- Real `nop`s the compiler emits on its own: 2-3 `nop` padding inside a very short loop before the
  back branch (R5900 short-loop workaround), and 2 `nop` between an `mtc1` and a dependent `div.s`.
  Write the loop/division plainly; never try to reproduce those nops.
- An empty `jal`/`jr` delay slot (`nop`) only means nothing eligible was available; it is not a
  source construct to imitate.

## Register allocation and temporaries
- Register allocation and instruction order follow statement order: if only a few instructions
  differ, try reordering statements, introducing or removing a temporary, a pointer variable for a
  sub-struct, an inline helper, a different loop form, or signed/unsigned types.
- Saved-register (`$s0`, `$s1`...) order is decided by priority = uses*log2(uses)/live length, not
  by declaration order. To swap two `$s` homes, change real uses or lifetimes, not declarations.
- To push a value to a higher `$s` register: end its live range later or give it fewer uses; to
  pull it lower: assign it later (after the early-return checks) or use it more often.
- A named pointer local the original only dereferenced (`next = n->next; n = next;`) becomes an
  extra user variable and shifts every other register; write `n = n->next` / `n->next->x` instead.
- A copy `t = param;` never survives inside one straight block (CSE merges the two). A retail
  `move` between two registers holding the same value needs a join in between or a later use of the
  older value.
- Two equivalent forms of one value in different registers: use the expression the original used.
  `entry = &tbl[i]; entry->a` and `tbl[i].a` give opposite `addu` operand orders (base first vs
  index first); match the order in every `addu` of the function.
- `*(p + i)` vs `p[i]` on byte arrays and `base + i*size + off` vs `((T *)(base + off))[i]` also flip
  `addu` operand order or constant placement; mirror the retail operand order.
- `table->arr[i].a` and `table->arr[i].b` (array embedded in a struct) give two address registers
  plus a `daddu` copy; `T *arr` member (`p->arr[i].a`) gives one. Pick the struct layout accordingly.
- Callee-saved register count too high: you cache a pointer/field across a call that the original
  reloaded after the call. Reload it (write the field access again) instead of keeping a local.
- Callee-saved register count too low: the original kept a value live across the call (a local
  computed before the call and used after it); hoist that computation before the call.
- One variable reused for two unrelated roles is one pseudo; two locals get separate registers.
  Reuse only when the retail registers show one home for both values.
- A temporary shifted from `$v0` to `$v1` (or back) right after a call whose result is ignored:
  the callee's declared return type is wrong. Declare it `void` vs `s32` per its real definition.
- A narrow parameter (`u8`/`s16`) is masked on entry (`andi 0xff`, `sll 16; sra 16`) when used; if
  retail has no mask, the parameter is `s32`/`u32`.
- A `dsrl` (64-bit shift) on an argument then `andi` = shift of a `u8`/`u16` parameter; a `u32`
  parameter gives `srl` (probe: `(c >> 3) & 0xF`).
- `s32 v = (u8)field` copied into a 32-bit local before `v == 1 || v == 2` avoids an `andi 0xff`
  and lets the compiler emit `addiu -1; sltiu 2`.

## Statement order and scheduling
- Independent stores are scheduled, not emitted in source order: among equal-priority stores the
  one that is the last use of a register tends to go first; try moving the last-use statement.
- A store fed by a constant needing `lui/ori` (or `lui/mtc1`) is issued early regardless of source
  position; reorder only the cheap ones.
- The store in the `jr $ra` delay slot is the scheduler's leftover, not necessarily the last C line.
- Two adjacent loads/stores swapped vs retail: check the declared types first. A load can move above
  a store only if their types cannot alias (int vs float vs pointer vs struct). Use the data's real
  type (`f32` vs `s32` field, `T *` vs `void *`/`s32` for pointers).
- A table really in read-only data should be declared `const`; this removes false dependencies and
  changes which of two loads is issued first.
- A global reloaded after a store through a pointer: the store's type may alias it. If retail does
  not reload, try a typed struct field (`w->a = v`) instead of `*(s32 *)(p + off) = v`.
- Struct copy then field stores: a later store whose type occurs inside the copied struct waits for
  the copy; the member types of the copied block decide what may be hoisted above it.
- Stores dependent on a division must follow the division in source order, else they land between
  `div` and the `mflo`/zero check.
- A load in the first branch slot after a call = a local read written right after the call
  (`x = p->field;` before the `if`).
- Reading a field into a local before an unrelated store lets that store fill a later `jal` slot.
- Chained `a = b = v` stores in the opposite order of `b = v; a = b;`.
- `size = a + b; size += c;` keeps each add in order; one long sum gets reassociated.
- `(w + 8) * 16` is folded to `w*16 + 128`; keep `t = w + 8` as its own local if retail adds first.
- When the code depends on unrelated declarations (same function, different code after editing
  externs), the compiler hashed symbol addresses during CSE; try the other natural form or park it.

## Branches, conditions and branch-likely
- `slt; xori 1` = expression `return x >= 2;` / `!(x < 2)`; `slt; sltiu 1` = early returns
  `if (x < 2) return 0; return 1;` (probe).
- `srl $v0, x, 31` = `return x < 0;`; retail `slti x, 0` instead comes from
  `if (x < 0) return 1; return 0;`.
- `sltu $v0, $zero, x` = `return x != 0;` / `p != 0`. Same from `bool` returns (no extra mask).
- `andi; sltu $zero` (0/1 flag) = `x = 0; if (f & 2) x = 1;`; `srl/sra; andi 1` = `x = (f & 2) != 0;`
  (probe).
- `addiu x, -LO; sltu x, N` = range test `v >= LO && v < LO+N` (probe). To keep two separate `slti`,
  nest the tests: `if (v >= LO) { if (v < HI) ...}`.
- `a && b` with two branches is normal; `(a & 1) && (a & 4)` style bit tests may fold into one mask,
  while nested `if`s keep separate `andi`s.
- `li A; li B; movz/movn` = `x = c ? A : B;` or `x = B; if (c) x = A;` (same code, probe). If the
  `movz`/`movn` choice or the `li` order is reversed, flip the condition (`c == 0` vs `c != 0`).
- `move; movz` with two registers = `return c ? a : b;` (probe).
- A ternary or `if` whose arm reads memory (`p->x < 0 ? -p->x : p->x`) is never turned into
  `movn`; it stays a branch-likely with the arm in the slot. A local temporary instead gives `movn`.
- `bc1tl/bc1fl` with `neg.s` in the slot = `a < 0.0f ? -a : a` (probe).
- `bltzl` with a fallback constant in the slot: `if (a + b < 0) x = K; else x += b;` (the sum is in
  the condition, both arms store).
- Taken-only (`...l`) slot holding a load that would be invalid on the other path (e.g. through a
  maybe-null pointer) = a natural `if (p == 0) {defaults} else {p->...}`. Do not force it.
- Inverting an `if`/`else` (testing the opposite condition, swapping arms) flips `blez`/`bgtz`,
  `beq`/`bne` and often turns a plain branch into branch-likely or back. Try both orders.
- `if (x < 0) { d = -1; x = -x; } else { d = 1; }` gives `bgezl; li`; testing `x >= 0` first gives a
  plain `bgez`. The tested condition's polarity follows the first-written arm.
- `daddu $v0,$zero,$zero` in a branch slot = early `return 0;` at that site; a `result = 0;` local
  at the top gives a hoisted zero instead. Choose per retail.
- Separate `return 1;` exits keep one `li $v0,1` per branch site; one merged return removes them.
- One shared `jal` whose argument is set in a branch slot (`bne; daddu $a0,$zero,$zero`, then
  `li $a0,1`) = both arms written in full: `if (c) { f(1); return 1; } f(0); return 1;`.
- A nullable-result pattern `if (f() == 0) { ...; return N; } return 0;` gives `bnel` with zero in
  the slot; `if (f() != 0) return 0; ...` gives plain `bne`.
- One-word `bne` vs `bnel` before a call path may depend on whether the callee is defined earlier
  in the same file (known not to throw). We compile one function per file: park such residuals.

## Loops
- Counted loops: write the loop the way a programmer would, e.g. `for (i = 0; i < 125; i++)
  v = f(&obj->elems[i], v);` over an array (or `p++` as its own statement). The compiler itself
  turns it into a down-counting register plus a pointer stride; reproducing that counter by hand
  with do/while or `p++` inside the call puts the decrement in the wrong slot.
- Down-counter ending in `bgez`/`bgezl` (count starts at N-1) = ascending `for (i = 0; i < N; i++)`
  whose `i` is only the exit test (probe).
- `bne`/`bnel` against a constant held in a register (`li $s2, 3` before the loop) = `i != 3`
  (probe). An up-counting `slt`/`bnez` counter = `i < N` where `i` is also used in the body.
- Branch-likely loop closer carrying the first load of the body in its slot is normal rotation of
  any `for`/`while`; write the plain loop.
- Saved-register exchange between cursor and index: the original indexed (`p[i]`, `out[count]`)
  instead of advancing a cursor (`*p++`), or the other way round. Try the other form.
- Guard + `do/while` (test duplicated at top and bottom) is how a plain `while`/`for` compiles. A loop
  that keeps a `b` to a test at the top usually has a call in its condition or a `break` early in
  the body.
- `b` into the middle of the loop landing on a call: priming-read loop,
  `n = find(); while (n) { work(n); n = find(); }`.
- List walk `for (n = head; n != 0; n = n->next)` vs `while`: same code; the difference is where you
  load fields: read the second field into a local before testing flags to fill the closer's slot.
- Loop initializers fill the delay slot in source order: `for (j = 0, p = base; ...)` vs
  `for (p = base, j = 0; ...)`.
- A loop `for (...; cursor += 8)` that advances the call-result register itself: keep one variable
  for the cursor (`cur = f(); base = cur; cur += hdr;`), not two separate pointers.
- Biased negative offsets in a loop (`-0x1C($s0)`): pointer advanced alongside the counter with the
  loop starting at 1: `for (i = 1; i < n; i++, p++)`.
- A loop around the final call (even one iteration) keeps that call `jal`, never `j`.

## Switch and jump tables
- `sltu t, k, N; beqz t, default; sll; lw; jr` = jump table: needs about 5 or more distinct case
  labels (probe: 4 cases give a compare tree, 5 give a table). Cases sharing one body count once.
- Table entries that repeat (`L1, L2, L3, L3, L3`) = separate cases with identical bodies that were
  merged afterwards; write each case separately.
- Low cases that do nothing still appear in the table: write them (`case 0: case 1: break;`).
- Compare tree starting with `beq k, 1` then `slt k, 2` = small signed switch (probe); a `u32`
  selector with 0,1,2 gives a linear `beq` chain instead.
- Arms ending `j $ra; li $v0, K` = `case X: return K;` (probe). Arms `b common; li $v,K` converging
  on one return = accumulator: `r = 1; switch (k) { case 0: r = 3; break; ... } return r;`.
- An if-chain of constant results becomes `movz`/`movn`; retail keeping real branches with a stray
  `slti` first = a small `switch` with grouped cases (`case 0: case 2: case 3: return 2;`).
- `case 1: f(); return; case 2: g(); break;`: the arm with `return;` keeps a sibling `j`, the last
  one falls into the shared epilogue as `jal`.
- Same call written separately in several cases ending `break` can merge into one `jal`; computing
  the argument then calling once changes the whole dispatch.
- Locals shared across switch arms (same register in each arm) are declared at function scope.

## Calls and tail calls
- Tail calls (C++ front end): a function ending in `j callee` (a jump, after restoring $ra) returns
  that callee's result: write `return callee(...);` with a non-void return type. A final
  `jal callee` followed by the epilogue means the result is not returned (a plain call).
- In this C++ front end a void function ending in a plain call `f();` gives `jal` + epilogue, while
  `return f();` (legal for void f in C++) gives `j f` (probe). Same inside branches:
  `if (c) return f();` gives `beq; ...; j f`.
- `jal` + epilogue where the caller returns the callee's value: return types differ in mode (64-bit
  caller returning an `s32` call, or a narrow callee widened) (probe: `long` returning `h()`).
- Indirect and virtual calls (`jalr`, printed `jal $31,$2`) are never turned into `j`, even when
  their result is returned (probe).
- A call returned through a `static inline` helper stays `jal` + epilogue (probe). Use an inline
  helper only when the same argument pattern recurs in many functions.
- Other reasons a tail call stays `jal`: variadic caller, struct return, an address-taken local or
  parameter, a 9th argument without incoming stack room, a loop around the call.
- Several `j`/`jal` tails in one function: arms ending with `return f(...)` get `j`; a call that
  merely falls into the shared epilogue gets `jal`.
- Arguments 5-8 go in `$t0-$t3` (not on the stack); a 7-argument call just loads `$t0-$t2`. Write the
  full prototype.
- A single argument-register load in the `jal` delay slot is normal; out-of-range offsets (needing
  `lui`) cannot go there, so the slot stays `nop` or takes another instruction.
- `jal operator_new; li $a0, SIZE` = `new T` (allocation size in the delay slot); in our C style:
  `p = (T *)func_XXXXXXXX(SIZE);` with the allocator's address.

## Return values
- Return values: if a callee's result stays in $v0 until the end while later temporaries use $v1,
  the function returns that result (keep it in a variable and return it). Old g++ constructors do
  this: call the base constructor, store the vtable pointer, return what the base constructor
  returned (`this`).
- `move $v1, $v0` right after a call with no copy back before `jr` = the function returns that call
  result (`r = f(); ...; return r;`): a function typed `void` showing this is really non-void.
- `s64 t = f(); if (t) { ...; return g(t); } return t;` keeps the post-call copy; overwriting `t`
  with `g(t)` removes it.
- `r = f(); if (r != 0) { ...; return 1; } return r;` passes `$v0` straight through on the zero path.
- Struct returned by value: hidden destination pointer arrives in `$a0` (other args shift by one) and
  is returned in `$v0`; the struct is built on the stack and copied (probe).
- `bool` results are used as is (`$v0` tested directly, no `andi 0xff` after the call) (probe).
- Use each callee's real return type: `void` vs `s32` vs pointer changes `$v0/$v1` choice, tail
  merging and even which branches get merged after the call.

## Integer arithmetic, 64-bit and EE-specific instructions
- 64-bit `sd`/`ld` save and restore registers; struct copies of 8-byte aligned data use `ld`/`sd`
  pairs (declare such structs with __attribute__((aligned(8))) or 64-bit members).
- `daddu/dsubu/dsll/dsra32` on data = `long`/`s64` arithmetic (probe); `dsll32; dsra32` pair = sign
  extension of a 32-bit value to 64 bits (`(s64)x`).
- Unsigned 32-bit value stored to a 64-bit slot: keep the `u32` type (cast or typed local); a signed
  expression sign-extends and changes register grouping.
- Constant divide `li 5; div; beql zero,..; break 7; mflo` = plain `x / 5` (the zero check is
  emitted even for constants, probe).
- Signed power-of-two division: `addiu x,(2^n-1); slt; movn; sra n` = `x / 2^n`; with `sll; subu`
  after = `x % 2^n` (probe). Unsigned: just `srl`/`andi`.
- Multiplication by a small constant becomes shifts/adds (`a*12` = `sll 1; addu; sll 2`, probe).
  Retail `li K; mult rd, rs, rt` (3-operand EE `mult`) = multiplier held in a named local
  (`s32 k = 0xC0; a * k`) (probe).
- `s16` decrement: `addiu -1` then `sll 16; sra 16` when the value is used; `u16` decrement gives
  `li 0xFFFF; addu` (probe).
- `srl; andi` to read and `and ~mask; or` to write a field of a word = a bitfield; declare it
  (`u32 b : 5;`, first member in the low bits) (probe). A test against an unshifted mask is plain
  mask code.
- A `union { u32 word; u16 half; }` keeps an `lhu` reload after writing `word`; a plain field lets
  the compiler drop the read.
- `lui $at, hi; addu $at, $at, idx; lw x, lo($at)` = indexed global array `D_X[i]` (probe).
- `mult rd, rs, rt` (EE three-operand, no `mflo`) is the normal output of `a * b`; `div; beql; break 7`
  then `mflo` = `a / b`, `mfhi` = `a % b` (probe).
- `min.s`/`max.s`, `sqrt.s`, `lq/sq`, `pextlw`, `qmfc2` etc. are not emitted from plain float C (except
  `lq/sq` for `u128` copies): use a small inline-asm helper (`__asm__("max.s %0, %1, %2" ...)`).
- `u128` (`int __attribute__((mode(TI)))`) copies give `lq`/`sq` (the last `sq` lands in the `jr`
  slot); `lq; sq; jr; nop` with an empty slot is an asm copy, not plain C.
- `por` moves and `pcpyld/pcpyud` around 128-bit values come from `u128` C or SDK asm macros.
- Bare MMI/COP2 (`vmul`, `lqc2`, `qmtc2`) in the middle of a function = inline asm from Sony's libvu0
  style macros, wrapped in `.set noreorder` when retail has a `nop` after it.

## Floats
- sqrt is inline asm: `__asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x))` (never a `sqrtf` call).
- Float constants: `lui $at, HI; mtc1 $at, $fN` (plus `ori` when the low half is nonzero) = a literal
  (`0.5f`); `mtc1 $zero, $fN` = `0.0f` (probe). Write the literal, not a global.
- cc1 truncates decimal float literals: `0.1f` is 0x3DCCCCCC, `0.2f` 0x3E4CCCCC (probe). Spell the
  literal the programmer wrote; for the last bit try neighbours (`6.283185f` vs `6.2831855f`) or an
  expression (`3.14159265f * 2.0f`), constants fold at compile time.
- The same constant loaded twice = the code between two uses had a join (e.g. a ternary
  `t = c ? a/b : 0.0f`); `t = 0.0f; if (c) t = a / b;` loads it once and keeps it.
- `c.lt.s; bc1t; li $v0,1; move $v0,$zero` = `return a < b;` on floats (probe). `c.le.s`/`c.eq.s`
  with `bc1f` = the negated test; check operand order (`a > b` is `c.lt.s b, a`).
- `cvt.w.s; mfc1` = `(s32)f`; `mtc1; cvt.s.w` = `(f32)i` (probe).
- `li.s 2147483648.0; c.le.s; bc1f; sub.s; cvt.w.s; or 0x80000000` = `(u32)f` (probe). An unsigned
  int->float conversion similarly adds a correction branch.
- `jal dpadd/dpsub/dpmul/dpdiv/dpcmp` etc. = `double` arithmetic (soft float, values in GPRs);
  float->double conversion calls appear for `double` locals or float args to variadic functions.
- `neg.s` = `-a`; `abs.s` = `__builtin_fabsf(a)` (probe); the ternary `a < 0 ? -a : a` gives a
  branch-likely instead (see Branches).
- Reuse one `f32` local for a value used before and after a call to keep it in one `$f20+` home;
  separate locals change the FPR assignment.
- FPR numbers differ in a call-free block: the order comes from latency (the scheduler), not names;
  only a change in the expression shape changes it.
- Callee-saved FPRs (`$f20`...) saved with `swc1` after the GPR saves = float values live across a
  call; reload a field after the call instead if retail has fewer.
- A float call result scaled immediately (`t = f(x) * k + c;`) keeps `t` in `$f0`; storing `t = f(x);`
  first lets CSE forward `$f0` and changes the next register.

## Globals and data (-G0)
- No `$gp`-relative accesses exist with -G0: a scalar global is `lui; lw %lo(sym)` and a field of a
  global struct `lui; lw %lo(sym+off)` (offset folded, probe). Declare `extern T D_XXXXXXXX;`.
- One `lui/addiu` pair held in an `$s` register across calls = `T *w = &D_X;` once, used afterwards;
  rematerialised per use = direct `D_X.field` / `((T *)D_X)[i].x` accesses at each site.
- `lui` shared but `addiu %lo` recomputed after a loop or if/else = second use through a pointer local
  (`p = (T *)D_X; ... p->x`).
- Strings: a literal (`"text"`) lands in the file's own .rodata and match.py compares only opcode and
  registers for it; `extern char D_X[];` with the retail address makes the `%hi/%lo` exact.

## Structs and copies
- `ldl/ldr` + `sdl/sdr` pairs (unaligned 64-bit) = `*dst = *src;` of a struct with 4-byte alignment
  (probe: 8 and 16 bytes; all loads before stores in each group). `ld/sd` = 8-byte aligned struct.
- Long copies (0x40 bytes and more) become an aligned/unaligned dual loop; `memcpy(d, s, LITERAL)` is
  also inlined (tail word `lwl/lwr` when alignment is unknown); a variable size calls `memcpy`.
- `jal memset` on a stack buffer followed by a copy = a local aggregate initializer
  (`T q = {0, 0}; *p = q;`) (probe); `f32 v[4] = {0, 0, 0, 1.0f};` gives `memset` + one store.
- Local array copied from read-only data with `ldl/ldr` at function start = an initialized local
  array (`u16 t[5][2] = {...};`).
- `addiu $a0, $base, off` before a call = `&p->member` (embedded struct); `lw $a0, off($base)` =
  a pointer member.
- A stack frame with a local slot but no stores to it = a local array that is written but never read
  (the compiler drops the stores, keeps the slot).
- Small adjacent `s16` fields tested together may be loaded with one `lw`; separate tests keep
  separate `lh`.
- Repeated `arr[i].f` accesses keep separate address computations; caching `e = &arr[i]` merges
  them. Match retail's count of `sll/addu` per access.
- Declare fields with the width retail loads: `lh` = `s16`, `lhu` = `u16`, `lb` = `s8`/`char`,
  `lbu` = `u8`; `slti` after the load = signed compare, `sltiu` = unsigned.

## C++ specifics: constructors, destructors, virtual calls, this-adjustment
- Game code is C++ (old g++ ABI); we write extern "C" functions named `func_XXXXXXXX` taking `this`
  as an explicit first parameter, with plain structs. Non-extern "C" names are mangled
  (`name__<len>Class`, ctor `__<len>Class`, dtor `_$_<len>Class`, vtable `_vt$<len>Class`).
- Vtable entries are 8 bytes `{s16 delta; s16 index; fn}`; slot 0 holds the RTTI function, so the
  k-th virtual (0-based, destructor included) is at `+8*(k+1)` (probe).
- Virtual call: `lw vt, K(obj); addiu e, vt, 8*i; lh d, 0(e); lw fn, 4(e); jalr fn; addu $a0, obj, d`
  = `e = (VEntry *)((char *)obj->vtbl + 8*i); e->fn((char *)obj + e->delta, ...)` (probe).
- The vtable pointer sits after the data members of the first class that declared virtuals (often
  offset 4 after one member); a second base has its own vptr, with negative deltas in its vtable.
- Conversion to a non-first base: `addiu $v0, $a0, OFF; movz $v0, $zero, $a0` =
  `p ? (B *)((char *)p + OFF) : 0` (null-checked this-adjustment) (probe).
- Constructors: `r = base_ctor(self); self->vtbl = D_xxxxxxxx; return r;`. Inlined base ctors store
  the base vtable then the derived vtable to the same slot (both stores remain).
- Destructor takes `(this, int flags)`: body, vtable stores, then `andi flags, 1; beq; j delete` =
  `if (flags & 1) operator_delete(this);` as a tail `return`.
- `delete p;` = `if (p != 0) dtor(p, 3);` as a sibling `j` (probe); `new T` = `jal new; li $a0, SIZE`.
- `bool` parameters and results are used without masking (probe); a byte mask on entry means `u8`.

Several rules were learned from the Digital Devil Saga decompilation's documentation (github.com/Megami-Decomps/dds-decomp), restated here in our own words.
