# The script engine (Adhoc) and how C++ is exposed to it

Gran Turismo 4 is mostly a scripting engine: the menus, the garage, the game modes and the race set-up are written
in Polyphony's **Adhoc** language, and the executable (`CORE.GT4`) provides the virtual machine and about a thousand
native methods the scripts call. This page describes the C++ side as recovered so far and maps it to the community's
documentation of the language and file formats.

Sources: `config/adhoc_methods.txt` (1,061 native methods and functions in 113 script classes, with callback addresses; attributes are not listed),
`config/classes.json` / `config/symbol_addrs.txt` (RTTI), matched registration code in `src/`, `tools/registration.py`
and gt4.md. Community: [Gran Turismo Modding Hub](https://nenkai.github.io/gt-modding-hub/) (Adhoc explained, `.adc` format,
GT4 build list, GT4 volume and file structure), Nenkai's
[GTAdhocToolchain](https://github.com/Nenkai/GTAdhocToolchain) (MIT; compiler/disassembler, bytecode versions) and
[OpenAdhoc](https://github.com/Nenkai/OpenAdhoc) (GPL-3.0; GT4 script sources, 29 projects). Only names and facts are taken
from them; nothing is copied. Statements marked **inferred** are not verified against the code.

## 1. What the community documents

- Adhoc is "a scripting language and bytecode introduced in Gran Turismo 4". Scripts handle almost all non-race logic and the
  executable runs what they request (hub, *Adhoc Explained*).
- Compiled scripts are `.adc` files (magic `ADCH`, a 3-character version after it). **GT4 retail uses bytecode version 5**; the online
  builds use 7 (GTAdhocToolchain lists 5 = GT4, 7 = GT4 Online, 10 = GT HD, 12 = GTPSP/GT5/GT6/GT Sport). The hub's GT4
  build page says Adhoc 5 supports instructions up to `VARIABLE_PUSH` (opcode 36), and version 7 up to `SOURCE_FILE` (39).
- UI layouts are `.mproject` / `.mwidget` files (XML) with images in `.gpb` containers; the scripts link to and drive the widgets. In the
  volume, scripts live in `script/` and `projects/`, the boot script in `config/` (`config-<branch>.adc`) (hub, *GT4 file structure*).
- OpenAdhoc's GT4 sources are organised in projects such as `arcade`, `boot`, `gtmode`, `network`, `online`, `option`, `photo_shoot`,
  `quick-*`, `ranking`, which line up with the menu-glue units of the executable (coverage-map.md: game-mode menus, online menus, photo mode).
- The hub notes that GT4 does not recover from script exceptions (error handling is stripped). The binary still contains exception and
  try/catch machinery (`hException`, `mTryCatch`, `HTryCatchFrame`), so the classes exist even if scripts do not use them as in later games.

## 2. The VM in the executable

The VM is a set of C++ classes (full list with sizes in [classes.md](classes.md), sections 1-2; units 0x2EA548-0x32E4A0 and 0x5ED000+):

- `RefCounter` (8 bytes: count, vptr) is the root of every heap value. `hObject` (16 bytes) is the base of script values.
  Value types: `hInt` (20), `hFloat`, `hString` (20), `hArray` (36), `hNil`, `hNumeric`, `hFunctionObject`/`hMethodObject`,
  `hModule` (44, a namespace-like container) and `hClass` (56, a script class). `hVariable` has local and module-level kinds.
  `hThread` (76) and `hThreadGroup` give the scripts cooperative threads (natives `Thread.start/stop`, `ThreadGroup.run`).
- **Members of classes and modules** are `hValue` subclasses (12 bytes): `hScriptFunction` / `hScriptMethod` (implemented in bytecode) and
  `hBuiltinFunction` / `hBuiltinMethod` / `hBuiltinAttribute` / `hBuiltinStatic` (implemented in C++). A builtin stores its C++ callback in the object
  (`+0x0C`; attributes also `+0x10`).
- **Bytecode**: `hInst` (8 bytes) has 37 concrete subclasses constructed at 0x319538-0x321xxx, one per opcode, named like the opcodes of the
  community's list (`mCall`, `mJump`, `mJumpZero`, `mJumpNotZero`, `mVariablePush`, `mIntConst`, `mFloatConst`, `mStringConst`, `mNilConst`,
  `mBinaryOperator`, `mUnaryOperator`, `mBinaryAssignOperator`, `mUnaryAssignOperator`, `mAssign`, `mListAssign`, `mAttributePush`,
  `mArrayPush`, `mStringPush`, `mPop`, `mEval`, `mNop`, `mPrint`, `mThrow`, `mTryCatch`, `mUndef`, `mRequire`, `mImport`, `mSetState`,
  `mLogicalAnd`, `mLogicalOr`, and the definitions `mClassDefine`, `mModuleDefine`, `mFunctionDefine`, `mMethodDefine`, `mAttributeDefine`,
  `mLocalDefine`, `mStaticDefine`). That is exactly the 37 opcodes the hub lists for version 5 (ARRAY_CONST_OLD ... VARIABLE_PUSH) and none of the
  later ones (`SOURCE_FILE`, `FUNCTION_CONST`, `MAP_CONST`...), which is consistent with GT4 = version 5. The pairing of a class to a numeric opcode
  is by name/order only (**inferred**; the dispatch table has not been read yet).
- **Frames**: `HFrame` with `HCodeFrame`, `HModuleFrame` and `HTryCatchFrame` (3 virtuals each) are the call/module/try frames; `hCode` (60 bytes)
  is the code object (**inferred**). `hADHOC` (120 bytes) is the interpreter root (**inferred** from the name); `ADHOC::PoolAllocator` is a namespaced type
  in the executable (name only).
- **Symbols**: names are interned to integer ids by `func_003166B8(str)` over a global table at 0x61A100 (`func_00326FD8`); `HSymID` is the RTTI name of the
  id type (**inferred**).

## 3. Making a C++ class visible to scripts

There are two stages: a *class record* created during static initialisation, and a *registration function* that fills the script class with natives.

### 3.1 Class records (static initialisation)

Every native class has a static-init function `f(init, prio)`; gt4.md rule 103 documents the 155 + 70 matched ones (244 solved by
`tools/static_init.py`). Besides 72 tiny ID objects (4 bytes each, numbered 0..0x47), each one builds a **registration record** with
`func_00325010(&table, &name, size, create, register, destroy)`:

```
func_00325010(rec, name, size, cb1, cb2, cb3):   /* matched */
    rec->cb1 = cb1; rec->cb2 = cb2; rec->cb3 = cb3; rec->next = 0;
    printf-like(func_005D4AD8, fmt, name, size);
    func_00324FF0(rec);       /* push onto the global list headed at D_00619E68 (link at +0xC) */
```

The three callbacks follow one shape (e.g. mLoggerControl: func_0011E9F8 / func_0011EA20 / func_0011EA48; size 0x310 = 784 = the instance size):

| callback | what it does (matched sources) |
|---|---|
| cb1 | `D_class = func_00324F98();` - creates the script class object and stores it in a per-class global |
| cb2 | `register_natives(D_class)` - calls the class's registration function, e.g. `func_0011F1E0` |
| cb3 | `D_class = 0;` - tear-down |

So at start-up the engine can walk the linked list at 0x619E68 and create/populate every native class (that the VM does exactly this walk is
**inferred**; the list head and link are matched). The `size` argument matches `virtual_04` of the class.

### 3.2 Registration functions

131 of the 135 registration functions are matched (coverage-map.md; `tools/registration.py` writes them from one template). The shape, e.g.
func_0015CC58:

1. **Class name**: build a string from a literal, then call the class object's virtual at vtable offset `0x190` with it. That slot is `hClass::virtual_49`
   (`func_00305590`), which turns the string into a symbol id and stores it in the class object at `+0x10`.
2. **Parent link**: `func_002F3A30(cls, parent_getter())` stores the parent class pointer at `cls + 0x2C`. The getter is any zero-argument function that
   returns the parent's class global (`func_00309CC0` returns `hObject`'s: D_00619C88; others return another class's global).
3. **Members**: for each native, build the member name as a string (the same literal triple as above), call a registrar, destroy the string.

Functions with no class block (only members) continue the registration of a class started by another function (see section 5).

### 3.3 The registrars

| function | registers | what it does (from `src/` and the splat listings) |
|---|---|---|
| `func_002F3818(cls, &Str, cb)` | method | `sym = func_003166B8(str)`; `func_002F36E0(cls, &sym, cb)` |
| `func_002F36E0(cls, &sym, cb)` | method (symbol already interned; used with a global symbol object) | allocates 0x10 bytes (tag "RefCounter") and constructs a `hBuiltinMethod` (`func_0032DCC0` -> `0x32DC08`: `hMethodValue` ctor, `+0x0C = cb`, vptr), wraps it in a handle, calls `func_003065F0(cls, &holder)`, destroys the holder (`func_0032D9A0(buf, 2)`) |
| `func_003068A8(cls, &Str, cb)` | function | like `002F3818`, via `func_00306780` |
| `func_00306780(cls, &sym, cb)` | function | same as `002F36E0` but a `hBuiltinFunction` (`func_0032D218` -> `0x32D160`) |
| `func_002F3860(cls, &Str, cb1, cb2)` | attribute | interns the name, `func_002F3730` builds a `hBuiltinAttribute` (`func_0032C778` -> `0x32C6B0`): `+0x0C = cb1`, `+0x10 = cb2`, a null callback replaced by the no-op stubs `func_002F3728` (for cb1) and `func_002F3720` (for cb2); then `func_003065F0`. Which callback is the getter and which the setter is **inferred** (first = get) |
| `func_003065F0(cls, &holder)` | insertion | `key = func_00323CD0(holder.obj)` (the member's name symbol), then `func_00306180(cls, key, &holder)` inserts into the class's member table |

The matched source of `func_002F36E0` shows only one parameter because the other two registers pass straight through to the helper (the
registration template in `tools/registration.py` uses the true 3-argument form).

How the registrars are used across the matched registration functions (181 files that contain the class-link call; counts are registration blocks, approximate):
about 820 methods (`002F3818`), 120 functions (`003068A8`; e.g. all of `MCarData`'s capitalised `GetCarName`-style natives, which look like static
functions called on the class rather than on an instance, **inferred**), 570 attributes (`002F3860`) and 220 registrations by global symbol
(`00306780` / `002F36E0` with a `.bss` symbol object instead of a string). Attributes are properties with a getter and/or setter: for example the logger
class registers `mode` with both callbacks, `course_label` with a getter only (cb2 = 0) and `load_track` with a setter only (cb1 = 0), which fixes
cb1 = getter, cb2 = setter.

String helpers in the template (all in `knowledge/runtime-types.md`): `func_005C2560` (clone a selfish rep), `func_005C2630` (replace/assign),
`func_0057F260` (strlen), `func_005C11A8` (allocator-name singleton) and `func_00326798` (sized free), plus the empty rep `D_00659FA8`.

## 4. How a script reaches C++

1. The script is compiled bytecode (`.adc`) loaded as a `hCode` into a module; a `mCall` instruction evaluates the target and arguments.
2. Resolving `object.method` looks the member up in the object's `hClass` (and then its parents via `+0x2C`) in the table that the
   registration functions filled.
3. Invoking a `hBuiltinMethod` goes through its virtual 14 (`func_0032DA40`): it loads the callback from `+0x0C` and `jalr`s it, then moves the result handle
   into the frame (retain/release around the store, same idiom as in every native).
4. The callback runs the game logic and writes its result with the **handle-assign idiom** into the slot it received (see
   [runtime-types.md](runtime-types.md)).

### Callback shapes seen in matched code

- Getters returning numbers: query the game (`func_00448528()`), box the result (`func_002FE278` -> `hInt`), assign into the return slot, destroy the temporary
  handle (e.g. `MCarData.GetCarLabelCount`, 0x12DC60).
- Getters taking a string argument: the argument is read through a handle (`func_00312370`), the `Str` extracted (`func_00314920`), `c_str()` inline, a game
  query fills a local buffer (`func_00127C48`), a new string is built and wrapped as `hString` (`func_00314B20`) and assigned to the return slot
  (e.g. `MQuickWork.getCatPs`, 0x1251D8; the callback takes `(Handle *ret, ..., int argc, args)`).
- Methods acting on `this`: obtain the current object from the VM (a zero-argument helper builds a handle), call the C++ member, destroy the handle
  (`MChaseActor.doStop` 0x2839C8, `MCarGarage.updateCurrentStatus` 0x141518). Several matched callbacks are plain `void f(void)` because they do not touch
  the argument registers.
- **Debug natives are stubs in retail**: `MSystem.SetDrawPerfMeter`, `IsDrawPerfMeter`, `DumpMemoryBlock`, `LoadKanjiFont`, `UnloadKanjiFont` and
  `MemoryBlockDump` are 40-byte empty functions.

## 5. The native classes

`config/adhoc_methods.txt` lists 1,061 methods and static functions (the one-callback registrations) in 113 script classes; 419 of those callbacks already
have a matched source. **Attributes (properties registered through `func_002F3860`) and global-symbol registrations are not in that list**, so the real
number of script-visible members is considerably larger (a count over the matched registration functions suggests roughly 1.5 to 2 times). Largest: `MNetwork` 163 (66 matched), `MCarGarage` 83 (56),
`MGame` 47 (15), a 46-method continuation `func_0014EF00` (14), `MCarData` 29 (4), `MMemoryCardManager` 25 (15), `MRenderContext` 24 (8),
`MPhotoRenderFace` 23 (9), `MCalendar` 21 (0), `MSystem` 21 (13), `MRaceData` 19 (12), `MRunViewer` 19 (6), `MNetConf` 18 (1), `MListBox` 18 (11).

Script class `MFoo` is C++ class `mFoo` (96 of the 113 names; see [classes.md](classes.md) for per-class natives, sizes and parents). Classes by role:

| role | classes |
|---|---|
| game data | `MCarData`, `MCarGarage`, `MGarage`, `MGame`, `MOption`, `MRaceData`, `MRaceRecord(Unit)`, `MCourseRecord(Unit)`, `MLicenseRecord(Unit)`, `MCalendar`, `MPresent`, `MUsedCar`, `MDatabase`, `MCourseData`, `MFavorite`, `MPlayList`, `MQuickWork`, `MRunViewer`, `MDemonstration`, `MLoggerControl` |
| save / storage | `MMemoryCardManager`, `MMemoryCardFile`, `MMemoryCardPlayList`, `MMemorycardProgress`, `MStorage`, `MStorageEntry`, `MGameStats`, `MPlayerStats` (`pack`/`unpack`) |
| network | `MNetwork`, `MNetConf`, `MHttp`, `MDnas`, `MDnasInst`, `MComm` |
| UI | `MWidget`, `MComposite`, `MRootWindow`, `MListBox`, `MSelectBox`, `MSelectBar`, `MScaleBar`, `MSliderBar`, `MTextFace`, `MImageFace`, `MModelFace`, `MCarFace`, `MMovieFace`, `MFlashFace`, `MPhotoRenderFace`, `MSlideShowFace`, actors (`MMoveActor`...), `MTransition`, `MProject`, `MManager`, `MRenderContext`, `MUpdateContext` |
| platform / system | `MSystem`, `MLocale`, `MUnit`, `MUtility`, `MRandom`, `MSound`, `MMusic`, `MEyetoy`, `MGamePort`, `MGpb`, `MXml`, `MDomNode`, `MShell`, `MPipe`, `MWatcher`, `MTransform`, `MColorObject` |
| language library | `Module`, `Numeric`, `string`, `Thread`, `ThreadGroup`, `IO`, `FileIO` |

### Registration functions whose class string is not in the list

Ten groups in `adhoc_methods.txt` are named `func_<address>` because the registration function has no class block. By their method names (**inferred**):

| group | methods | probably |
|---|---|---|
| `func_002EE208` | unshift, shift, pack, push, pop, join, bsearch, move, sort, erase | the Array class (`hArray`) |
| `func_002F1CB0` | nilp | Nil (`hNil`) |
| `func_00302110` | sin, cos | a math module |
| `func_00309D00` | toString, toFloat, toInt, dump, getDeepCopy | the base Object class (`hObject`) |
| `func_0030E100` | GetRelative, GetAbsolute, GetBaseName, GetDirName, GetCurrentDir, IsAbsolute | a path utility module |
| `func_00316EA8` | exit, MemoryBlockDump | global system functions |
| `func_00317C80` | GetMicroSecond | a time module |
| `func_0026DC30` | LoadKanjiFont, UnloadKanjiFont | font functions |
| `func_0014EF00` | gear ratio/engine curve/brake controller/drive train settings | continuation of the `MCarGarage` registration (adjacent address; 83 + 46 natives) |
| `func_00191C20` | clear/unset/set/get/search analog and button configuration | controller key/analog configuration; class unknown |

## 6. Gaps

- The interpreter loop (`hADHOC`, frame handling, dispatch of the `hInst` subclasses) is mostly unmatched; this page therefore describes object layout and
  registration, not execution.
- Argument passing into callbacks (how `argc`/arguments reach them) is visible only in a few matched examples; a complete calling convention is not yet derived.
- The mapping from the `.adc` opcode numbers to the `hInst` classes, and the binary format of `.adc` as loaded by `hCode`, are documented by the community, not re-derived here.
- `hBuiltinStatic` has no identified registrar.
