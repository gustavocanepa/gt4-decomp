#!/usr/bin/env bash
# One-time setup of the Linux side (native Linux or WSL): compiler, MIPS binutils, decomp-permuter.
# Usage: bash tools/setup_linux.sh
set -e
base="$HOME/.local/share/gt4"
mkdir -p "$base"

echo "== packages (MIPS binutils, 32-bit libc for the compiler, python venv, cpp for the permuter)"
sudo dpkg --add-architecture i386 2>/dev/null || true
sudo apt-get update -qq
sudo apt-get install -y -qq binutils-mips-linux-gnu libc6:i386 python3-venv cpp >/dev/null

echo "== compilers (ee-gcc 2.96 and every profile project.toml names; decomp.me builds)"
python3 "$(dirname "$0")/install_compilers.py"
"$base/ee-gcc2.96/bin/ee-gcc" --version | head -1

echo "== python venv (permuter modules, splat)"
if [ ! -x "$base/venv/bin/python" ]; then python3 -m venv "$base/venv"; fi
"$base/venv/bin/pip" install -q toml Levenshtein pynacl "splat64[mips]"

echo "== decomp-permuter"
if [ ! -d "$base/decomp-permuter" ]; then
    git clone -q --depth 1 https://github.com/simonlindholm/decomp-permuter "$base/decomp-permuter"
fi
# the permuter runs in the venv that holds its modules; a failure here stops the script
if "$base/venv/bin/python" "$base/decomp-permuter/permuter.py" --help >/dev/null; then echo "permuter ok"; else
    echo "permuter check failed: its modules are not importable in $base/venv" >&2; exit 1; fi

echo "== splat"
"$base/venv/bin/python" -c "import splat; print('splat', splat.__version__)"
