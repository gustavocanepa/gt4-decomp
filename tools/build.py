#!/usr/bin/env python3
"""Full build: link every matched function at its original address into one ELF and compare the
result with the original executable, byte for byte.

    build.py [--jobs 4] [--keep-going]

Every src/func_ADDR.* is compiled with the game's compiler and linked, with the real addresses of
everything it references, into a single ELF. Code that is not decompiled yet is taken from your own
executable (`.incbin` of the original bytes, never committed), so the image is complete from day
one and shrinks to pure source as functions are matched. The build passes when both loaded segments
hash the same as the original's.

This closes the gap left by match.py, which compares one function at a time and, for words that
carry a relocation, only the opcode and registers: here every relocation is resolved by the linker,
so a function that points at the wrong global fails.

Outputs (all in build/full/): gt4.elf, report.json (per-function status) and, on the screen, a
summary plus every function that does not survive the link.
"""
import argparse
import csv
import glob
import hashlib
import json
import os
import re
import subprocess
import sys

import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "full")
WSL_DIR = "$HOME/.local/share/gt4/full"
ELF = os.path.join(ROOT, "orig", "SCUS-97328", "CORE.GT4.elf")
SYMBOL = re.compile(r"^(?:func|D|jtbl|sub|data)_([0-9A-Fa-f]{8})(?:__.*)?$")  # C++ mangling allowed
# Sections a compiled function may bring along without changing the image.
HARMLESS = {".text", ".reginfo", ".mdebug", ".mdebug.eabi64", ".comment", ".pdr", ".gnu.attributes",
            ".note.GNU-stack", ".eh_frame", ".gcc_except_table"}


# gcc 2.96 puts a local symbol for .eh_frame after the globals, which modern ld rejects; the image
# carries no debug or unwind data from these objects, so both are dropped after compiling.
STRIP = "-R .eh_frame -R .rel.eh_frame -R .mdebug -R .mdebug.eabi64"


def to_wsl(path):
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def wsl(script, check=True):
    """Run a bash script in WSL and return its stdout."""
    path = os.path.join(OUT, "step.sh")
    open(path, "w", newline="\n").write("set -e\n" + script)
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    res = subprocess.run(["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(path)],
                         capture_output=True, text=True, env=env)
    if check and res.returncode:
        sys.exit(f"WSL step failed:\n{res.stdout[-3000:]}\n{res.stderr[-3000:]}")
    return res.stdout


def segments():
    """The original's loaded segments: [(vaddr, file offset, size)]."""
    import struct
    data = open(ELF, "rb").read()
    phoff, = struct.unpack_from("<I", data, 28)
    phnum, = struct.unpack_from("<H", data, 44)
    out = []
    for i in range(phnum):
        p_type, off, vaddr, _, filesz, _, _, _ = struct.unpack_from("<8I", data, phoff + 32 * i)
        if p_type == 1:
            out.append((vaddr, off, filesz))
    return data, out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--keep-going", action="store_true", help="exit 0 even if the image differs")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)

    elf, segs = segments()
    (text_addr, text_off, text_size), (data_addr, data_off, data_size) = segs
    open(os.path.join(OUT, "text.bin"), "wb").write(elf[text_off:text_off + text_size])
    open(os.path.join(OUT, "data.bin"), "wb").write(elf[data_off:data_off + data_size])

    sources = {}
    for path in glob.glob(os.path.join(ROOT, "src", "func_*.*")):
        m = re.match(r"func_([0-9A-Fa-f]{8})\.(c|cpp)$", os.path.basename(path))
        if m:
            sources[int(m.group(1), 16)] = path
    starts = set(sources)
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            starts.add(int(row["address"], 16))
    starts = sorted(s for s in starts if text_addr <= s < text_addr + text_size)

    # 1. Compile every source on the Linux side, four at a time.
    print(f"compiling {len(sources)} functions...", flush=True)
    wsl(f"""
d="{WSL_DIR}"; mkdir -p "$d/src" "$d/obj"
cp -u {to_wsl(os.path.join(ROOT, 'src'))}/func_* "$d/src/"
cd "$d/src"
for f in func_*; do o="../obj/${{f%.*}}.o"; [ "$o" -nt "$f" ] || echo "$f"; done > ../todo.txt
cat ../todo.txt | xargs -r -P{a.jobs} -I{{}} bash -c 'f={{}}; o="../obj/${{f%.*}}"; {project.compiler_command()} "$f" -o "$o.raw" 2>"$o.err" && mips-linux-gnu-objcopy {STRIP} --wildcard -G "${{f%.*}}*" "$o.raw" "$o.o"; rm -f "$o.raw"; true'
""")
    info = wsl(f"""
cd "{WSL_DIR}/obj"
for o in func_*.o; do
  echo "@ $o"; mips-linux-gnu-readelf -SW "$o" | awk '$1 ~ /^\\[/ && $2 ~ /^\\./ {{print "S", $2, $6}} $1 ~ /^\\[/ && $3 ~ /^\\./ {{print "S", $3, $7}}'
  mips-linux-gnu-nm -u "$o" | awk '{{print "U", $2}}'
done
""")

    # 2. Decide, per function, whether its object can go into the image.
    status, objects = {}, {}
    cur = None
    parsed = {}
    for line in info.splitlines():
        if line.startswith("@ "):
            cur = int(line[7:15], 16)
            parsed[cur] = {"sections": {}, "undefined": []}
        elif line.startswith("S ") and cur is not None:
            _, name, size = line.split()
            parsed[cur]["sections"][name] = int(size, 16)
        elif line.startswith("U ") and cur is not None:
            parsed[cur]["undefined"].append(line.split()[1])
    undefined = set()
    for i, addr in enumerate(starts):
        if addr not in sources:
            continue
        nxt = starts[i + 1] if i + 1 < len(starts) else text_addr + text_size
        p = parsed.get(addr)
        if p is None or ".text" not in p["sections"]:
            status[addr] = "does not compile"
            continue
        extra = {k: v for k, v in p["sections"].items()
                 if v and k not in HARMLESS and not k.startswith(".rel") and not k.endswith("tab")}
        bad_syms = [s for s in p["undefined"] if not SYMBOL.match(s)]
        if extra:
            status[addr] = "brings its own data: " + ", ".join(sorted(extra))
        elif bad_syms:
            status[addr] = "references unnamed-address symbols: " + ", ".join(bad_syms[:3])
        elif p["sections"][".text"] > nxt - addr:
            status[addr] = f"too long ({p['sections']['.text']} bytes, room for {nxt - addr})"
        else:
            objects[addr] = p["sections"][".text"]
            undefined.update(p["undefined"])
            status[addr] = "linked"

    # 3. Linker script: objects at their addresses, the original's bytes in between.
    gaps, order = [], []
    pos = text_addr
    for addr in sorted(objects):
        if addr > pos:
            gaps.append((pos, addr - pos))
            order.append(("gap", pos))
        order.append(("obj", addr))
        pos = addr + objects[addr]
    if pos < text_addr + text_size:
        gaps.append((pos, text_addr + text_size - pos))
        order.append(("gap", pos))
    asm = [".set noreorder"]
    for start, size in gaps:
        asm += [f'.section .text.g{start:08x}, "ax"', ".balign 4",
                f'.incbin "text.bin", 0x{start - text_addr:x}, 0x{size:x}']
    asm += ['.section .data.orig, "aw"', ".balign 4", '.incbin "data.bin"']
    open(os.path.join(OUT, "gaps.s"), "w", newline="\n").write("\n".join(asm) + "\n")

    defined = {f"func_{a:08X}" for a in objects}
    syms = []
    for s in sorted(undefined):  # PROVIDE never overrides a real definition
        syms.append(f"PROVIDE({s} = 0x{SYMBOL.match(s).group(1)});")
    body = []
    for kind, addr in order:
        if kind == "gap":
            body.append(f"    gaps.o(.text.g{addr:08x})")
        else:
            body.append(f"    obj/func_{addr:08X}.o(.text)")
    ld = ("\n".join(syms) + "\nSECTIONS\n{\n"
          f"  .text 0x{text_addr:x} : SUBALIGN(4)\n  {{\n" + "\n".join(body) + "\n  }\n"
          f"  .data 0x{data_addr:x} : SUBALIGN(4) {{ gaps.o(.data.orig) }}\n"
          "  /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.eh_frame) *(.gcc_except_table) *(*) }\n}\n")
    open(os.path.join(OUT, "link.ld"), "w", newline="\n").write(ld)

    # 4. Link and compare.
    print(f"linking {len(objects)} functions...", flush=True)
    wsl(f"""
d="{WSL_DIR}"
cp {to_wsl(OUT)}/text.bin {to_wsl(OUT)}/data.bin {to_wsl(OUT)}/gaps.s {to_wsl(OUT)}/link.ld "$d/"
cd "$d"
mips-linux-gnu-as {project.CONFIG['cpu']['as_flags']} gaps.s -o gaps.o
mips-linux-gnu-ld -EL -e 0x100008 -T link.ld -o gt4.elf --no-check-sections
mips-linux-gnu-objcopy -O binary --only-section=.text gt4.elf built_text.bin
mips-linux-gnu-objcopy -O binary --only-section=.data gt4.elf built_data.bin
cp gt4.elf built_text.bin built_data.bin {to_wsl(OUT)}/
""")
    built_text = open(os.path.join(OUT, "built_text.bin"), "rb").read()
    built_data = open(os.path.join(OUT, "built_data.bin"), "rb").read()
    orig_text = elf[text_off:text_off + text_size]
    orig_data = elf[data_off:data_off + data_size]

    failed = []
    for addr, size in objects.items():
        o = addr - text_addr
        if built_text[o:o + size] != orig_text[o:o + size]:
            status[addr] = "differs after linking"
            failed.append(addr)
    text_ok = built_text == orig_text
    data_ok = built_data == orig_data
    sha = lambda b: hashlib.sha1(b).hexdigest()

    linked_bytes = sum(objects[a] for a in objects if status[a] == "linked")
    report = {"text_sha1": sha(built_text), "text_matches": text_ok, "data_matches": data_ok,
              "functions": {f"{a:08x}": s for a, s in sorted(status.items())},
              "linked_functions": sum(s == "linked" for s in status.values()),
              "linked_code_bytes": linked_bytes, "code_bytes": text_size,
              "sizes": {f"{a:08x}": s for a, s in sorted(objects.items())}}
    json.dump(report, open(os.path.join(OUT, "report.json"), "w"), indent=1)

    counts = {}
    for s in status.values():
        key = s.split(":")[0].split(" (")[0]
        counts[key] = counts.get(key, 0) + 1
    print(f".text {'OK' if text_ok else 'DIFFERS'}  sha1 {sha(built_text)} (original {sha(orig_text)})")
    print(f".data {'OK' if data_ok else 'DIFFERS'}")
    for k, v in sorted(counts.items(), key=lambda kv: -kv[1]):
        print(f"  {v:5d}  {k}")
    print(f"code from source: {linked_bytes} of {text_size} bytes ({linked_bytes / text_size:.2%})")
    for addr, s in sorted(status.items()):
        if s != "linked":
            print(f"  {addr:08x}  {s}")
    sys.exit(0 if (text_ok and data_ok) or a.keep_going else 1)


if __name__ == "__main__":
    main()
