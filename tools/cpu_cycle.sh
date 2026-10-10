#!/bin/sh
# One CPU-only cycle over the small and medium functions (no language model): every free tool in
# turn, then the full build. Prints how many functions the cycle added, so a watch can stop when a
# cycle no longer pays. Usage: sh tools/cpu_cycle.sh [permute_minutes] [jobs]
# Log: build/auto/cpu_cycle.out. The first cycle drafts every small function with m2c; later
# cycles retry the failures with the type context the matched sources have added since.
cd "$(dirname "$0")"
mkdir -p ../build/auto
log=../build/auto/cpu_cycle.out
mins=${1:-120}
jobs=${2:-2}
count() { python -c "import autoloop; print(len(autoloop.done_addrs()))"; }
say() { echo "== $* $(date +%H:%M)" >> $log; }
start=$(count); say "cycle start: $start functions"
# first drafts for every small function not drafted yet (resumable), then the retries with the
# type context the matched sources have added since
python cpu_solve.py --max-bytes 512 --jobs $jobs 2>&1 | tail -1 >> $log; say "m2c first drafts"
python cpu_solve.py --retry --context types --context-only --max-bytes 512 --jobs $jobs 2>&1 | tail -1 >> $log; say "m2c with type context"
python fragments.py apply --jobs $jobs --max-differ 12 2>&1 | tail -1 >> $log; say "fragments"
python near_fix.py --jobs $jobs 2>&1 | tail -1 >> $log; say near_fix
python dedup_all.py --jobs $jobs 2>&1 | tail -1 >> $log; say copies
timeout $((mins * 60)) python permute_cpu.py --seconds 90 --jobs $jobs 2>&1 | tail -1 >> $log; say permuter
python dedup_all.py --jobs $jobs 2>&1 | tail -1 >> $log
python build.py --keep-going --jobs $jobs > ../build/auto/build_full.log 2>&1
grep -E "^\.text|^\.data|linked$" ../build/auto/build_full.log >> $log
end=$(count); say "cycle end: $end functions (+$((end - start)))"
