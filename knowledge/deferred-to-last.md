# Deferred to the end

Decision of the owner, 2026-10-18: the functions that look hand-written, and the fragments that
borrow their caller's registers, are worked **last**. By then the code around them is decompiled,
and what still calls them or is called by them shows what is left unconnected. No assembly (`.s`)
is accepted for them (see `config/asm_functions.txt` for the 205 that were assembly in the
original and are not targets): they stay open until a C/C++ source reproduces the bytes, or are
reported as open.

Do not lease these to workers or tools meanwhile (`swarm.py` workers return `fragment` and make no
tries anyway). When their turn comes:

1. For the fragments, first check the function inventory: a routine that jumps into its
   neighbours and uses registers it never set (`s5`-`s7`, `ra`) is usually one function cut in
   pieces. Merge the boundaries and decompile it whole, from the public source if it has one
   (the inflate code is gzip/zlib).
2. For the hand-written ones, a strong model with `tools/oracle.py`, many tries; record what the
   compiler cannot emit (trapping `daddi`, hand-scheduled `movz` chains, `t5`-`t9` allocation).

## Seen so far (2026-10-17 workers)

| Address | What | Note |
|---|---|---|
| 0058a280, 0058a4a8, 0058a5f8, 0058a668, 0058ab08 | inflate: bit reader and main loop | borrow `s5`-`s7`, jump into each other; one function cut in pieces? gzip/zlib source |
| 0058ac20 | fragment | uses caller's `s3`-`s7` and `ra` |
| 0058b2b0, 0058b370 | syscall stub tables | `break` / `addiu $zero,n` pairs: check against `config/asm_functions.txt` |
| 0057f768 | soft-double divide | trapping `daddi`/`dsub`, `movz` chains, `t5`-`t9`; ~100 instructions off whatever the profile |
| 0057f3c0 | saturating double bits to u64 | fully if-converted `daddi`/`movz`/`movn` |
| 0057fa98 | `fixdfsi` | trapping `daddi`/`dsub`, branchless `movz` chains |
| 0057d1f0, 0057d2b8, 0057d380 | sin/cos kernels | EE accumulator ops (`adda.s`, `madda.s`, `madd.s`, `msub.s`) |
| 0057f188 | unrolled byte compare | looks hand-written |
| 0057f490, 0057f4f8 | long to double / long to float helpers | trapping `addi`/`daddi`, `$at`, t-registers, unscheduled: part of the soft-float library cluster |
| 00545a54 | MMI register-saving loop | `sq` saves of t0-t2/v1 and a t-register loop; C gives no `sq` |
| 005a4644 | hand-written MMI memchr | t-registers, unscheduled |
| 004ac034 | unaligned 64-byte copy | retail has an `sdl $t1,0xA7($a0)` whose offset no C source gives (looks like a typo in the original) |
| 004a7438 | fragment of the VU0 graphics code | keeps `ra` in `$t2` and returns with `jr $t2` |
| 004a74a0, 004a747c, 004a7454, 004a7890, 004a7844, 004a7a54, 004a7a00, 004a7988, 004a79b0, 004a79d8, 004ac400, 004a5f00 | libvu0 (`sceVu0*`): unit matrix, transpose matrix, sincos, ... | Opus (V2, oracle) 2026-10-18: hand-scheduled; `lui`/`addiu`/`sb` and `ld ra` sit between VU instructions that are scheduling barriers for ee-gcc 2.96; local-alloc gives `$v0` to the constant (priority 10000) over the base (3333). Probably Sony's libvu0, multi-instruction inline asm in the SDK source. |
| 004a7350 | hand-written assembly called by 004a7988 | `ori $t0,$t0,0x0`, fixed registers, same file as the 004a7438 fragment |
| 0012c250, 00232470, 00235ed0 (+ the other large static-init ctor/dtor functions, about 8 in all) | static initialisation of 70+ global objects, 5 words off | Opus (O3) 2026-10-19: one delay-slot decision. The guard of the object at +0x40 carries REG_BR_PROB 6001 (the NE heuristic); the original compiler saw a not-taken note there. In gcc-20001003 (predict.c, jump.c, ifcvt.c, reorg.c) a not-taken note can only come from a successor without successors, EQ of pointers, EQ (3999) or LT/LE against 0, and an inverted jump flips its note, so no arm swap, negation, pointer cast, real C++ globals, empty guard, throw() or profile moves it. Do not spend tries on source shape; what is left is a decision for the maintainer. Also: the dtor callee of another unit must not carry throw() (the original has bnel). |
| 005b2808 | SDK (ee-gcc2.9) handler install: `old = h.func; h.arg = arg; h.func = func; D_00889A80 = $gp` | opus-solo 2026-10-23: 2 of 40 off, build/drafts/func_005B2808.v2.c. The original's `sw $gp` sits in a branch delay slot; reorg never puts an asm insn in a delay slot, so the original read `$gp` through a global register variable (`register void *gp asm("$28")`), which tools/asm_policy.py refuses as register pinning. A one-instruction `asm("sw $gp, %0" : "=m"(...))` gives everything else; whether a global `$gp` variable is acceptable for SDK code is the owner's call. |

## Assembly-looking functions found 2026-10-23 (opus-solo), left open

Listed here instead of config/asm_functions.txt (they were added there briefly, then taken out under the
decision above). Evidence per group:

- **network crypto module 0x545a54-0x546ae0 (bignum add/sub/mul, an RC4 variant)** (18): `move` encoded as `or`, `sq` saves of `$a0`-`$a2`, `$t0`-`$t6` in first-use order with `$v0/$v1` unused, empty `jr` slots. 00545a54, 00545ac8, 00545b28, 00545b88, 00545bf0, 00545c58, 00545d7c, 00545eb8, 00545f30, 00545fc0, 00546038, 005460c8, 005464b0, 00546668, 00546830, 005468d0, 005469d0, 00546a60
- **SDK float/string helpers 0x57f238-0x57fbe0** (19): trapping `daddi`/`dsub`/`dadd`, `$at` as an arithmetic scratch, a MIPS I load-delay `nop` (the strcmp). 0057f238, 0057f2f8, 0057f360, 0057f3c0, 0057f418, 0057f470, 0057f480, 0057f768, 0057fa38, 0057fa48, 0057fa98, 0057faf8, 0057fb50, 0057fb88, 0057fb98, 0057f490, 0057f4f8, 0057f578, 0057f8b8
- **vector/MMI bodies** (55): each needs at least 3 distinct VU0/COP2/MMI instructions without a C operator (`por`/`pcpyld`/`pcpyud`/`plzcw`/`mtsab`/`qfsrv` not counted), i.e. more inline asm statements than asm_policy.py allows (counted with operands, so one inline helper used several times is not overcounted). 003e8438, 004a70e8, 004a6c58, 0049a6a0, 001fde68, 0049a4f8, 0049d580, 0049db08, 0049a360, 0049e780, 0049c140, 0049e918, 0049a200, 004ac118, 005a6900, 0056e2c0, 0056e170, 003e7f08, 003b8ea0, 001c1a50, 001fdd28, 00451238, 00492978, 003e3840, 00492ef0, 003b8530, 003e8790, 0049e2d8, 003e3ed0, 0049f1f8, 00496638, 003b7dd8, 004961b8, 0049d970, 003e2710, 004a6e20, 003d51b0, 0049d728, 0049dcb0, 00499d00, 0044dcc0, 00499948, 004522d8, 00456918, 003e32e8, 00568b40, 0049f170, 005692c0, 0056df58, 0056de38, 00454f40, 00498e48, 00455708, 001c1760, 001c1678
- **not code** (1): 00616f24 is 2800 bytes of a data table in .text (the words decode as `.word`/`tge`/`mfsa` noise); an inventory error rather than a function. 00616f24
- **int-to-float inline asm sequence** (1): `plzcw`/`andi`/`sra $at`/`or` around a call. 00578598

## Blocked on compiler-build codegen, not source (2026-11-07, deepseek-v4)

These have a source the permuter (`tools/permute.py`) drives to a small, **nonzero** score and cannot
close, because what remains is a decision of the compiler *build* we do not have, not of the C. That
was shown by exhaustive search (a dozen source shapes each, every `[compilers]` profile, the relevant
flags, and a permuter sweep), so re-attempting from source shape is not worth tries. Reported open.

| Address | Residual (original vs ours) | What was ruled out |
|---|---|---|
| 0058d140 | `(x>>4)*6`: original `mult $zero,$v1,$a0` + `mflo $v1` (product through HI/LO); ours `mult $v1,$v1,$a0` (R5900 3-operand, one instruction shorter). | ee-gcc 2.96 and 2.9-both-assemblers emit the 3-op form; `-march=` is rejected (ee-gcc is EE-hardcoded); no plain MIPS gcc is installed. Permuter plateau = exactly 60 (one reordering). *Partly useful:* a variable factor (`u16 six=6`) forces `mult` over strength-reduced shifts (4/8 → 6/7) — but that is a source note, not a match. |
| 004c5018 | loop test rotated to the bottom (`bltzl` back-edge) where retail keeps a top test (`bgez` exit + `b` back); retail re-reads `*p` twice (`lhu $v0` test, `lhu $a0` arg) and returns `n` from two sites; ours CSEs one `lhu` and merges the return. | nine loop shapes (`while`, `if(*)while`, `for(;;)`, early-return, `do{}while(1)`, compound `*p && f(*p++)<0`, explicit `goto`, double-`return n`); `nogcse`/`nsa` markers. gcc rotates them all. Best 11/19. |
| 00549258 | result kept in `$a0` where retail uses `$a3`; because of that gcc folds `r+2` into the `lwl`/`lwr` offset and fills the `beq` delay with the epilogue `ld $s0` (forcing `beql`) instead of materialising `a0=r+2` (plain `beqz`). | packed struct, `u8*`, `u32*` temporaries, `throw()` on the callee, `volatile`, `nogcse`/`nsa`. The allocator never moves. Best 10/28. |

**Permuter metric (why a "10/28" draft scores ~1150 there):** the permuter scores penalty
edit-distance (INSERTION/DELETION 100, REORDERING 60, REGALLOC 5) over the full alignment, not the
pairwise instruction diff `match.py` prints, so a draft that is 10/28 pairwise-different *plus* a
reordering and a register swap legitimately scores ~1150. That is the scorer working, not a bug. A
broad sweep of the 40 best `cpu_solve` near-misses in `build/queue.json` all plateaued nonzero (best
60), so the ~632 open functions are these compiler-build residuals, not source-shape near misses.

**Toolchain nit:** `match.gnu_asm` prints callee symbols as 8 hex digits (`func_00549130`) while most
sources spell them 6 (`func_549130`). This costs one regalloc point on the permuter's `jal` line (it
can never reach a perfect 0 with a mismatched symbol) but is harmless for `match.py`, which compares
opcodes only; a future cleanup could normalise the symbol spelling in `match.gnu_asm`.

**Update 2026-11-10 (deepseek-v4):** the decision oracle is recovered (gdb 13.1 reads STABS on a
Debian 12 host; no system-wide gdb change) and `oracle.py climb` matched 0055d778 from this pool
by composing source edits that make the compiler reproduce the original's order (19 -> 6 -> 0
decision units). So the compiler-*forcing* + search path — not source-shape rewriting — is the way
forward for these: `oracle.py measure` now classifies the pool (of 297 measured m2c drafts, ~7 are
logic-complete) and `climb`/`sched`/`aim` are usable. A campaign is under way; see
build/phase3_progress.md and the PR for the running tally.
