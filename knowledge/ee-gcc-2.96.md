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
- Byte-array member indexed by a variable: `addu $v0, $idx, $base` (index first) is `p->b[i]` with
  `u8 b[]` declared in the struct; m2c's `*(u8 *)(p + i + 0x14)` gives base first. Five 64-127 B
  misses on func_00359510's table matched this way (func_00364D20, 00344C88, 00365248, siblings).
- **Indexed address whose sum lands in the base's register** (`addu $a0, $a0, $v0` / `addu $v1, $v1, $v0`
  with the index product second, where mine has `addu $v0, $v0, $a0`): the original computed the
  element address in its own statement: `E *e = p->arr + i; e->x = v;` or `s8 *e = base + i * 0xEC;`
  then `*(f32 *)(e + off)`. Inline `p->arr[i].x` / `M2C_FIELD(base + i*size, ...)` never matches.
  11 functions (func_004082F0, func_003F3A28, func_00344DA8 family, func_001D33B0).
- m2c lists stores in their scheduled order; the source wrote them in field order. A run of stores
  after a call (constructor bodies: base ctor, vtable pointer, then members) matches when written
  vtable first and then by ascending offset (12 functions, e.g. func_001C74B8, func_001FD2A8);
  if not, permute the run (build/auto/small64/perm.py tries every order).
- m2c drops a constant offset kept in a saved register: retail `addiu $s0, $a0, 0x2C` in the prologue
  and loads/stores at `0($s0)` while the draft reads `M2C_FIELD(arg0, s32 *, 0)`: write
  `s32 *h = (s32 *)(arg0 + 0x2C);` and use `*h` (handle setters/getters around func_00328660 and
  func_003284E8, 11 functions; func_003BE128).
- Factory registration `p = func_00326750(size, 4, D_x); ctor(p[, arg1]); sp[0] = p; reg(arg0, sp);`:
  m2c shows `reg(arg0, sp, p)`; the call takes two arguments and p goes through the stack struct
  (23 functions in one pass with build/auto/small64/factory.py).
- m2c's falling-pointer fill loops (`*p = K; p -= 4;` on an `s32 *`, scaled wrongly) are
  `for (i = N; i >= 0; i--) a[i] = K;`; when the constant's `lui/ori` must precede the counter,
  hold it in a local assigned earlier (func_003BB9A0).
- A function ending in a plain void call compiled as C gets `j` (sibling call); retail `jal` +
  epilogue there means C++ (func_003D8A60, func_00107328: same body as .cpp matched).
- m2c splits a stack struct's first word into a separate `sp0` local (`daddu $a0, $s0` where retail
  has `lw $a0, 0($sp)`, or `daddu $t0, $v0` where retail stores `sw $v0, 0($sp)`): declare one
  `s32 sp[4]` and use `sp[0]` (func_00229F88, func_00306980).
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
- m2c lists its temporaries in its own order, not the original's: when the first differing lines
  are loads from another base register (`lw $v0, 0($s4); lw $v1, 4($s4)` before mine's
  `lw $s1, 8($s2)`), move the statement computing from that base first (a `size()` of the source
  before the destination's begin/end: func_00335248, 17 -> 6 differ with the address fix).
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
- A compare computed before a store and tested after it (`sltiu $v1, old, 1` before `sw new`, then
  `beql $v1`) needs the flag as its own local before the update: `int first = p->n == 0; p->n++;`
  (or `int last = --p->n == 0;`); testing `old == 0` after the store folds the compare into the branch.
- Interrupt control (`ei`, Sony's EI()) is a single-instruction intrinsic: `__asm__ volatile("ei");`
  (allowed by tools/asm_policy.py); DIntr() is func_005B72A8 (handle retain/release 003285A8/003285F8).

## Branches, conditions and branch-likely
- **Byte tests in `$v1` instead of `$v0`** across a whole draft (`lbu $v1; beql $v1, $zero`) while
  the original tests in `$v0`: the draft is compiled as C, the game as C++. The same body as .cpp
  (`char *` instead of `void *` arithmetic, extern "C") takes `$v0` (func_003A78B8: 31 -> 25 differ,
  all byte tests fixed). Game code near misses with that pattern: switch to C++ first.
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
- A rotated loop (entry test `beqz n`, body, test at the bottom, strength-reduced pointer) that a
  `for` refuses to give (g++ leaves `b` to a top test): write `j = 0; if (j < info->n) do { ... j++; }
  while (j < info->n);` (func_00353218). Index into 0xEC-byte records through a block-local pointer
  `u8 *w = p + OFF + j * 0xEC;` to get base-first `addu $v0, $s1, $v0` (func_00352C90).
- `sltu $v1, $zero, b; xori $v0, a, 0x0; movn flag, $v1, $v0` = `if (a && b) flag = true;` (bool
  flag, int/bool a, b set 0/1 earlier); `if (a) flag = b;` or `flag = a && b;` drop the `sltu`/`xori`
  (func_00352C90).
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
- **m2c drops a passed-through `this`.** Mine sets `daddu $a0, $sX` before a `jal` where the original
  leaves `$a0` alone (the incoming arg0, saved to `$s0` and then advanced): the callee is a method
  called on the caller's own `this` and m2c, seeing no write to `$a0`, left the argument out.
  Prepend `arg0` to that call (func_004404B8, 528 B, 11 differ -> MATCH; near_fix.py rule).
  The same holds for any leading run of arguments: `daddu $a2, $zero, $zero` in the original where
  mine has `$a0` = the caller passes its own `arg0, arg1` on and adds a third (mScrollBox__virtual_70:
  m2c's `func_002638E0(0)` is `func_002638E0(arg0, arg1, 0)`; near_fix.py tries k = 1..3).
- Two virtual calls through the same member pointer (`this->p->vf1(); this->p->vf2();`): the
  original reloads `this->p` after the first call; m2c hoists both loads into temporaries before
  it, which CSE then merges. Write the member access inside each call (mScrollBox__virtual_70,
  29 -> MATCH, with the vtable entry held in a statement-expression local).
- **Float argument place.** Floats go in `$f12+` whatever their place in the list, so m2c puts them
  last; but arguments are evaluated right to left, so the place shows in the order of the last
  register moves before the `jal`: original `mov.s $f12` before `daddu $t2` while mine has the
  reverse = the float comes before that integer argument. Try each place (near_fix.py rule;
  func_00335248: 4 -> 2 differ). Read the callee's prologue to see which registers it really uses.
  Several floats usually travel together: func_0040F850(int, f, f, f, f, int x 17) (m2c put the
  four floats after the 8th integer); moving the block right after argument 0 matched func_00410880
  and its two siblings (3 x 752 B). near_fix.py tries the block positions before single moves.
- **A temporary in `$v1` where the original has `$v0`** right after a call whose result is unused
  (`li $v0, 1; sw $v0, 0x164($s5)` after `jal`): the callee is declared returning `int` (m2c's
  `M2C_UNK`) but is `void`. A call with a value sets `$v0` there, and local-alloc then skips `$v0`
  for the next temporary. Declare the callee `void` (func_00335248, 624 B: 2 differ -> MATCH, where
  a 4-minute permuter run had failed; near_fix.py rule `void_returns`, chained after the other rules).
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
- **`addu base, idx` vs `addu idx, base` for an indexed field (race/physics, measured 2026-10-09).**
  Byte arithmetic `M2C_FIELD(p + i * 4, s32 *, 0xC)` (or `((s32 *)p)[i + 3]`) always adds the
  scaled index first (`addu $v0, $v0, $s0`); a struct member array `p->tbl[i]` adds the base first
  (`addu $v0, $s0, $v0`). Swapping the `+` cannot fix it; declare the array (or near_fix.py's
  `M2C_ARRAY(p, s32, 0xC, i)`, an anonymous struct cast). Open: an array of 0xEC-byte structs
  indexed beside a float array (func_00344DA8, `addu $a0, $a0, $v0`) still comes out index-first.
- **m2c's float-pointer loop strides are scaled twice.** `f32 *p; ... p += 0xEC;` (m2c prints the
  byte stride) gives `addiu 0x3B0`; declare the walking pointer `s8 *` and store through
  `*(f32 *)p` (func_0036A490).
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
- Order of the halves: gcc emits `uld/usd/ulw/usw` (struct passed by value, e.g. an 8-byte
  pointer-to-member in $t0) and every GNU ee-as we have expands them left half first (`ldl; ldr`).
  `ldr; ldl` (right first, 284 library functions incl. the 0x5c2b60.. PMF thunks) came from an
  assembler expanding those macros right first: marker `/* compiler: ee-gcc2.96-nsa-nosib-rf */`
  (tools/cc_rf.sh + rf_as.py; func_005C2B60 matches as `f(a0, a1, a2, a3, D_pmf)` with a by-value
  `struct { short delta; short index; int pfn; }`). Detect it by an `xxr X` followed by `xxl X` of
  the same kind (`ldr X; sdl X` is just a left-first load then store); blockcopy.py routes them.
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

- **Float literals: write them in hex.** ee-gcc 2.96 rounds some shortest-decimal float literals to the neighbouring float (m2c's `0.099999994f` compiles to 0x3DCCCCCB, the original is 0x3DCCCCCC; the diff shows a one-off `ori` low half after `lui`). A hex float literal (`0x1.999998p-4f`) is read exactly. tools/cpu_solve.py rewrites every float literal this way.
- **`lui/addiu` versus `lui/ori` with the same low half** means the original takes the address of a global (a `%lo` relocation goes through `addiu`), where the C has a plain integer constant. Use the symbol `D_ADDR` instead of the number (tools/near_fix.py does it from the diff).
- **Arguments 5-8 travel in $8-$11.** The EE ABI passes up to eight integer arguments in registers: `$a0-$a3` and then `$8-$11`, which the EABI/n32 names call `$a4-$a7` (and `$12-$15` are `$t0-$t3`). rabbitizer prints o32 names (`$t0` for `$8`); m2c's mipsee target reads `$t0` as `$12`, so it lost arguments 5-8 ("Read from unset register $t0") and called functions with too few arguments. `match.m2c_asm()` renames the registers before m2c sees them.
- **Drafts that do not compile** almost always fail for one of four reasons, all fixed from the compiler's own messages by `cpu_solve.compile_fix()`: an undeclared stack slot (`sp0`), too few arguments for m2c's guessed prototype (declare the callee unprototyped, `f()`), the result of a callee declared `void` (declare it `M2C_UNK`), `*` on an integer or `void *` (cast to the assigned variable's type).
- **A second compiler: ee-gcc 2.9 (990721/991111).** The ~270 functions whose prologue saves callee-saved registers 16 bytes apart (`autoloop.other_compiler`, 80 KB, 0x3ac140-0x5b9af0) were built by ee-gcc 2.9: of decomp.me's EE compilers only the 2.9 releases space the saves 16 bytes apart (2.96 and 3.2 use 8), and on those functions 2.9 drafts are the closest (tools/compiler_probe.py --foreign). A source chooses it with `/* compiler: ee-gcc2.9-991111 */` on its first line (project.toml `[compilers]`; match.py, build.py and the CI honour it; tools/other_compiler.py runs the draft pipeline with it: 10 of 270 matched as drafts, the rest are ordinary draft problems, and the four 2.9 releases with -O1/-O2/-O3/-Os, -G0/-G8, -fno-gcse, -fschedule-insns, -fno-schedule-insns2, -fno-strict-aliasing all give the same code on the closest ones). The library region (>= 0x5547e8) is otherwise NOT another compiler: no candidate release or flag set (-O1/-O3/-Os/-G8/-fno-schedule-insns2/-fno-strict-aliasing) does better than ours, no function uses `$gp` (so -G0 everywhere), and its near misses are the usual draft problems.
  - **Its near misses (2026-10-09, 10 matched from the closest drafts; rules in other_compiler.py `climb`):** (1) never leave a literal address: `*(T *)0x657A80` must be `extern T D_00657A80;` and a code address argument the function (`name_addresses`), because 2.9 schedules a literal's `lui` elsewhere even when the diff shows no addiu/ori pair; (2) the arms of `if/else` come out in source order, the else arm being the branch target, so a `bnel`/`beqz` polarity diff is fixed by swapping the arms (`swapped_arms`); (3) the return type of a callee whose result is unused (void vs int) picks `$v0`/`$v1` for the next value (`near_fix.void_returns`, both directions); (4) loads hoisted above `void *`-typed stores: type the stored fields as the pointers they are; (5) a counted loop m2c writes as a do-while with a falling counter is a `for (i = 0; i < N; i++)`; (6) a global struct accessed as `lui; addiu; lw 0x28(base)` (not `%lo(D+0x28)`) is a local `base = D_X;` assigned after the first call. Sibling calls (`j f`) do occur in 2.9 code. A `sq`/`lq` save of `$s0` (func_00588BA8) is still unexplained.
## What m2c's drafts get wrong, counted (tools/fragments.py edits)

739 near misses (m2c's draft at most 12 instructions off) later matched by a person, a model, the permuter or a rule, each compared with its matched source. The edit kinds, most frequent first, with the judge-diff atoms (`orig>mine` opcodes, `op:reg`/`op:imm`/`op:order` for one operand kind) that announce them:
- **A temporary added (149).** A field read or a call result stored in a named local before its use(s). Atoms: `daddu:reg`, `sw>daddu`, `addu:reg`, `lw>daddu`: a `move` or a register choice differs right after a load or call. m2c inlines every single-use value; the original kept it in a variable (often a `this`-like pointer or a loop bound), which changes the register and the schedule.
- **Typed struct fields instead of `M2C_FIELD` (122)** and **casts removed (117).** Atoms: `lw:both`, `lh:both`, `addiu:imm`, `ld>addiu`: two adjacent loads swapped, or a store hoisted. With `M2C_FIELD(x, s32 *, 8)` every access is an `s32` through `s8 *` arithmetic and may alias every other; a real field type lets the scheduler reorder them as the original did. m2c's `(s32)` casts on assignments and arguments are almost never in the matched sources; a cast to a narrower type adds `sll/sra` or `andi`, one to `s32` of a 64-bit value changes the `daddu`/`addu` choice.
- **An address written as a number (114).** Atoms: `addiu>ori`, `lui:imm`, `lui:reg`, `daddu>lui`, `lui>daddu`: `lui/ori` where the original has `lui/addiu %lo`. Write `&D_ADDR` (the applier and near_fix.py do it from the diff; the applier also catches the ones near_fix skipped, whose literal is not in `0x` form).
- **Tail call (54).** Atoms: `ld>j`, `jr>addiu`, `jal>ld`, `addiu>jr`, `jr>ld`: the epilogue is in the wrong place around the last call. `return f(...);` with a non-void return type.
- **Return type (8 mined, but the applier's most productive edit after addresses: 1 in 3 of its matches).** m2c types a function `void` whenever it does not see `$v0` set at the end; the original returned a callee's result (`jal` then `jr` with `$v0` untouched) or a value in `$v0` the draft computed into another register. Atoms: `daddu:reg`, `jr>…`, `nop>jr`. Declare it `M2C_UNK`/`s32` and `return` the value; the reverse (`void` for a draft returning something nobody reads) also occurs.
- **Parameter types (20) and immediates scaled by the pointee (15 applied).** `s8 *`/`void *` parameters where the original used `s32 *` or a struct pointer: `addiu -0x10` vs `-0x4` for `p - 1`, `addu` scale, `lb` vs `lw`. Atoms: `addiu:imm`, `sll>…`.
- **Parameter list (28), passed-through arguments (7).** Unused leading parameters dropped by m2c (fixed in the draft by `cpu_solve.missing_params`), or a caller's own unused parameter that a callee receives unchanged (`callee:args`): add it to the call and to the callee's prototype.
- **Temporaries removed (20), `if` arms swapped (8), loop form (4), ternaries (3), statement order (1)** are rare at this distance: the structural edits a near miss needs are almost always types, addresses and tail calls, not control flow.

Applied to the 3,708 near misses of at most 12 instructions (`fragments.py apply`, 60.6 K judge calls): 253 matched (18.3 KB, all under 512 B; 236 of them under 128 B), 1,104 more brought closer, differing instructions 23,325 -> 19,110. The first edit of a match was the return type 122 times, an address 92, an immediate rescaled by the pointee 16; the kept edits over all climbs: address 535, immediate 402, return type 376, parameter type 184, field type 103, dictionary template 71, local type 58, temporary 54, passed-through argument 49, statement order 42, callee return type 35. Yield by initial distance: 1 instruction 19%, 2: 8% (the rest are operand-order residuals no rewrite of the statement fixes), 3: 23%, 4-6: 4%, 7-12: 4%.

- **Address low halves compare as 16 bits.** In the judge's diff the original's `addiu` shows a negative immediate (-0x6570) where our `ori` shows 0x9A90 for the same address; near_fix.py compares them as 16-bit values (it missed every address with a low half >= 0x8000 before).
- **m2c with a type context (tools/types_db.py).** Without prototypes m2c guesses every callee from the registers it sees set, so a callee whose arguments the caller computes in `$a0`-`$a3` through `addiu` becomes `f()` with no arguments and the draft loses every `addiu`/`move` feeding it (`func_00396808`: 22 differing instructions, 5 with the real prototype `void func_003979E0(void **, s32)`); a context of known prototypes (`--context`) restores the calls, and the `s32` vs `void *` parameter types it carries fix the `addiu` offsets scaled by the pointee. Measured on 400 failed drafts: 12% get closer, none gets farther, over the queue 1 failed function in 150 matches outright (91 of 13,553: 80 under 128 B, 11 of 128-512 B, none larger), and 1 in 11 gets a closer draft. Field layouts of the classes (`struct X { ... }` from the instructions' load/store widths) add nothing measurable beyond the prototypes: m2c already reads the width from the instruction, and what the near misses still lack is statement structure, not field types.
- **A callee's return type in the context decides `$v0`/`$v1` and the tail.** A context prototype returning `void` for a function whose result the original kept (or the reverse) moves the next temporary between `$v0` and `$v1` and turns `return f()` back into `jal` + epilogue: the database keeps the definition's return type and, when matched callers declared more parameters than the definition reads, the longest parameter list (a matched caller had to set every register the real prototype asked for).

## Library code compiled from its public source (tools/libmatch.py, expat 1.95.7)
- **A callee defined earlier in the same file changes the caller's code.** With exceptions off
  (C, or `-fno-exceptions`) `rest_of_compilation` marks every function it has compiled
  `TREE_NOTHROW` "for the benefit of other functions later in this translation unit"; calls to
  those get a `REG_EH_REGION 0` note, and reorg's liveness scan (`resource.c:
  find_dead_or_set_registers`) stops at every call *without* it. So a call to a function defined
  above in the file lets reorg move more into delay slots (`beql` with the thread's first
  instruction in the slot, duplicated tail blocks), a call to a declared-only one does not. This
  is the "delay-slot decision" behind the parked static-init functions and the `bne`/`bnel` note
  above. Compiling one function per file loses it: an empty definition of each earlier callee
  (`__attribute__((section(".libmatch.stubtab"))) static T f(args) { }`) restores the mark, but
  the calls then bind to the stub, so such sources only serve the judge until build.py resolves
  them (weak stubs plus `func_X = ADDR;` assignments instead of `PROVIDE` would do it).
- **In C++ `throw()` on the declaration gives the same mark without a stub.** g++ 2.96
  `build_call` (cp/call.c) sets `TREE_NOTHROW` on the callee when its type is `TYPE_NOTHROW_P`, so
  `extern "C" void f(void *) throw();` makes reorg treat calls to f like calls to a function defined
  above. Symptom in game code: mine has `beql` where the original has `beqz` with an epilogue `ld`
  in the slot, or a `nop` slot before a `jal` where the original hoists the argument load
  (`lw $a0, 0($sp)`). Add `throw()` to the callees (those at lower addresses in the same unit are the
  ones the original defined above): RaceSimplePanel__virtual_05 (func_003A78B8, 512 B), 25 differ
  -> MATCH. C sources have no equivalent; compile game code as C++ when it is C++.
  C library functions are nothrow in C++ too (glibc-style headers declare them `__THROW`):
  func_00575DA0 (free) needs `throw()` even at a higher address (func_004E70F0, a library
  destructor, 35 -> 11 differ; the last 11 were the sibling call, fixed by `return f(self);`).
- **Expat was built with `-fno-strict-aliasing`**: 272 of its 323 functions match with the
  project flags, 321 with `-fno-strict-aliasing` added (loads of one type no longer move above
  stores of another: `toAscii`, `copyEntityTable`, `cdataSectionProcessor`...). The other flags
  are the project's; `size_t` is 32-bit (64-bit `size_t` loses 22 functions). The sources that
  need the flag name the `ee-gcc2.96-no-strict-aliasing` entry of project.toml on their first
  line (35 of the 236 expat sources in src/).
- **gas 2.10-ee mis-expands the table-jump macro** `lw $3,$Ln($2)` (what gcc emits for a
  `switch` jump table) into `lw $3,%hi($Ln)($3)` instead of `lui` when the macro directly follows a
  `.set noreorder` branch-likely block in a small file; the same code assembled as part of the
  whole file is right. Nine expat functions with jump tables fail the judge on that one word
  (`appendAttributeValue`, `*_scanPi`, `*_cdataSectionTok`, `*_scanEndTag`,
  `*_nameMatchesAscii`); objects with jump tables are not linked by build.py anyway (`.rodata`
  with relocations).
- Functions only reached through a pointer (`charRefNumber`, the `xmlrole.c` state functions)
  are missing from build/functions.csv and sit glued to the function before them; a source may
  define both in order (the judge compares the whole object from its first function).
- **A `beqz` whose delay slot holds the target's first instruction (not the fall-through's) wants a
  taken-prediction.** reorg's `fill_eager_delay_slots` tries the fall-through first unless
  `mostly_true_jump` says taken, and `estimate_probability` gives every `x == 0` jump 40%
  (`REG_BR_PROB` 3999 -> "not taken"). `if (__builtin_expect(p, 0)) { ... }` (p the tested value
  itself, not `p != 0`) makes the skip jump very likely and reorg steals from the target:
  mSceneViewFace__virtual_78/79 (856 B each), 9 differ -> MATCH. `__builtin_expect(p != 0, ...)`
  changes the code instead (an `sltu`). The symptom also leaves a `nop` before the next loop
  label (`.p2align 3` padding shifts by one instruction).
