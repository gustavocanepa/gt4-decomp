# Contributing

Thanks for helping. The goal is C++ source that compiles, with the original compiler, to exactly
the instructions of `CORE.GT4`. Only exact matches are merged.

## Ground rules

- **Never commit game data**: no disc images, no `CORE.GT4`, no extracted files, no dumps of the
  game's code or data. `.gitignore` already excludes `orig/*` and `build/`.
- Everything in the repository is in English.
- A function is accepted only when `python tools/match.py check ADDR FILE` prints `MATCH`.

## Getting started

Follow **Setup** in [README.md](README.md). Then pick work in one of these ways:

1. **Match a function by hand.** Take an unmatched address from `build/functions.csv` (functions
   without a `src/func_XXXXXXXX.*` file), look at it with `python tools/match.py asm ADDR`, write
   `src/func_ADDR.cpp` and run `python tools/match.py check ADDR src/func_ADDR.cpp`. When it
   matches, run `python tools/dedup.py apply ADDR` to settle its exact copies too.
2. **Run the guided queue** (works for humans and AI agents alike):
   ```sh
   python tools/agent_step.py fill 300        # queue the smallest unmatched functions
   python tools/agent_step.py claim 1         # take one
   python tools/agent_step.py prompt ADDR     # rules, original asm, m2c draft, solved examples
   python tools/agent_step.py try ADDR FILE   # judge; on MATCH it is saved to src/
   python tools/agent_step.py giveup ADDR 4   # record a hard one as deferred
   ```
3. **Finish near misses** with the permuter: `python tools/permute_deferred.py`.
4. **Hard functions**: deferred ones (see `python tools/autoloop.py report`) and the larger ones
   that need shared code reconstructed first (STL templates, the reference-counted string class).
5. **Understanding**: naming functions, recovering structs and classes, documenting idioms in
   [`knowledge/`](knowledge/). A new compiler rule that explains a family of mismatches is worth
   more than many single matches.

## Pull requests

- One topic per PR; matched functions can be batched.
- Say how the functions were produced (by hand, permuter, AI-assisted) in the description.
- Make sure `match.py check` passes for every file you add or change.
