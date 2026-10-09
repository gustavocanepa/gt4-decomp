# Class hierarchy (from RTTI)

The engine's class list, recovered from the g++ RTTI that the executable carries: `config/classes.json`
has 509 classes (490 with a vtable), `config/symbol_addrs.txt` has 5,458 function names derived from them
(`Class__virtual_NN`, `Class__structor_N`, `Class__tf`) plus the vtable addresses, and `tools/rtti.py` writes the
type-name list to `build/rtti_names.txt` (generated, not in the repository). Everything on this page is derived from those files plus the matched sources in `src/`;
where a purpose is guessed from a name or from the shape of the code it says **inferred**.
The big picture (subsystems, address ranges, how they connect) is in [architecture.md](architecture.md);
the script side is in [script-engine.md](script-engine.md) and the basic types in [runtime-types.md](runtime-types.md).

## How to read the entries

`- \`Class\` (size N; vtable 0xADDR, K slots; m/t fns matched; n natives) [parent \`P\`] - note`

- **size**: the constant returned by the class's `virtual_04`, when that function is matched. It agrees with the
  allocation sizes seen at constructors and destructors (hInt 0x14, hBuiltinMethod 0x10, hString 20) and grows with
  inheritance (mWidget 160, mComposite 176, mBox 192, mHBox 208), so it is read as the instance size in bytes
  (checked on those classes; inferred for the others).
- **vtable, slots**: address of the primary vtable and the number of entries after the type_info word.
  Layout (verified on hClass at 0x6736A8): each entry is 8 bytes `{short delta; short index; void *fn}` with the function
  at +4; entry 0 is the type_info pointer, entry `i + 1` is `virtual_i`. The vptr is at object offset +4 for every
  `RefCounter`-derived class (offset 0 holds the reference count word).
- **fns matched**: RTTI-named functions (virtuals and constructors/destructors in `symbol_addrs.txt`) that have a matched
  source in `src/`, out of those that exist (snapshot of 2026-10-08). Library-wide numbers are in
  [coverage-map.md](coverage-map.md).
- **natives**: script-callable methods registered for the class (`config/adhoc_methods.txt`, 1,061 entries in 113 script
  classes). Script class `MFoo` corresponds to the C++ class `mFoo` (96 of the 113 script names map this way; the
  rest are `Module`, `Numeric`, `string`, `Thread`, `ThreadGroup`, `IO`, `FileIO` and ten registration functions whose
  class string was not captured, listed in [script-engine.md](script-engine.md)).
- Naming prefixes: `h*` are the script virtual machine's value types, `m*` are native classes exposed to scripts
  (data model, UI widgets, events, platform services; and also the bytecode instruction classes, which reuse the
  `m` prefix), `M*`/`If*` are reader/filter helpers, the rest (`Race*`, `Dynamics*`, `Car*`...) are plain C++ game classes
  that scripts do not see directly. `...PS2` classes are the PlayStation 2 implementations of a platform interface.

Inheritance on this page is the first base recorded in `classes.json` (every class has at most one); a class is
listed under its parent when the parent is in the same section, otherwise with `[parent X]`.

## 1. Script virtual machine: values and members

The Adhoc VM's object model. Everything a script can hold is a `RefCounter`-derived heap object; native members are `hValue` subclasses. See [script-engine.md](script-engine.md).

- `HFrame` (vtable 0x676580, 3 slots; 0/4 fns matched) - call-frame base; code, module and try/catch frames below
  - `HCodeFrame` (vtable 0x6763c0, 3 slots; 1/4 fns matched)
  - `HModuleFrame` (vtable 0x676398, 3 slots; 2/4 fns matched)
  - `HTryCatchFrame` (vtable 0x676370, 3 slots; 1/4 fns matched)
- `HSymID` (no vtable) - interned symbol id (RTTI name only); string-to-symbol is func_003166B8 over a global table at 0x61A100
- `RefCounter` (vtable 0x676958, 8 slots; 3/3 fns matched) - root of every script-visible heap value; 8 bytes with the vptr at +4 (matched destructor 0x328450); objects are allocated through the tagged allocator with the tag string "RefCounter"
  - `hADHOC` (size 120; vtable 0x6732e8, 8 slots; 2/5 fns matched) - interpreter/VM root object (inferred from the name and from the unit 0x2EA548 sitting before the Array/Class types); 120 bytes
  - `hObject` (size 16; vtable 0x674f30, 49 slots; 4/6 fns matched) - base of all script values and native classes; 16 bytes: refcount word, vptr at +4, +8 (lazily filled through virtual 9, inferred), +0xC cleared by the constructor (0x30A678). Virtual 3 returns the class descriptor, virtual 4 returns sizeof
    - `hArray` (size 36; vtable 0x673358, 49 slots; 6/14 fns matched) - script array, 36 bytes; natives unshift, shift, pack, push, pop, join, bsearch, move, sort, erase (registered by func_002EE208, whose class string is not captured in adhoc_methods.txt)
    - `hArrayElement` (size 24; vtable 0x673510, 49 slots; 6/8 fns matched)
    - `hCode` (size 60; vtable 0x673850, 49 slots; 3/5 fns matched) - compiled code block (60 bytes; inferred from the name)
    - `hException` (size 20; vtable 0x6739e8, 49 slots; 5/6 fns matched) - exception object (20 bytes)
    - `hFloat` (size 20; vtable 0x673d60, 49 slots; 6/31 fns matched) - boxed float, same operator-slot run as hInt (virtuals 21-41)
    - `hFunctionObject` (size 20; vtable 0x673ef8, 49 slots; 5/9 fns matched)
    - `hIO` (size 20; vtable 0x674320, 58 slots; 6/6 fns matched) - stream base with natives read, write
      - `hFileIO` (size 252; vtable 0x673b80, 58 slots; 5/14 fns matched) - file object, 252 bytes; natives open, close
    - `hInt` (size 20; vtable 0x674188, 49 slots; 10/37 fns matched) - boxed integer, 0x14 bytes (the destructor 0x2FE1D8 frees 0x14 with tag "RefCounter"); virtuals 21-43 form a run of operator slots (arithmetic/compare, inferred)
    - `hMethodObject` (size 24; vtable 0x674830, 49 slots; 3/8 fns matched)
    - `hModule` (size 44; vtable 0x674a58, 51 slots; 4/8 fns matched) - namespace-like container (44 bytes); natives load, defined, defineStatic, removeStatic, clearStatic
      - `hClass` (size 56; vtable 0x6736a8, 51 slots; 8/13 fns matched) - script class object (56 bytes): +0x10 class-name symbol id (set by virtual 49 = func_00305590), +0x28 counter (virtual 6 decrements and tests zero), +0x2C parent class (func_002F3A30); holds the table of native members filled by the registration functions
    - `hNil` (size 16; vtable 0x674500, 49 slots; 5/7 fns matched) - the nil value; native nilp (func_002F1CB0)
    - `hNumeric` (size 16; vtable 0x674d98, 49 slots; 6/6 fns matched) - numeric base; natives toFloat, toInt
    - `hString` (size 20; vtable 0x675268, 49 slots; 5/16 fns matched) - script string, 20 bytes: the character pointer is at +0x10 and points into a ref-counted string (see runtime-types.md); natives at, split, substr, format, upcase, downcase, build
    - `hThread` (size 76; vtable 0x6763e8, 49 slots; 3/5 fns matched) - script thread (76 bytes); natives Thread.start, Thread.stop
    - `hThreadGroup` (size 28; vtable 0x6765a8, 49 slots; 3/6 fns matched) - set of threads; natives getCurrent, append, run
    - `hVariable` (size 20; vtable 0x6767c0, 49 slots; 5/5 fns matched) - variable slot base; hLocalVariable and hModuleVariable are the local and module-level kinds
      - `hLocalVariable` (size 24; vtable 0x674698, 49 slots; 8/9 fns matched)
      - `hModuleVariable` (size 28; vtable 0x674c00, 49 slots; 5/9 fns matched)
  - `hValue` (size 12; vtable 0x676740, 14 slots; 4/4 fns matched) - base of function/method/attribute/static members (12 bytes)
    - `hAttribute` (size 16; vtable 0x6769a8, 14 slots; 8/11 fns matched)
    - `hBuiltinAttribute` (size 20; vtable 0x676a28, 14 slots; 7/9 fns matched) - native attribute: two callbacks at +0x0C and +0x10 (constructor 0x32C6B0), defaulted to no-op stubs func_002F3728 / func_002F3720 when null; registered by func_002F3860
    - `hBuiltinStatic` (size 20; vtable 0x676bc8, 14 slots; 7/9 fns matched) - native static value (20 bytes); no registration helper identified yet
    - `hFunctionValue` (size 12; vtable 0x674090, 16 slots; 6/8 fns matched)
      - `hBuiltinFunction` (size 16; vtable 0x676aa8, 16 slots; 5/7 fns matched) - native function: callback at +0x0C (constructor 0x32D160); registered by func_003068A8 / func_00306780
      - `hScriptFunction` (size 16; vtable 0x6750c8, 16 slots; 6/8 fns matched) - function implemented in script bytecode (inferred from the name)
    - `hMethodValue` (size 12; vtable 0x6749c8, 16 slots; 7/8 fns matched)
      - `hBuiltinMethod` (size 16; vtable 0x676b38, 16 slots; 5/7 fns matched) - native method: constructor 0x32DC08 stores the C++ callback at +0x0C; registered by func_002F3818 / func_002F36E0
      - `hScriptMethod` (size 16; vtable 0x675158, 16 slots; 6/8 fns matched) - method implemented in script bytecode (inferred from the name)
    - `hStaticValue` (size 16; vtable 0x6751e8, 14 slots; 11/12 fns matched)
- `hArrayCompare` (vtable 0x65b5a0, 2 slots; 5/8 fns matched) - comparison functor for hArray sort/bsearch (inferred)
  - `FunctionCompare` (vtable 0x673338, 2 slots; 0/3 fns matched)

## 2. Script virtual machine: bytecode instructions

`hInst` (8 bytes) with one subclass per Adhoc opcode, constructed at 0x319538-0x321xxx (`hInst__structor_N`). Each class name is the opcode name in CamelCase, so they line up with the instruction names of the community's bytecode documentation (version 5 = 37 opcodes, up to VARIABLE_PUSH).

- `hInst` (size 8; vtable 0x674120, 11 slots; 30/38 fns matched) - bytecode instruction base, 8 bytes (refcount + vptr); one subclass per Adhoc opcode, see script-engine.md [parent `RefCounter`]
  - `mArrayPush` (size 12; vtable 0x676238, 11 slots; 4/6 fns matched)
  - `mAssign` (size 8; vtable 0x6761d0, 11 slots; 5/6 fns matched)
  - `mAttributePush` (size 12; vtable 0x676100, 11 slots; 4/6 fns matched)
  - `mBinaryAssignOperator` (size 20; vtable 0x676098, 11 slots; 4/6 fns matched)
  - `mBinaryOperator` (size 20; vtable 0x676030, 11 slots; 4/6 fns matched)
  - `mCall` (size 12; vtable 0x675fc8, 11 slots; 4/6 fns matched)
  - `mClassDefine` (size 32; vtable 0x675f60, 11 slots; 3/6 fns matched)
  - `mDefine` (size 12; vtable 0x6762a0, 11 slots; 4/4 fns matched)
    - `mAttributeDefine` (size 16; vtable 0x676168, 11 slots; 4/5 fns matched)
    - `mFunctionDefine` (size 16; vtable 0x675e28, 11 slots; 4/6 fns matched)
    - `mLocalDefine` (size 12; vtable 0x675b50, 11 slots; 5/5 fns matched)
    - `mMethodDefine` (size 16; vtable 0x675a18, 11 slots; 4/6 fns matched)
    - `mStaticDefine` (size 16; vtable 0x6756d8, 11 slots; 4/7 fns matched)
  - `mEval` (size 8; vtable 0x675ef8, 11 slots; 4/6 fns matched)
  - `mFloatConst` (size 12; vtable 0x675e90, 11 slots; 4/6 fns matched)
  - `mImport` (size 28; vtable 0x675dc0, 11 slots; 3/6 fns matched)
  - `mIntConst` (size 12; vtable 0x675d58, 11 slots; 4/6 fns matched)
  - `mJump` (size 12; vtable 0x675cf0, 11 slots; 5/7 fns matched)
  - `mJumpNotZero` (size 12; vtable 0x675c88, 11 slots; 5/7 fns matched)
  - `mJumpZero` (size 12; vtable 0x675c20, 11 slots; 5/7 fns matched)
  - `mListAssign` (size 12; vtable 0x675bb8, 11 slots; 4/6 fns matched)
  - `mLogicalAnd` (size 12; vtable 0x675ae8, 11 slots; 5/7 fns matched)
  - `mLogicalOr` (size 12; vtable 0x675a80, 11 slots; 5/7 fns matched)
  - `mModuleDefine` (size 28; vtable 0x6759b0, 11 slots; 4/6 fns matched)
  - `mNilConst` (size 8; vtable 0x675948, 11 slots; 5/6 fns matched)
  - `mNop` (size 12; vtable 0x6758e0, 11 slots; 5/6 fns matched)
  - `mPop` (size 8; vtable 0x675878, 11 slots; 5/6 fns matched)
  - `mPrint` (size 12; vtable 0x675810, 11 slots; 4/6 fns matched)
  - `mRequire` (size 8; vtable 0x6757a8, 11 slots; 5/6 fns matched)
  - `mSetState` (size 12; vtable 0x675740, 11 slots; 5/6 fns matched)
  - `mStringConst` (size 12; vtable 0x675670, 11 slots; 3/6 fns matched)
  - `mStringPush` (size 12; vtable 0x675608, 11 slots; 4/6 fns matched)
  - `mThrow` (size 8; vtable 0x6755a0, 11 slots; 6/6 fns matched)
  - `mTryCatch` (size 12; vtable 0x675538, 11 slots; 5/6 fns matched)
  - `mUnaryAssignOperator` (size 20; vtable 0x6754d0, 11 slots; 4/6 fns matched)
  - `mUnaryOperator` (size 20; vtable 0x675468, 11 slots; 4/6 fns matched)
  - `mUndef` (size 24; vtable 0x675400, 11 slots; 4/6 fns matched)
  - `mVariablePush` (size 28; vtable 0x676308, 11 slots; 3/6 fns matched)

## 3. Native classes: game data model

Classes that scripts query for car, garage, race and record data. They derive from `hObject` and their constructors/virtuals are tiny; the substance is in their registered natives (callbacks near each class's unit).

- `mCalendar` (size 20; vtable 0x65af28, 49 slots; 4/5 fns matched; 21 natives) - GT-mode calendar: elapsed week/date and events such as putBuyNewCarEvent, putBuyUsedCarEvent, putPresentCarEvent, putRunRaceEvent [parent `hObject`]
- `mCarData` (size 16; vtable 0x65ad90, 49 slots; 5/5 fns matched; 29 natives) - SpecDB car queries; natives IsExist, GetCarLabel, GetCarName, GetMaker, GetCountry, GetCategory, IsDirtRunnable, GetDirtCarCode, GetSnowCarCode... [parent `hObject`]
- `mCarGarage` (size 400; vtable 0x65b408, 49 slots; 4/9 fns matched; 83 natives) - the player's garage car as the script sees it: colours, parts, performance; 83 natives plus 46 more (gear ratios, engine curve, brake controller, drivetrain: registered by func_0014EF00, whose class string is not captured) [parent `hObject`]
- `mCourseData` (size 16; vtable 0x65ef60, 49 slots; 5/5 fns matched; 4 natives) - course data queries: max car count, type, id, attribute string [parent `hObject`]
- `mCourseRecord` (size 20; vtable 0x65bdc0, 49 slots; 4/5 fns matched; 3 natives) - per-course records; create, getUnit, getMTUnit [parent `hObject`]
- `mCourseRecordUnit` (size 20; vtable 0x65bf58, 49 slots; 4/5 fns matched; 12 natives) - one course record entry: rank count, best time/speed, date, car name, pass code [parent `hObject`]
- `mDatabase` (size 16; vtable 0x65f0f8, 49 slots; 5/5 fns matched; 14 natives) - SpecDB label queries: course, race and car labels, makers [parent `hObject`]
- `mDemonstration` (size 20; vtable 0x65c0f0, 49 slots; 4/5 fns matched; 3 natives) - demo mode: initialize, resetPlayListCounter, resetMovieCount [parent `hObject`]
- `mFavorite` (size 20; vtable 0x660880, 49 slots; 4/5 fns matched; 8 natives) - favourite list: has, append, remove, buildLabelList, isFull [parent `hObject`]
- `mGame` (size 24; vtable 0x65c288, 49 slots; 3/6 fns matched; 47 natives) - game-wide state: config script, options, entry car, battle settings, valid game data check (47 natives) [parent `hObject`]
- `mGarage` (size 20; vtable 0x65c5b8, 49 slots; 4/5 fns matched; 16 natives) - the car list: addCar, addNewCar, addUsedCar, delCar, undelCar, setRidingCar... [parent `hObject`]
- `mLicenseRecord` (size 20; vtable 0x65c750, 49 slots; 4/5 fns matched; 1 natives) - licence test results; getUnit [parent `hObject`]
- `mLicenseRecordUnit` (size 20; vtable 0x65c8e8, 49 slots; 4/5 fns matched; 7 natives) [parent `hObject`]
- `mOption` (size 5840; vtable 0x65d2e8, 49 slots; 5/6 fns matched; 11 natives) - options store, 5,840 bytes; natives setDefault, apply, getDeviceConfig/setDeviceConfig, getDeviceFeedback... [parent `hObject`]
- `mPlayList` (size 20; vtable 0x65dc68, 49 slots; 4/5 fns matched; 2 natives) - music play list: initStraight, initShuffle [parent `hObject`]
- `mPresent` (size 20; vtable 0x65de00, 49 slots; 4/5 fns matched; 5 natives) - prize/present tables: getByRace, setByRace, getByTime, setByTime [parent `hObject`]
- `mQuickWork` (size 16; vtable 0x65a2b0, 49 slots; 5/5 fns matched; 8 natives) - quick-race grid info: grid car names, colour chip, power, weight, tire type, grid time [parent `hObject`]
- `mRaceData` (size 192; vtable 0x65df98, 49 slots; 5/5 fns matched; 19 natives) - race/event definition lookups: required license, drivetrain, aspiration, car type, tire, PS, price (19 natives) [parent `hObject`]
- `mRaceRecord` (size 20; vtable 0x65e130, 49 slots; 4/5 fns matched; 7 natives) - race records: license gold/silver/bronze queries, mission clear [parent `hObject`]
- `mRaceRecordUnit` (size 20; vtable 0x65e2c8, 49 slots; 4/5 fns matched; 3 natives) [parent `hObject`]
- `mRunViewer` (size 20; vtable 0x65e460, 49 slots; 4/5 fns matched; 19 natives) - the current run's setup shared between menus and race: entry car code/colour, message, race type (inferred) [parent `hObject`]
- `mUsedCar` (size 20; vtable 0x65edc8, 49 slots; 4/5 fns matched; 2 natives) - used-car lot get/set [parent `hObject`]

## 4. Native classes: save data and storage

Memory card, storage devices, save-game blocks.

- `SettingSerialize` (size 2560; vtable 0x688560, 9 slots; 9/12 fns matched) - settings (de)serialiser, 2,560 bytes
- `mGameStats` (size 272; vtable 0x65c420, 49 slots; 5/6 fns matched; 2 natives) - save-game stats block with pack/unpack (272 bytes) [parent `hObject`]
- `mGpb` (size 24; vtable 0x66c460, 49 slots; 5/6 fns matched; 3 natives) - UI asset container (.gpb) load/unload/get [parent `hObject`]
- `mMemoryCardFile` (size 24; vtable 0x65cc48, 49 slots; 3/6 fns matched; 17 natives) - one save file: save, saveNew, saveDnas, load, remove [parent `hObject`]
- `mMemoryCardManager` (size 52; vtable 0x65ce20, 49 slots; 3/6 fns matched; 25 natives) - memory-card service: save, isConnect, isFormat, isChanged, isNoFile... [parent `hObject`]
- `mMemoryCardPlayList` (size 28; vtable 0x65cfb8, 49 slots; 3/6 fns matched; 8 natives) [parent `hObject`]
- `mMemorycardProgress` (size 16; vtable 0x65d150, 49 slots; 5/5 fns matched; 2 natives) [parent `hObject`]
- `mPlayerStats` (size 272; vtable 0x65dad0, 49 slots; 4/6 fns matched; 2 natives) - player stats block with pack/unpack (272 bytes) [parent `hObject`]
- `mProgress` (size 44; vtable 0x664bb8, 49 slots; 3/5 fns matched) [parent `hObject`]
- `mStorage` (size 20; vtable 0x665fa0, 59 slots; 7/8 fns matched; 11 natives) - storage abstraction (memory card / hard disk / USB): getStorage, isRemovable, isFormatted, getFreeSize, doFormat [parent `hObject`]
  - `mStorageHD` (size 20; vtable 0x666188, 59 slots; 9/15 fns matched)
  - `mStorageMC` (size 20; vtable 0x668308, 59 slots; 13/15 fns matched)
- `mStorageEntry` (size 184; vtable 0x6720e0, 49 slots; 4/6 fns matched; 3 natives) - directory entry: isDirectory, isFile, isSymLink [parent `hObject`]

## 5. Native classes: network and online

The script-facing online layer. The C network stack behind it (XML, GameSpy-style transport) is in the unnamed unit at 0x494578-0x54DB98 and has no RTTI.

- `mComm` (size 36; vtable 0x667bf0, 49 slots; 4/5 fns matched; 5 natives) - raw sockets: gethostbyname, connect, send, receive, close [parent `hObject`]
- `mDnas` (size 56; vtable 0x66aa40, 49 slots; 4/5 fns matched; 8 natives) - Sony DNAS authentication: Initialize, RequestAuthorization, RequestId, IsDone, Abort [parent `hObject`]
- `mDnasInst` (size 28; vtable 0x6621a0, 49 slots; 3/5 fns matched; 2 natives) [parent `hObject`]
- `mHttp` (size 272; vtable 0x662008, 49 slots; 3/5 fns matched; 14 natives) - HTTP client: GET, POST, SVOLOGIN, response and transaction status [parent `hObject`]
- `mNetConf` (size 616; vtable 0x6646a0, 104 slots; 4/6 fns matched; 18 natives) - network configuration (netcnf) queries, 616 bytes; PS2 subclass 1,136 bytes [parent `hObject`]
  - `mNetConfPS2` (size 1136; vtable 0x667fb8, 104 slots; 42/61 fns matched)
- `mNetwork` (size 508; vtable 0x662338, 49 slots; 3/5 fns matched; 163 natives) - online/LAN layer exposed to scripts, 508 bytes, 163 natives: interface/network init, login, lobby channels, game list/create/join, buddy and ignore lists, account stats, LAN games, race-menu synchronisation (raceMenu*), file put/get, instant messages, billing [parent `hObject`]
- `mSession` (size 16; vtable 0x671c00, 49 slots; 5/5 fns matched) [parent `hObject`]

## 6. Native classes: platform, input and system services

Rendering and update contexts, controller ports, EyeToy, locale, random numbers, system queries, and a few arena/pool helpers.

- `EyeToyPS2` (vtable 0x660c90, 1 slot; 1/2 fns matched) - EyeToy platform glue
- `RelocatorBase` (vtable 0x689ec8, 1 slot; 2/2 fns matched)
- `_UnitArenaBase` (vtable 0x6888a8, 2 slots; 3/3 fns matched)
- `fpool` (vtable 0x689cf8, 1 slot; 1/2 fns matched)
- `mColorObject` (size 32; vtable 0x662d60, 49 slots; 6/6 fns matched; 1 natives) [parent `hObject`]
- `mEyetoy` (size 16; vtable 0x65f290, 86 slots; 42/42 fns matched; 5 natives) - EyeToy camera: initialize, start_camera, stop_camera, update_camera [parent `hObject`]
  - `mEyetoyPS2` (vtable 0x6605c0, 86 slots; 31/39 fns matched)
- `mEyetoyImageProcessor` (size 16; vtable 0x65f860, 55 slots; 11/11 fns matched) [parent `hObject`]
  - `mGTShirt` (size 16; vtable 0x65fa28, 77 slots; 27/27 fns matched; 1 natives) - GT-shirt (EyeToy) image processing; clear
    - `mGTShirtPS2` (vtable 0x660a18, 77 slots; 22/28 fns matched)
- `mGameInputAnalog` (size 84; vtable 0x66c2c8, 49 slots; 4/6 fns matched) [parent `hObject`]
- `mGameInputButton` (size 52; vtable 0x66c130, 49 slots; 5/6 fns matched) [parent `hObject`]
- `mGameInputData` (size 196; vtable 0x66bf98, 49 slots; 4/5 fns matched) [parent `hObject`]
- `mGamePort` (size 200; vtable 0x66be00, 49 slots; 3/5 fns matched; 1 natives) - controller port; update [parent `hObject`]
- `mLocale` (size 16; vtable 0x66e6a8, 49 slots; 5/5 fns matched; 3 natives) - locale get/set, isPal [parent `hObject`]
- `mLocalizedText` (size 16; vtable 0x66e840, 9 slots; 2/5 fns matched) [parent `RefCounter`]
- `mLoggerControl` (size 784; vtable 0x65a118, 49 slots; 37/47 fns matched; 8 natives) - race data logger control, 784 bytes: analyze_start/stop and per-lap setters [parent `hObject`]
- `mOSKeyboard` (size 104; vtable 0x66f598, 8 slots; 2/4 fns matched) [parent `RefCounter`]
- `mPipe` (size 336; vtable 0x6649f0, 49 slots; 5/5 fns matched; 4 natives) [parent `hObject`]
- `mRandom` (size 16; vtable 0x66fc40, 49 slots; 4/5 fns matched; 2 natives) - GetValue/getValue [parent `hObject`]
- `mRenderContext` (size 7516; vtable 0x665160, 77 slots; 6/8 fns matched; 24 natives) - UI renderer state, 7,516 bytes: startPage, closePage, pushPage, loadGpb, captureScreen [parent `hObject`]
  - `mRenderContextPS2` (size 7596; vtable 0x663be0, 77 slots; 14/33 fns matched)
- `mShell` (size 20; vtable 0x665c70, 49 slots; 5/5 fns matched; 3 natives) - debug shell: putMessage, execute, getCandidates [parent `hObject`]
- `mSystem` (size 16; vtable 0x65e900, 49 slots; 4/4 fns matched; 21 natives) - platform queries: version string/branch/build number, region code, language, video system, date-time strings, DNAS code, reboot; debug hooks (SetDrawPerfMeter, DumpMemoryBlock) are empty in the retail build [parent `hObject`]
- `mTransform` (size 52; vtable 0x666980, 49 slots; 4/6 fns matched; 6 natives) [parent `hObject`]
- `mUnit` (size 16; vtable 0x65ea98, 49 slots; 4/4 fns matched; 12 natives) - unit-system formatting (course length/height, velocity, calendar order) [parent `hObject`]
- `mUpdateContext` (size 300; vtable 0x666db0, 72 slots; 4/8 fns matched; 16 natives) - per-frame UI update state: pad buttons and analog channels, render context, start page [parent `hObject`]
  - `mUpdateContextPS2` (size 1076; vtable 0x663990, 72 slots; 9/28 fns matched)
- `mUtility` (size 16; vtable 0x65ec30, 49 slots; 5/5 fns matched; 4 natives) - string formatting: time, money, format string, price magnification [parent `hObject`]
- `mWindowContext` (size 52; vtable 0x6676f0, 49 slots; 3/5 fns matched) - window/display context; PS2 subclass [parent `hObject`]
  - `mWindowContextPS2` (size 52; vtable 0x667558, 49 slots; 5/5 fns matched)
- `rbuf` (vtable 0x689958, 1 slot; 0/2 fns matched)

## 7. UI: widgets and faces

`mWidget` (child of `hModule`, so a widget is also a script module) is the root. Containers (`mComposite`, boxes, scroll windows) arrange children; `*Face` classes draw content. Unit range 0x1FC4D8-0x2EA548.

- `mWidget` (size 160; vtable 0x667220, 95 slots; 4/6 fns matched; 6 natives) - root of the UI tree, parent hModule; 160 bytes, 95 vtable slots; natives getActor, setActor, doInitialize, doCopy, interpolateX/Y [parent `hModule`]
  - `mBlurFace` (size 172; vtable 0x668c10, 95 slots; 4/9 fns matched)
  - `mCarFace` (size 700; vtable 0x65b0c0, 95 slots; 3/11 fns matched; 7 natives) - car display face (700 bytes): image path, colour index, model set/motion loading
  - `mColorChipFace` (size 220; vtable 0x65bab8, 95 slots; 4/11 fns matched; 2 natives)
  - `mColorFace` (size 184; vtable 0x669e48, 95 slots; 3/8 fns matched; 4 natives)
    - `mGraphFace` (size 2244; vtable 0x66c5f8, 95 slots; 3/8 fns matched; 1 natives) - graph plot face (2,244 bytes): changePoints
    - `mImageFace` (size 240; vtable 0x66cc78, 95 slots; 3/10 fns matched; 3 natives) - image face (240 bytes): get/setImagePath, adjustSize
      - `mFrameImageFace` (size 312; vtable 0x66baf8, 95 slots; 3/10 fns matched; 8 natives)
      - `mMovieFace` (size 352; vtable 0x664398, 95 slots; 8/17 fns matched; 13 natives) - video face (352 bytes): preload, loadIpic, asyncSound, setPause...
      - `mProgressFace` (size 256; vtable 0x66f938, 95 slots; 6/9 fns matched)
  - `mComposite` (size 176; vtable 0x662ef8, 103 slots; 3/7 fns matched; 12 natives) - container widget (176 bytes); natives clearWindow, insertChild, appendChild, removeChild, replaceChild, countChild
    - `mBox` (size 192; vtable 0x6629b8, 103 slots; 5/7 fns matched) - layout box (192 bytes); mHBox/mVBox/mDBox/mFBox/mMBox are the arrangement variants
      - `mDBox` (size 208; vtable 0x672fa0, 103 slots; 3/5 fns matched)
        - `mHBox` (size 208; vtable 0x66c900, 103 slots; 3/9 fns matched)
        - `mVBox` (size 208; vtable 0x672950, 103 slots; 3/5 fns matched)
      - `mFBox` (size 192; vtable 0x66af28, 103 slots; 5/5 fns matched)
        - `mOptionMenu` (size 288; vtable 0x66f5e8, 104 slots; 4/14 fns matched; 5 natives)
        - `mRootWindow` (size 240; vtable 0x665418, 103 slots; 4/18 fns matched; 10 natives) - top-level window of a page (240 bytes): focus management, fadein, fadeout, crossfade
        - `mScaleBar` (size 264; vtable 0x665780, 103 slots; 4/15 fns matched; 2 natives)
        - `mSliderBar` (size 272; vtable 0x671d98, 103 slots; 6/14 fns matched; 2 natives)
      - `mMBox` (size 204; vtable 0x66e898, 103 slots; 3/9 fns matched)
      - `mPhotoMapWindow` (size 356; vtable 0x65d480, 103 slots; 10/32 fns matched; 3 natives) - photo-mode map window (356 bytes): setBaseLen, doFocus, getAperture
    - `mButton` (size 180; vtable 0x668f18, 103 slots; 4/12 fns matched) - button widget (180 bytes) paired with mButtonActor and button events
    - `mColorWindow` (size 256; vtable 0x66a328, 103 slots; 7/13 fns matched; 4 natives)
    - `mKeyboardBox` (size 180; vtable 0x66dab8, 103 slots; 4/5 fns matched; 1 natives)
    - `mKeytopBox` (size 180; vtable 0x66de00, 103 slots; 4/8 fns matched)
    - `mProject` (size 184; vtable 0x664d50, 103 slots; 6/9 fns matched; 3 natives) - UI project (.mproject) object: findPage, exportRootWindow, getDir
    - `mScrollArrow` (size 188; vtable 0x670e80, 103 slots; 5/8 fns matched)
    - `mScrollBase` (size 184; vtable 0x670b38, 103 slots; 4/6 fns matched)
    - `mScrollBox` (size 192; vtable 0x670160, 103 slots; 4/7 fns matched)
    - `mScrollPinch` (size 188; vtable 0x6707f0, 103 slots; 5/10 fns matched)
    - `mScrollWindow` (size 308; vtable 0x6704a8, 103 slots; 3/11 fns matched; 2 natives)
    - `mScrollable` (size 188; vtable 0x6711c8, 107 slots; 7/11 fns matched) - scrolling base for list/select/text boxes
      - `mListBox` (size 344; vtable 0x66e2f0, 107 slots; 9/22 fns matched; 18 natives) - list with item template/count/widgets (344 bytes, 107 slots, 18 natives)
      - `mSelectBar` (size 248; vtable 0x671530, 107 slots; 6/20 fns matched; 8 natives) - selection bar (248 bytes), same native set as mSelectBox
      - `mSelectBox` (size 252; vtable 0x671898, 107 slots; 6/22 fns matched; 13 natives) - selection list (252 bytes): moveIndex, incIndex, decIndex, sort, getFocusedWidget
      - `mTextBoxFace` (size 968; vtable 0x6725e8, 107 slots; 7/12 fns matched; 1 natives)
  - `mEyetoyFace` (size 172; vtable 0x65f550, 96 slots; 7/8 fns matched)
    - `mEyetoyFacePS2` (vtable 0x6602b0, 96 slots; 2/7 fns matched)
  - `mFlashFace` (size 184; vtable 0x66b4a0, 95 slots; 3/11 fns matched; 3 natives) - Flash-style movie face (184 bytes): flash path, reset
  - `mInputNumberFace` (size 292; vtable 0x66cfb0, 95 slots; 4/10 fns matched)
  - `mInputTextFace` (size 3568; vtable 0x66d2b8, 95 slots; 6/13 fns matched; 5 natives) - text input (3,568 bytes): putString, backspace, delete, left, right
  - `mLoggerFace` (size 176; vtable 0x65fca0, 95 slots; 5/12 fns matched)
  - `mModelFace` (size 780; vtable 0x66ed98, 95 slots; 3/11 fns matched; 8 natives) - 3D model inside the UI (780 bytes): model set, env image, motion paths
  - `mPhotoRenderFace` (size 256; vtable 0x65d7c8, 95 slots; 4/11 fns matched; 23 natives) - photo rendering and printing (256 bytes): printout, nozzleCheck, rendering, printCancel, getPrinterProgress
  - `mPhotoViewFace` (size 160; vtable 0x65ffa8, 95 slots; 8/10 fns matched)
  - `mRaceCourseMapFace` (vtable 0x65a768, 98 slots; 4/6 fns matched)
    - `mRaceCourseMapFacePS2` (size 200; vtable 0x65a448, 98 slots; 7/14 fns matched)
  - `mSceneViewFace` (size 192; vtable 0x65aa88, 95 slots; 23/52 fns matched) - scene view face (192 bytes, 51 own methods): a 3D scene embedded in the UI; its ten near-identical event virtuals are family 9 in coverage-map.md
  - `mSlideShowFace` (size 8020; vtable 0x65e5f8, 95 slots; 4/10 fns matched; 3 natives) - slide show (8,020 bytes): doPlay, doStop, isPlaying
  - `mTextFace` (size 288; vtable 0x666370, 95 slots; 8/15 fns matched; 3 natives) - text rendering face (288 bytes): getTextSize, abbreviate, adjustScale
  - `mToolTipFace` (size 340; vtable 0x666678, 95 slots; 5/11 fns matched; 3 natives)
  - `mVirtualFace` (size 168; vtable 0x672c98, 95 slots; 4/7 fns matched)

## 8. UI: actors and transitions

Time-based animation objects attached to widgets, and page-to-page transitions.

- `mActor` (size 20; vtable 0x662668, 53 slots; 17/19 fns matched; 2 natives) - UI animation actor base (20 bytes): initialize, rewind; subclasses move, rotate, blink, fade, magnify, chase, anchor, switch [parent `hObject`]
  - `mAnchorActor` (size 40; vtable 0x6686c8, 53 slots; 4/6 fns matched)
  - `mBlinkActor` (size 64; vtable 0x668880, 53 slots; 4/7 fns matched)
  - `mButtonActor` (size 68; vtable 0x669260, 53 slots; 5/8 fns matched)
  - `mChaseActor` (size 52; vtable 0x669c60, 53 slots; 5/7 fns matched; 2 natives)
  - `mFadeActor` (size 64; vtable 0x663570, 53 slots; 4/9 fns matched; 1 natives)
    - `mMCFileActor` (size 128; vtable 0x65ca80, 55 slots; 5/8 fns matched)
  - `mMagnifyActor` (size 56; vtable 0x66ebe0, 53 slots; 6/8 fns matched)
  - `mMoveActor` (size 100; vtable 0x66f248, 53 slots; 4/8 fns matched; 2 natives)
  - `mRotateActor` (size 64; vtable 0x66fe08, 53 slots; 5/8 fns matched; 2 natives)
  - `mSwitchActor` (size 68; vtable 0x672278, 53 slots; 5/8 fns matched; 3 natives)
  - `mTextActor` (size 36; vtable 0x672430, 53 slots; 4/6 fns matched)
- `mTransition` (size 32; vtable 0x666b18, 57 slots; 9/16 fns matched; 6 natives) - page transitions: panOut, panIn, panOutIn, syncOut/Wait/In [parent `hObject`]
  - `mBlockTransition` (size 60; vtable 0x668a38, 57 slots; 3/8 fns matched)
  - `mColorTransition` (size 56; vtable 0x66a150, 57 slots; 6/9 fns matched)
  - `mCrossTransition` (size 64; vtable 0x66a670, 57 slots; 4/10 fns matched)

## 9. UI: events and filters

Event objects delivered to widgets and scripts.

- `MEventFilter` (vtable 0x6653d8, 2 slots; 4/7 fns matched)
  - `IfRootEvent` (vtable 0x665120, 2 slots; 1/3 fns matched)
  - `IfScriptEvent` (vtable 0x665140, 2 slots; 1/4 fns matched)
  - `IfWidget` (vtable 0x667200, 2 slots; 2/3 fns matched) - event-filter interfaces (IfRootEvent, IfScriptEvent, IfWidget) deriving from MEventFilter
- `mEvent` (size 32; vtable 0x66ad80, 51 slots; 3/5 fns matched) - UI event base (32 bytes); window events (button, key, motion), crossing events (enter/leave/focus), activate, cancel, finalize, callback, script and function events [parent `hObject`]
  - `mActivateEvent` (size 32; vtable 0x668520, 51 slots; 5/7 fns matched)
  - `mCallbackEvent` (size 36; vtable 0x669910, 51 slots; 4/7 fns matched)
  - `mCancelEvent` (size 32; vtable 0x669ab8, 51 slots; 5/7 fns matched)
  - `mCrossingEvent` (size 32; vtable 0x66a848, 51 slots; 9/10 fns matched)
    - `mEnterEvent` (size 32; vtable 0x66abd8, 51 slots; 5/7 fns matched)
    - `mFocusEnterEvent` (size 32; vtable 0x66b7a8, 51 slots; 5/6 fns matched)
    - `mFocusLeaveEvent` (size 32; vtable 0x66b950, 51 slots; 5/6 fns matched)
    - `mLeaveEvent` (size 32; vtable 0x66e148, 51 slots; 5/8 fns matched)
  - `mFinalizeEvent` (size 32; vtable 0x66b270, 51 slots; 5/7 fns matched)
  - `mFunctionEvent` (size 52; vtable 0x663728, 51 slots; 4/7 fns matched)
  - `mScriptEvent` (size 40; vtable 0x665ac8, 51 slots; 4/7 fns matched)
  - `mWindowEvent` (size 32; vtable 0x667888, 51 slots; 5/6 fns matched)
    - `mButtonEvent` (size 48; vtable 0x669418, 51 slots; 6/9 fns matched)
      - `mButtonPressEvent` (size 48; vtable 0x6695c0, 51 slots; 4/8 fns matched)
      - `mButtonReleaseEvent` (size 48; vtable 0x669768, 51 slots; 4/8 fns matched)
    - `mKeyEvent` (size 48; vtable 0x66d5c0, 51 slots; 6/9 fns matched)
      - `mKeyPressEvent` (size 52; vtable 0x66d768, 51 slots; 4/11 fns matched)
      - `mKeyReleaseEvent` (size 48; vtable 0x66d910, 51 slots; 4/10 fns matched)
    - `mMotionEvent` (size 40; vtable 0x66f0a0, 51 slots; 3/7 fns matched)

## 10. UI: project loading, readers and model

Parsing of `.mproject`/`.mwidget` style layouts (XML) into widget trees: readers convert typed attributes, `mProject`/`mManager` register classes and prototypes.

- `MAction` (vtable 0x665760, 2 slots; 3/3 fns matched)
  - `RebuildPropagate` (vtable 0x6653f8, 2 slots; 1/3 fns matched)
- `MColor` (no vtable)
- `MModel` (vtable 0x664040, 9 slots; 4/10 fns matched)
  - `CompatibleModel` (vtable 0x6650c8, 9 slots; 3/4 fns matched)
- `MReaderBase` (vtable 0x6638d0, 4 slots; 1/1 fns matched) - readers that parse typed widget attributes (bool, int, float, string, colour, vector, rectangle, region, widget); ten subclasses
  - `MColorReader` (vtable 0x662d30, 4 slots; 4/5 fns matched)
  - `MRectangleReader` (vtable 0x665098, 4 slots; 2/3 fns matched)
  - `MRegionReader` (vtable 0x66fdd8, 4 slots; 2/3 fns matched)
  - `MVector3Reader` (vtable 0x667000, 4 slots; 2/3 fns matched)
  - `MVectorReader` (vtable 0x667030, 4 slots; 2/3 fns matched)
  - `MWidgetReader` (vtable 0x667528, 4 slots; 2/6 fns matched)
  - `MboolReader` (vtable 0x666d50, 4 slots; 2/22 fns matched)
  - `MfloatReader` (vtable 0x666d20, 4 slots; 3/20 fns matched)
  - `MintReader` (vtable 0x666d80, 4 slots; 2/24 fns matched)
  - `MstringReader` (vtable 0x666cf0, 4 slots; 2/15 fns matched)
- `MRegion` (no vtable)
- `MenuControl` (vtable 0x667bc8, 3 slots; 1/4 fns matched)
- `RefPointer` (no vtable)
  - `HObject` (no vtable)
    - `MDomNode` (no vtable)
  - `MData` (no vtable)
    - `MModelSet` (no vtable)
  - `MListItem` (no vtable)
- `mData` (size 8; vtable 0x66a9f0, 8 slots; 3/4 fns matched) [parent `RefCounter`]
- `mDomNode` (size 52; vtable 0x6633d8, 49 slots; 3/5 fns matched; 3 natives) - XML node: hasAttribute, getAttribute, getFirstNode [parent `hObject`]
- `mDomNodeList` (size 32; vtable 0x663240, 49 slots; 3/5 fns matched) [parent `hObject`]
- `mListItem` (size 32; vtable 0x66e658, 8 slots; 3/5 fns matched) [parent `RefCounter`]
- `mManager` (size 48; vtable 0x663e58, 49 slots; 3/5 fns matched; 9 natives) - UI class/prototype registry: registerClass, registerPrototype(s), getPrototype, loadPrototype, loadProject, unloadProject [parent `hObject`]
- `mWatcher` (size 28; vtable 0x667060, 50 slots; 3/5 fns matched; 2 natives) - watcher list: append, remove [parent `hObject`]
  - `mScriptWatcher` (size 40; vtable 0x66ffc0, 50 slots; 5/6 fns matched)
- `mXml` (size 1072; vtable 0x667a30, 49 slots; 3/5 fns matched; 1 natives) - XML parser object, 1,072 bytes; native parse [parent `hObject`]

## 11. Race: sessions and modes

`RaceBase` is the per-race driver object; one subclass per game mode. The race loop itself is only partly named; most of the simulation lives in unnamed clusters (see architecture.md).

- `ErrorEventView` (vtable 0x67fc28, 1 slot; 2/2 fns matched)
- `PauseBase` (vtable 0x681bd0, 5 slots; 4/4 fns matched)
  - `PhotoPause` (vtable 0x681b98, 5 slots; 2/6 fns matched)
  - `RacePause` (vtable 0x681b28, 5 slots; 1/6 fns matched)
  - `SimplePause` (vtable 0x681b60, 5 slots; 5/6 fns matched)
- `PhotoModeInput` (vtable 0x686668, 3 slots; 1/2 fns matched)
- `RaceBGMBase` (vtable 0x67d768, 9 slots; 10/10 fns matched) - race background music; RaceBGMPS2 and RaceLicenseBGM
  - `RaceBGMPS2` (vtable 0x679828, 9 slots; 5/10 fns matched)
    - `RaceLicenseBGM` (vtable 0x680ca8, 9 slots; 2/3 fns matched)
- `RaceBase` (vtable 0x67ca98, 100 slots; 55/87 fns matched) - race session base, 100 vtable slots (86 own methods); RacePS2Base adds the PS2 implementation (148 slots) and RaceBasic/RaceBasicWithRaceDisplay add the on-screen display
  - `RacePS2Base` (vtable 0x679378, 148 slots; 31/70 fns matched)
    - `RaceBasic` (vtable 0x67d298, 152 slots; 1/2 fns matched)
      - `RaceBasicWithRaceDisplay` (vtable 0x67cdc8, 152 slots; 3/5 fns matched)
        - `RaceSinglePlayer` (vtable 0x682a20, 152 slots; 2/4 fns matched) - single-player race base; Arcade, Championship, FreePractice, GTmode, NetSinglePlayer (RallyBattle), PhotoDevelop and the Training/Mission pair derive from it
          - `RaceArcade` (vtable 0x67bfa8, 152 slots; 1/3 fns matched)
            - `RaceArcadeDemo` (vtable 0x67c520, 152 slots; 5/5 fns matched)
            - `RaceArcadeSingle` (vtable 0x67bad8, 152 slots; 8/10 fns matched)
          - `RaceChampionship` (vtable 0x684bf0, 152 slots; 3/7 fns matched)
          - `RaceFreePractice` (vtable 0x67fc70, 152 slots; 4/8 fns matched)
          - `RaceGTmode` (vtable 0x684678, 152 slots; 5/8 fns matched)
          - `RaceNetSinglePlayer` (vtable 0x685168, 152 slots; 4/4 fns matched)
            - `RaceNetRallyBattle` (vtable 0x678d48, 152 slots; 7/17 fns matched)
          - `RacePhotoDevelop` (vtable 0x682310, 152 slots; 7/12 fns matched)
          - `RaceTrainingBase` (vtable 0x6840f8, 153 slots; 4/4 fns matched)
            - `RaceMission` (vtable 0x6815e0, 153 slots; 5/13 fns matched)
            - `RaceTraining` (vtable 0x683c20, 153 slots; 6/9 fns matched)
      - `RaceSolitaire` (vtable 0x683420, 158 slots; 1/4 fns matched) - time-trial style base (no opponents, inferred from the subclasses): FreeRun, License, MachineTest
        - `RaceFreeRun` (vtable 0x680140, 158 slots; 10/37 fns matched)
        - `RaceLicense` (vtable 0x6807a8, 158 slots; 9/22 fns matched)
        - `RaceMachineTest` (vtable 0x680ee0, 158 slots; 2/6 fns matched)
    - `RacePhotoMode` (vtable 0x681c08, 150 slots; 5/9 fns matched) - photo mode inside a race; RacePhotoModeCameraManager (71 slots) drives the camera
- `RaceCourse` (vtable 0x67e1d8, 1 slot; 0/2 fns matched)
- `RaceLanBattle` (vtable 0x677c28, 154 slots; 24/43 fns matched) - LAN versus race (154 slots), with RaceLanBattleInformation and RaceInputLan
- `RaceNetBattle` (vtable 0x6787c0, 152 slots; 17/37 fns matched) - online versus race (152 slots) and RaceNetBattleInformation
- `RacePhotoModeCameraManager` (vtable 0x6820c8, 71 slots; 13/35 fns matched)
- `RaceSplitBattleBase` (vtable 0x677128, 154 slots; 0/2 fns matched)
  - `RaceSplitBattle` (vtable 0x676c48, 154 slots; 14/29 fns matched) - split-screen two-player race (inferred from the name) with RaceSplitDisplay

## 12. Race: parameters, entries and results

Information objects (inputs to a race), entries (cars/drivers) and result handling.

- `RaceEntryBase` (vtable 0x67fbb8, 6 slots; 4/7 fns matched)
- `RaceEntryCar` (vtable 0x67fbf8, 1 slot; 0/2 fns matched)
- `RaceEntryInformation` (vtable 0x67fc10, 1 slot; 2/2 fns matched)
- `RaceEventQueue` (vtable 0x67fc40, 1 slot; 2/2 fns matched)
- `RaceInformation` (vtable 0x6806e8, 19 slots; 3/5 fns matched) - per-mode race parameter bundle (19 slots); one subclass per mode (inferred from the names)
  - `RaceChampionshipInformation` (vtable 0x6850c0, 19 slots; 3/6 fns matched)
  - `RaceGTmodeInformation` (vtable 0x684b48, 19 slots; 3/5 fns matched)
  - `RaceMachineTestInformation` (vtable 0x6813e0, 19 slots; 5/5 fns matched)
  - `RaceReplayInformation` (vtable 0x683080, 19 slots; 6/8 fns matched)
  - `RaceSinglePlayerInformation` (vtable 0x682ef0, 19 slots; 2/2 fns matched)
    - `RaceArcadeInformation` (vtable 0x67c478, 19 slots; 2/2 fns matched)
      - `RaceArcadeDemoInformation` (vtable 0x67c9f0, 19 slots; 3/5 fns matched)
    - `RaceNetSinglePlayerInformation` (vtable 0x685638, 19 slots; 2/2 fns matched)
      - `RaceNetRallyBattleInformation` (vtable 0x679218, 19 slots; 6/7 fns matched)
    - `RaceTrainingInformation` (vtable 0x6845d0, 19 slots; 2/4 fns matched)
  - `RaceSolitaireInformation` (vtable 0x683920, 19 slots; 3/3 fns matched)
    - `RaceFreeRunInformation` (vtable 0x680640, 19 slots; 5/6 fns matched)
- `RaceInput` (vtable 0x686618, 8 slots; 1/5 fns matched)
  - `RaceInputLan` (vtable 0x678620, 8 slots; 4/8 fns matched)
- `RaceLanBattleInformation` (vtable 0x678670, 19 slots; 5/7 fns matched)
- `RaceLanControlManager` (vtable 0x6785d8, 7 slots; 2/8 fns matched)
- `RaceLapTime` (vtable 0x680790, 1 slot; 1/2 fns matched)
- `RaceNetBattleInformation` (vtable 0x678c90, 21 slots; 6/9 fns matched)
- `RaceResultBase` (vtable 0x683320, 8 slots; 8/10 fns matched) - result handling; ResultArcade, ResultChampionship, ResultLicense, ResultLinkBattle
  - `ResultArcade` (vtable 0x683288, 17 slots; 2/6 fns matched)
    - `ResultChampionship` (vtable 0x6863e0, 17 slots; 4/7 fns matched)
    - `ResultLicense` (vtable 0x683370, 17 slots; 8/10 fns matched)
    - `ResultLinkBattle` (vtable 0x6798c0, 17 slots; 10/21 fns matched)
- `RaceSolitaireEntry` (vtable 0x6839c8, 6 slots; 2/3 fns matched)
- `RaceSplitBattleInformation` (vtable 0x677ad8, 19 slots; 17/20 fns matched)

## 13. Race: HUD (RaceDisplay*)

The in-race display and its 32 widgets/elements.

- `RaceDisplayBase` (no vtable)
  - `RaceDisplay` (vtable 0x67e278, 56 slots; 18/57 fns matched) - in-race HUD root (56 own methods); RaceSplitDisplay for split screen, RaceLicenseDisplay for licence tests
    - `RaceLicenseDisplay` (vtable 0x680d00, 58 slots; 2/16 fns matched)
  - `RaceSplitDisplayBase` (vtable 0x67e598, 29 slots; 2/2 fns matched)
    - `RaceSplitDisplay` (vtable 0x67e4a0, 29 slots; 12/30 fns matched)
- `RaceDisplayEventBase` (vtable 0x67e7f8, 3 slots; 0/1 fns matched) - HUD event messages: lap time, checkpoint, speed, general time, information, message
  - `RaceDisplayDiffEvent` (vtable 0x67e780, 3 slots; 1/1 fns matched)
    - `RaceDisplayGeneralTimeEvent` (vtable 0x67e708, 3 slots; 2/8 fns matched)
    - `RaceDisplayLapDiffEvent` (vtable 0x67e730, 3 slots; 2/5 fns matched)
    - `RaceDisplayTimeDiffEvent` (vtable 0x67e758, 3 slots; 2/5 fns matched)
  - `RaceDisplayInformationEvent` (vtable 0x67e6b8, 3 slots; 3/4 fns matched)
  - `RaceDisplayLapTimeEvent` (vtable 0x67e7d0, 3 slots; 3/4 fns matched)
    - `RaceDisplayCheckPointEvent` (vtable 0x67e7a8, 3 slots; 2/4 fns matched)
  - `RaceDisplayMessageEvent` (vtable 0x67e690, 3 slots; 3/4 fns matched)
  - `RaceDisplaySpeedEvent` (vtable 0x67e6e0, 3 slots; 2/4 fns matched)
- `RaceDisplayObjectBase` (vtable 0x67fac0, 9 slots; 1/2 fns matched) - base of 32 HUD elements: speed/tach/boost meters, gear, lap, rank, minimap, fuel, tire wear, panels (including MTR and Prius panels)
  - `RaceABMonitor` (vtable 0x67f328, 9 slots; 0/6 fns matched)
  - `RaceCapacityMonitor` (vtable 0x67f5d0, 9 slots; 1/3 fns matched)
  - `RaceCarIconDisplay` (vtable 0x67f628, 10 slots; 2/5 fns matched)
  - `RaceDigitalSpeedmeter` (vtable 0x67fa08, 9 slots; 1/7 fns matched)
  - `RaceEventDisplay` (vtable 0x67f7e8, 10 slots; 0/6 fns matched)
  - `RaceFuelMeter` (vtable 0x67f2d0, 9 slots; 2/6 fns matched)
  - `RaceIndicator` (vtable 0x67f570, 10 slots; 2/7 fns matched)
  - `RaceLapTimesDisplay` (vtable 0x67f8a8, 9 slots; 1/4 fns matched)
  - `RaceMTRGravityMeter` (vtable 0x67eee0, 10 slots; 3/4 fns matched)
  - `RaceMTRMeter` (vtable 0x67efa0, 10 slots; 4/4 fns matched)
  - `RaceMTRMeterPanel` (vtable 0x67ef40, 10 slots; 0/4 fns matched)
  - `RaceMTRMultiFunctionDisplay` (vtable 0x67ee20, 10 slots; 2/4 fns matched)
  - `RaceMTRSpeedMeterPanel` (vtable 0x67ee80, 10 slots; 3/4 fns matched)
  - `RaceMessageDisplay` (vtable 0x67f848, 10 slots; 2/6 fns matched)
    - `RaceReplayModeDisplay` (vtable 0x67e820, 10 slots; 2/4 fns matched)
  - `RaceMeterBase` (vtable 0x681580, 10 slots; 9/13 fns matched)
    - `RaceBarMeter` (vtable 0x681488, 11 slots; 3/4 fns matched)
      - `RaceBattleTachometer` (vtable 0x683a98, 11 slots; 2/4 fns matched)
    - `RaceRoundMeterBase` (vtable 0x6814f0, 16 slots; 5/9 fns matched)
      - `RaceBoostmeter` (vtable 0x686298, 16 slots; 2/4 fns matched)
      - `RaceOnboardSpeedmeter` (vtable 0x683a08, 16 slots; 1/2 fns matched)
      - `RaceRoundTachometerBase` (vtable 0x683b90, 16 slots; 1/2 fns matched)
        - `RaceOnboardTachometer` (vtable 0x683b00, 16 slots; 3/6 fns matched)
  - `RaceMiniMap` (vtable 0x67e448, 9 slots; 10/12 fns matched)
  - `RaceMusicDisplay` (vtable 0x67e880, 10 slots; 2/5 fns matched)
  - `RaceOdometer` (vtable 0x67f9b0, 9 slots; 2/5 fns matched)
  - `RacePanel` (vtable 0x67ec88, 37 slots; 2/7 fns matched)
    - `RaceOnboardPanel` (vtable 0x67ea18, 37 slots; 27/33 fns matched)
    - `RacePriusPanel` (vtable 0x67e8e0, 37 slots; 27/33 fns matched)
    - `RaceSimplePanel` (vtable 0x67eb50, 37 slots; 19/26 fns matched)
  - `RacePriusHybridDisplay` (vtable 0x67f160, 11 slots; 1/7 fns matched)
  - `RaceRankDisplay` (vtable 0x67fa60, 10 slots; 2/5 fns matched)
  - `RaceRefuelMeter` (vtable 0x67f278, 9 slots; 1/4 fns matched)
  - `RaceShiftPositionDisplay` (vtable 0x67f508, 11 slots; 2/8 fns matched)
  - `RaceShiftTimingLampDisplay` (vtable 0x67f438, 11 slots; 2/8 fns matched)
  - `RaceSideGravityMeter` (vtable 0x67f3d8, 10 slots; 3/7 fns matched)
  - `RaceSimpleBarMeter` (vtable 0x67f380, 9 slots; 2/4 fns matched)
  - `RaceSteeringDisplay` (vtable 0x67f738, 9 slots; 2/5 fns matched)
  - `RaceSuggestedGearDisplay` (vtable 0x67f4a0, 11 slots; 2/8 fns matched)
  - `RaceTexturePanel` (vtable 0x67f790, 9 slots; 1/3 fns matched)
  - `RaceTireWearDisplay` (vtable 0x67f6e0, 9 slots; 2/7 fns matched)
  - `RaceTooltipDisplay` (vtable 0x67edc0, 10 slots; 1/5 fns matched)
  - `RaceValueDisplayBase` (vtable 0x67f958, 9 slots; 9/13 fns matched)
    - `RaceCountDisplay` (vtable 0x67f108, 9 slots; 2/3 fns matched)
    - `RaceGasConsumptionDisplay` (vtable 0x67f1c8, 9 slots; 2/3 fns matched)
    - `RaceGasMileageDisplay` (vtable 0x67f220, 9 slots; 2/3 fns matched)
    - `RaceRichCountDisplay` (vtable 0x67f0b0, 9 slots; 1/2 fns matched)
      - `RaceLapDisplay` (vtable 0x67f058, 9 slots; 1/3 fns matched)
    - `RaceSpeedDisplay` (vtable 0x67f688, 9 slots; 1/3 fns matched)
    - `RaceTimeDisplay` (vtable 0x67f900, 9 slots; 1/3 fns matched)
    - `RaceValueDisplay` (vtable 0x67f000, 9 slots; 3/4 fns matched)

## 14. Cars, drivers and dynamics

The physics step conductors, car models and geometry, driver and crew models. The numeric suspension/tyre code has no RTTI and lives in unnamed clusters.

- `CarDataBase` (vtable 0x688548, 1 slot; 2/2 fns matched)
- `CarGeometryBase` (no vtable) - car body geometry interface with 48 virtuals; Normal, Special and MTR variants
  - `CarGeometry` (vtable 0x67d7c0, 48 slots; 16/50 fns matched)
  - `MTRGeometry` (vtable 0x67dc70, 48 slots; 48/51 fns matched)
  - `NormalCarGeometry` (vtable 0x67d950, 48 slots; 47/51 fns matched)
  - `SpecialCarGeometry` (vtable 0x67dae0, 48 slots; 44/51 fns matched)
- `CarIconMaker` (vtable 0x67e140, 17 slots; 7/19 fns matched)
- `ComputeDriverPostureCaller` (no vtable)
  - `StandardComputeDriverPostureCaller` (vtable 0x67e108, 1 slot; 1/2 fns matched)
- `DriverCallback` (vtable 0x67fb18, 5 slots; 7/7 fns matched)
- `DynamicsConductor` (vtable 0x679e98, 52 slots; 9/11 fns matched) - per-mode conductor of the physics update (inferred from the name and the subclasses: SinglePlayer, FreePractice, FreeRun, License, Training, Mission, MachineTest, Battle2P, BattleMP); the actual dynamics code is in unnamed clusters
  - `DynamicsConductorBattle2P` (vtable 0x679988, 52 slots; 39/54 fns matched)
  - `DynamicsConductorBattleMP` (vtable 0x679b38, 52 slots; 14/18 fns matched)
  - `DynamicsConductorFreePractice` (vtable 0x6856e0, 52 slots; 14/20 fns matched)
  - `DynamicsConductorFreeRun` (vtable 0x685890, 52 slots; 16/25 fns matched)
  - `DynamicsConductorLicense` (vtable 0x685a40, 52 slots; 22/33 fns matched)
    - `DynamicsConductorTraining` (vtable 0x685f50, 52 slots; 4/4 fns matched)
      - `DynamicsConductorMission` (vtable 0x685da0, 52 slots; 20/23 fns matched)
  - `DynamicsConductorMachineTest` (vtable 0x685bf0, 52 slots; 11/16 fns matched)
  - `DynamicsConductorSinglePlayer` (vtable 0x679ce8, 52 slots; 17/26 fns matched)
- `EnemyLineProcessorOld` (vtable 0x6888c8, 1 slot; 2/2 fns matched)
- `HandleSolverBase` (vtable 0x6864f8, 2 slots; 6/7 fns matched) - steering-wheel hand placement solvers (Easy, Fixed, Free, SingleHanded) - purpose inferred from the names
  - `EasyHandleSolver` (vtable 0x6864d8, 2 slots; 2/3 fns matched)
  - `FixedHandleSolver` (vtable 0x6864b8, 2 slots; 2/3 fns matched)
  - `FreeHandleSolver` (vtable 0x686498, 2 slots; 1/3 fns matched)
  - `SingleHandedHandleSolver` (vtable 0x686478, 2 slots; 1/3 fns matched)
- `HumanModel` (vtable 0x67fb88, 4 slots; 4/5 fns matched) - driver/crew skeleton: RaceDriverModel and RaceCrewModel (pit crew, inferred)
  - `RaceDriverModel` (vtable 0x67fb50, 5 slots; 1/2 fns matched)
    - `RaceCrewModel` (vtable 0x67df68, 5 slots; 2/4 fns matched)
- `PitmanCallback` (vtable 0x6829d0, 5 slots; 4/4 fns matched)
- `PitmenData` (vtable 0x682a08, 1 slot; 1/2 fns matched) [parent `ScenePack`]
- `RigidBodyManager` (vtable 0x683408, 1 slot; 0/2 fns matched) - rigid-body world holder (1 virtual)
- `ShowRoomCar` (vtable 0x67a048, 1 slot; 2/2 fns matched)
- `VehicleModel` (vtable 0x67dfa0, 43 slots; 4/5 fns matched) - car model used by the simulation; RaceCarModel (43 own methods) adds the race car
  - `RaceCarModel` (vtable 0x67de00, 43 slots; 18/44 fns matched)
- `mCarModel` (size 156; vtable 0x65b5c0, 60 slots; 5/7 fns matched; 5 natives) [parent `hObject`]
  - `mCarModelPS2` (size 2656; vtable 0x65b8c8, 60 slots; 6/15 fns matched)

## 15. Camera, sound, scenes and media

Race cameras, engine sound, particles, showroom scenes, image/movie/model data objects.

- `CameraBase` (vtable 0x688450, 9 slots; 7/10 fns matched) - camera interface (9 virtuals); SceneCameraBase; DevelopCamera has 54 own methods
  - `SceneCameraBase` (vtable 0x6884a8, 18 slots; 9/12 fns matched)
- `ConcourseCallback` (vtable 0x686328, 5 slots; 4/4 fns matched)
- `DevelopCamera` (vtable 0x6827e0, 57 slots; 26/57 fns matched)
- `DirectivityMicrophone` (vtable 0x67e248, 1 slot; 1/2 fns matched) - directional microphone model for car sound (inferred)
- `FileInstrumentStream` (vtable 0x6883d8, 2 slots; 1/3 fns matched) - streamed instrument data
- `GTSOUNDINSTRUMENT` (vtable 0x688888, 2 slots; 1/2 fns matched) - engine/instrument sound source; EngineSound and the JAM variant derive from it
  - `EngineSound` (vtable 0x67e120, 2 slots; 1/3 fns matched)
  - `GTSOUNDINSTRUMENTJAM` (vtable 0x688868, 2 slots; 3/4 fns matched)
- `Ipic` (vtable 0x668508, 1 slot; 2/2 fns matched) - image format used for preview frames (hub: .ipic); IpicArchive
- `IpicArchive` (vtable 0x6684f0, 1 slot; 1/2 fns matched)
- `PGLXshapeBuilder` (vtable 0x688b58, 1 slot; 2/3 fns matched)
- `Particle` (no vtable)
  - `SparkParticle` (vtable 0x681ae8, 6 slots; 2/7 fns matched)
- `ParticleManager` (vtable 0x681ad0, 1 slot; 1/2 fns matched) - particle system; SparkParticle
- `PropNameSearcher` (vtable 0x6829b8, 1 slot; 2/3 fns matched)
- `ScenePack` (no vtable) - scene package base for Concourse and PitmenData
  - `Concourse` (vtable 0x686380, 2 slots; 3/3 fns matched) - showroom/pit scene (hub: pit/ ScenePack files); LicenseConcourse variant
    - `LicenseConcourse` (vtable 0x686360, 2 slots; 2/3 fns matched)
- `mBlob` (size 24; vtable 0x662820, 49 slots; 4/5 fns matched) [parent `hObject`]
- `mFlash` (size 12; vtable 0x66b418, 15 slots; 4/4 fns matched) [parent `mData`]
  - `mFlashPS2` (size 32; vtable 0x667d88, 15 slots; 6/11 fns matched)
- `mImage` (size 8; vtable 0x663900, 16 slots; 4/4 fns matched) [parent `mData`]
  - `mImagePS2` (size 36; vtable 0x667e10, 16 slots; 9/12 fns matched)
- `mModelMotion` (size 36; vtable 0x664098, 8 slots; 6/9 fns matched) [parent `mData`]
- `mModelSet` (size 8; vtable 0x6640e8, 11 slots; 4/4 fns matched) [parent `mData`]
  - `mModelSetPS2` (size 16; vtable 0x667ea0, 11 slots; 4/7 fns matched)
- `mMovie` (size 8; vtable 0x6642e8, 20 slots; 4/4 fns matched) [parent `RefCounter`]
  - `mMoviePS2` (size 20; vtable 0x667f08, 20 slots; 9/16 fns matched)
- `mMusic` (size 36; vtable 0x66f400, 49 slots; 3/5 fns matched; 7 natives) [parent `hObject`]
- `mSound` (size 24; vtable 0x665e08, 49 slots; 3/5 fns matched; 13 natives) [parent `hObject`]
- `mStream` (size 40; vtable 0x6624d0, 49 slots; 3/6 fns matched) [parent `hObject`]
  - `mModelStream` (size 44; vtable 0x664150, 49 slots; 5/6 fns matched; 1 natives)
- `mpegif` (vtable 0x689818, 1 slot; 0/2 fns matched) - MPEG decoder interface

## 16. C++ runtime and iostream classes

libstdc++ 2.9x pieces with RTTI: iostream buffers and exception/type_info classes.

- `_IO_FILE` (no vtable)
  - `streambuf` (vtable 0x68a0b0, 17 slots; 11/15 fns matched) - libstdc++ streambuf; filebuf and stdiobuf below
    - `filebuf` (vtable 0x68a018, 17 slots; 14/20 fns matched)
      - `stdiobuf` (vtable 0x68a190, 17 slots; 2/10 fns matched)
- `_Rb_tree_node_base` (no vtable)
- `_ios_fields` (no vtable)
- `exception` (vtable 0x68a3f8, 2 slots; 6/10 fns matched)
  - `bad_alloc` (vtable 0x68a3b8, 2 slots; 2/3 fns matched)
  - `bad_cast` (vtable 0x68a2d8, 2 slots; 2/3 fns matched)
  - `bad_exception` (vtable 0x68a3d8, 2 slots; 2/3 fns matched)
  - `bad_typeid` (vtable 0x68a2b8, 2 slots; 3/4 fns matched)
- `istdiostream` (no vtable)
- `ostream` (no vtable)
- `type_info` (vtable 0x68a2f8, 1 slot; 2/2 fns matched) - gcc RTTI type_info hierarchy (class_type_info, si_type_info, etc.)
  - `__array_type_info` (vtable 0x68a310, 1 slot; 2/2 fns matched)
  - `__attr_type_info` (vtable 0x68a388, 1 slot; 2/2 fns matched)
  - `__builtin_type_info` (vtable 0x68a370, 1 slot; 20/20 fns matched)
  - `__func_type_info` (vtable 0x68a358, 1 slot; 2/2 fns matched)
  - `__pointer_type_info` (vtable 0x68a3a0, 1 slot; 2/2 fns matched)
  - `__ptmd_type_info` (vtable 0x68a328, 1 slot; 2/2 fns matched)
  - `__ptmf_type_info` (vtable 0x68a340, 1 slot; 2/2 fns matched)
  - `__user_type_info` (vtable 0x68a288, 4 slots; 6/8 fns matched)
    - `__class_type_info` (vtable 0x68a228, 4 slots; 3/6 fns matched)
    - `__si_type_info` (vtable 0x68a258, 4 slots; 2/6 fns matched)


## 17. Namespaced types (RTTI name strings only)

`classes.json` holds only classes whose names are plain identifiers. The executable's `.data` also contains about 240 mangled
names of namespaced classes (`Q<n><len><name>...` in g++ 2.96 mangling). They were listed by scanning the executable for
these strings; no vtables, parents or function names have been derived for them yet, so this table is names only
(`Namespace::Type`). The nesting shows more of the architecture than the plain list does.

- `ADHOC` (1): PoolAllocator (the VM's pool allocator) - `PoolAllocator`
- `AutomobileControlRecord` (1): vehicle control recording (Manager) - `Manager`
- `CameraSys` (22): race and photo cameras (follow, on-board, heli, pit-in, round, shot manager...) - `CameraAutoFix`, `CameraDesigner`, `CameraFinishType1`, `CameraFollow`, `CameraGrid`, `CameraHeli`, `CameraInterrupt`, `CameraManager`, `CameraOnBoard`, `CameraPathanim`, `CameraPhotoBase`, `CameraPhotoMotion`, `CameraPitIn`, `CameraPoint`, `CameraRound`, `CameraShot`, `CameraVariable`, `DiveController`, `GammaEffector`, `PhotoCameraManager`, `PhotoModeStatus`, `ShotManager`
- `GT4FIRSTADVERTISE` (1): boot advertisement image display - `DisplayAdvertiseImage`
- `GT4MC` (21): memory-card file kinds (game data, replay, photo/film/picture data, play list, slide show list, patch data) - `Device`, `DeviceDemo`, `File`, `File::Progress`, `File::ProgressBase`, `File::ProgressProxy`, `File::SubProgress`, `FileBroken`, `FileGT4`, `FileGT4FilmData`, `FileGT4GameData`, `FileGT4ImplementIcon`, `FileGT4PatchData`, `FileGT4PhotoData`, `FileGT4PictureData`, `FileGT4PlayList`, `FileGT4Replay`, `FileGT4ReplayBest`, `FileGT4ReplayDemo`, `FileGT4ReplayList`, `FileGT4SlideShowList`
- `GT4Model` (8): car model callbacks and recorded-parameter sponsors (replay) - `CarModel::AfterFireCallback`, `CarModel::Callback`, `CarModel::WheelCallback`, `CarParamSponsor`, `RecordedCarParamSponsor`, `RecordedDriverPosture`, `RecordedSceneCamera`, `ShowRoomCarParamSponsor`
- `GT4PhotoMode` (1): photo-mode object - `PhotoModeObject`
- `GT4_Motion` (18): motion/animation callback interfaces (geometric, lighting, perspective, render, camera) - `CameraCallBack`, `CameraCheckCallBack`, `GeometricCallBack`, `GeometricCallBackBase`, `GeometricFlexibleCallBack`, `LightingCallBack`, `LightingCheckCallBack`, `MotionCallBack`, `NameSearchCallBack`, `NameSearcher`, `PerspectiveCallBack`, `PerspectiveCheckCallBack`, `RenderCallBack`, `RenderCallBackBase`, `SimpleStoreCallBack`, `StoreMatrixCallBack`, `UserMotionLight`, `VectorCallBack`
- `GranTurismo4` (40): game-level objects: Option*, LoadingConfig*, Context/ChampionshipContext, GameObject*, Calendar, Present, UsedCar, UserProfile, Status - `Available`, `Calendar`, `ChampionshipContext`, `Context`, `CourseRecordBase`, `Favorite`, `GameObjectBase`, `GameObjectManager`, `GameObjectPS2`, `GameSerializeBase`, `GameZone`, `LicenseRecord`, `LoadingConfig`, `LoadingConfigPS2`, `LoadingConfigPS2FadeBase`, `LoadingConfigPS2FadeIn`, `LoadingConfigPS2Off`, `LoadingConfigPS2Simple`, `LoadingConfigPS2Solid`, `LoadingPS2`, `MenuGameObject`, `Option`, `OptionEvent`, `OptionLANBattle`, `OptionLogger`, `OptionNetConfig`, `OptionRaceControllerBase`, `OptionRaceControllerPS2`, `OptionRaceInputCheetah`, `OptionRaceInputCougar`, `OptionRaceInputDevice`, `OptionRaceInputDualShock2`, `OptionRaceInputGTForce`, `OptionRaceInputPortPS2`, `Present`, `RaceRecord`, `Status`, `UpdateManager`, `UsedCar`, `UserProfile`
- `Jpeg2Sys` (9): JPEG codec (the JFIF code in unit_0046A050) - `BitStreamIn`, `BitStreamOut`, `HuffmanDecoderTable`, `JpegDecoder`, `JpegDecoderGT4`, `JpegEncoder`, `JpegEncoderGT4`, `MCUencode`, `QuantizationDecoderTable`
- `MENU` (1): menu navigation helper - `NavigateP`
- `ModelSet2` (1): model set callback - `Callback`
- `PDICOMM` (1): communication host - `Host`
- `PDIRTIME` (3): online session layer (RTime, client table) - `BaseSystem`, `ClientTable`, `RTime`
- `PDISTD` (25): Polyphony 'standard' library: FAT file systems, file objects/streams, FIFOs, inflate, allocator, game port bases - `CSFifoBase`, `ControlManagerBase`, `ControlManagerLanBase`, `Fat`, `Fat12`, `Fat32`, `FatDrive`, `FifoBase`, `FileExpandPS2`, `FileExpandPS2Local`, `FileInternalStream`, `FileInternalStreamDefault`, `FileObject`, `FileObjectDefault`, `FileStream`, `GamePortBase`, `GamePortConfigBase`, `GenericAllocator`, `InflateBase`, `InflatorBase`, `ListManager`, `MTFifoBase`, `MTListManager`, `PrintFormatTargetBase`, `SOUND::NameMap`
- `PDIUSB` (6): USB stack (hub, keyboard, mouse, serial) - `pdiusb_iopsvr`, `udev`, `uht`, `ukbd`, `ums`, `userial`
- `PlayStation2` (23): platform layer: file devices (cdrom/pipe/ro2), IOP init, USB storage, game ports, libnet, netcnf, RPC, Speex voice player - `CustomSpeexDecoder`, `CustomSpeexPlayer`, `FileDevicePS2`, `FileDevicePipe`, `FileDeviceRo`, `FileDeviceRo2`, `FileDeviceRo2ExDL`, `FileDeviceRoInflator`, `GT4GamePort`, `GamePort`, `IOP::Initialize`, `IOP::InitializeCdReplace`, `IOP::InitializeReplace`, `LibnetBase`, `Netcnf`, `PDIClientRpc`, `RPC`, `USBGamePort`, `UsbStorage`, `UsbStorageDrive`, `hdx1735`, `hmd`, `laserbird`
- `RaceCourse` (1): course callback - `Callback`
- `RoFS2` (3): the volume (VOL) page manager with an inflating variant (see the community's GT4 volume format) - `Deflated::IInflator`, `Deflated::PageManager`, `NullPageManager`
- `SDDRV` (3): sound-driver sequencers - `SeSequencer`, `Sequencer`, `SqSequencer`
- `SPEC_DATABASE` (9): SpecDB reader: tables, label/string storage, car equipment/parts, race spec, disabled info - `CarEquipments`, `CarGarage`, `DatabaseStorage`, `DatabaseTable`, `DisabledInfo`, `LabelInformation`, `PartsInformation`, `RaceSpec`, `StringsStorage`
- `Serialize` (5): replay/ghost/track data (GhostData, ReplayData, MaxSpeed, TrackData) - `Base`, `GhostData`, `MaxSpeed`, `ReplayData`, `TrackData`
- `SlideShowSys` (1): slide show draw manager - `DrawManager`
- `hArray` (1): StringCompare functor - `StringCompare`
- `mCarModel` (1): MotionAlignSet - `MotionAlignSet`
- `mOSKeyboard` (1): Key - `Key`
- `pdiRiderman` (4): rider/skeleton bones (Bone, PlateBone, StickBone, EuclidFactor) - `Bone`, `EuclidFactor`, `PlateBone`, `StickBone`
- `strobe` (4): Flash-style movie runtime instances (sprite, button, edit-text, place-object) behind mFlashFace - `ButtonInstance`, `EditTextInstance`, `PlaceObjectInstance`, `SpriteInstance`

## Known gaps

- Parents are the first base recorded in `classes.json` (at most one per class); multiple inheritance and secondary
  vtables were not examined. 19 classes have no vtable of their own (pure interfaces or only type_info).
- Instance sizes are only known where `virtual_04` is matched; fields are known only where matched sources use them
  (runtime-types.md lists those: reference count/vptr, hString pointer at +0x10, hClass name/parent, native callback slots).
- Purposes marked **inferred** come from names and call shapes, not from verified behaviour.
