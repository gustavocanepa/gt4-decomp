# Who works on what (2026-11-25)

- octavioCuatrochio takes the big plain C/C++ functions (over about 1 KB). The project's own workers
  (`tools/swarm.py assign ... --max-bytes 1024`) stay under that size and skip his areas. A
  contributor who wants specific addresses reserved says so in a PR or issue.
- The VU0/MMI and hand-written functions stay in `knowledge/deferred-to-last.md`: no inline assembly
  in the repo, so they remain open until a C/C++ source reproduces the bytes.
- Every PR is merged with a merge commit (authorship is kept) and proved by a full build of the
  merged HEAD (`.text` and `.data` hashes of the original) before the README numbers are published.
