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
