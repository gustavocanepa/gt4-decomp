#!/usr/bin/env bash
# Split the executable with splat (Linux/WSL): assembly for every function, data, linker script,
# all under build/splat/ (generated from your own copy of the game, never committed).
# Usage: bash tools/splat.sh        (after tools/core2elf.py; splat lives in a venv made by setup_linux.sh)
set -e
cd "$(dirname "$0")/.."
mkdir -p build/splat
mips-linux-gnu-objcopy -O binary --gap-fill=0x00 orig/SCUS-97328/CORE.GT4.elf build/splat/CORE.GT4.rom
touch config/symbol_addrs.txt
"$HOME/.local/share/gt4/venv/bin/python" -m splat split config/gt4.yaml "$@"
