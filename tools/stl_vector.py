#!/usr/bin/env python3
"""SGI STL sequence instantiations (vector<T>, and the algorithms they call): the sibling of
tools/stl.py for containers whose members carry no key compare to deduce the type from. Every
member is compiled once per element shape (a scalar type, a POD of n words, a pointer) and
allocator with the element's type_info getter as a placeholder; the image is searched for code
equal to it (relocated words compared loosely), and each function found is instantiated again with
the getter it calls (the element type named after it) and judged. Callees are named by their gcc
2.96 mangled names and placed where the original calls them (config/stl_symbols.txt), as in stl.py.

    stl_vector.py scan [-m MEMBER] [-s SHAPE]   search every member for every shape, keep MATCHes
    stl_vector.py members                       the members instantiated
    stl_vector.py shapes                        the element shapes tried
"""
import argparse
import os
import struct

import match
import project
import stl

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "stl_vector")

# shape -> (C++ declaration of Elem, or None for a builtin, builtin type, named after the getter)
SCALARS = ["char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int", "float"]
SHAPES = {s.replace(" ", "_"): ("scalar", s) for s in SCALARS}
SHAPES["ptr"] = ("ptr", None)
for n in range(1, 7):
    SHAPES[f"pod{n}"] = ("pod", n)
# game classes: a 4-byte class with an out-of-line copy constructor and, by the flags, an
# out-of-line destructor (d) and assignment (a); alone, or followed by a vector<scalar> member
# (wrapped in a struct with the implicit copy members: the extra inline level shows in the loop
# code, 005c5690). The callees are placeholders (CLASS_FNS) read from the matching function.
for flags in ("", "d", "a", "da"):
    SHAPES[f"cls_c{flags}"] = ("cls", (flags, None))
    SHAPES[f"cls_c{flags}_vu16"] = ("cls", (flags, "unsigned short"))
CLASS_FNS = {"cctor": "stl_cctor", "dtor": "stl_dtor", "assign": "stl_assign", "inner_tf": "stl_tf_inner"}

ALLOCATORS = {
    "tagged": ("GameAlloc", "(T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name)",
               "func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name)"),
}
# SGI simple_alloc shape over memalign: no call for zero elements; the free takes only the block;
# the heap (alignment) argument is the allocator's (two allocators, 0x10 and 0x40)
for heap in (0x10, 0x40):
    ALLOCATORS[f"plain{heap:x}"] = (f"PlainAlloc{heap:x}", f"n == 0 ? 0 : (T *)func_00575E60({heap:#x}, n * sizeof(T))",
                                    "func_00575DA0(p)")

MEMBERS = {
    "insert_fill": "template void Vec::insert(Vec::iterator, Vec::size_type, const Elem &);",
    "insert_aux": "template void Vec::_M_insert_aux(Vec::iterator, const Elem &);",
    "insert_aux0": "template void Vec::_M_insert_aux(Vec::iterator);",
    "insert": "template Vec::iterator Vec::insert(Vec::iterator, const Elem &);",
    "push_back": "template void Vec::push_back(const Elem &);",
    "assign_op": "template Vec &Vec::operator=(const Vec &);",
    "reserve": "template void Vec::reserve(Vec::size_type);",
    "erase_pos": "template Vec::iterator Vec::erase(Vec::iterator);",
    "erase_range": "template Vec::iterator Vec::erase(Vec::iterator, Vec::iterator);",
    "range_insert": "template void Vec::_M_range_insert(Vec::iterator, const Elem *, const Elem *, forward_iterator_tag);",
    "resize": "template void Vec::resize(Vec::size_type, const Elem &);",
    "assign_fill": "template void Vec::assign(size_t, const Elem &);",
    "copy_ctor": "template Vec::vector(const Vec &);",
    "fill_ctor": "template Vec::vector(Vec::size_type, const Elem &, const Vec::allocator_type &);",
    "dtor": "template Vec::~vector();",
    # the algorithms the members call out of line
    "fill": "template void fill(Elem *, Elem *, const Elem &);",
    "fill_n": "template Elem *fill_n(Elem *, unsigned int, const Elem &);",
    "copy_backward": "template Elem *copy_backward(Elem *, Elem *, Elem *);",
    "copy": "template Elem *copy(Elem *, Elem *, Elem *);",
    "copy_const": "template Elem *copy(const Elem *, const Elem *, Elem *);",
    "ucopy": "template Elem *uninitialized_copy(Elem *, Elem *, Elem *);",
    "ucopy_const": "template Elem *uninitialized_copy(const Elem *, const Elem *, Elem *);",
    "ufill_n": "template Elem *uninitialized_fill_n(Elem *, unsigned int, const Elem &);",
    # their out-of-line halves for elements with a real copy constructor/destructor
    "ufill_n_aux": "template Elem *__uninitialized_fill_n_aux(Elem *, unsigned int, const Elem &, __false_type);",
    "ucopy_aux": "template Elem *__uninitialized_copy_aux(Elem *, Elem *, Elem *, __false_type);",
    "ucopy_aux_const": "template Elem *__uninitialized_copy_aux(const Elem *, const Elem *, Elem *, __false_type);",
    "destroy_aux": "template void __destroy_aux(Elem *, Elem *, __false_type);",
}
ALGORITHMS = {"fill", "fill_n", "copy_backward", "copy", "copy_const", "ucopy", "ucopy_const", "ufill_n",
              "ufill_n_aux", "ucopy_aux", "ucopy_aux_const", "destroy_aux"}

# list<T>: the node (_List_node<T>: next, prev, data) is what the allocator allocates and tags
LIST_MEMBERS = {
    "clear": "template void Base::clear();",
    "insert_fill": "template void Lst::insert(Lst::iterator, Lst::size_type, const Elem &);",
    "insert_range": "template void Lst::insert(Lst::iterator, const Elem *, const Elem *);",
    "insert_range_it": "template void Lst::insert(Lst::iterator, Lst::const_iterator, Lst::const_iterator);",
    "erase_range": "template Lst::iterator Lst::erase(Lst::iterator, Lst::iterator);",
    "resize": "template void Lst::resize(Lst::size_type, const Elem &);",
    "assign_op": "template Lst &Lst::operator=(const Lst &);",
    "assign_fill": "template void Lst::assign(Lst::size_type, const Elem &);",
    "remove": "template void Lst::remove(const Elem &);",
    "unique": "template void Lst::unique();",
    "merge": "template void Lst::merge(Lst &);",
    "reverse": "template void Lst::reverse();",
    "sort": "template void Lst::sort();",
    "copy_ctor": "template Lst::list(const Lst &);",
    "dtor": "template Lst::~list();",
}

# container -> (headers, typedefs with {cls}, the type the allocator tags, members, algorithms)
CONTAINERS = {
    "vector": (["stl_vector.h"], "typedef vector<Elem, {cls}<Elem> > Vec;", "Elem", MEMBERS, ALGORITHMS),
    "list": (["stl_list.h"], "typedef list<Elem, {cls}<Elem> > Lst;\ntypedef _List_base<Elem, {cls}<Elem> > Base;",
             "_List_node<Elem> ", LIST_MEMBERS, set()),
}

PRELUDE = """#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
{headers}

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(void *p);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;
"""

ALLOC_CLASS = """
template <class T>
class {cls} {{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind {{ typedef {cls}<U> other; }};
    {cls}() throw() {{}}
    {cls}(const {cls} &) throw() {{}}
    template <class U> {cls}(const {cls}<U> &) throw() {{}}
    ~{cls}() throw() {{}}
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
"""


def class_decl(arg, name, fns, alloc):
    """A game class element: the 4-byte class whose copy constructor (and destructor, assignment by
    the flags) are out of line, calling the functions in fns ({role: address}, missing roles keep
    their placeholder), alone or followed by a wrapped vector<scalar> member."""
    flags, inner = arg
    sym = {r: f"func_{fns[r]:08X}" if r in fns else p for r, p in CLASS_FNS.items()}
    obj = f"T_{fns['cctor']:08X}" if "cctor" in fns else "Cls"
    out = f'extern "C" void {sym["cctor"]}(void *self, const void *other);\n'
    body = f"    int w;\n    {obj}() {{}}\n    {obj}(const {obj} &o) {{ {sym['cctor']}(this, &o); }}\n"
    if "d" in flags:
        out += f'extern "C" void {sym["dtor"]}(void *self, int in_charge);\n'
        body += f"    ~{obj}() {{ {sym['dtor']}(this, 2); }}\n"
    if "a" in flags:
        out += f'extern "C" void *{sym["assign"]}(void *self, const void *other);\n'
        body += f"    {obj} &operator=(const {obj} &o) {{ {sym['assign']}(this, &o); return *this; }}\n"
    out += f"\nstruct {obj} {{\n{body}}};\n"
    if inner is None:
        return out + f"typedef {obj} Elem;"
    if alloc != "tagged":  # the member vector keeps the game's tagged allocator
        _, allocate, deallocate = ALLOCATORS["tagged"]
        out = ALLOC_CLASS.format(cls="GameAlloc", allocate=allocate, deallocate=deallocate) + "\n" + out
    return (out + f'extern "C" void *{sym["inner_tf"]}(void);\n'
            f"template <> struct TypeTag<{inner}> {{ static void *tf() {{ return {sym['inner_tf']}(); }} }};\n"
            f"struct {name} {{\n    {obj} a;\n    struct V {{\n        vector<{inner}, GameAlloc<{inner}> > v;\n    }} v;\n}};\n"
            f"typedef {name} Elem;")


def source(shape, alloc, member, tf=None, name=None, container="vector", fns=None):
    """The instantiation of member for an element of this shape. tf: the type_info getter's
    address (None: a placeholder symbol); name: the element type's name for non-builtin shapes;
    fns: a class element's out-of-line callees ({role: address}, see CLASS_FNS)."""
    kind, arg = SHAPES[shape]
    cls, allocate, deallocate = ALLOCATORS[alloc]
    getter = f"func_{tf:08X}" if tf else "stl_tf"
    name = name or "Obj"
    if kind == "scalar":
        elem = f"typedef {arg} Elem;"
    elif kind == "ptr":
        elem = f"struct {name};\ntypedef {name} *Elem;"
    elif kind == "cls":
        elem = class_decl(arg, name, fns or {}, alloc)
    else:
        elem = f"struct {name} {{\n    int w[{arg}];\n}};\ntypedef {name} Elem;"
    headers, typedefs, tagged, members, _ = CONTAINERS[container]
    tag = f'extern "C" void *{getter}(void);\ntemplate <> struct TypeTag<{tagged}> {{ static void *tf() {{ return {getter}(); }} }};' if alloc == "tagged" else ""
    if kind == "pod" and container != "vector":  # list::remove/unique/merge/sort compare elements
        elem += f"\ninline bool operator==(const {name} &a, const {name} &b) {{ return a.w[0] == b.w[0]; }}"
        elem += f"\ninline bool operator<(const {name} &a, const {name} &b) {{ return a.w[0] < b.w[0]; }}"
    return (f"/* compiler: {stl.COMPILER} */\n/* SGI STL (include/stl/stl_{container}.h) instantiated by tools/stl_vector.py:"
            f" {container}<{arg if kind == 'scalar' else name + (' *' if kind == 'ptr' else '')}, {cls}> {member} */\n"
            + PRELUDE.replace("{headers}", "\n".join(f"#include <{h}>" for h in headers))
            + ALLOC_CLASS.format(cls=cls, allocate=allocate, deallocate=deallocate)
            + f"\n{elem}\n{tag}\n{typedefs.format(cls=cls)}\n\n{members[member]}\n")


def compile_source(text, path):
    open(path, "w", newline="\n").write(text)
    try:
        obj = match.compile_c(path)
    except SystemExit:
        return None, None, None
    blob, srelocs, funcs = match.read_object(obj, want_symbols=True)
    os.remove(obj)
    if not funcs:
        return None, None, None
    fname, foff, fsize = funcs[0]
    fsize = max(fsize, len(blob) - foff)
    words = match.trim_padding(list(struct.unpack_from(f"<{fsize // 4}I", blob, foff)))
    relocs = {off - foff: (r[0], r[1]) for off, r in srelocs.items() if foff <= off < foff + len(words) * 4}
    return words, relocs, fname


def judge(addr, path, words, relocs, fname, text_addr, text):
    orig = match.words_at(text_addr, text, addr, len(words) * 4)
    calls = stl.jal_addresses(orig, relocs, addr)
    if any(stl.symbols.address_of(s) not in (None, a) for s, a in calls.items()):
        return "calls a placed name at another address"
    new = {s: a for s, a in calls.items() if not s.startswith("func_") and stl.symbols.address_of(s) is None}
    if stl.symbols.address_of(fname) not in (None, addr):
        return f"{fname} already placed elsewhere"
    named = [s for s, a in stl.stl_symbols().items() if a == addr and s != fname]
    if named:  # a matched caller already gave this function its type
        return f"named {named[0]} by its caller"
    new[fname] = addr
    before = stl.stl_symbols()
    stl.record_symbols(new)
    ok, out = stl.judge(addr, path)
    if ok:
        return "MATCH"
    stl.write_symbols(before)
    first = next((l for l in out.splitlines() if "instructions differ" in l or "REJECTED" in l), out[:200])
    return "near: " + first.split(": ", 1)[-1]


def scan(members, shapes, done, container="vector"):
    text_addr, text = match.load_text()
    os.makedirs(OUT, exist_ok=True)
    matched = []
    for alloc in ALLOCATORS:
        for shape in shapes:
            for member in members:
                if member in CONTAINERS[container][4] and alloc != "tagged":  # no allocator in them
                    continue
                path = os.path.join(OUT, f"{container}_{alloc}_{shape}_{member}.cpp")
                words, relocs, _ = compile_source(source(shape, alloc, member, container=container), path)
                if words is None:
                    continue
                for addr in stl.candidates(words, relocs, done, text_addr, text):
                    orig = match.words_at(text_addr, text, addr, len(words) * 4)
                    calls = stl.jal_addresses(orig, relocs, addr)
                    tf = calls.get("stl_tf") if alloc == "tagged" else None
                    # a class element is named by the callees it calls (its copy constructor first)
                    fns = {r: calls[p] for r, p in CLASS_FNS.items() if p in calls}
                    known = (fns.get("cctor") or tf) if SHAPES[shape][0] == "cls" else tf
                    if alloc == "tagged" and known is None and SHAPES[shape][0] != "scalar":
                        continue
                    if SHAPES[shape][0] == "cls" and SHAPES[shape][1][1] is None and "cctor" in fns:
                        name = f"T_{fns['cctor']:08X}"
                    else:
                        name = f"E_{known:08X}" if SHAPES[shape][0] == "cls" else f"T_{tf or addr:08X}"
                    fpath = os.path.join(OUT, f"{addr:08x}.cpp")
                    fw, fr, fname = compile_source(source(shape, alloc, member, tf, name, container, fns), fpath)
                    if fw is None or len(fw) != len(words):
                        continue
                    status = judge(addr, fpath, fw, fr, fname, text_addr, text)
                    print(f"{addr:08x} {len(fw) * 4:5d}  {container:<6} {alloc:<9} {shape:<15} {member:<13} {status}", flush=True)
                    if status == "MATCH":
                        dst = os.path.join(ROOT, "src", f"func_{addr:08X}.cpp")
                        open(dst, "w", newline="\n").write(open(fpath).read())
                        done.add(addr)
                        matched.append((addr, len(fw) * 4))
    big = sum(1 for _, s in matched if s > 512)
    print(f"{len(matched)} matched, {sum(s for _, s in matched)} bytes, {big} over 512 B")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["scan", "members", "shapes"])
    ap.add_argument("-m", "--member", action="append")
    ap.add_argument("-s", "--shape", action="append")
    ap.add_argument("-c", "--container", choices=list(CONTAINERS), default="vector")
    a = ap.parse_args()
    members = CONTAINERS[a.container][3]
    if a.command == "members":
        for k, v in members.items():
            print(f"{k:<14} {v}")
        return
    if a.command == "shapes":
        for k, v in SHAPES.items():
            print(f"{k:<15} {v}")
        return
    scan(a.member or list(members), a.shape or list(SHAPES), project.done_addresses(), a.container)


if __name__ == "__main__":
    main()
