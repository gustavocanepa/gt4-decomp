# ee-gcc 2.96 codegen map: residual pattern -> pass -> source lever

For drafts whose logic is right but whose registers or instruction order differ. Each entry names
the compiler pass that makes the decision (read in the gcc 2000-10-03 snapshot, ../gcc-20001003,
the era Sony's 2.96-ee-001003-1 derives from), what the decision is computed from, the C-level
levers, and the functions it was checked on with the instruments below. Rule of the Musashi
decompilation that holds here too: read the allocation ORDER before touching a register; most
register residuals went away once the source shape (which pseudos exist, their refs and lifetimes)
was right. Compiler-rule knowledge that predates this map is in knowledge/ee-gcc-2.96.md; this file
explains the mechanisms behind those rules and adds the instruments.

## Instruments

- `python tools/rtl_dumps.py ADDR|FILE [--as ADDR] [--ls]` compiles with the source's compiler
  profile plus `-da -S` (the compiler accepts every gcc 2.9x `-d` letter) and keeps one dump per
  pass in build/rtl/ADDR/: `SRC.00.rtl .01.sibling .02.jump .03.cse .04.addressof .08.gcse .09.loop
  .10.cse2 .11.cfg .13.life .14.combine .15.ce .16.regmove .17.sched .19.lreg .20.greg .21.flow2
  .22.ce2 .25.sched2 .27.jump2 .28.mach .29.dbr`, plus out.s and out.o. (Sony's build numbers the
  passes differently from the snapshot: no ssa/dce dumps, an unnamed index 18 before lreg, so
  address passes by name, not number.) The formats are the snapshot's: the greg dump prints the
  global allocator's order and dispositions, lreg the per-pseudo statistics global.c reads, sched
  and sched2 the ready lists and a clock table per block, dbr reorg's counts, life the loop tree.
- `python tools/alloc_table.py ADDR [FILE] [--insns] [--diff] [--sched1] [--sched] [--dbr]`
  prints the allocator's view: one row per pseudo in allocation order (global first, in global.c's
  order; then local-alloc's), with its role (compact RTL of its first definition), refs, live
  length, sets, calls crossed, the priority global.c computes, the hard register it got, and what
  the original holds in that register where the judge's listing differs (`$s1x5` in the `orig`
  column of the row that got `$s0`: five differing instructions have `$s1` where mine has `$s0`).
  `--insns` lists the pre-allocation insns with their REG_DEAD notes (the sched dump), `--diff`
  the judge's side-by-side listing, `--sched1/--sched` the clock tables, `--dbr` reorg's summary.
  Dumps are cached per (address, source path, mtime).

## The allocators, from the source

Order of passes that matter here: cse -> gcse (constant/copy propagation) -> loop (invariant
motion, strength reduction) -> cse2 -> flow (life analysis: REG_N_REFS, REG_LIVE_LENGTH,
REG_N_CALLS_CROSSED, REG_DEAD notes) -> combine -> regmove -> sched1 (haifa, on pseudos, with
interblock motion) -> local-alloc -> global -> reload -> flow2 -> sched2 (hard registers) ->
jump2 -> reorg (delay slots) -> final.

- **Pseudos.** Every user variable and every temporary that lives in a register is a pseudo.
  Parameters are pseudos copied from `$a0..` in the prologue. The function's return value is NOT a
  pseudo: DECL_RESULT is the hard register `$v0` itself (`(set (reg 2) ...)` at every `return`),
  which is why return-value residuals behave differently from variable residuals.
- **local-alloc.c** runs first, one basic block at a time, on pseudos that live inside one block.
  It numbers the quantities in the order they are first set while scanning the block forwards,
  sorts them by `floor(log2(refs)) * refs * size / (death - birth)` (ties: lower quantity number
  first), and gives each the first free hard register in numeric order (`$v0, $v1, $a0...`, then
  `$t`, then `$s0..` only for quantities crossing a call), skipping registers live over its range;
  quantities with a copy-suggested register (the pseudo is copied from or to a hard register, e.g.
  an argument or `$v0`) are placed first and get that register if it is free.
  Two details that decide most local residuals (local-alloc.c `block_alloc`, `combine_regs`,
  `QTY_CMP_PRI`): (a) the length in the priority is the quantity's span in half-insn units of the
  scheduled block (birth 2*i of the setting insn, death 2*i of the last use), NOT lreg's
  "across N insns" (REG_LIVE_LENGTH, which update_equiv_regs even doubles for REG_EQUIV pseudos
  such as a constant base); alloc_table.py's `pri` column now uses the span for local rows.
  (b) an insn whose output is a pseudo and one of whose register operands dies in it ties the two
  into one quantity (operand 1 first, then any other operand; arithmetic too, not only copies):
  the tied quantity sums both pseudos' refs and spans both lives, so a quotient tied to its
  dividend can out-rank everything (func_003DDEC8: end + end/step = 4 refs over 8 = 10000).
  Calls do not end a block here (-fno-exceptions): a value live across a call in straight-line
  code is still local-alloc's, taking `$s0..` in local priority order (func_004A4050).
- **global.c** then takes the pseudos that span blocks: priority `floor(log2(refs)) * refs /
  live_length * 10000 * size` (lreg's "used N times across M insns"), ties by pseudo number, printed
  as `;; N regs to allocate: ...` in the greg dump. `find_reg` tries hard registers in numeric
  order; pass 0 only among registers already in use (all call-clobbered ones count as "in use",
  plus whatever local-alloc took), never one another pseudo prefers; a pseudo crossing a call
  excludes the call-clobbered set, so the first such pseudo takes `$s0`, the next `$s1`... A hard
  register set while the pseudo is live (a call's `$v0` result, a return value, an argument
  register) is a conflict and is skipped. Copy preferences (`pref $a0`) only redirect among
  registers of the same class after a free one was found.
- **reload** gives the rest stack slots and rematerialises constants (`reg_equiv_constant`).

So two s-registers swapped = the two pseudos' priority order swapped; a value in `$v1` where the
original has `$v0` = `$v0` was in use or conflicting at that point; `$a2` for a temporary = the
`$v`/`$a0`/`$a1` registers were busy over its range.

## Residual classes

### 1. `$v0`/`$v1` swapped on a returned value or a temporary after a call
- Pass: local-alloc (same block) or global (conflicts with hard register 2).
- Mechanism: `$v0` is the first register in allocation order, so the first temporary takes it
  unless `$v0` is live there: a call that returns a value sets `(reg 2)` (a callee declared
  `void` does not), a `return v;` that was expanded as `(set (reg 2) ...)` keeps `$v0` live from
  there to the end, and a global pseudo whose copy to `$v0` is its last use prefers `$v0` but only
  gets it if no local quantity took it first.
- Levers: the callee's real return type (`void` vs `int`: knowledge/ee-gcc-2.96.md `void_returns`);
  where the result is set: `return 0;` at a site puts `(reg 2) = 0` in that block, a `result = 0;`
  variable at the top makes a pseudo that is copied at the end (extra `move`); a block-local
  compare or index temporary gets `$v0` before any global pseudo can.
- Evidence: func_00447828 (switch returning byte fields): the draft `u8 v = 0; switch {...; case 5:
  v = r->v90; break;} return v;` made `v` a global pseudo (3 refs/8, pri 3750) allocated after the
  local `sltiu` temporary, so `v` got `$v1` plus a final `move`; the form `if (index >= 6) return
  0; switch (index) { case k: return field; }` sets `$v0 = 0` in its own block right after the
  compare, the switch's duplicate range check is threaded away, reorg moves the zero into the
  `beqz` slot and the compare lands in `$v1`: MATCH (src/func_00447828.cpp). The same guard +
  `switch` of direct returns matched its siblings func_00447778 and func_004477D0 (1-based
  index: `if (index < 1 || index > 5) return 0;`), which had 12 and 1 failed diary entries.
- ee-gcc 2.9-991111 (`/* compiler: ee-gcc2.9-991111 */`) local-alloc differs: a pseudo that dies
  inside the MEM address of an insn conflicts with that insn's output (`lui $v1; lw $v0,
  lo($v1)` instead of `lui $v0; lw $v0`), so `return D_x;` straight into `$v0` puts the `%hi` in
  `$v1`, while the same load into a result pseudo (copied to `$v0` at the end) keeps `$v0`; a
  directly used operand that dies (`srl $v0, $tmp, 6`) is instead tied to the hard `$v0` by
  suggestion. Open family (0058CF88, 0058CFD8, 0058D0A8, 00585928): retail mixes both behaviours
  in one function; no C shape found yet.

### 2. s-register role swaps (callee-saved homes exchanged)
- Pass: global.c `allocno_compare`, then `find_reg` in numeric order.
- Mechanism: the pseudo with the highest `floor(log2(refs))*refs/live_length` that crosses a
  call takes `$s0`. Refs count every appearance (sets and uses), live_length the insns the value is
  live in (after sched1 reordered them). `log2` is floored: 2-3 refs weigh 1, 4-7 weigh 2, 8-15
  weigh 3, so one extra use can double a pseudo's priority exactly at 4 or 8 refs.
- Levers: give the pseudo that should be lower more uses or a shorter life (assign it later, use
  it twice), the other one fewer uses or a longer life (keep it to the end: return it, use it after
  the last call); split a variable into two pseudos (a parameter tested and then replaced becomes
  short-lived parameter + result pseudo with a ternary or a mem-initializer); merge two into one.
- Evidence: func_004B0960 (constructor with a default-name parameter): `if (n == 0) n = D_x;`
  kept `n` as one pseudo (4 refs/14 insns, pri 5714) below `this` (5/11, 9090) -> `this` in `$s0`;
  the original has name `$s0`, this `$s1`, c `$s2`, b `$s3`. `: name(n ? n : D_x), mAC(b) { mC =
  c; }` makes the parameter short-lived and a result pseudo that out-ranks `this`: MATCH
  (src/func_004B0960.cpp). The probe build/rtl/probe0.cpp shows the order directly: greg prints
  `5 regs to allocate: 86 97 85 84 87` = refs/length 7/8, 7/9, 4/13, 2/4, 6/24 (84 and 87 tie at
  5000 and sort by number).

### 3. Float register order (`$f1`/`$f2` swapped, `$f0`/`$f3` swapped)
- Pass: local-alloc (FP temporaries rarely cross blocks), with sched1 deciding births and deaths.
- Mechanism: same priority, ties by first-set order in the scheduled block; the first free FP
  register in numeric order over the quantity's range. sched1's order of the loads is set by the
  critical path (a value feeding two operations ranks above one feeding one), register weight,
  dependents, then source order (`rank_for_schedule`), so the births are not simply source order.
- Levers: change which value has the longer path or more consumers (reassociate, compute a
  product into a named local first, read a field into a local before the expression); change a
  value's life (a load used sooner); split or merge pseudos (two reads of a field instead of one
  CSE'd pseudo need something between them that CSE cannot see through).
- Lever that worked (twice): the pre-scheduling REG_DEAD position. sched1's tie-break after the
  critical path is INSN_REG_WEIGHT, computed from the notes of the source-order insns: the load
  that is the last use of a pointer (`a`'s REG_DEAD) weighs 0 and is issued first, so the field
  read LAST in source order is loaded FIRST and lives longest. func_00423EE0: `a.x*b.x + b.y*a.y`
  loads a.y first (a.y 2/8 -> f3); `f32 ay = a->f.y;` before `d = a->f.x*b->f.x + ay*b->f.y`
  moves a's death to the a.x load, a.y is loaded late and its tied quantity takes f0: MATCH (6
  diary entries of operand orders had failed). func_0048D000: a generated sweep of local
  declarations (`vx`, `vy`, `p1 = m0*vx`, `m6`; 119 shapes judged with `match.py check-many`)
  found `f32 vx = v->x(); f32 p1 = m->m[0]*vx; f32 vy = v->y(); f32 p2 = m->m[3]*vy;`: MATCH.
  When operand orders are exhausted, sweep statement/local shapes mechanically.
- Evidence (explained, not matched): func_003DDEC8 `end` (2 refs/3, 6666) is allocated before
  `step` (3/5, 6000) because `step` feeds both `div.s` and therefore is always loaded first by
  sched1 (depend-count tie-break): a single `step` pseudo cannot come first; five rewrites of the
  arithmetic stay at 7 differ. func_0048D000: `v.y` and `m[6]` tie at 2500, `v.y` is set first and
  takes `$f2`; the original has `m[6]` first. func_00423EE0: `b.y` (2/4) before `a.y` (2/8); the
  original has `a.y` in `$f0`. Each needs a shape that changes the lengths, not the operand order
  (the diaries say every operand order was tried).

### 4. One pseudo where the original had two (or the reverse): an extra or missing `move`
- Pass: cse (merges equal loads into one pseudo), loop (hoists an invariant load into a NEW
  pseudo, leaving the guard test on the first load), regmove, combine.
- Mechanism: `for (i = 0; i < t->count; i++)` with no store in the loop: the exit-test copy at the
  top uses the first `lhu`; loop.c moves the loop's own load out and gives it a fresh pseudo, which
  is the `daddu $a2, $v0` the original shows. A `count = t->count` local is one pseudo for both.
- Levers: write the bound inline vs as a local; read a field again after a call instead of
  caching; a second user variable (`next = n->next; n = next`) is a second pseudo.
- Evidence: func_004298E0, 4 differ -> MATCH (src/func_004298E0.cpp).
- CSE jump equivalences pick the substitute register: after `if (x != K) return;` cse records
  x == K on the fall-through, and later uses of K (or x) become the class's canonical register,
  which cse.c `make_regs_eqv` makes the one living longest beyond the current block.
  func_00612C70: `tag0 != -1` then `tag1 == -1` used tag0's register in the final xor (ours) where
  retail uses the -1 register; `int none = -1;` set one basic block EARLIER (before the previous
  range test) keeps `none` a pseudo across blocks, it becomes canonical and tag0 stays
  block-local: MATCH. (The same set in the compare's own block is folded back to the constant.)
- Refs from a "useless" statement: func_00579438 (Mersenne Twister init_genrand, 5 differ, v0/v1
  swapped in the loop tail) matched once the reference source's no-op `mt[mti] &= 0xffffffffUL;`
  was restored: the extra reload and store change the loop block's quantities. Library code:
  write it as the reference source does, no-ops included.

### 5. A load stuck below a store (or hoisted above one)
- Pass: sched1/sched2 dependence analysis (`sched_analyze_2` -> `true_dependence` ->
  alias.c `alias_sets_conflict_p`), with -fstrict-aliasing on (the game's flags).
- Mechanism: a load may move above a store only when their alias sets cannot conflict: `int`
  versus `float` versus distinct struct types, `const` data; a `char *`/`void *` access or an
  `M2C_FIELD` byte-arithmetic access aliases everything. The expat library was built with
  -fno-strict-aliasing, where nothing moves.
- Levers: declare the real types of the fields and pointers; `const` tables; the
  `ee-gcc2.96-no-strict-aliasing` profile for library code (knowledge/ee-gcc-2.96.md, Statement
  order section, validated by many matches).
- A register residual can be this class: func_0055B478 had `&self->s` in `$t1` instead of `$a1`
  because sched1 hoisted the argument load `$a1 = self->m28` above the stream store (`*s->p++`),
  keeping `$a1` busy. Under no-strict-aliasing nothing crosses the store, so the source order
  must give retail's order: call arguments are expanded right to left (the `*p++` argument
  before `self->m28`), and `s32 mode = self->m34 & 0xF;` before the call puts that load above
  the store: MATCH with the nsa profile.

### 6. Store order runs and other equal-priority reorderings
- Pass: sched1 `rank_for_schedule`: priority (critical path), then INSN_REG_WEIGHT before reload
  (registers born minus registers dying in the insn: a store where its value register dies weighs
  -1 and goes first), then relation to the last scheduled insn (independent insns first, then
  anti-dependent, then data-dependent), then the number of dependents, then LUID (source order).
  sched2 uses the same without the weight.
- Levers: which store is the last use of its register (move that statement), hoisted constants
  (`lui/ori` values are ready first), a temporary that makes a value die earlier. The rotated
  zero-store runs, "last use goes first", and the division-order rules in knowledge/ee-gcc-2.96.md
  are instances.
- Evidence: func_0032B798's two argument moves before a `jal` are equal in every criterion down
  to LUID: the original emitted `a2 = value` before `a1 = fmt`; no statement reordering changes
  emission order inside one call, so the residual is in how the value reached its register
  (open).

### 7. Delay-slot filler choices and branch-likely
- Pass: reorg.c. `fill_simple_delay_slots` first (an insn from before the branch, or after it for
  non-jumps), then `fill_eager_delay_slots` for conditional jumps: it takes from the target thread
  when `mostly_true_jump` says taken (REG_BR_PROB >= 90% "very likely", >= 50% likely, loop
  back-edges and tests of loops very likely, a branch out of a loop unlikely), else from the
  fall-through; an insn taken from one thread that is not safe on the other is annulled = the
  `...l` branch-likely forms. The liveness scan (resource.c) stops at calls without a nothrow mark.
- Levers: `__builtin_expect` on the tested value (knowledge/ee-gcc-2.96.md, mSceneViewFace), the
  polarity of the test (which arm is the fall-through), `throw()`/earlier definition of callees,
  a return-value set in its own block (class 1) that reorg can move into a slot.
- Evidence: func_00447828 (the `$v0 = 0` of the guard's return block in the `beqz` slot).

### 8. Interblock (speculative) motion: argument moves hoisted above a conditional branch
- Pass: sched1 with interblock scheduling (`-fsched-interblock`, default): cheap safe insns of a
  likely successor block move up into the branch block ("Procedure interblock/speculative motions"
  in the sched dump).
- Evidence (open): func_002D0AD8's `daddu $a0, $s0` sits above the `bne` and `a1 = 0` in its slot
  in the original, with the loaded field in `$a2`; `__builtin_expect` on either polarity, a third
  argument, and a local for the field do not reproduce it (5-16 differ). The branch probabilities
  come from the `bp` pass (predict.c) and the dump `.12.bp` is the place to compare.
- When the original did NOT hoist (args set after the branch, the tested field in a low register):
  haifa-sched.c only schedules a loop-free function as one interblock region while it has at most
  `MAX_RGN_BLOCKS` = 10 basic blocks (and 100 insn luids); above that every block is its own
  region and no motion happens. So the source had one block more: count `Start of basic block` in
  the `.16.regmove` dump (10 = hoists, 11 = does not). func_002D09D8 (mScrollArrow::onButtonPress):
  `if (window) { if/else of four tail calls } return 0;` matches, `if (!window) return 0;` first has
  10 blocks and hoists. A function that falls off the end gets an extra block too (`clobber v0`).
  Other ways out: `is_cfg_nonregular` (a non-jump insn with a REG_LABEL note, computed gotos, EH).

### 8c. `beql`/`bnel` (annulled) where the original has a plain branch, or the reverse
- Pass: dbr (reorg.c `fill_slots_from_thread`), with liveness from resource.c
  `mark_target_live_regs`. An insn taken from the branch target goes in without annulling only
  when it sets nothing live on the fallthrough path. That liveness is approximate: it starts at the
  basic block that `find_basic_block` finds by scanning back to the previous BARRIER (none: the
  function start, block 0) and walks forward to the fallthrough insn, and a REG_DEAD note only
  takes effect at the next CODE_LABEL. So a register that died in the branch (`$v0` compared and
  dead) still counts as live when no label or barrier lies between, and the slot is annulled.
- Lever: the layout before the fallthrough. Separate statements with their own early return
  (`if (a) return 0; if (f()) return 0;`) put a jump + BARRIER before the next test and give plain
  branches; one `a || f()` condition gives the annulled form (func_00564990: both forms seen, the
  registers of the separate form still differ there).

### 8b. Functions that behave as if sched1 never ran (experimental profile ee-gcc2.96-nosched1)
- Symptom: alloc_table shows a pseudo losing its suggested argument register because sched1
  hoisted the argument copy (`$a2 = r95`) above the pseudo's other uses, or loads/param copies in an
  order no source shape reproduces under the default flags. With `-fno-schedule-insns` the copy
  stays at the call, becomes the pseudo's last use, and the pseudo takes the argument register.
- Evidence: func_00484A90 (constructor passing `&l80`, 13 differ after a permutation search)
  matched with `ee-gcc2.96-nsa-nosched1` plus the list-init store order prev, count, next (source
  order is output order without sched1). func_004A2930 (22 -> 0) with `ee-gcc2.96-nosched1`. A
  sweep of every unmatched cpu_solve draft with <= 14 differ under nosched1 matched 12 raw m2c
  drafts (their statement order is retail's instruction order); those may be a store-order
  shortcut rather than the real flags. Improved but open: 004796B8 (19 -> 2), 003EC2B8 (7 -> 4,
  fixes the s0/s1 swap), 00447DD0 (5 -> 3), 004A2C58 (17 -> 4).
- How to use: after the default profile plateaus on scheduling/allocation order, judge the draft
  under both nosched1 profiles (`match.py check-many`); without sched1, write statements in the
  original's instruction order.

### 9. Spill and frame slot order
- Pass: reload1.c `alter_reg` assigns stack slots to spilled pseudos in increasing pseudo number
  (creation order); addressable locals get their slots at expansion (declaration order); the MIPS
  frame puts locals below the register saves (`$s0` lowest, `$ra` highest). Read from the source,
  no reproducer run yet: when a frame residual appears, dump the greg pass (reload's
  `Spilling for insn` lines) and compare slot numbers with pseudo numbers before trusting this.

### 10. Constant rematerialised per use vs held in a callee-saved register
- Pass: gcse constant propagation (`cprop_insn`) folds a pseudo set once from a constant into the
  memory operands that stay valid (MIPS accepts constant addresses: the assembler expands them to
  `lui $at; sw lo($at)`), so the register disappears and each use gets its own `lui`; what cprop
  cannot fold stays a pseudo, and if that pseudo crosses a call it is kept in an s-register;
  local-alloc.c `update_equiv_regs` lowers the priority of once-set constant pseudos and reload
  rematerialises those that got no register.
- Levers: the diary shows `-fno-gcse` keeps the scratchpad base (0x70002000) in an s-register
  (func_004A4050), so the original's base was something cprop could not substitute: an address
  that is not a literal to the compiler (loaded from a global, a parameter, computed), or uses
  cprop cannot rewrite into a valid insn (a `sq`/`lq`, a 64-bit `sd` with an out-of-range sum).
  Open family (0x4A0000 scratchpad functions): compare the `.08.gcse` dump of the draft, which
  prints each constant propagation, against the retail register use.
- Checked on func_004A2D20 (base passed to two calls): it is CSE pass 1 (`.03.cse`), not gcse,
  that turns `$a0 = base` into `$a0 = 0x70002000`: mips.h CONST_COSTS returns 0 for every
  CONST_INT (non-MIPS16), a REG costs 0 too, and cse takes the constant on a tie. So `-fno-gcse`
  keeps the base only where it sits in MEM addresses (func_004A4050, whose remaining residual is
  the class-2 order of base vs. the parameter in local-alloc: the parameter needs >= 8 refs to
  out-rank the 8-ref base over the same span); a base passed as an argument must have been
  opaque to cse in retail (another extended basic block with -fno-gcse, or not a literal).

## Worked examples (attempts diary "only the register choice differs")

| function | class | table said | lever | result |
|---|---|---|---|---|
| func_004298E0 | 4 | `count` one pseudo (`zext lhu`, 4 refs) in `$a2` where the original tests `$v0` then copies to `$a2` | `i < t->count` inline, no local | MATCH |
| func_00447828 | 1, 7 | global `v` (pri 3750) after local `sltiu` temp -> `$v1` + move | guard `if (index >= 6) return 0;` + `return field` cases | MATCH |
| func_004B0960 | 2 | `n` 5714 < `this` 9090 -> this in `$s0` | ternary in the mem-initializer list | MATCH |
| func_003DDEC8 | 3 | `end` 6666 before `step` 6000 (sched1 loads step first: two consumers) | 5 arithmetic shapes | 7 differ, open |
| func_0048D000 | 3 | `v.y`/`m[6]` tie at 2500, first-set order | (all operand orders already tried) | 4 differ, open |
| func_00423EE0 | 3 | `b.y` 5000 before `a.y` 2500 | needs a.y later / b.y earlier | 2 differ, open |
| func_0032B798 | 6 | two arg moves equal down to LUID | none by statement order | 2 differ, open |
| func_002D0AD8 | 8 | original hoists `a0 = self` above the `bne`, field in `$a2` | `__builtin_expect`, 3rd arg, local | 5-16 differ, open |
| func_002D09D8 | 8 | mine hoists `a0`/`a1` above the `bne`, original does not | 11 basic blocks (`if (w) {...} return 0;`) | MATCH |
| func_00359A38 | - | the recorded draft is a different function (32/32 differ): no register problem to read | | skip |
| build/rtl/probe0.cpp | 2 | demo: greg order 86 97 85 84 87 = `$s0..$s3` + `$a0` | | - |
| func_00423EE0 | 3/6 | a.y loaded first (pointer a dies there), 2500 vs 5000 | `f32 ay = a->f.y;` first | MATCH |
| func_0048D000 | 3 | v.y / m[6] tie, v.y set first | local-declaration sweep (check-many) | MATCH |
| func_00612C70 | 4 | final xor uses tag0's register (cse canonical) | `int none = -1;` one block earlier | MATCH |
| func_00447778, func_004477D0 | 1/7 | result pseudo loses `$v0` to the `sltiu` temp | 00447828's guard + `switch` returns | MATCH |
| func_0055B478 | 5 | `$a1` busy: m28 load hoisted above the `*p++` store | nsa + `mode` local before the call | MATCH |
| func_00579438 | 4 | loop-tail v0/v1 | reference MT19937 source incl. its no-op `&=` | MATCH |
| func_004A4050 | 2 (local) | base 8 refs vs parameter 6 refs over one span | 8-ref parameter fixes the s-regs, not the shape | 10 differ, open |
| func_003DDEC8 | 3 (local) | end tied with its quotient (10000) > step (3750) | step needs a 4th ref | 7 differ, open |
| func_004A2D20 | 10 | cse folds the argument copy to the constant | (opaque base unknown) | open |
| func_00484A90 | 8b | sched1 hoists the `$a2 = &l80` copy, &l80 loses `$a2` | ee-gcc2.96-nsa-nosched1 + store order | MATCH |
| func_004A2930 | 8b | constant 0xFF loses `$v0` | ee-gcc2.96-nosched1 + `mask = 0; if (r) mask = 0xFF;` | MATCH |
| func_005528A8 | 1 | result variable must be its own pseudo (a0), not the call result | `if (e != 0) ret = e; else { ret = 0; ... }` | MATCH |

## What a cheaper agent should do with this

1. For a near miss whose diff is registers only: `python tools/alloc_table.py ADDR DRAFT --diff`.
   Read the `orig` column: it names the pseudo whose register the original has elsewhere.
2. If that pseudo is `global#k` and the swap is between s-registers: compare its `pri` with the
   pseudo that holds the original's register; change refs or live length of one of them in the
   source (class 2 levers) until the order flips; re-run the table, then the judge.
3. If it is `local` and the swap is `$v0`/`$v1`/`$a*`: look for the hard register that was busy
   (`--insns`: a `$v0 = ...` set, a call result, an argument copy with `sugg`) and move the
   statement that sets it (class 1), or make the temporary block-local / global as the original.
4. If it is FP (`$f*`): print `--sched1`, read the order of the loads in the clock table, and
   change which value has more consumers or a shorter life (class 3); operand-order permutations
   alone do not change priorities.
5. If no register differs but instructions are reordered: `--sched` shows the ready lists; equal
   priorities fall to register weight (last use first) and source order (class 6); loads below
   stores are alias sets (class 5); slot contents are reorg (class 7).
6. Log the table's reading in the diary (`attempts.py log ... --hypothesis "alloc_table: ..."`)
   even when the function stays open, so the next agent starts from the mechanism.
7. When the mechanism says "this value must be loaded later / live shorter" but no single edit
   does it, generate the shapes (local declarations, statement orders, operand orders, inline
   helpers) with a small script into one directory and judge them in one call:
   `python tools/match.py check-many LIST --jobs 2` (LIST = lines `ADDR FILE`), 100+ shapes a
   minute. func_0048D000 matched this way; the sweeps for 00425770, 00397FF8, 00415608 and
   004A4050 are recorded in their diaries.
8. ee-gcc 2.9-991111 sources: rtl_dumps.py/alloc_table.py read its unnumbered dumps too
   (SRC.lreg, SRC.greg ...); when several drafts share build/rtl/ADDR/, the newest source's dumps
   are used.

## Type-shape residuals: what the "same length, 1-6 instructions off" pool really is (2026-10-11)

The whole pool of cpu_solve near misses recorded as `same_length` with 1-6 differing instructions
was judged again (tools/nearfix_types.py, 3 jobs) and every genuine diff read. Three findings.

**1. Most of the pool is not a near miss.** Of the 1,162 records at 1-3 off, 1,100 belong to
functions already matched; of the 181 unmatched drafts at 1-6 off, 108 (60%) are *truncated*:
m2c lost part of the body (an `if (...) {}` with nothing inside, a stub) and the draft returns
early, so the judge trims the original to the draft's length and prints `(original N, mine N)`
with N the trimmed length. `same_length` in results.jsonl is therefore only meaningful when N is
the inventory's span (`match.function_span(addr) // 4`, padding aside); the tool skips those
drafts. At <= 12 off the same holds (436 of 966 unmatched drafts). The other previous robots'
low yield (regsearch: 2 of 1,162) was mostly this: there was nothing to permute.

**2. The genuine residuals fall into type-level classes, not register recipes.** The 82 genuine
drafts at <= 6 off (a draft can be in several classes):

| class | drafts | what the diff shows | lever |
|---|---|---|---|
| same instructions, other order (stores, a store vs the epilogue loads or an argument copy) | 17 | class 5/6 above | store statement order, `nsa` profile, open |
| `$v0`/`$v1` choice on a block-local temporary | 16 | class 1 above | `void` callee when the result is dropped (near_fix.void_returns); the rest open |
| literal that is a global's address (`lui/ori` vs `lui/addiu`, a store through `lui $at`) | 12 | %lo relocation on one side only | near_fix.addresses / derefs re-applied (the drafts were remade after near_fix ran) |
| other register choice | 11 | operand order, tied quantities | regsearch recipes, open |
| access width (`sw` where the draft has `sb`, `lw` vs `lhu`, `ld` vs `lwu`) | 10 | same offset and base, other opcode | width + alias set 0, below |
| float (constant place, `$f` order, `cvt.w.s` where the original reads an int) | 8 | class 3 above, or a field typed f32 by another function | open |
| branch kind (`beqz` vs `beql`, `bnel` target, a return value set in a block) | 7 | class 7 above | open |
| virtual call through the old-ABI vtable entry | 6 (+3 with the delta typed s32) | `addiu $v1, $v1, 0x68; lh 0($v1); lw 4($v1)` vs `lh 0x68($v1); lw 0x6C($v1)` | `VEntry *e_` statement expression, below |
| parameter declared narrower than the original's | 1 | `andi $s3, $a1, 0xFFFF` where the original copies `$a1` | the parameter as s32 |

**3. The two new mechanisms, proven with the judge.**

- *Access width and alias set 0.* m2c types a `sw` of 0 as `s8` (func_00391930, 0033CE70,
  003E09A8, 003BFA28...). Widening the type to `s32` makes the diff worse (1 -> 4-9): the
  following loads (`lw $a0, 0x20($a1)`, pointers and ints alike) move above the store, and cse
  stops reloading the pointer after it, while the original keeps them below. Only an access of
  alias set 0 keeps every load below the store, and in the game's C++ that is what a member of
  class type gets: gcc 2.96 c-common.c `lang_get_alias_set` returns 0 for every AGGREGATE_TYPE
  under `clk_cplusplus` ("It's not yet safe to use alias sets for classes in C++ because the
  TYPE_FIELDs list for a class doesn't mention base classes"), while an int or pointer member
  gets its own set. So a 4-byte handle/wrapper member stored by value is a word access that
  aliases everything. In a C source the same thing is an access through a union member (the
  `UNION_TYPE` rule of the same function): `M2C_FIELD(p, union AliasAny *, 0x10).w = v` with
  `union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; }`. MATCH on
  func_00391930, 0033CE70, 003E09A8, 00336338, 0044E3B0 (two fields); the nsa profile matched
  only 2 of the first 3, so the union is the mechanism, not a flag. Lesson for drafts: when the
  judge shows a wider store at the right offset and the loads after it stay put in the original,
  it is a class-typed member, not a char.
- *Virtual call entries.* m2c writes `M2C_FIELD((vptr + OFF), T (**)(...), 4)(obj +
  M2C_FIELD(vptr, s16 *, OFF), args)`: the entry address is folded into two offsets, the original
  computes it (`addiu`) and loads `delta` and `fn` from it, as the matched sources' `VEntry *e_ =
  (VEntry *)((char *)vptr + OFF); ((T (*)(...))e_->fn)((char *)obj + e_->delta, args)` does
  (tools/dtors.py, src/ VCALL macro). MATCH on func_00343270, 003DDA58, 001BF058 (with the
  dropped result's type `void`, which frees `$v0` for the entry: `jalr $v1` with the vptr in
  `$v0`, the reverse when the result is used), 002797F8, 00336D90 (with `nosib`). Open residual
  of the same shape (func_002F1098, 00195270, alloc_table): the object pseudo has `sugg $a2` but
  sched1 hoists the copy `$a2 = r89` above the `$a0 = r89 + delta` add, so r89 lives past the
  copy and gets `$a3` plus a `daddu`; in retail the object is loaded straight into its argument
  register and the vptr fetch and the adjustment read it. Neither a local for the adjusted
  `this`, nor the object temporary inlined (so cse would substitute the argument register), nor
  `void` changes it; the ordering of the copy against the add is the open question (the RTL
  before sched1 is the same in both; class 6 tie-breaks).

Instrument note: the judge's count is positional, so one inserted instruction makes every row
after it "differ" (26 of 32 for one `daddu`). nearfix_types ranks candidates by an alignment
distance (instructions outside the longest common alignment of the two columns) and only the
judge's MATCH counts.

Yield over the pool (<= 12 off, 530 genuine drafts): 37 matched, 21 by the type rules alone
(width 5, vcall 4, literal 8, void callee 4, this passed through 3, parameter 4; several
combined) and 16 only together with the compiler profile the diff points at (near_fix.profiles_for:
`nosib` 10, `no-strict-aliasing` 5, 2.9 SDK 1); 155 drafts got closer and wait in
build/auto/nearfix_types/work/ADDR_best.c for the register and order levers of the classes above.

## Short drafts: why 3.3 K kept m2c drafts were shorter than their function (2026-10-11)

The "truncated" pool (the kept draft's judged width below the inventory's span: GT4 3,316 of
6,402 unmatched differing drafts, 400 at <= 12 off; TT 3,154 of 7,736, 453 at <= 12 off; GT3 0,
see below) was traced on a sample of 33 by re-running m2c and reading its output. Causes, with
the share of the sample and what was changed (tools/cpu_solve.py, tools/match.py,
tools/patches/m2c-passthrough-args.patch; the same files copied to ../TT and ../GT3):

1. **The pipeline kept the shorter draft (12 of 33).** The judge trims the original to the
   draft's length when the draft returns where the original goes on (a glued function may
   follow), so `--void` variants, context drafts whose callee prototype dropped an argument or
   the result, and any draft that lost code scored `2 of 2` against a complete `14 of 14` and
   were kept (results.jsonl `how`: 2,770 `kept`, 449 `m2c+types`, 65 `m2c --void+types`).
   Fix: `differs_by(res, addr)` adds twice the instructions the judge left out; rows carry
   `full`. Nothing was lost by m2c in these: a fresh plain draft was complete.
2. **Complete draft, shorter code (8 of 33).** The C has everything; gcc's shape is shorter
   (a tail call `j` for `jal; ld; jr`, a folded vtable entry, one literal shape). These are
   ordinary near misses of a different length, not truncation; nearfix_types sees them now.
3. **`cvt.w.s` exported as `.word` (3 of 33, 736 sites in GT4).** rabbitizer prints the valid
   instruction as `.word X # cvt.w.s $f1, $f0`; m2c skips a `.word` silently, so the draft kept
   the register's old value (`func(..., 0x3F000000)` for `(s32)(x + 0.5f)`). Fix: `mnemonic_text`
   in match.gnu_asm (the `vclipw` forms too).
4. **An untouched argument register before a set one (2 of 33).** m2c skipped `$a0` as "not an
   argument" and shifted the later ones down: `f(0x800, 0x2000, 0x20)` for a call that sets
   `$a3, $a4, $a5` and passes `$a0-$a2` through. Fix: the EE ABI patch (integer registers only;
   o32 untouched).
5. **Stack locals as separate scalars (1,137 of the 3,316 drafts).** When the frame's address
   escapes (`sp` passed to a callee: an object constructed on the stack, an array), m2c's
   `s32 sp10; ... sp10 = v; f(sp)` stores are dead and gcc drops them: the draft lost the code
   (func_0019B3A0: 67 of 110 instructions). Fix: `stack_frame` declares one
   `struct StackFrame_ADDR { s8 pad0[4]; s32 sp4; ... } sp_` over the local area (below the
   callee-saved registers, `frame_extent`), `sp` -> `(s8 *)&sp_`, `spNN` -> `sp_.spNN`
   (func_0019B3A0: 106 of 110). m2c's own `--stack-structs` round trip fails on its overlapping
   `M2C_UNK` fields, so the struct is built from the draft's declarations.
6. **Variadic prologue (11 of 3,316).** `sd $a2..$a7; swc1 $f12..$f19` to the frame are
   `va_start`; m2c writes dead stores. Open (write `...` and a `va_list`).

Result of the redraft (`cpu_solve.py --only ... --context types`, 3 jobs, ~1.6 s per
function): GT4 862 of 3,316 drafts now complete (142 at <= 12 off), 893 kept their old draft
(it was the best under the new score too), 15 judge MATCHes from the redraft and 12 more from
nearfix_types over the 142 (27, build/auto/m2cfix/matched.txt); TT 926 complete (153 at
<= 12 off), 20 + 14 matches (34). The drafts still short are of kind 2 (complete C, shorter
code) or 5 with the frame's shape still wrong, or variadic.

GT3 has no truncated drafts because almost no GT3 draft compiles: the latest verdict of 4,981
functions is `does not compile` (ctx types), 704 of them from `saved_reg_gp` undeclared (GT3
addresses its globals through `$gp`: `M2C_FIELD(saved_reg_gp, s32 *, -0x6EC8)`), the rest other
context errors. A GT3 draft pipeline needs a `$gp` base rule first (open).

### 11. Delay-slot fill and interblock motion defeated by a loop head
- Symptom: retail leaves `nop` (or its own instruction) in a branch delay slot and keeps
  the following instruction after the branch; gcc instead moves the first instruction of
  the fall-through block into the slot (a `lui` address load, a `-1` return constant, an
  `addiu`). The branch offset is then one short and every later row shifts.
- Mechanism: sched2 / `fill_delay_slots` only moves an instruction into the slot when its
  block has no other incoming edge. A block that is also a loop head has an incoming
  back-edge, so its first instruction cannot be moved.
- Lever: make the affected block the head of a loop (`do { ... } while (0);`). Only legal
  where the block is a self-contained statement group, and it does not change semantics.
- Evidence: func_00547428 (0x40-byte copy from `D_0064C380`): five earlier tiers stalled at
  35-37/40 on exactly this (register homes plus a filled `beqz` slot); every plain source
  shape tried here (early return, if/else, result variable, `?:`, src pointer local,
  nsa-g/nsa/default) also stalled. Wrapping the copy in a loop head under an inverted guard
  fixed the delay slot and the allocation at once (base `$v0`, pointer `$a3`, temps
  `$v1/$a1/$a2`): MATCH, 40 instructions. func_0057FBEC (two copied blocks) improved
  67/70 -> 14/70 because the same lever stopped the second symbol's `lui` being hoisted
  into slot 1; its residue is a `$v0`/`$v1` allocator swap the lever does not reach.
- Counter-example: func_004B2CF8 regressed (5/14 -> 12/13), and on func_004AB318 the loop
  head fixed the slot content (`addiu $a3,$a3,8`) but flipped a plain `beqz` into `beql`
  (section 8c). Apply only when retail's branch is already the plain form.
- Style: `AGENTS.md` discourages `do { } while (0)` written only to move an instruction.
  Treat this as a last resort for a block that is genuinely a statement group, and say in
  the source comment why the loop head is there.

### 12. A pointer hoisted above the first call: interblock motion, not a local at the top
- Symptom: retail computes `sub = self + N` in the prologue zone (own saved register, frame
  one slot larger) although the first use is many calls later, behind a branch. A draft with
  `Sub *sub = &self->sub;` at the top issues the add after the first call, tied to `self`'s
  register (frame one slot smaller, every later row shifted).
- Mechanism: a function without loops is ONE haifa region (`rgn 0 nr_blocks N` in the
  `-fsched-verbose=5` dump). An add that lives in a later, control-equivalent block has no
  dependence on the calls before it (its source is still call-crossing at flow time), so
  sched1 moves it up into block 0 and issues it at t=1. The same add written in block 0 has
  no in-block consumer, priority 1, and is issued after the call.
- Lever: do not declare the local. Write `&self->sub` at the late use sites; cse joins them
  into one pseudo in that block and the scheduler hoists it.
- Evidence: func_001737B8 (mMCFileActor vslot 54), eight failed entries since 10/13
  (101/103, or 1/105 with the item read through the sub-object): MATCH with
  `func_00105728(&self->texture)` / `func_001055C0(&self->texture)` and no local.
- Dead ends measured there: `do { } while (0)` around the first call is a sched1 barrier
  that also fixes the frame but stays in sched2 and reorders the prologue saves (9 off); a
  copy `me = self` kept alive by a later dead store makes `self` non-call-crossing, which
  anchors the add before the call (`sched_before_next_call`), but the copy has priority +1
  and is issued first, so `self` stays in `$a0` (2 off).

### 13. `sub.s` into the dying home, then `mov.s` to the argument register
- Symptom: retail computes an argument as `sub.s $f20,$f20,$f21` and copies it to `$f19`;
  the draft combines the subtraction straight into the argument register.
- Mechanism: combine never merges across a call. The subtraction was written before an
  intervening call, in place on a user variable (two sets, so the pseudo crosses the call
  and sched1 is free to sink the insn below it).
- Lever: `height -= inset;` before the call whose result is another argument, then pass
  `height`. func_002182E0: 38 -> 14 rows (rest: allocation order of two float homes and
  the issue order of the argument loads).

### 14. Argument loads issued `a1, a2, a0`
- sched2 ties the loads of one call on priority, class and dependents; INSN_LUID decides.
  A load that comes first in retail was a fresh pseudo dying at the load: it gets the
  argument register by copy preference and its copy sits before the glued group. A
  function-scope variable assigned in both arms (`count = space;` / `count = length;`)
  does this for the arm where cse keeps the copy (func_00227BE0, a2 proven, a1 open).

### 15. Live length doubled per constant set; a redundant set that survives to sched2 (2026-11-16)
- Pass 1, local-alloc.c `update_equiv_regs` (read in GCC_COPY/gcc-20001003/gcc/local-alloc.c):
  scanning insns in stream order, every set of a multi-set pseudo whose REG_EQUAL note is a
  constant does `REG_LIVE_LENGTH (regno) *= 2`, until the first set without a constant note calls
  `no_equiv`. So lreg's "across N insns" is the real live count x1, x2, x4... (measured on
  func_00465078: ratios 1.03 / 2.05 / 4.10 against an exact per-insn count of the sched dump).
  This decides global.c priority: `steer` (34 refs) with one `steer = 0` before its first
  non-constant set is x2 (pri 2168, outranks curveLimit, f25/f26 swapped); with two constant
  sets it is x4 (pri ~1115) and lands between curveLimit and lock as retail. A CSE'd self-copy
  `(set r r)` with a REG_EQUAL constant counts too; reload deletes it later.
- Pass 2, ifcvt.c `find_if_case_1`: `if (!c) x = K; else { ... }` with a small THEN block hoists
  `x = K` above the branch and leaves the ELSE block's label with 0 uses. cselib (reload_cse)
  clears its table at any CODE_LABEL, so a second `x = K` after that label survives reload_cse;
  the jump pass after reload deletes the unused label; sched2 then still sees the second set
  (an insn that reads x is held after it); jump2 `delete_noop_moves` finally deletes it because
  `find_equiv_reg` scans back across jumps (it stops only at labels) to the first `x = K`.
  Net effect: an invisible insn that orders sched2. Without the 0-use label, reload_cse deletes
  the second set before sched2 and the reader moves up one slot.
- Evidence: func_00465078 (6.8 KB AI driver controller): `if (sign == 0) { steer = 0.0f; } else
  if (dir == 1) { steer = 0.0f; ...setup... } else {...}` fixed both the steer/curveLimit swap
  and the lock copy `mov.s $f27,$f26` order at once: MATCH. The same source as `if (sign) {...}
  else steer = 0.0f;` (case 2 conversion, no 0-use label) stays 1 off.
- Diagnosis: compare lreg's live length with the per-insn count (build/work/465078/lv/live.py
  SCHED LREG REG) to see the multiplier; `grep "\[0 uses\]"` in the .15.ce/.20.greg dumps for
  labels ifcvt left behind.

### 16. Equal-span FP quantities: an inline reference layer adds the stage retail had (2026-11-18)
- Symptom: three values loaded, negated and stored in one block (a conjugate quaternion) take
  `$f0,$f1,$f2` in load order in the draft, but retail gives `$f0` to the last-loaded one and
  still loads them in the same order.
- Mechanism (local-alloc 2*refs/span, sched1 2-issue): when every cycle of the block is full
  (here 3 loads + 3 negs + 4 stores + 6 ALU address/argument insns), each load+neg+store
  quantity spans the same number of insns and the quantity order (first set) decides. Retail
  had one extra 1-cycle stage between each `neg` and its store, which bunches the stores at the
  end: spans 15/15/14, so the last component wins `$f0`.
- Lever: write the result through a setter with a reference parameter instead of field stores:
  `static inline void setQ(Quat &r, f32 x, f32 y, f32 z, f32 w) { r.x = x; ... }` and
  `makeQuat(...) { Quat r; setQ(r, x, y, z, w); return r; }`. Field stores, store-order
  permutations, `operator[]` (char*) stores, const/ref parameters and 576 load-order x store-order
  combinations did not do it.
- Method that found it: `build/work/41d140/simL.py`, a small model of haifa's list scheduler for
  one block (units memory/alu x2/flop, issue rate 2, rank = priority, weight, class, dependents,
  luid; priorities copied from the `-fsched-verbose=5` dependence table) plus local-alloc's
  priority. Validated against the real schedule, then brute-forced over block changes (drop or
  add an insn, add a dependence, permute luids) to see which inputs give retail's registers; the
  surviving change ("one extra stage per component") pointed at an inline layer.
- Evidence: func_0041D140 fixed-L block, 13 -> 4 differ.

### 17. Two rematerialised addresses at one call issued in the "wrong" order (open, 2026-11-18)
- Symptom: before a `jal`, retail issues `addiu $v1,$sp,X` (for a3) before `addiu $v0,$sp,Y`
  (for a0), and the f13 copy before the a0 copy; the draft issues them in argument order.
- Facts read from the source (reload1.c, haifa-sched.c) and checked on dumps:
  - spill registers are taken round-robin per insn (`last_spill_reg`, advanced in
    set_reload_reg; find_equiv_reg/inheritance hits do not advance it) and skip the insn's own
    hard registers; observed order here v0, v1, a0, a1. The registers a later call gets
    therefore reveal the order the reloads were processed in.
  - input reloads are emitted immediately before their insn, so sched2's luid of the two
    reloads equals the sched1 order of the two argument copies.
  - sched2 ties them on priority, class and dependents, so luid decides; a reload register that
    is reused by a later argument load gets a longer chain and wins (that is why the IK calls
    issue `&endL`'s reload first).
  - sched1 puts an argument copy first only if its source dies there (INSN_REG_WEIGHT counts
    REG_DEAD/REG_UNUSED); argument copies are otherwise in prototype order, and every copy is
    anti/output dependent on the previous call (all class 2).
  - cse1 forgets `(plus $1 c)` frame addresses across calls ($1 is call-used) but keeps the
    pseudo that held one; gcse's single PRE pass plus the final cprop pass merge every later
    pseudo set of the same frame address into the first one, so an address pseudo never dies
    early while a later call still needs the address.
  - MIPS has no ADJUST_PRIORITY/MD_SCHED hooks; machine_dependent_reorg only runs for MIPS16;
    Sony's sce-patch changes none of haifa/reload/local-alloc/gcse.
- Open case: func_0041D140 call 28 (4 rows): retail's next call proves the a0 copy was reloaded
  first, yet sched2 issued the a3 reload first; no source form found (about 1,500 variants:
  wrappers, reference layers, pointer variables, assignment forms, IK prototypes, random
  combinations). Retail's sched2 block must contain something the draft's lacks (compare
  section 15's invisible redundant set).
- Progress (z34, 3 left): wrapping the debug stores after the call as
  `do { if (dbg) { ... } } while (0);` (or `for (;;) { ...; break; }`) fixed retail's
  `mov.s $f13` between the a3 and a0 copies. The loop notes make the first insn after them (the
  dbg pointer reload) a sched2 barrier: it becomes a dependent of every earlier insn that reads
  a register still live (here f20 and sp), so the f13 copy gains one dependent and ties with the
  a0 copy (4/4), and luid then puts f13 first. The two reloads stay 6 (v0) / 5 (v1): the barrier
  insn is also the only later v1 user, so v1 gains nothing. `build/work/41d140/deps28.py DUMP`
  prints these counts from a `-fsched-verbose=5` sched2 dump.

### 18. A global FP pseudo blocked by local-alloc's hard registers, not by global priority (2026-11-18)
- Symptom: a value that spans blocks (`h = car->m40`, used before and after an `if`) takes `$f3`
  where retail has `$f2`, and a 0.0 constant in the `if` takes `$f2`; global priorities show
  the constant first (3 refs over 9 insns, doubled to 18 by REG_EQUIV, against h's 3/19).
- Read the greg dump's `;; N conflicts:` line for the pseudo: the hard registers at its end
  (`32 33 34` = f0-f2) are the registers local-alloc already gave to block-local temporaries
  overlapping it in the merge block. Fixing the global order alone does nothing while f2 stays a
  hard conflict, so check both.
- Levers (func_00361908, 16 -> 2): (1) read the field twice (`car->m40` in both statements, no
  local): gcse PRE loads it on each path (as it did for m44), giving one pseudo with 2 sets and
  4 refs that outranks the constant; reorg then merges the two loads into the branch delay slot;
  (2) reorder independent statements in the merge block (`m1060 = ...` before `m103C = m48 *
  9.8`) so sched1's order gives the overlapping local (`m20`) `$f3` and frees `$f2`.
- Related, loop preheader order: loop.c emits hoisted movables in loop-body order, so an
  invariant (`0x80` of `0x80 - x`) comes before another (a base-register copy for the second
  byte read) only if its expression comes first in the body: `int angle = 0x80 - a[j]; u8 r =
  b[j];` instead of reading both bytes first (func_00361908, 2 -> 0).

### 19. Stack-slot layout and rules from a 4.9 KB match (func_004173B0, 2026-11-18)
- Temp slots (function.c assign_stack_temp_for_type) are reused only by the SAME machine mode,
  most recently freed first. A struct with a union holding a u128 and an int[2] array are both
  BLKmode (reuse each other's freed 16-byte slots, no split below 16 bytes); a plain f32 is SFmode
  (fresh 4-byte slots). A one-float class WITH a user copy constructor (the unit's `Angle`) is
  TREE_ADDRESSABLE, hence BLKmode: its temporaries bound to `const Angle &` are stored to 16-byte
  slots; without the copy constructor it stays SFmode in a register. Compile a 10-line probe with
  build/work/4173b0/cc.sh to settle such questions before guessing.
- By-value parameters of an inline that are passed on by reference (`clampMap(m, v, lo, hi)` ->
  `clampf(.., lo, hi)`) are stored to SF stack slots; literals bound directly to `const f32 &`
  are not. Two inline expansions get their two param slots in reverse order (freed slot reuse).
- gcc 2.96 gcse kills every memory expression in a block that contains ANY store (no alias
  analysis, mem_set_in_block): a load reused across an `if` (PRE) in the draft but reloaded in
  retail means retail had a store between the two loads in RTL order (here: `s32 active =
  p->active;` read before the `arm = ...` stores).
- A value retail reaches through one pseudo across calls (the same `$fp` for every access) is a
  reference or pointer variable in the source (`Vec &arm = shoulderPos;`); cse forgets frame
  addresses at calls, so a plain local is re-addressed from `$sp` after each call.
- Store via `4(s0)` but load via `0x44(t0)` (t0 = a spilled base reloaded) = the unit's
  `x = (*this)[0] + v[0]` operator+= form: member store, char*-arithmetic load whose address
  pseudo reload rematerialises from the spilled base.
- In C++ gcc 2.96 the vptr goes after the class's own data members: a padding member declared
  after the virtual functions moves the vptr; space subobjects with a wrapper struct instead.
- flow's redundant-store removal (mem_set_list) is flushed by an inline asm (min.s/max.s clamp):
  `a = K - a; a2 = K - a2;` before both clamps lets the raw `a2` store die as in retail.

### 20. A redundant store as an invisible reference; a pointer copy kept for one arm (func_00412C78, 2026-11-18)
- **s-register rotation of struct-address pseudos with equal asm refs** (`&b`/`&c` homes swapped,
  same number of uses in both listings): flow counts a reference the final code no longer has.
  `fix(&x, 0, 0, 0.5)` right after `integrate(&x, dt)` (which ends with `acc = 0`) stores `acc = 0`
  again in the same block: flow counts the store (16 refs instead of 15, floor_log2 jumps from 3
  to 4), global.c ranks that pseudo first, and reload_cse deletes the store as a no-op (cselib
  knows the slot holds `$f20`). Look for a helper call whose extra store is redundant in its block.
- **`daddu v0,s0` at the top of a block, used only by one arm's store** (the other arm and the
  block itself use `$s0`): a pointer with two sets. `f32 *p = vel;` before the test, the positive
  arm stores through `p`, the negative arm reassigns `p = vel;` first. A plain copy (an inline
  parameter, a fresh local) never survives: gcse cprop finds it available in the arm, and cse2's
  last path through the block gives the block and the arm one canonical register
  (make_regs_eqv). Same rule as the float copy of func_0040DDC0 (ee-gcc-2.96.md, "One variable
  shared by two arms"); here it applied to one of three inlined copies of the same spring, so that
  case got its own helper.
- A cross-jumped tail can hide a wrong constant: once registers matched, the only difference left
  was a `b` into another case's `sw; jal; li.s 2.0; swc1` tail (the source stored 1.0f).

### 21. C or C++, `throw()`, and statement expressions in conditions (func_005999B8, 2026-11-18)
- libio's `_IO_dtoa` (4.8 KB, public floatconv.c) matched only as C++ with every earlier helper
  declared `throw()`. The same body as C stayed at 55 of 1196, all branch-likely and delay-slot
  choices. Why: `can_throw()` (except.c) counts any call without a `REG_EH_REGION <= 0` note as
  throwing, in C as well, and resource.c's `find_dead_or_set_registers` stops its liveness scan
  there. A call gets that note only when the callee is `TREE_NOTHROW`: declared `throw()`, or
  compiled earlier in the same unit with nothing in it that can throw (toplev.c). C++ headers
  declare malloc/free `throw()`, so in a C++ unit the allocating helpers are nothrow too. The
  smaller toplev-only set (leaf helpers) was worse (37).
- g++ 2.96 wraps every `if` condition in `CLEANUP_POINT_EXPR`. fold pushes it inward past `&&`
  operands only when `has_cleanups()` is false, and a statement expression is a language-specific
  tree code (`has_cleanups` = -1). So `if (!word1(d) && ...)` with the statement-expression
  `word0/word1` macros is computed as a value (`sltiu`, then `beqz`), while C branches directly. Inline
  accessor functions fix that, but then fold rewrites `!(word1(d) & 1)` into a computed bit
  test (`xori; andi; beqz`): writing `(word1(d) & 1) == 0` gives retail's `andi; bnez`.
- C++ gives addressable locals (`&be`, `&bbits` passed to d2b) their frame slots in declaration
  order. C assigns them late, at the first address-taken use. Retail's frame had the Bigint buffers
  first, then `be`, then `bbits`.

### 22. SGI iterator vs const_iterator slots; declaration order inside a block (func_004E8F58, 2026-11-18)
- In the original the `begin()`/`end()` results of a map or list went through the same 16-byte
  BLKmode slots as the string temporaries, while the loop variable sat in its own 4-byte slot.
  SGI STL explains it: `_Rb_tree_iterator(const iterator &)` (and `_List_iterator`'s) is the copy
  constructor of `iterator`, so `iterator` is TREE_ADDRESSABLE and BLKmode, but it is only a
  converting constructor for `const_iterator`, which stays SImode. So write the loop as
  `const_iterator it = m.begin()` over a non-const container, and give the two iterator structs
  those constructors. Giving both a copy constructor puts the loop variables into the low
  BLKmode slots; giving neither one keeps the temporaries in registers.
- One block-scope local declared before its neighbour's temporaries moves every slot after it.
  Retail's `char buf[128]; Str cred = a + ":" + b; Base64 enc;` gave buf 0x90, the temporaries
  of the `+` chain (one new slot at 0x110), then enc 0x120. Declaring `enc` before `cred` added a
  slot and a pseudo, and that pseudo pushed a 14-reference `this` (priority
  floor_log2(refs) * refs / live length) out of `$fp` onto the stack.

### 23. Correction to 21: the floatconv unit is C; group sources give the nothrow context (2026-11-18)
- except.c `nothrow_function_p()` returns 1 when `!flag_exceptions`, so in a C unit built with
  -fno-exceptions every function compiled earlier in the file becomes TREE_NOTHROW, and calls to
  it carry the REG_EH_REGION 0 note that reorg's liveness scan needs. A one-function C source that
  only declares its callees loses that note. Section 21's C++ + `throw()` form imitates it, but
  C++ changes other things: frame slots in declaration order, statement-expression conditions,
  and `(void)&x` making `x` a stack variable where C's ADDRESSOF purge gives it back a register.
- The faithful form is a group source: the real earlier bodies in one C file, judged from the
  first function's address (match.py judges everything the object puts after it), as libmatch's
  source_groups do. _IO_strtod matched this way, verbatim, appended to the Binit..d2b group
  together with ratio (0x5978E8-0x599788, 1960 instructions); build.py lets a group replace later
  source starts.
- floatconv was built with the EE's `FLT_ROUNDS 0`, not the project's `<float.h>` stand-in value 1:
  `_IO_strtod`'s fast path (`nd <= DBL_DIG && FLT_ROUNDS == 1`) is missing in retail. The group
  compiles under ee-gcc2.96-g (no filled soft-float call delay slots), like newlib.

### 24. PRE-made frame-address pseudos and local-alloc ties (func_00402320, 3904 B, 2026-11-18)
- gcse PRE turns every `(plus $sp-base c)` that several blocks compute into one reaching
  register, inserting copies on the edges where it is missing (`PRE/HOIST: edge (a,b), copy
  expression N` in the .08.gcse dump). These pseudos then compete in global alloc with
  priority floor_log2(refs) * refs / live length. Retail kept only the ones with the most uses
  (here &pos, &dir in $s4/$s3, with no register for sp+0x70), and that was decided by how many
  inline members reach each object through `this`: a by-value `put()`, reference accessors
  `f32 &X()`, a member `up()` for a choice made on the vector.
- Two function-scope vectors reused for two jobs (case 5's position and normal, later the eye
  vector and the rotated vector) gave retail's shared slots 0x40/0x50 and its two long-lived
  address registers; separate block locals did not.
- A last v0/v1 swap inside a two-armed member came from local-alloc.c QTY_CMP_PRI: PRE inserted
  dead address copies into one arm, sched1 dual-issued them into the lui -> addiu -> lq stalls,
  the address quantity's life grew, and the TI data quantity (size 2) outranked it. What fixed
  it was the other arm's form: stores through `X() = ...` instead of `x = ...`. That changes the
  expressions the arm makes available, and so the insertions. `oracle.py force --set` certified
  the decision first; a generated combination search over the helper forms (variants.py, 47
  variants) found the source.

### 25. CSE's zero holders, wider-mode constants and a sched barrier from cross-jumped arms (func_00368628, 3752 B, 2026-11-18)
- **A float 0.0 kept in a callee-saved register across a call and copied into later locals**
  (`mov.s $f22, $f0` in a `jal` slot, then `mov.s $f2, $f22`, `mov.s $f29, $f22`): mips CONST_COSTS
  prices a CONST_DOUBLE at 2 insns and a REG at 0, so cse replaces every later `x = 0.0f` (and
  the 0.0 operand of a compare) with any register it knows holds 0. Which register: make_regs_eqv
  keeps as class head the one whose REGNO_LAST_UID is latest, so the holder is a variable set to
  0 before the call that is used (or set again) late in the function (here `extra`). It also
  costs a 13th FP register, which is what pushed `dt` onto the stack as in retail.
- **A fresh `mtc1 $zero` where yours reuses a register known to be 0**: cse lost the
  equivalence. Two ways retail does it: the path skipped around a block that sets the holder
  (invalidate_skipped_block: `rate = 0; if (A && B) rate = K; else if (C && D) rate = K;`, two
  `rate = K` arms that jump2 merges back into one), or the statements are in an order that
  makes the copy go the other way (`extra = out; out = rest; load = 0.0f;` keeps `load`'s own
  zero; `load = 0.0f; out = rest;` gives `out = load`). gcse's CONST-PROP turns copies back into
  constants but cse2 redoes them, so the cse1/cse2 dumps decide, not gcse.
- **A spilled int flag with one reference more than retail** (it outranked two flags retail
  kept in `$s7`/`$fp`): `pos = 1; rec->flags = 1;` lets cse store `(subreg:QI pos)` through
  src_related (a CONST_INT already in a wider-mode register), which counts as a use. Retail's
  `li v0,1; sw v0,pos; sb v0,flags` came from the store first through an inline setter with a
  by-value parameter (`setFlags(rec, 1); pos = 1;`): the parameter is an SImode pseudo, so reload
  finds `$v0 == 1` for the spilled `pos = 1`, and sched2 still puts the `sw` before the `sb` the
  cut arm cross-jumps into. `u8`/`bool` locals change nothing here (PROMOTE_MODE widens them).
- **Two independent insns issued in the "wrong" order at the head of a block** (`mtc1 $zero`
  before a `c.lt.s` that has the higher priority): retail had a block boundary between them.
  Writing the zero in both arms of the preceding `if` (`if (clipped) { ...; rate = 0.0f; } else
  { rate = 0.0f; }`) gives that boundary, and jump2 cross-jumps the two copies into retail's
  single `mtc1`. regsearch.py found the same effect with `do { } while (0)`, which AGENTS.md
  does not accept as a source form.
- A value computed before a call and kept in a callee-saved register that is reused for the
  next steps (`sub.s $f22,$f22,$f24` before `jal`, then `div.s $f22`, `div.s $f22`) is one
  variable updated in place (`extra -= power; extra = extra * 1000 / f(); extra = dt * extra /
  23400;`); a separate `delta` local takes another register.

## 16. Mechanisms from the 2026-11-25 worker pass

- **Post-call group**: after a call, consecutive simple hard-reg/pseudo moves are glued to it in
  expand order (the `+` rows in `-fsched-verbose`). Where no group forms, the second issue slot of
  the call's cycle goes to the lowest-position dependent that is immediately ready (002C34B0,
  002182E0).
- **Cross-jump blocker**: flow inserts `(use (const_int 0))` after a call that ends a block before
  a label, and `find_cross_jump` stops on it, so a call written in both arms is never tail-merged.
- **Stale branch probability**: reorg's choice of thread for a delay slot follows the REG_BR_PROB
  note; a plain EQ test gets 40% and fills from the fall-through.
- **Clobber count**: the number of leading clobber insns in an aggregate initialiser changes
  sched1's two-per-cycle packing and, through it, local-alloc spans (0026F630).
- **Alias set 0 for a union member**: a store to a member of an anonymous union has alias set 0 and
  keeps its order against calls and other stores (0053C2F0).
- **A statement between two loops** stops loop.c's "multiple entry points" bail-out so the buffer
  address is hoisted (0054B1A8); an ascending `for` is reversed by loop.c.
- **cse1 flushes its hash table every 1000 insns**: a constant held in a register across two
  statements means the flush falls between them (004242F0, open).
- **Accessors taking `unsigned x` and masking `x & 0xFF`** match where a `u8` parameter does not
  (SAFER 0044B900, 0044BBD8).
- 00445B88 compares five fields against -1 that leave no code; only their number is recoverable,
  so the source uses `f[33..35]` and says so in a comment.

## 17. Mechanisms from the second 2026-11-25 pass (variable reuse, alias sets, flat chains)

Four near misses of the deferred list closed with source-shape levers that no earlier entry had
(func_00417110, func_004B9438, func_0053A178, func_0050E6E8); one old rule was confirmed. Each rule
names the pass that decides and what to look for in the listing.

- **One scratch variable for several values** (the strongest lever of the pass). A user variable
  set in more than one block is ONE pseudo for all its values: global.c allocates it once, with
  the conflicts and preferences of all its ranges, and local-alloc never ties it into a quantity.
  Signs in the listing: unrelated values in the same register one after the other where the
  draft's separate variables take the lowest free register each (`x`, `abs(...)`, an `Angle`
  value all in `$f2`); a `load T; copy n = T` pair where the draft has one register (the copy's
  destination is the reused variable: it keeps the register of its earlier value and cse cannot
  fold the copy because the pseudo is not the temp's class); a local-alloc "near tie" between two
  temp chains (the chain whose last link is assigned to the reused variable loses that link's
  two refs: func_00417110, k-chain 30/46 -> 24/38 against 14/22).
  - func_00417110: `v` = constant term of the quadratic, then the chosen cosine, then
    `abs(PI/2 - acos(v))`, then the angle. It conflicts with hard `$f12` (the `PI - v` argument),
    so prune_preferences drops its `$f12` preference and it takes `$f2`.
  - func_0053A178: `n` = address of the counts table, then the count read from it
    (`n = (*count)++`): retail's `lw a0; daddu a3,a0` with the limit test on `a0`.
  The original programmers reuse `t`, `n`, parameters: when a register "moves" between unrelated
  values, try one variable before anything else.
- **Flat `else if` chain against nested ifs for a selected value** (func_00417110): with
  `if (A) x = r[0]; else if (B) x = r[1]; else if (C) x = min(...); else return;` the variable is
  only set at the three success points, so it does not conflict with gcse's reaching register of
  the `r[0]` loads; global.c `expand_preferences` then passes the argument-register preference
  through the copy `x = r0` and the load pseudo takes `$f12`. A nested form that assigns
  `x = r[1]` before testing it makes the two conflict and swaps the homes. Do not judge the two
  forms by the diff count while another allocation residual is open: the flat chain was 100 off
  before the scratch variable and exact after it.
- **global.c details read on this function** (GCC_COPY/gcc-20001003/gcc/global.c):
  `set_preference` also takes the FIRST operand of an arithmetic source (`r = a * b` prefers
  the hard register local-alloc gave `a`); in `find_reg` a copy preference beats that plain
  preference; `prune_preferences` first removes preferred registers the pseudo conflicts with
  (a call-argument preference dies when the argument register is set while the value is live)
  and pass 0 skips registers a lower-priority conflicting pseudo prefers.
- **A directly accessed global scalar has alias set 0** (func_0050E6E8). `extern int g; g = x;`
  is `(mem/f (lo_sum ..) 0)`: it conflicts with every load, so every later load through a
  pointer depends on the store and the store gets a high sched1/sched2 priority. A struct member
  (`blk.arg = x`) or a dereference carries the alias set of its type: a pointer-typed member
  store does not conflict with `int` loads, has priority 1 and is issued as a filler when the
  memory unit is idle. Retail's `sh zero,g1; sw cb,g2; lw; lw; sw; sw; sw arg,g3` needed g1
  plain (first), g2 and g3 pointer members of two block structs, and the two loads in locals
  (a load after a store through the other base keeps its dependence). Symptom to look for: a
  global store that the draft issues early and retail leaves for the end of the block (or the
  reverse), with its `lui` late as well. Under `-fno-strict-aliasing` none of this applies.
- **No named temporary for an element that is tested and updated** (func_004B9438):
  `if (s[i] >= 0x3040 && s[i] <= 0x309F) s[i] += 0x60;`. fold turns the range test on the
  `unsigned short` lvalue into `(u16)(x + 0xCFC0) < 0x60` in the narrow type: the constant is
  the zero-extended `0xCFC0` (hoisted by loop.c into a register, `ori`) followed by
  `andi 0xFFFF`; a test written on an `int` copy gives `addiu -0x3040; sltiu`. With no user
  pseudo for the character, the count and loop.c's pointer get retail's homes (a named `u16 c`
  swaps them). A length helper that indexes (`while (s[n]) n++`) keeps the pointer copy in the
  loop preheader; one that walks its own copy of the pointer puts the copy before the first
  test, where reorg takes it into the branch's slot.
- **`throw()` on a later callee decides an earlier branch-likely** (confirmed, section 7):
  func_00417110's `bc1f` with the return-value copy in its slot needed `throw()` on the tangent
  callee that the fall-through path calls: resource.c's forward scan only learns that `$f0` is
  clobbered when it may cross that call.
- **`xori reg,reg,0` before `movz/movn`** (func_00529770, open): mips `gen_conditional_move`
  always emits `cmp = op0 XOR op1`, also for a comparison with 0. if_convert runs three times
  before reload (after jump1, right before cse2 inside `.10.cse2`, and `.15.ce` after combine);
  only a conversion made by the third call keeps the xor. So the source arm was not a single
  insn until combine (or its else block had a second predecessor until thread_jumps): every
  plain if/else or `?:` is converted earlier and loses the `xori`.
- **Reading sched1 ties** (func_00417110, func_0052C640): among equal priorities the weight
  comes first, then the class against the last scheduled insn, then the NUMBER of dependents
  (a product used twice is issued before one used once, whatever the source order), then luid.
  local-alloc's spans are counted in sched1's order, which sched2 hides: when only a quantity
  priority is off, look for the insn whose sched1 slot can move, not at the final listing.
- Tools: `tools/schedtrace.py` cannot compile on a Windows mount; the same dump comes from
  `bash tools/rtl_wsl.sh FILE OUTDIR "<compiler command> -fsched-verbose=5"` (the `.17.sched`
  and `.25.sched2` files then carry the dependence tables and ready lists). `tools/oracle.py`
  needs the venv Python of setup_linux.sh (`~/.local/share/gt4/venv/bin/python3`).

## 18. Mechanisms from the 2026-11-26 worker pass

- Callee return type steers sched2: declaring a tail-call wrapper as `int` makes the call a SET of `$2`, which empties the `$v0` use list and moves the dependent store into the delay slot (005293D0).
- sched2 has no weight criterion after reload: ties go by class against the last scheduled insn, then dependent count, then luid. An `int` store after an `int` load depends through alias sets; a pointer-typed field (`void *user`) breaks that (005319A8).
- An accessor returning bool (`h.isValid()`) gives the branch REG_BR_PROB 5000 and makes reorg fill the `beqz` delay slot from the target; a plain `p != 0` gives 3999 and takes the fall-through. `__builtin_expect` fixes the slot but adds a DI pseudo and swaps `v0`/`v1` (002127E8).
- Stores through a bare `(mem (reg))` cursor stop cse from merging stack-slot loads; indexed stores share one load and lose the `mov.s` copies (0021F6C8).
- A temporary used after its copy (`next = weight + 2.0f; weight = next;`) reproduces `add.s; mov.s`; `weight += 2.0f` adds in place (00216748).
- Units around 0x3C8xxx-0x3D6xxx use the no-strict-aliasing profile (003D6D30, 003C8668).
- A variable assigned twice in a loop (`n_times_set == 2`) is not a giv: loop.c reduces only `self + i*stride`. The loop pass runs twice and trivially-dead-insn deletion runs between them, so dead copies count only in the first pass; this shifts the hoist threshold (64, minus 3 per moved insn) (003C8668).
- A derived giv only accumulates benefit if its source register has a single use.
- local-alloc tries a "false" life widened by one insn on each side; moving one slot in sched1 (already-shifted index before the calls, x/y/z read after the products) fixed 003E8610.
- Ternary `h ? 8.0f : 16.0f` keeps `li 3; or`; `float y = 8; if (!h) y = 16;` lets cse1 fold it into `li 3` (0049B850, still open at 13 off).
- Variadic allocator declaration `int f(void *out, ...)` is the only form that gives both `sll` for `u16*4` and `dsll32/dsrl32` for the unsigned product (005237C8, open).

## 26. A hoisted then-arm against an earlier constant; asm-built constants and local-alloc (func_0057DE48, open, 2026-11-25)
Custom vprintf, 930 instructions, 12 differing (draft build/work/57de48/r/best_12.cpp; diary in
attempts.jsonl and build/work/57de48/NOTES.md).
- **ifcvt find_if_case_1 inserts the hoisted then-arm right before `earliest`**, which is the jump
  itself when the condition is a plain register (`if (!fixed)`): an earlier `char *dot = 0;`
  stays ahead of the hoisted `size = i`, sched2 ties the two (priority 1, dependents 1) and luid
  keeps `dot = 0` first, so reorg slots `size = i`. Retail has the reverse order.
  BRANCH_COST is 1 for the EE (mips.h gives 2 only to R4000/R6000), so `{ size = i; dot = 0; }`
  is never hoisted.
- **Writing the copy before the branch instead** (`size = i; dot = 0; if (fixed) {...}`) gives
  the order but makes cse1 canonicalise i to `size` in the arm whenever size's REGNO_LAST_UID is
  later than i's (make_regs_eqv). Ending size's uses earlier makes i canonical and fixes the
  rows, but moves preferences that hang on those uses (`size = ndig - last` hands size's `$a0`
  preference to ndig through expand_preferences). An arm that reassigns size first
  (`size = prec; if (i >= prec) size = i;`) keeps i, but the first jump pass already builds
  `(if_then_else (ne slt 0) prec i)`, so reload ties i (`movn`) where retail ties prec (`movz`).
- **Unfolded 64-bit constants** (`li 0x380; dsll32 20`, both `li`s before both shifts): every C
  form folds to `dli` (CONST_COSTS is 0 for any CONST_INT, so cse always folds); a one-insn
  `dsll32` asm helper reproduces them. With `__asm__ __volatile__` the asm is a sched1/sched2
  barrier: insns written before it stay before it, and the load scheduled ahead of the `li`s
  (longest latency) decides local-alloc's overlaps. update_equiv_regs moves a once-set constant
  pseudo's init next to its single use, so writing the constant early does not keep it early;
  a variable set twice (in-place `"+r"`) does.
- Method: oracle `rec['local']` (block, pseudos, birth/death, refs, result) gives local-alloc's
  quantity order directly; priority = floor_log2(refs) * refs / (death - birth). Forcing the
  F-block locals to retail's registers (oracle force --at alloc) left one sched2 pick, which
  proves the remaining work is the quantity order, not the logic.

## 27. A copy before a branch whose arm must keep reading the source register (func_0057DE48, 2026-11-25)
- Retail `daddu s0,s1` (size = i) before `beqz fixed`, an unrelated insn in the slot, and the arm
  computing `max(i, prec)` from `s1`: write the copy before the `if` and **store to the copy's
  destination first in the arm** with a value that is used (`size = prec; dot = q - size - 1;
  size = (i < size) ? size : i;`). The store kills cse1's `size == i` equivalence (otherwise
  make_regs_eqv makes the longer-lived `size` canonical and the arm reads `s0`).
- Cmove orientation decides reload's tie: the jump-time if_convert(0) (inside `.02.jump`, before
  cse1) builds a two-value select `x = c ? a : b` as `(if_then_else (eq slt 0) i prec)` and a
  reassign-first `x = b; if (c) x = a;` as `(if_then_else (ne slt 0) b a)`. movsi_on_si's first
  alternative ties operand 3 to the output, so the first gives `daddu x,prec; movz x,i` and the
  second `movn x,prec` with `i` tied. Use the form whose operand 3 is the register retail copies
  into the output first. Same lever for a DImode select (`bias = neg; if (!negative) bias = pos;`
  gives `movn pos,neg`).
- Sony's backend (GCC_COPY SCE296 `mips.h`): CONST_COSTS is 0 for every CONST_INT, and cc1 has a
  64-bit HOST_WIDE_INT, so a shifted 64-bit constant is always folded and printed as one `dli`.

## 28. Stack-slot reuse decided by a class's size (func_002A6D10, 2026-11-25)
Symptom: every block-local slot after one point is 0x10 off and the frame is 0x10 smaller than
retail; one temporary sits in a free hole where retail opens a new slot.
Mechanism (function.c, gcc-20001003, the same file in the ee tree): block locals and temporaries
are temp slots. `assign_stack_temp_for_type` reuses a free slot only if the modes are equal (a
class is BLKmode only with a non-trivial copy constructor, cp/class.c), and splits a BLKmode slot
when `size - CEIL_ROUND(request, 16) >= 16`. `combine_temp_slots` (no-strict-aliasing only)
merges adjacent free BLKmode slots by adding the **requested** sizes (`p->size += q->size`), not
their 16-byte footprints. So a 4-byte object in a 16-byte slot contributes 4, and whether a
later split leaves a reusable remainder depends on the exact sizeof of each earlier object.
Lever: the sizeof of the classes involved. In mInputTextFace::onKeyPress a 16-byte MethodHandle
left a 0x1C remainder (split off at 0x210, where the next SymID temporary landed); with an
8-byte MethodHandle (`s32 p; s32 pad;`) the handle takes the whole remainder and the SymID
opens a new slot, as in retail. When a slot shift starts after a large array reuses earlier
blocks' slots, recompute the combined size from the requested sizes before trying statement
orders.

## 29. Untied constants, reused C89 variables and sched barriers at calls (func_00393D20, 3312 B, 2026-11-26)
- **A product left untied from its dying constant** (retail `lui/ori/mtc1 $f0; mul.s $f12, $f1, $f0`
  where the draft gives `mtc1 $f12; mul.s $f12, $f1, $f12`): local-alloc's block_alloc ties operand
  0 with a dying operand (operand 1 first, then the others), and combine_regs refuses when either
  pseudo is not block-local (`reg_qty < 0`). Retail's product is a global pseudo: the source
  reuses one variable across branches (C89 style), e.g. the small-camera scale product stored in
  the variable the other branch uses for `cosv`, and the scale itself in the other branch's `root`
  (00393D20: 18 -> 8 rows). A `const f32 k = 0.85f` at function scope does not help (cse propagates
  it). The same reuse explains two different values in one register in two arms (`half` = fw*0.5
  then sx*0.5, both `$f13`).
- **Insns forced before the next call** (haifa-sched.c sched_analyze): an insn reading a pseudo
  with REG_N_CALLS_CROSSED == 0 is chained before the next call (sched_before_next_call), and a
  call depends on every pending memory read (flush_pending_lists). Otherwise a conversion or a
  shift whose result crosses calls sinks below a call that has the longer chain (calls in a long
  straight-line block carry priority ~100, conversions < 60). Placement of `w2 = w*2` relative to
  a call in the source still decides global-alloc's live length (h2 vs w2 taking s1/s2).
- **Real C++ virtual calls vs a named entry pointer**: `VEntry *ve = ...; ve->fn(obj + ve->delta)`
  gives other v0/v1 choices than `obj->slotN()`; declare the class with real virtuals (slot k at
  `+8*(k+1)`, vptr after the leading fields).
- **Matched (2026-11-26, 8 -> 0) by three more levers**, each read in the gcc source:
  - **Arm tails cross-jumped after sched2.** jump2 (the only `JUMP_CROSS_JUMP` pass) runs after
    sched2 (toplev.c). Writing the same tail in both arms (`cosv = fh / sy * 0.85f;` /
    `cosv = fw / sx * 0.85f;`) lets sched2 schedule the constant load and the multiply inside each
    arm; jump2 then merges them into the join, whose own schedule starts with the product already
    ready. Retail's `li 0.85; mul.s; li 1.0` (mul before the second constant) came out of this; any
    single join-block form issues the 1.0 load first (the mul waits for the 0.85 load's latency).
    A fresh `aspect = fw / fh` local for the compare (not a reused C89 variable) kept d2 in f4.
  - **Keeping an insn below a call in sched1.** sched_analyze_1 gives the SET of a pseudo with
    REG_N_CALLS_CROSSED == 0 an anti dependence on the previous call; a set of a call-crossing
    pseudo has none and floats above the call. `r *= 0.5f` after the call (r crosses calls) was
    hoisted back; `f32 r = fw / zoom * 0.5f;` written after the call (a new value that crosses no
    call, divide included) stays below it, and the divide's latency issues r*r after c*c and the
    add, so local-alloc sees h*h, c*c, r, add, r*r, sub: r*r has the shortest span, takes f0,
    then c*c f1, h*h f2 as retail. (With equal spans the earlier-born quantity wins: an r*r tied
    with c*c on priority always lost on qty number.)
  - **Global preferences follow dying values.** global.c expand_preferences merges the preference
    sets of a global set in an insn and a global that dies in it, and set_preference only looks at
    operand 0 of an arithmetic source. `r = c * r` (in place) merged r's and c's preferences into
    the root's chain and gave root f2; keeping the product in its own local (`f32 cr = c * r;
    cosv = (cr + root) / d2;`) gave root f1 as retail.

## 30. Ordering local-alloc quantities through sched1's tie-breaks (func_004013E8, 3464 B, 2026-11-26)
Five spring channels, each clamped with asm `max.s`/`min.s`; retail keeps the position update and
the clamp temporary both in `$f1` and the velocity reload in `$f0`. 38 -> 0 by three levers:
- **Local-alloc needs the right quantity placed first, and sched1's order decides it.** With
  INSN_SCHEDULING, find_free_reg first tries each quantity's range widened by one insn on each side
  (local-alloc.c fake_birth/fake_death) and marks that range, so the quantity allocated second
  avoids an adjacent one's register. Retail's registers need the velocity chain (load, max, min,
  store) issued completely before the temporary's load: the velocity quantity is then short
  (30000, placed first, `$f0`), the position update next to it is pushed to `$f1`, and the
  temporary, no longer adjacent to the update, also gets `$f1`.
- **A load through a pointer waits for a store sched1 cannot disambiguate.** alias.c knows a
  pointer's value only from a REG_EQUAL/REG_EQUIV note, and local-alloc adds REG_EQUIV after
  sched1, so `*(float *)px` must follow every earlier store, while a direct frame access does not.
  Writing the velocity clamp and its store first, then reading the position through the pointer
  (`v = clamp(*pv); st.v = v; t = mx(*(float *)px, lo); x = mn(t, hi); st.x = x;`) produces that
  order. Equal-priority loads otherwise tie-break on dependents count (rank_for_schedule): a direct
  frame load collects more memory dependents and wins.
- The same in a vector subtraction (`to -= mine`, components in a row): retail's component
  quantities are not adjacent. A pointer to `mine` taken where it is declared (so cse no longer
  folds it to a frame address by the time it is used) and each component read into a temporary
  before its subtraction (`float my = pm[1]; to.Y() -= my;`) separates them.
- **A zero compare's register can be a variable's.** The last register was the 0.0 of
  `if (0 < v) ... else if (v < 0)`: retail had `float rate = 0.0f;` before the tests, with
  `rate = ...` in both arms. cse substitutes the register known to hold 0 (rate's) into both
  compares, and rate lives in `$f1` through the arms. No source order of the tests moves a plain
  constant zero off `$f0`.

## 19. Mechanisms from the second 2026-11-26 worker pass

- A pass-through inline for the start value keeps the arm at two insns until combine, so if-convert happens only in the `ce` pass (`xori` + `movz`), and gcse PRE then stops hoisting the load above the join (004C2830).
- Indexed presence tests (`&fonts->data` with `i*11`) keep `(plus base idx)` away from cse/gcse; combine splits it into `addu v1,base,idx; lw 4(v1)` (004C2830).
- Declaring `int count` before `u8 i` decides a global-alloc priority tie in favour of the lower pseudo number (004C2830).
- A scratch pointer reused for two roles becomes one global pseudo with a copy preference for `$a1`, which pushes the table base to `$t0`; the default (strict aliasing) profile also changes sched2 store order against nsa (005178D8).
- gcse does PRE on memory loads in this version: re-reading a field through an inline accessor at the start of each arm keeps the reload; a chained assignment `angle = x = state(self)->angle` keeps the `mov.s` that cprop otherwise folds (003485D0).
- gas 2.10 (as2004 profile) assembles `l.s $f2,sym($3)` after another `l.s` with `lwc1` instead of `lui`; one-line near misses of that shape may only need the as2004 profile (003485D0).
- Writing negation `v = -v` inside each arm instead of once before the test leaves only the `side` store shared, so tail merging yields the retail `bc1tl` (003513F8).
- Still open: 002B7310 stays at 2/104; 00516B40 needs related-value addressing off one symbol (&D_00854038 + offsets).
