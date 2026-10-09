#!/usr/bin/env python3
"""Move string constants of matched functions from `extern char D_XXXXXXXX[]` into the source as
the literals they were, so that tools/build.py places the object's own .rodata at its original
address (and tools/report.py counts it as data from source).

    rodata_to_source.py [--jobs N] [--limit N] [--write] [ADDR ...]

A function qualifies when every string it declares this way
  - is a NUL-terminated printable string (2+ characters, after a NUL) in the original image,
  - the literal compiles where the extern was used, without a cast (a `char` object assigned to a
    `void *` or returned as an object pointer is some other object, not a literal),
  - after the rewrite the object brings only .rodata (no .rel.rodata), its %hi/%lo references to
    that .rodata all agree on one original address, and the original holds the object's .rodata
    bytes there (the rule of tools/build.py),
  - no other function's instructions reference any address inside that placed range, and
  - tools/match.py check still says MATCH.
Without --write nothing is changed; with it the qualifying sources are rewritten and listed in
build/auto/rodata_moved.txt.
"""
import argparse
import json
import os
import re
import struct
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import match  # noqa: E402
import project  # noqa: E402

ROOT = project.ROOT
TMP = os.path.join(ROOT, "build", "auto", "rodata_tmp")
OUT_LIST = os.path.join(ROOT, "build", "auto", "rodata_moved.txt")
HARMLESS = {".text", ".reginfo", ".mdebug", ".mdebug.eabi64", ".comment", ".pdr", ".gnu.attributes",
            ".note.GNU-stack", ".eh_frame", ".gcc_except_table"}
DECL = re.compile(r'^[ \t]*extern\s+(?:"C"\s+)?(?:const\s+)?(?:char|s8|u8|unsigned char|signed char)\s+'
                  r'(D_[0-9A-F]{8})\s*(\[\s*\d*\s*\])?\s*;[ \t]*\r?\n', re.M)
# Opcodes whose 16-bit immediate is the %lo of an address with rs as base.
LO_OPS = {0x09, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F, 0x1A, 0x1B}


def sext(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def sections_of(path):
    """{name: (bytes, sh_type)} of an ELF32 object."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    base = secs[shstrndx][4]
    out = {}
    for s in secs:
        name = d[base + s[0]:d.index(b"\0", base + s[0])].decode()
        if name:
            out[name] = d[s[4]:s[4] + s[5]] if s[1] != 8 else b"\0" * s[5]
    return out


class Image:
    def __init__(self):
        entry, secs = project.load_image()
        (self.text_addr, self.text), = [(a, b) for a, b in secs if a <= entry < a + len(b)]
        others = [(a, b) for a, b in secs if a != self.text_addr]
        self.data_addr, self.data = max(others, key=lambda s: len(s[1]))
        self.refs = self._xrefs()

    def in_data(self, a):
        return self.data_addr <= a < self.data_addr + len(self.data)

    def _xrefs(self):
        """{data address: set of instruction addresses} from lui/%lo pairs (conservative)."""
        refs = {}
        n = len(self.text) // 4
        words = struct.unpack_from(f"<{n}I", self.text)
        for i, w in enumerate(words):
            if w >> 26 != 0x0F:
                continue
            reg, hi = (w >> 16) & 31, (w & 0xFFFF) << 16
            for j in range(i + 1, min(n, i + 64)):
                x = words[j]
                if x >> 26 in LO_OPS and (x >> 21) & 31 == reg:
                    t = (hi + sext(x)) & 0xFFFFFFFF
                    if self.in_data(t):
                        refs.setdefault(t, set()).add(self.text_addr + 4 * j)
                        refs.setdefault(t, set()).add(self.text_addr + 4 * i)
                if x >> 26 == 0x0F and (x >> 16) & 31 == reg:
                    break
        return refs

    def cstring(self, a):
        o = a - self.data_addr
        end = self.data.find(b"\0", o)
        return None if end < 0 or end - o > 4096 else self.data[o:end]


def literal(b):
    out = []
    for c in b:
        ch = chr(c)
        if ch in '"\\?':
            out.append("\\" + ch)
        elif 0x20 <= c < 0x7F:
            out.append(ch)
        else:
            out.append(f"\\{c:03o}")
    return '"' + "".join(out) + '"'


def rewrite(text, img, cast=False):
    """The source with each `extern char D_X[]` string replaced by its literal (as a `char *` when
    cast: what the extern's type gave), or (None, why)."""
    decls = list(DECL.finditer(text))
    if not decls:
        return None, "no string externs"
    new = text
    for m in decls:
        name, is_array = m.group(1), bool(m.group(2))
        addr = int(name[2:], 16)
        if not img.in_data(addr):
            return None, f"{name} outside data"
        s = img.cstring(addr)
        if s is None or len(s) < 2 or any(not (0x20 <= c < 0x7F or c in (9, 10, 13)) for c in s):
            return None, f"{name} not a printable string"
        if img.data[addr - img.data_addr - 1] != 0:
            return None, f"{name} does not start a string"
        new = new.replace(m.group(0), "", 1)
    for m in decls:
        name, is_array = m.group(1), bool(m.group(2))
        if not re.search(rf"\b{name}\b", new):
            continue  # declared twice, already replaced
        lit = literal(img.cstring(int(name[2:], 16)))
        if cast:
            lit = f"((char *){lit})"
        if is_array:
            if re.search(rf"&\s*{name}\b|\bsizeof\b", new):
                return None, f"{name}: address-of an array or sizeof"
            new = re.sub(rf"\b{name}\b", lambda _: lit, new)
        else:
            new = re.sub(rf"\(\s*(?:const\s+)?char\s*\*\s*\)\s*&\s*{name}\b", lambda _: lit, new)
            new = re.sub(rf"&\s*{name}\b", lambda _: lit, new)
            if re.search(rf"\b{name}\b", new):
                return None, f"{name}: used as a value"
    return new, None


def placement(obj, addr, img):
    """(base, size) where tools/build.py would put the object's .rodata, or (None, why)."""
    secs = sections_of(obj)
    sizes = {k: len(v) for k, v in secs.items()}
    extra = {k for k, v in sizes.items() if v and k not in HARMLESS and not k.startswith(".rel")
             and not k.endswith("tab") and k != ".shstrtab"}
    if extra != {".rodata"} or sizes.get(".rel.rodata"):
        return None, f"sections {sorted(extra)}"
    rodata = secs[".rodata"]
    blob, srelocs, _ = match.read_object(obj, want_symbols=True)
    mine = lambda off: struct.unpack_from("<I", blob, off)[0]
    orig = lambda a: struct.unpack_from("<I", img.text, a - img.text_addr)[0]
    bases = set()
    offs = sorted(srelocs)
    for n, off in enumerate(offs):
        rtype, sym = srelocs[off][0], srelocs[off][1]
        if sym != ".rodata" or rtype != match.R_MIPS_HI16:
            continue
        lo = next((o for o in offs[n + 1:] if srelocs[o][1] == ".rodata" and srelocs[o][0] == match.R_MIPS_LO16), None)
        if lo is None:
            return None, "hi without lo"
        addend = ((mine(off) & 0xFFFF) << 16) + sext(mine(lo))
        target = ((orig(addr + off) & 0xFFFF) << 16) + sext(orig(addr + lo))
        bases.add(target - addend)
    if len(bases) != 1:
        return None, f"{len(bases)} bases"
    base = bases.pop()
    o = base - img.data_addr
    if not (0 <= o and o + len(rodata) <= len(img.data) and img.data[o:o + len(rodata)] == rodata):
        return None, "bytes differ at the original place"
    return (base, len(rodata)), None


def judge(addr, path, img, span):
    text = open(path, encoding="utf-8").read()
    for m in DECL.finditer(text):  # cheap first: a string another function uses is not this one's
        a = int(m.group(1)[2:], 16)
        if any(not addr <= ins < addr + span for ins in img.refs.get(a, ())):
            return addr, None, f"{m.group(1)} also referenced elsewhere"
    # No cast fallback: a "string" that only compiles as `(char *)"..."` (assigned to a void *,
    # returned as an object pointer) is some other object whose bytes happen to look like text.
    res = judge_text(addr, path, img, span, text, False)
    if res[2] == "does not compile" and all(type_name_use(text, m.group(1)) for m in DECL.finditer(text)):
        res = judge_text(addr, path, img, span, text, True)
    return res


# The type_info constructors (__si_type_info / __user_type_info): their second argument is the
# type's name, a string the compiler emitted into the __tf function's own .rodata. Their sources
# declare it void *, so that literal alone may be passed as a `char *`.
TYPE_INFO_CTORS = ("func_005BFB68", "func_005BFB88")


def type_name_use(text, name):
    uses = len(re.findall(name + r"(?!\w)", text)) - 1  # minus the declaration
    calls = sum(len(re.findall(c + r"\s*\([^,;()]+,\s*" + name + r"\s*[,)]", text)) for c in TYPE_INFO_CTORS)
    return uses > 0 and uses == calls


def judge_text(addr, path, img, span, text, cast):
    new, why = rewrite(text, img, cast)
    if new is None:
        return addr, None, why
    os.makedirs(TMP, exist_ok=True)
    tmp = os.path.join(TMP, os.path.basename(path))
    with open(tmp, "w", encoding="utf-8", newline="") as f:
        f.write(new)
    try:
        try:
            obj = match.compile_c(tmp)
        except SystemExit:
            return addr, None, "does not compile"
        try:
            place, why = placement(obj, addr, img)
        finally:
            os.remove(obj)
        if place is None:
            return addr, None, why
        base, size = place
        lo, hi = addr, addr + span
        for a in range(base, base + size):
            for ins in img.refs.get(a, ()):
                if not lo <= ins < hi:
                    return addr, None, f"0x{a:08x} also referenced at 0x{ins:08x}"
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:08x}", tmp],
                             capture_output=True, text=True, cwd=ROOT)
        if res.returncode != 0 or "MATCH" not in res.stdout:
            return addr, None, "no longer matches"
        return addr, (new, base, size), None
    finally:
        if os.path.exists(tmp):
            os.remove(tmp)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addrs", nargs="*")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--write", action="store_true")
    args = ap.parse_args()
    report = json.load(open(os.path.join(ROOT, "build", "full", "report.json")))
    linked = {int(a, 16) for a, s in report["functions"].items() if s == "linked"}
    sizes = {int(a, 16): v for a, v in report["sizes"].items()}
    srcs = project.sources()
    img = Image()
    if args.addrs:
        todo = [int(a, 16) for a in args.addrs]
    else:
        todo = []
        for a in sorted(linked & set(srcs)):
            if f"{a:08x}" in report["data_sizes"]:
                continue
            if DECL.search(open(srcs[a], encoding="utf-8", errors="replace").read()):
                todo.append(a)
    if args.limit:
        todo = todo[:args.limit]
    print(f"{len(todo)} candidates", flush=True)
    done, taken = [], []
    with ThreadPoolExecutor(max(1, min(2, args.jobs))) as pool:
        for addr, ok, why in pool.map(lambda a: judge(a, srcs[a], img, sizes.get(a, 0)), todo):
            if ok is None:
                print(f"{addr:08x} skip: {why}", flush=True)
                continue
            new, base, size = ok
            if any(base < e and b < base + size for b, e in taken):
                print(f"{addr:08x} skip: overlaps another moved function's .rodata", flush=True)
                continue
            taken.append((base, base + size))
            done.append((addr, size))
            print(f"{addr:08x} OK: {size} bytes at 0x{base:08x}", flush=True)
            if args.write:
                with open(srcs[addr], "w", encoding="utf-8", newline="") as f:
                    f.write(new)
                with open(OUT_LIST, "a", encoding="utf-8") as f:
                    f.write(os.path.relpath(srcs[addr], ROOT).replace("\\", "/") + "\n")
    print(f"{len(done)} functions, {sum(s for _, s in done)} bytes of .rodata moved into source"
          + ("" if args.write else " (dry run)"))


if __name__ == "__main__":
    main()
