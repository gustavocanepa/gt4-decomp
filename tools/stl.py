#!/usr/bin/env python3
"""SGI STL instantiations: the library region holds gcc 2.96's own STL (include/stl, the headers of
the 2000-10-03 libstdc++ v2, THIRD_PARTY.md) instantiated for the game's types. One member of a
container gives its element types away (node size, type_info getter, key compare, copy
constructor); the same template instantiated for those types with the game's allocator and
string then reproduces every out-of-line member of that container.

    stl.py try ADDR [-m NAME]  deduce the tree type from the _M_insert at ADDR (or a member whose
                               tree is known), instantiate every member (or just NAME), find the
                               function each one is in the image, judge it, keep it on MATCH
    stl.py scan                every _M_insert in the image: deduce its tree, solve all members
    stl.py types               the tree types found so far
    stl.py members             the members the tool instantiates

Deduction (rb-tree _M_insert): the key type from the compare function it calls, the node size from
the allocation, the type_info getter from the call before it, the mapped type from how the value
is copied into the node (an out-of-line copy constructor, or an inline word/8-byte copy).
Sources are compiled with `/* compiler: ee-gcc2.96-stl */` (project.toml: the STL headers on the
include path, -fno-strict-aliasing as the library was built, -fno-implicit-templates so the object
holds only the member instantiated explicitly). A member that calls other instantiations refers to
them by their gcc 2.96 mangled names: on a MATCH those names get the addresses the original calls
at the same offsets, recorded in config/stl_symbols.txt (tools/symbols.py reads it), so the judge
and the build resolve them exactly. Callees the instantiation cannot know (a mapped type's
destructor) start as placeholders and are read from the matching function the same way.
"""
import argparse
import csv
import os
import re
import struct
import subprocess
import sys

import match
import project
import symbols

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "stl")
STL_SYMBOLS = os.path.join(ROOT, "config", "stl_symbols.txt")
COMPILER = "ee-gcc2.96-stl"

# key compare function -> (type name, Rep::clone, Rep::operator delete, heap name getter): the
# key is a libstdc++ v2 basic_string (knowledge/gt4.md); Str2 is a second instantiation of it
# (another allocator; its release is not known yet, so members that destroy keys stay open)
KEYS = {0x5C2A50: ("Str", 0x5C2560, 0x326798, 0x5C11A8), 0x608D98: ("Str2", 0x5D2B58, None, None)}
# allocate function -> (style, deallocate): "tagged" is allocate(size, 4, typeid(T).name()),
# "plain" is allocate(0x10, size) with no type_info
ALLOCS = {0x326750: ("tagged", 0x326798), 0x575E60: ("plain", 0x575DA0)}
STR_HEAP = 0x5C11A8
R_MIPS_26 = 4
LIBRARY_START = 0x596FA0  # where the library code begins (knowledge/gt4.md)
NEIGHBOURHOOD = 0x3000    # how far from its tree's other members a shared-code member may sit


class Spec:
    """One rb-tree instantiation: _Rb_tree<Key, pair<const Key, Mapped>, _Select1st, less<Key>, GameAlloc>."""

    def __init__(self, key, node_size, tf, alloc, mapped_kind, mapped_size, ctor=None, dtor=None, at=0):
        self.key = key
        self.at = at  # the _M_insert the tree was deduced from
        self.node_size = node_size
        self.tf = tf
        self.alloc = alloc
        self.mapped_kind = mapped_kind  # "ctor" (out-of-line copy constructor), "pod", or "key" (a string too)
        self.mapped_size = mapped_size
        self.ctor = ctor
        self.dtor = dtor  # None until a member that destroys values is matched

    @property
    def mapped(self):
        if self.mapped_kind == "key":
            return self.key
        if self.mapped_kind == "ctor":
            return f"Val_{self.ctor:08X}"
        return f"Pod{self.mapped_size}_{self.tf or self.at:08X}"  # one name per tree

    def describe(self):
        return (f"map<{self.key}, {self.mapped}> node {self.node_size:#x}"
                + (f" type_info func_{self.tf:08X}" if self.tf else f" allocator func_{self.alloc:08X}")
                + (f" dtor func_{self.dtor:08X}" if self.dtor else ""))


# ---------------------------------------------------------------- reading the original

def instructions(addr):
    """[(vram, word, mnemonic, operands)] of the function at addr."""
    out = []
    for line in match.gnu_asm(addr).splitlines():
        m = re.match(r"/\* ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S+)\s*(.*)", line)
        if m:
            out.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3), m.group(4).strip()))
    return out


def jal_target(operands):
    m = re.match(r"func_([0-9A-F]{8})", operands)
    return int(m.group(1), 16) if m else None


def deduce(addr):
    """The Spec of the tree whose _M_insert is at addr, or None when the function is not one."""
    ins = instructions(addr)
    jals = [(i, jal_target(a)) for i, (_, _, m, a) in enumerate(ins) if m == "jal"]
    alloc = next(((i, t) for i, t in jals if t in ALLOCS), None)
    if alloc is None:
        return None
    ai, afn = alloc
    style = ALLOCS[afn][0]
    before = [(i, t) for i, t in jals if i < ai]
    if len(before) < (2 if style == "tagged" else 1):
        return None
    tf = before[-1][1] if style == "tagged" else None
    cmp_ = before[-2][1] if style == "tagged" else before[-1][1]
    if cmp_ not in KEYS or (style == "tagged" and tf is None):
        return None
    key = KEYS[cmp_][0]
    node = None
    reg = "$a0" if style == "tagged" else "$a1"
    for _, _, m, a in ins[before[-1][0]:ai + 2]:
        mm = re.match(re.escape(reg) + r", \$zero, (-?0x[0-9a-fA-F]+|\d+)", a)
        if m == "addiu" and mm:
            node = int(mm.group(1), 0)
    if node is None or node <= 0x14:
        return None
    # the value copy: after the string pointer store (the key), up to `daddu $t0, $s3, $zero`
    j = next((i for i in range(ai, len(ins)) if ins[i][2] == "sw" and ins[i][3] == "$v1, 0x0($s0)"), None)
    if j is None:
        return None
    k = next((i for i in range(j + 1, len(ins)) if ins[i][2] == "daddu" and ins[i][3] == "$t0, $s3, $zero"), len(ins))
    seg = ins[j + 1:k]
    ctor = next((jal_target(a) for _, _, m, a in seg if m == "jal"), None)
    if ctor == KEYS[cmp_][1]:  # the mapped value is a string too: its copy inlines the same clone
        return Spec(key, node, tf, afn, "key", node - 0x14, at=addr)
    if ctor is not None:
        return Spec(key, node, tf, afn, "ctor", node - 0x14, ctor=ctor, at=addr)
    return Spec(key, node, tf, afn, "pod", node - 0x14, at=addr)


# ---------------------------------------------------------------- the source

def key_source(name):
    compare, (_, clone, free, heap) = next((c, k) for c, k in KEYS.items() if k[0] == name)
    release = (f"func_{free:08X}(r, size, 4, func_{heap:08X}()->name);" if free
               else "stl_unknown_release(r, size);")
    decls = (f'extern "C" HeapName *func_{heap:08X}(void);\n'
             f'extern "C" void func_{free:08X}(void *p, int size, int align, const char *name);' if free
             else 'extern "C" void stl_unknown_release(void *p, int size);')
    return f"""struct Rep {{
    int len;
    int cap;
    int ref;
    int sel;
}};

struct HeapName {{
    const char *name;
}};

extern "C" int func_{compare:08X}(const void *self, const void *other, unsigned int pos, unsigned int n);
extern "C" char *func_{clone:08X}(Rep *rep);
{decls}

/* the game's string: libstdc++ v2 basic_string (knowledge/runtime-types.md); the pointer is read and
   written as an int so the representation's counters can alias it */
struct {name} {{
    char *p;
    {name}(const {name} &o) {{
        int q = *(int *)&o.p;
        Rep *r = (Rep *)(q - 0x10);
        int d = q;
        if (r->sel != 0) {{
            d = (int)func_{clone:08X}(r);
        }} else {{
            r->ref = r->ref + 1;
        }}
        *(int *)&p = d;
    }}
    ~{name}() {{
        Rep *r = (Rep *)(*(int *)&p - 0x10);
        if (--r->ref == 0) {{
            int size = r->cap + 0x10;
            {release}
        }}
    }}
    bool operator<(const {name} &o) const {{ return func_{compare:08X}(this, &o, 0, (unsigned int)-1) < 0; }}
}};
"""


def mapped_source(spec):
    if spec.mapped_kind == "key":
        return ""
    if spec.mapped_kind == "pod":
        return f"struct {spec.mapped} {{\n    int w[{spec.mapped_size // 4}];\n}};\n"
    dtor = f"func_{spec.dtor:08X}" if spec.dtor else "stl_unknown_dtor"
    return f"""extern "C" void func_{spec.ctor:08X}(void *self, const void *other);
extern "C" void {dtor}(void *self, int in_charge);

struct {spec.mapped} {{
    int w[{spec.mapped_size // 4}];
    {spec.mapped}(const {spec.mapped} &o) {{ func_{spec.ctor:08X}(this, &o); }}
    ~{spec.mapped}() {{ {dtor}(this, 2); }}
}};
"""


def source(spec, member):
    name, decl = MEMBERS[member]
    style, free = ALLOCS[spec.alloc]
    if style == "tagged":
        alloc_decl = f'extern "C" void *func_{spec.alloc:08X}(int size, int align, const char *name);'
        free_decl = f'extern "C" void func_{free:08X}(void *p, int size, int align, const char *name);'
        tf_decl = f'extern "C" void *func_{spec.tf:08X}(void);'
        allocate = f"(T *)func_{spec.alloc:08X}(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name)"
        deallocate = f"func_{free:08X}(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name)"
        tag = f"template <> struct TypeTag<Node> {{ static void *tf() {{ return func_{spec.tf:08X}(); }} }};"
    else:
        alloc_decl = f'extern "C" void *func_{spec.alloc:08X}(int heap, int size);'
        free_decl = f'extern "C" void func_{free:08X}(void *p, int size);'
        tf_decl = ""
        allocate = f"(T *)func_{spec.alloc:08X}(0x10, n * sizeof(T))"
        deallocate = f"func_{free:08X}(p, n * sizeof(T))"
        tag = ""
    text = f"""/* compiler: {COMPILER} */
/* SGI STL (include/stl/stl_tree.h) instantiated by tools/stl.py:
   _Rb_tree<{spec.key}, pair<const {spec.key}, {spec.mapped}>, _Select1st, less<{spec.key}>, GameAlloc>::{name} */
#include <stl_tree.h>

{alloc_decl}
{"" if free == 0x326798 and spec.key == "Str" else free_decl}
{tf_decl}

{key_source(spec.key)}
{mapped_source(spec)}
/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {{
    const char *name;
}};

/* typeid(T).name() of the types this source allocates, without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
template <class T>
class GameAlloc {{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind {{ typedef GameAlloc<U> other; }};
    GameAlloc() throw() {{}}
    GameAlloc(const GameAlloc &) throw() {{}}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {{}}
    ~GameAlloc() throw() {{}}
    T *allocate(size_type n, const void * = 0) {{
        return {allocate};
    }}
    void deallocate(T *p, size_type n) {{
        {deallocate};
    }}
    size_type max_size() const throw() {{ return size_t(-1) / sizeof(T); }}
    void construct(T *p, const T &v) {{ new (p) T(v); }}
    void destroy(T *p) {{ p->~T(); }}
}};

typedef {spec.key} Key;
typedef pair<const {spec.key}, {spec.mapped}> Value;
typedef _Rb_tree_node<Value> Node;
{tag}

typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

{decl}
"""
    return text


MEMBERS = {
    "_M_insert": ("_M_insert", "template Tree::iterator Tree::_M_insert(_Rb_tree_node_base *, _Rb_tree_node_base *, const Value &);"),
    "insert_unique": ("insert_unique", "template pair<Tree::iterator, bool> Tree::insert_unique(const Value &);"),
    "insert_unique_hint": ("insert_unique(position)", "template Tree::iterator Tree::insert_unique(Tree::iterator, const Value &);"),
    "insert_equal": ("insert_equal", "template Tree::iterator Tree::insert_equal(const Value &);"),
    "insert_equal_hint": ("insert_equal(position)", "template Tree::iterator Tree::insert_equal(Tree::iterator, const Value &);"),
    "find": ("find", "template Tree::iterator Tree::find(const Key &);"),
    "find_const": ("find const", "template Tree::const_iterator Tree::find(const Key &) const;"),
    "lower_bound": ("lower_bound", "template Tree::iterator Tree::lower_bound(const Key &);"),
    "lower_bound_const": ("lower_bound const", "template Tree::const_iterator Tree::lower_bound(const Key &) const;"),
    "upper_bound": ("upper_bound", "template Tree::iterator Tree::upper_bound(const Key &);"),
    "upper_bound_const": ("upper_bound const", "template Tree::const_iterator Tree::upper_bound(const Key &) const;"),
    "count": ("count", "template Tree::size_type Tree::count(const Key &) const;"),
    "equal_range": ("equal_range", "template pair<Tree::iterator, Tree::iterator> Tree::equal_range(const Key &);"),
    "_M_erase": ("_M_erase", "template void Tree::_M_erase(Tree::_Link_type);"),
    "erase_pos": ("erase(position)", "template void Tree::erase(Tree::iterator);"),
    "erase_key": ("erase(key)", "template Tree::size_type Tree::erase(const Key &);"),
    "erase_range": ("erase(first, last)", "template void Tree::erase(Tree::iterator, Tree::iterator);"),
    "_M_copy": ("_M_copy", "template Tree::_Link_type Tree::_M_copy(Tree::_Link_type, Tree::_Link_type);"),
    "assign": ("operator=", "template Tree &Tree::operator=(const Tree &);"),
    "clear": ("clear", "template void Tree::clear();"),
    "dtor": ("~_Rb_tree", "template Tree::~_Rb_tree();"),
}
# members that destroy values come last, in the order their calls chain (erase(key) -> erase(first,
# last) -> erase(position)), so each one's callee is already placed when it is looked for
NEEDS_DTOR = ["_M_erase", "erase_pos", "erase_range", "erase_key", "assign", "clear", "dtor"]
CTOR_DTOR_DISTANCE = 0x80  # a class's constructor and destructor sit next to each other


# ---------------------------------------------------------------- symbols

def stl_symbols():
    out = {}
    if os.path.exists(STL_SYMBOLS):
        for line in open(STL_SYMBOLS):
            m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", line)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    return out


def write_symbols(table):
    lines = ["// gcc 2.96 mangled names of the STL instantiations tools/stl.py matched (read by tools/symbols.py)"]
    for name, addr in sorted(table.items(), key=lambda kv: (kv[1], kv[0])):
        lines.append(f"{name} = 0x{addr:08X}; // type:func")
    open(STL_SYMBOLS, "w", newline="\n").write("\n".join(lines) + "\n")
    symbols._table = None


def record_symbols(new):
    """Add {mangled name: address} to config/stl_symbols.txt."""
    table = stl_symbols()
    table.update(new)
    write_symbols(table)


# ---------------------------------------------------------------- compiling and finding

def compile_member(spec, member, tag):
    """Compile one instantiation: (source path, words, {offset: (type, symbol)}, function name)."""
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, f"{tag}_{member}.cpp")
    open(path, "w", newline="\n").write(source(spec, member))
    try:
        obj = match.compile_c(path)
    except SystemExit:
        return path, None, None, None
    blob, srelocs, funcs = match.read_object(obj, want_symbols=True)
    os.remove(obj)
    if not funcs:
        return path, None, None, None
    fname, foff, fsize = funcs[0]
    fsize = max(fsize, len(blob) - foff)
    words = match.trim_padding(list(struct.unpack_from(f"<{fsize // 4}I", blob, foff)))
    relocs = {off - foff: (r[0], r[1]) for off, r in srelocs.items() if foff <= off < foff + len(words) * 4}
    return path, words, relocs, fname


_spans = None


def spans():
    global _spans
    if _spans is None:
        with open(match.FUNCTIONS) as f:
            _spans = [(int(r["address"], 16), int(r["max_size"])) for r in csv.DictReader(f)]
    return _spans


def candidates(words, relocs, done, text_addr, text):
    """Unmatched functions whose code is the compiled member's, relocated words compared loosely."""
    n = len(words)
    out = []
    for addr, size in spans():
        if addr in done or size < n * 4 or size > n * 4 + 8:
            continue
        orig = match.words_at(text_addr, text, addr, n * 4)
        ok = True
        for i, (w, o) in enumerate(zip(words, orig)):
            rel = relocs.get(i * 4)
            if rel:
                if not match.same_ignoring_reloc(o, w, rel[0]):
                    ok = False
                    break
            elif w != o:
                ok = False
                break
        if ok and size > n * 4:  # the rest of the span must be padding
            tail = match.words_at(text_addr, text, addr + n * 4, size - n * 4)
            ok = all(t == match.NOP for t in tail)
        if ok:
            out.append(addr)
    return out


def jal_addresses(words, relocs, addr):
    """{symbol: address} for every call the original makes where the compiled member calls a symbol."""
    out = {}
    for off, (rtype, sym) in relocs.items():
        if rtype == R_MIPS_26 and off // 4 < len(words):
            w = words[off // 4]
            if w >> 26 == 3:  # jal
                out.setdefault(sym, ((addr + off) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    return out


_callers = None


def callers_of(addr):
    """The functions that call addr (every jal in the code, once)."""
    global _callers
    if _callers is None:
        text_addr, text = match.load_text()
        starts = sorted(a for a, _ in spans())
        import bisect
        rev = {}
        words = struct.unpack_from(f"<{len(text) // 4}I", text)
        for i, w in enumerate(words):
            if w >> 26 == 3:
                target = ((text_addr + i * 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                k = bisect.bisect_right(starts, text_addr + i * 4) - 1
                if k >= 0:
                    rev.setdefault(target, set()).add(starts[k])
        _callers = rev
    return _callers.get(addr, set())


def tied(addr, calls, known, spec):
    """Whether the function at addr belongs to the tree whose members (and types) are `known`:
    it calls one of them, one of them calls it, a caller of it also calls one of them, or the
    destructor it calls sits next to the mapped type's constructor."""
    if any(a in known for a in calls.values()):
        return True
    mine = callers_of(addr)
    if mine & known:
        return True
    if any(mine & callers_of(k) for k in known):
        return True
    d = calls.get("stl_unknown_dtor")
    if d is not None and spec.ctor is not None and abs(d - spec.ctor) <= CTOR_DTOR_DISTANCE:
        return True
    return False


def nearest(cands, known):
    """For code shared by every tree with this key (find, lower_bound...): the copy closest to the
    tree's other members in the library (one translation unit's instantiations sit together),
    when one is clearly nearest."""
    lib = [k for k in known if k >= LIBRARY_START]
    if not lib:
        return None
    centre = sorted(lib)[len(lib) // 2]
    by = sorted(cands, key=lambda a: abs(a - centre))
    if abs(by[0] - centre) > NEIGHBOURHOOD:
        return None
    if len(by) > 1 and abs(by[0] - centre) * 2 >= abs(by[1] - centre):
        return None
    return by[0]


def judge(addr, path):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    out = res.stdout + res.stderr
    return res.returncode == 0 and "MATCH" in out and "could not be checked" not in out, out


def judge_candidate(spec, member, tag, path, words, relocs, fname, addr, orig, calls):
    """Judge the compiled member against the function at addr, with the names it calls placed
    where that function calls; keeps the names on MATCH."""
    if any(symbols.address_of(s) not in (None, a) for s, a in calls.items()):
        return addr, "calls a placed name at another address"
    resolved_dtor = False
    if "stl_unknown_dtor" in calls and spec.dtor is None:  # a callee the instantiation could not know
        spec.dtor = calls["stl_unknown_dtor"]
        resolved_dtor = True
        path, words, relocs, fname = compile_member(spec, member, tag)
        calls = jal_addresses(orig, relocs, addr)
    new = {s: a for s, a in calls.items() if not s.startswith("func_") and symbols.address_of(s) is None}
    new[fname] = addr
    before = stl_symbols()
    record_symbols(new)
    ok, out = judge(addr, path)
    if ok:
        return addr, "MATCH"
    write_symbols(before)  # not it: forget the names this candidate suggested
    if resolved_dtor:
        spec.dtor = None
    first = next((l for l in out.splitlines() if "instructions differ" in l or "REJECTED" in l), out[:200])
    return addr, f"near: {first.split(': ', 1)[-1]}"


def solve_member(spec, member, tag, done, text_addr, text, known, only=None):
    """Instantiate one member, find its function, judge it; returns (addr, status)."""
    path, words, relocs, fname = compile_member(spec, member, tag)
    if words is None:
        return None, "does not compile"
    cands = [only] if only is not None else candidates(words, relocs, done, text_addr, text)
    if not cands:
        return None, f"no function of {len(words) * 4} bytes with this code"
    near = None
    untied = []
    for addr in cands:
        orig = match.words_at(text_addr, text, addr, len(words) * 4)
        calls = jal_addresses(orig, relocs, addr)
        if only is None and not tied(addr, calls, known, spec):
            untied.append(addr)
            continue
        near = judge_candidate(spec, member, tag, path, words, relocs, fname, addr, orig, calls)
        if near[1] == "MATCH":
            return near
    if near is None and untied:
        addr = nearest(untied, known)
        if addr is None:
            return untied[0], f"same code, but not tied to this tree ({len(untied)} copies: " + " ".join(f"{u:08x}" for u in untied[:6]) + ")"
        orig = match.words_at(text_addr, text, addr, len(words) * 4)
        calls = jal_addresses(orig, relocs, addr)
        near = judge_candidate(spec, member, tag, path, words, relocs, fname, addr, orig, calls)
        if near[1] == "MATCH":
            return near
    return near if near else (None, "no candidate")


def keep(addr, path):
    dst = os.path.join(ROOT, "src", f"func_{addr:08X}.cpp")
    open(dst, "w", newline="\n").write(open(path).read())
    return dst


# ---------------------------------------------------------------- commands

def find_inserts():
    """Every _M_insert in the image: the functions whose code deduces to a tree."""
    out = []
    for addr, size in spans():
        if 1000 <= size <= 1100:
            spec = deduce(addr)
            if spec:
                out.append((addr, spec))
    return out


def solve_tree(addr, spec, members, done, verify=False):
    """Every member of the tree whose _M_insert is at addr; verify: judge against matched functions
    too, keeping nothing (a check of the generator)."""
    text_addr, text = match.load_text()
    tag = f"{addr:08x}"
    results = []
    known = {addr} | ({spec.tf} if spec.tf else set()) | ({spec.ctor} if spec.ctor else set()) | ({spec.dtor} if spec.dtor else set())
    order = [m for m in members if m not in NEEDS_DTOR] + [m for m in NEEDS_DTOR if m in members]
    pool = set() if verify else done
    for member in order:
        found, status = solve_member(spec, member, tag, pool, text_addr, text, known, only=addr if member == "_M_insert" else None)
        if status == "MATCH":
            known.add(found)
            if spec.dtor:
                known.add(spec.dtor)
            if not verify and found not in done:
                keep(found, os.path.join(OUT, f"{tag}_{member}.cpp"))
                done.add(found)
            elif found in done:
                status = "MATCH (already matched)"
        results.append((member, found, status))
        print(f"  {MEMBERS[member][0]:<22} {'' if found is None else f'{found:08x}'}  {status}", flush=True)
    return results


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["try", "scan", "types", "members"])
    ap.add_argument("addr", nargs="?")
    ap.add_argument("-m", "--member", action="append")
    ap.add_argument("--dtor", help="try: the mapped type's destructor, when known")
    ap.add_argument("--verify", action="store_true", help="try: judge against matched functions too, keep nothing")
    a = ap.parse_args()
    if a.command == "members":
        for k, (name, decl) in MEMBERS.items():
            print(f"{k:<20} {name:<22} {decl}")
        return
    done = project.done_addresses()
    members = a.member or list(MEMBERS)
    if a.command == "try":
        addr = int(a.addr, 16)
        spec = deduce(addr)
        if spec is None:
            raise SystemExit(f"0x{addr:08x} does not look like an rb-tree _M_insert")
        if a.dtor:
            spec.dtor = int(a.dtor, 16)
        print(f"{addr:08x}: {spec.describe()}")
        solve_tree(addr, spec, members, done, verify=a.verify)
        return
    trees = find_inserts()
    if a.command == "types":
        for addr, spec in trees:
            print(f"{addr:08x}: {spec.describe()}")
        return
    print(f"{len(trees)} trees", flush=True)
    total = 0
    for addr, spec in trees:
        print(f"{addr:08x}: {spec.describe()}", flush=True)
        res = solve_tree(addr, spec, members, done)
        total += sum(1 for _, f, s in res if s == "MATCH")
    print(f"{total} members matched; run tools/organize.py then tools/build.py")


if __name__ == "__main__":
    main()
