# Gran Turismo HD: names and prototypes for GT4's code

Gran Turismo HD (PS3, 2006) is built from GT4's code base. Its debug executables (the public
"gthd-ps3-debug-binaries" set: `1166.elf`, `1171.elf` (near-identical builds), `1668.elf` (no
symbols)) keep a full symbol table, so most of GT4's C++ classes can be named method by method.
`tools/gthd_names.py` does it (TOOLS.md); this page is what was learned. The executables are
data: read only, never executed, never copied into the repository (only names and type facts
derived from them are).

## The executable

- PowerPC64 big-endian ELF, PS3 lv2 ABI: 32-bit pointers, every function has an 8-byte `.opd`
  descriptor `{code, toc}`; the symbol `NAME` is the descriptor, `.NAME` the code. Globals are
  reached through the TOC (`lwz rX, d(r2)` loads a pointer from `.got`).
- `.symtab`: 58,857 symbols, 28,567 Itanium-mangled. 749 `_ZTV` vtables, `_ZTI` type_info objects
  (`__si_class_type_info` gives the single base, `__vmi_class_type_info` the list).
- 1,025 `FILE` symbols name the source files (`gameobject_ps3.cxx`, `init_ps3common.cxx`, ...;
  1,007 are source files, the rest crt/asm headers and `<built-in>`). ELF puts all locals first,
  so only a unit's local symbols follow its FILE symbol (static functions, `_GLOBAL__I_` /
  `_GLOBAL__D_`, static data, local .opd descriptors); the globals are placed by contiguity
  (section "Translation units").
- DWARF: 13 compile units, all toolchain runtime (crt1, unwind-dw2, libsupc++): no game type or
  struct layout at all. Class layouts must still come from the code (tools/types_db.py).
- Compiler: SN/GCC 4 PPU (Itanium ABI): two destructor entries per class (D1 complete, D0
  deleting) where g++ 2.96 has one, constructors in C1/C2 pairs, `__cxa_pure_virtual` for pure
  virtuals (GT4: `__pure_virtual` at 0x5BC5C0).

## How GT4's classes line up (2026-10-10)

- 420 of GT4's 509 RTTI classes have a GT HD twin: 407 by name, the rest PS2 -> PS3
  (`RacePS2Base` / `RacePS3Base`, `RaceBGMPS2` / `RaceBGMPS3`, `m*ContextPS2`) or a single
  namespaced class of the same name. 416 have a vtable in both.
- Slot counts agree for about a third of the classes; the rest differ because GT HD added methods
  (hObject: 49 slots in GT4, 53 in GT HD: `getObjectValue`, `c_str`, `getElementCount` and one
  more operator), dropped some, or put a new base under a class (`RaceBase` derives from
  `GranTurismo4::GameObjectPS3` in GT HD, from nothing in GT4; 11 m* classes moved under `mNode`).
  So slots are aligned per class block (the class's own slots after its parent's) with gaps on
  both sides, scored by the override pattern of the descendants and the code size, and kept only
  with a clear margin (tools/gthd_names.py's docstring has the rules).
- Code sizes: GT HD's PPC function is 1.3-2x the EE one (log ratio ~N(0.4, 0.45) over agreeing
  slots), a usable signal for anything bigger than a stub.
- GT HD's script-object operators are declared in alphabetical order (`op_add`, `op_and`,
  `op_andand`, ... `op_xor`, vtable slots 24-52); GT4's are not: the bodies of hInt's overrides
  (slots 21-47) read add, sub, mul, div, mod, (26: no ALU op), eq, ne, four `slt` compares, not,
  andand, oror, uminus, ..., and, or, xor, lshift, rshift, invert, with `op_elem` last (48). Those
  slots are left unnamed (their override pattern and sizes are all the same, the alignment cannot
  tell them apart); the medium-confidence pairing the alignment proposes there is wrong, which is
  why only high vtable names are applied.

## What came out

- Virtual methods: of 3,711 distinct GT4 virtual-function addresses (pure virtual excluded),
  2,669 got a GT HD name: 2,498 high, 171 medium (listed, not applied), 3 conflicts.
  Spot checks that hold for every class: all 227 `rc_size` are the 8-byte `return N` (the
  `virtual_04` classes.md reads as sizeof), all 227 `rc_class` are 16 bytes, `getClassID` is the
  40-byte virtual that calls the 16-byte static `GetClassID`; `hModule::setName` is the
  `virtual_49` (0x305590) the registration functions call to set a class name.
- Other functions, through the call graph (callees at the same place in paired functions) and
  strings used by exactly one function in each game: 834 medium, 116 low. Held-out check: with
  half of the high vtable pairs as seeds, the propagation recovered the other half with 35/36
  medium and 49/49 low correct (the miss is the D2 instead of the D1 destructor, same name).
  Typical finds: every class's `InitClass(hClass*)` (the registration functions, by their
  strings), the static `GetClassID`, `HObject` constructors, race/dynamics helpers.
- Applied to config/symbol_addrs.txt (`// type:func gthd` block): 2,899 names (2,101 vtable, 798
  call graph/strings); 2,105 replace a `Class__virtual_NN` as the canonical name, 787 name a
  function that had none; 7 land on functions rtti.py lists as structors (they build an object
  inline, e.g. `hThread::beginCodeFrame`) and stay aliases there. Constructors and destructors
  keep their `Class__structor_N` names (GT HD's D1/D2 and C1/C2 variants do not map one to one).
- Names: `Class__method` with GT4's class spelling (the PS3 twin's methods under the PS2 name),
  namespaces kept (`SPEC_DATABASE__DatabaseStorage__IsExistID`), operators spelled out
  (`operator_inc`), overloads `_const` / `_2`.
- Prototypes: config/gthd_prototypes.json has, for the 416 classes, the 2,942 slots each class
  declares or overrides with the GT HD parameter types and constness (pure virtuals named after
  their first override). Parameter types are GT HD's (`HObject const&`, `mRenderContext*`): the
  same names as GT4's classes, but layouts may have changed in two years.

## Translation units (tools/gthd_units.py, 2026-10-10)

GT HD side: which source file each function is in.
- Anchors: 2,719 functions are locals of a FILE symbol, 937 more reach a static object of one file
  through their TOC loads (statics are private to their unit). Only 429 of the 1,007 files have a
  local function; many have only static data.
- The linker lays the units out in symtab order (anchors of consecutive files are in increasing
  address order, 1 exception): code between two anchors of one file is that file's. gcc 4 ends a
  unit with `__static_initialization_and_destruction_0`, `_GLOBAL__I_`, `_GLOBAL__D_`, but the
  unit's COMDAT template/inline instances (`std_map<...>` members) come *after* them: only weak
  code may follow a closing initialiser in its own unit.
- Gaps between anchors of two files (and files listed between them without anchors): each unit
  has its own `.toc` entries in the same order, so a function's TOC entries place it inside one
  file's TOC range (entries used by two files, or from > 2 MB apart, are shared: ignored); else
  the class name gives the file (`mCarModel` -> `MCarModel.cpp`, 3,766 functions); else the file
  most of the class's placed functions are in.
- Result: of 26,091 GT HD functions 15,153 placed high, 6,521 medium, 4,417 unresolved. Held-out
  check (every other anchor removed and placed again): 1,469 high all right, 186 medium with 7
  wrong (class votes and one TOC case), 169 unresolved.

GT4 side.
- g++ 2.96 closes every unit that has static constructors with 32-byte wrappers
  `_GLOBAL_.I.` (`addiu sp,-16; li a0,1; ...; jal __static_initialization_and_destruction_0;
  ori a1,zero,0xFFFF`) and `_GLOBAL_.D.` (`a0 = 0`): 370 + 320 here. Every one is a hard unit
  boundary: no GT HD file runs across any of them (0 of 197 checked). So 370 of GT4's units have
  exact ends without any GT HD help.
- 2,893 of the 3,619 GT HD pairs land on a placed, non-weak GT HD function and label their GT4
  function with its file. Runs of one file between the hard boundaries give the units; 7 lone
  labels inside another file's run are outliers (a parent's method named for an override, e.g.
  `mNode::doRealize` in MComposite's run).
- config/units_gthd.txt: 453 units; 323 named after 305 GT HD files (17 files in two or three
  runs: the order of the units differs, or a pair is wrong); names high 171 units (8,469
  functions, 1.74 MB), medium 65 (3,149, 0.57 MB), low 87 (13,044, 1.76 MB: one pair naming a
  big block, mostly the library/runtime region 0x4945xx+ where GT HD's PS3 libraries differ:
  check before use). Boundaries: 374 high (initialiser wrappers, adjacent labels of two files),
  39 medium (an RTTI boundary of config/units.txt in the gap), 39 low (somewhere in the gap).
- Against config/units.txt (782 RTTI clusters + anonymous fillers): only 115 of its boundaries
  are real ones; 186 of its units are cut by a high boundary (7 RTTI-named, e.g.
  `mRaceCourseMapFace_mRaceCourseMapFacePS2` spans the end of a unit: two files), and 160 of the
  171 high-named units span several of its units (a class cluster plus anonymous code of the
  same file). Classes and files differ: `mListItem`'s methods sit in MListBox.cpp's unit, the
  "mPhotoMapWindow" cluster at 0x206840 is MComposite.cpp. units_gthd.txt has the same first two
  columns as units.txt, so tools/layout.py could switch to it after review.

Compiler profiles per real unit (the external review: 89 RTTI units mix profiles; the count is
moving while sources' markers are being rewritten: 68 at this run). The proposal has 96 mixed
units (larger units, more chance to hold a deviant); in every one the mix is a handful of marked
sources among dozens of default ones. `--check-profiles` on the 32 named (name not low) mixed
units:
- 24 resolve to one profile: in 22 units with `no-strict-aliasing` sources and 2 with `as2004`,
  every default source also matches when compiled with the minority profile (MCarGarage 135/135,
  cargeometry 197/197, playlist 165/165, h_module 56/56, ...). -fno-strict-aliasing (and the
  2004 assembler) is a per-unit flag that most functions do not react to: these whole units can
  carry the one marker.
- 3 `no-strict-aliasing` units almost: h_thread 357/367, MMusic 33/34, display_objects 227/228
  (the failing default sources are listed in build/gthd/profile_check.json: a boundary to move,
  or a source shape that only matches with strict aliasing).
- `nosib` and `nogcse` do not resolve: MListBox 75/82, display 45/47, base 73/76 default sources
  match with them (the rest need sibling calls / gcse), so the one `nosib` / `nogcse` source in
  such a unit is a source-shape workaround (or misplaced) rather than the unit's flags.
- 6 marked sources match with the default profile too (marker unnecessary): 0x2390E8, 0x2D4990,
  0x2D75F0, 0x2DB4E8, 0x30C2C8 (no-strict-aliasing), 0x3BEC40 (as2004).
- 2 units have several minority profiles (toyotaHybrid; init_ps3_2 at 0x494500, a low-quality
  name over the network stack).

## Globals (tools/gthd_units.py --globals / --apply, 2026-10-10)

- GT HD reaches globals through TOC slots holding their address (sometimes `symbol + offset`);
  GT4 through `lui` + `addiu`/load/store (`-G0`: no gp-relative data). Float constants (`lwc1`
  of an address nothing stores to) and string literals are unnamed on both sides and left out;
  float *variables* (stored somewhere) stay in.
- Pairs of functions vote "GT HD object S starts at A - offset here"; kept when every paired user
  on both sides agrees (high: >= 2 votes), or by elimination (one unexplained datum on each
  side, no paired user contradicting it: medium). A medium object that is a static member of
  the class of every paired function using it is high: every `mX::GetClassID` pair names
  `mX::ClassID_` (149 classes).
- Validation: the 5 GT HD vtables the method paired (`vtable for HCodeFrame`, ...) all land
  exactly 8 bytes before rtti.py's `Class__vtable` (Itanium's offset-to-top and typeinfo words
  precede the address point), i.e. 5/5 right.
- 197 globals paired (172 high, 25 medium); the 172 high ones are in config/symbol_addrs.txt
  (`// type:data gthd` block): the ClassIDs, `RaceCarSound::visual_volume_` and its neighbours,
  `PDISTD::UNIT_MANAGER`, `DisplayRText::rtext_ptrs_`, `HSymbol::OP_*`, `SDDRV::VoiceSystem::master_`.
  Names spelled `Class__member_` (trailing underscore kept), function-local statics
  `Class__method__var`; names already used as identifiers in src/ or include/ are refused (1:
  `effect`). All 690 matched sources that reference one of them still match when their `D_`
  tokens are renamed (symbols.rename_text, as organize.py does).
- Why so few: only ~470 of the 3,186 uniquely paired GT HD functions load a named global at all
  (most methods work on `this`), and GT4 code inlines differently. More pairs of functions, or
  the data layout (GT HD's .data/.bss are per unit in link order too: the named neighbours of a
  paired global, at the same distance here) would extend it.

## Open

- The 171 medium vtable pairs and 116 low call-graph pairs need another witness (a second
  caller, a string, or a matched source that shows what the function does).
- Units: review config/units_gthd.txt (low names, the 39 low boundaries, the 17 files in several
  runs) before tools/layout.py uses it instead of config/units.txt; the 4,417 unresolved GT HD
  functions (gaps between files without anchors) could be placed with the .rodata/.data ranges
  of each unit (string literals and data are laid out per unit too).
- Profiles: the 24 units that resolve to one profile could carry it on every source; the
  failing default sources of h_thread / MMusic / display_objects and the nosib/nogcse sources of
  MListBox / display / base need a look (build/gthd/profile_check.json).
- Globals: 25 medium pairs need a second witness; data-layout neighbours (above) not used yet.
- Tourist Trophy: its classes are not recovered (build/classes.json is empty); its names come
  from GT4's through the twin lists (tools/crossgame.py, neartwin.py), not from GT HD directly.
