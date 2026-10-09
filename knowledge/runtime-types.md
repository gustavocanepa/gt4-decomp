# Runtime types and idioms

The basic building blocks the game code uses everywhere: the reference-counted string, the handle (smart
pointer) to script objects, the allocator, the STL containers, and the object/vtable layout. These are
what you see in the matched sources in `src/`. The rules for *compiling* them byte-exactly are in
[gt4.md](gt4.md) and [ee-gcc-2.96.md](ee-gcc-2.96.md); this page explains what the things *are*.

Sources: matched files in `src/` (cited by address), `knowledge/gt4.md`, `config/symbol_addrs.txt`.
Items marked **inferred** come from names or call shapes and were not confirmed by reading the whole
function. Function names are `func_<address>` because most of these helpers have no RTTI name.

## Compiler and ABI in one paragraph

Game code is C++ built by Sony's ee-gcc 2.96 (`-O2 -G0`, `-fno-exceptions`; only 53 library functions have
exception frames). The old g++ ABI is used: the vtable pointer is not at offset 0 but after the first member
(offset 4 in every `RefCounter`-derived class), a destructor takes `(this, flags)`, constructors return `this`,
`bool` is 4 bytes, and pointers to members are 8 bytes `{short delta; short index; ...}`. The CPU is the PS2
Emotion Engine (MIPS III, 64-bit registers, 32-bit pointers); `float` is single precision and `sqrt` is the inline
`sqrt.s` instruction.

## Virtual calls and vtables

A vtable is an array of 8-byte entries `{short delta; short index; void *fn}` with the function at +4. Entry 0
holds the type_info pointer, entry `i + 1` is virtual method `i`. A virtual call is
`e = vtbl + 8 * (i + 1); fn = e->fn; fn((char *)obj + e->delta, ...)`; `delta` is the this-adjustment (0 for
single inheritance, which is all that was seen in the vtables inspected). Matched code writes this with a `VEntry` struct
(414 of the matched files declare one). Verified on the hClass vtable at 0x6736A8: entry 50 (offset 0x190) is
`hClass::virtual_49`, which the registration functions call to set a class name
([script-engine.md](script-engine.md)).

Destructors are called as `dtor(obj, flags)`: bit 0 set means "also free the memory"
(`if (flags & 1) operator_delete(obj)`), and the explicit calls `dtor(&local, 2)` mean "destroy in place, do not free".
Constructors return `this` (a load right after a constructor call lands in `$v1`, see gt4.md).

Instance sizes are returned by `virtual_04` of every `RefCounter`-derived class (see classes.md).

## Memory allocation

All heap blocks go through a **tagged allocator** with explicit sizes:

| helper | meaning (inferred from use) |
|---|---|
| `func_00326750(size, align, tag)` | allocate; returns 0 for size 0; `align == 4` takes the plain path `func_00326588(size)`, other alignments go to the heap object at 0x8744D0 (`func_00575E60` -> `func_005725A8`) |
| `func_00326798(ptr, size, align, tag)` | free; the caller passes the size and alignment again (sized delete) |
| `func_005C1628(ptr)` | `operator delete`: null check, then `func_00575DA0` |

The `tag` is a C string naming the owner. Script objects always use the literal `"RefCounter"` (hInt: 0x14
bytes, hBuiltinMethod: 0x10, handle-owned blocks: 8 or 0x10). Library containers use a per-element-type *name
singleton*: `func_005C11A8()` (the string type) and `func_005C1100()` (a vector element type) lazily fill a
`{name, ...}` struct on first use and return it; the `->name` field is passed as the tag. The purpose of the
tag is probably memory accounting, since the `MSystem` natives include `DumpMemoryBlock` and `GetMaxMemorySize`
(**inferred**). Containers and strings compute the byte size themselves when freeing (`cap + 0x10`,
`(eos - start) * sizeof(T)`).

## The reference-counted string

The game's string is the g++ 2.9x `basic_string<char>` with copy-on-write representation: the object is one
pointer, `char *p`, which points at the first character; the representation header sits 16 bytes before it.

```c
struct Rep {        /* at p - 0x10 */
    s32 len;        /* length */
    s32 cap;        /* capacity ("reserve") */
    s32 ref;        /* reference count; the block is freed when it drops to 0 */
    s32 sel;        /* "selfish": non-zero means the rep may not be shared and must be cloned on copy */
};                  /* characters follow, NUL terminated */
```

(`gt4.md`: "Strings keep their length 16 bytes before the text"). A shared empty representation lives at
`D_00659FA8` (the first characters are at `D_00659FA8 + 0x10`), so default strings never allocate.
Stack temporaries holding a string occupy a 16-byte slot (the struct is padded to 0x10), which is why matched
code declares `struct Str { char *p; char pad[0xC]; }` or a `Str` inside a union.

Operations seen in the matched code:

| operation | code |
|---|---|
| copy / construct from another string | `if (r->sel != 0) p = func_005C2560(r); else { p = (char *)(r + 1); r->ref++; }` (clone when selfish, otherwise share) |
| assign from a C string | `func_005C2630(&s, 0, -1, src, func_0057F260(src))` - `replace(pos, n, src, len)` with `n = -1` (npos), where `func_0057F260` is `strlen` |
| compare | `func_005C2A50(a, b, pos, n)` - `basic_string::compare`; the rb-tree `find` of `map<string, ...>` uses it |
| release | `if (--rep->ref == 0) func_00326798(rep, rep->cap + 0x10, 4, func_005C11A8()->name);` |
| `c_str()` (inline) | `len == 0 ? "" : (p[len] = 0, p)` |
| string assignment | `if (src != &self->s) { release(dst); copy-construct dst from *src; }` |

The "build a string from a literal, call something, destroy it" triple (copy the empty rep, `replace` the literal in,
call, release) is the most repeated pattern in the program: every script-native registration builds its class name
and every method name this way (solved verbatim in func_002CBB18, func_0015CC58; see
[script-engine.md](script-engine.md)).

Text is stored in a single-byte/EUC-JP style encoding: numbers may appear as full-width EUC digits
(`0xA3B0 + digit`, gt4.md), and the community's Adhoc docs state that bytecode symbols are EUC-JP below version 10.

`hString` (the script string, 20 bytes) is a thin wrapper: its vtable pointer is at +4 and the `Str` pointer is at
+0x10, and its destructor (0x314858) releases the representation exactly as above.

## Handles (smart pointers to script objects)

A **handle** is a one-word pointer to a `RefCounter`-derived object, with intrusive reference counting: object word
`+0` is the count, `+4` the vptr. Handles are what native functions receive and return, and what the VM holds in
variables. The matched code never shows the inner operations by name, only their addresses:

- `func_003285A8(p)` retain (increment), `func_003285F8(p)` release (decrement, free through the object's own
  virtual destructor when it reaches 0) - not yet matched, roles inferred from every use site.
- the **handle-assign idiom** (gt4.md): `if (dst != src) { new = *src; if (new) retain(new); old = *dst; if (old) release(old); *dst = new; }`
  - this is how every native writes its return value into the caller's slot (func_0012DC60 and 100+ other files).
- constructors of typed handles: `func_002FE278(&h, int)` boxes an int into a new `hInt` (allocates 0x14 with tag
  `"RefCounter"`, runs `hInt`'s constructor `func_002FE108`, wraps it); `func_00314B20(&h, &Str)` makes an `hString` handle from a
  string; `func_00312370(&h, arg)` builds a handle to an argument (used to read script arguments as strings, **inferred**);
  `func_00309348(&h, &ptr)` is the generic "wrap raw pointer" constructor.
- a handle destructor is called as `dtor(&h, 2)`: `func_002FC870`, `func_00312318`, `func_003038E0`... one per handle type.
  Handles sit in 16-byte stack slots (arrays of them are built with gcc's vec-init loops, see gt4.md rules 61-63).

The base of the hierarchy, `RefCounter`, has 8 bytes (count, vptr); `hObject` adds two words (16 bytes); see
[classes.md](classes.md) for the sizes of the value types.

Because the same tagged allocation and handle idioms repeat, the 1,000+ registration/native callbacks are mostly
instances of a few templates (tools/registration.py, tools/families.py).

## Containers (SGI STL as shipped with gcc 2.96)

Only the **template instantiations** match with our compiler flags; library code in 0x596FA0 and above is
otherwise compiled differently (gt4.md "Open" notes).

- **`std::vector<T>`** (SGI `_M_insert_aux`, `insert`, `push_back`...): 16 bytes `{ pad; T *start; T *finish; T *end_of_storage }`
  (one leading word, e.g. the empty allocator; matched in func_005D8920). Reallocation: allocate `n * sizeof(T)` through the
  tagged allocator, `uninitialized_copy` (via `value_type(&r)`, a dead 16-byte stack store), construct with placement
  `operator new(unsigned, void *) throw()`, copy back with `memmove` (`func_005A47D4`), free with the sized
  free. After a store through an element, `finish` is reloaded only if `T` is a struct that could alias.
- **`std::map` / `std::set`** (SGI red-black tree): node = `{ s32 color; Node *parent; Node *left; Node *right; value }`
  (value at +0x10); the tree object is `{ pad; Node *header }` with `header->parent` the root. Iterators are one pointer, padded to
  16 bytes on the stack, built with inline `ctor(&it, node)` and compared with inline `eq()`. Functions seen:
  `find` (`func_005D5878`, a `map<string, ...>` lookup using `basic_string::compare`), `lower_bound`, `insert_unique`
  (returns `pair<iterator, bool>` by hidden pointer; `bool` is 4 bytes), `__insert`, `erase`. In `lower_bound`,
  `len` and `middle` stay in memory because `distance`/`advance` are inline helpers taking pointers (gt4.md).
- **`std::list`**: per-element-type member instances exist in the same library range (coverage-map.md: rb-tree, vector and
  list members are the part of 0x596FA0+ that matches). The game code also has an intrusive linked list (head/tail at
  `+0x30/+0x34` of the owner, links at node `+4/+8`, func_00328BE0).
- **iostream** (`streambuf`, `filebuf`, `stdiobuf`, `ostream`, `istdiostream`) and the C runtime are present as library code
  (units in 0x54DBB8-0x5BFB00); see [architecture.md](architecture.md).

The game's own containers (script arrays `hArray`, the class member tables inside `hClass`) are built on these;
`hArray` has the usual script operations (push, pop, sort, bsearch...).

## Vectors, matrices and floats

Math types are small POD structs of `f32`: `Vec3` = `{x, y, z}` (12 bytes), `Vec4` 16 bytes, a 4x4 matrix is 64 bytes laid out
row by row (the identity initialiser loop in gt4.md rule 95 clears 16 floats). For byte matching the vector types
are declared as unions so their stores are serialised (rule 78). Float
parameters travel in `$f12` and up; products are written unfactored to keep the original
common-subexpression layout (rule 25). The physics code in the unnamed clusters (unit_0034E9A0 etc.) is pure float
code without strings.

## Globals and scratchpad

Global objects live in `.data/.bss` at 0x617A80-0x6D5DFC; the executable's own addresses are used as symbol names
(`D_00659FA8`). The class-registration static initialisers define 72 small ID objects each (gt4.md rule 103,
[script-engine.md](script-engine.md)). The PS2 scratchpad (base `0x70002000`) is used by function 004A4550 (still open in gt4.md).

## What is not known

- Field layouts: only the fields that matched sources touch are known (reference count/vptr, `hString.p` at +0x10, `hClass`
  name/parent/counter, native callback slots at `+0xC/+0x10`). Everything else in the objects is `unkNN`.
- `func_003285A8` / `func_003285F8` / `func_00326750` are the roles described above by use; they are not decompiled yet.
- Whether `sel` is exactly libstdc++'s `selfish` flag is inferred from the clone-on-copy branch; the layout of `len/cap/ref` matches the
  libstdc++ v2 `_Rep` and the observed arithmetic (`cap + 0x10`).
