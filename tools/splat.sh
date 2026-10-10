#!/usr/bin/env bash
# Split the executable with splat (Linux/WSL): assembly for every function, data, linker script,
# all under build/splat/ (generated from your own copy of the game, never committed).
# Usage: bash tools/splat.sh        (after tools/core2elf.py; splat lives in a venv made by setup_linux.sh)
# The ELF, the splat configuration and the ROM name come from [game] in project.toml.
set -e
cd "$(dirname "$0")/.."
read -r elf config basename < <(python3 -c 'import tomllib; g = tomllib.load(open("project.toml", "rb"))["game"]; print(g["elf"], g["splat_config"], g["basename"])')
mkdir -p build/splat
mips-linux-gnu-objcopy -O binary --gap-fill=0x00 "$elf" "build/splat/$basename.rom"
touch config/symbol_addrs.txt
"$HOME/.local/share/gt4/venv/bin/python" -m splat split "$config" "$@"
