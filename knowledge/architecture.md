# Engine architecture

What the executable (`CORE.GT4`, NTSC-U SCUS-97328 v1.01) is made of, subsystem by subsystem: what it does, which
classes and address ranges implement it, how much is matched, and how it connects to the rest. This is the
semantic map that the `func_00xxxxxx` names in `src/` do not give.

Sources: `knowledge/coverage-map.md` and `progress/report.json` (match numbers, 2026-10-08), `config/classes.json`
(509 RTTI classes), `config/symbol_addrs.txt`, `config/units.txt` (783 units), `config/adhoc_methods.txt`, the matched files in
`src/`, and the community's [Gran Turismo Modding Hub](https://nenkai.github.io/gt-modding-hub/) for what the game
does with its data files. Statements marked **inferred** come from names or call shapes; **unknown** means not yet
established. Companion pages: [classes.md](classes.md), [script-engine.md](script-engine.md), [runtime-types.md](runtime-types.md).

## The shape of the program

GT4 is a thin C++ engine under a large Adhoc script program. The executable provides a script virtual machine, a UI/widget system
that the scripts drive, a set of native classes for game data, and the race (simulation, display, physics, sound) which is
the one part that is not scripted. The retail disc loads `CORE.GT4` (this binary) from a bootstrap and then reads everything else
from the `.VOL` volume (scripts, `.mproject` layouts, cars, courses, sound).

```
                       .adc scripts + .mproject/.mwidget + .gpb   (from the VOL volume)
                                          |
             +----------------------------v-----------------------------+
             |  Script VM (hObject values, hInst bytecode, hClass)       |  0x2EA548-0x32F028
             +----+----------------+---------------------+---------------+
                  | native calls   | widgets/events      | native calls
        +---------v------+  +------v----------+   +------v-----------------+
        | game data      |  | UI framework    |   | system / platform      |
        | mCarData,      |  | mWidget tree,   |   | mSystem, mStorage,     |
        | mCarGarage ... |  | faces, actors   |   | mNetwork, mSound ...   |
        +---------+------+  +------+----------+   +------+-----------------+
                  |                |                     |
                  |      +---------v----------+          |
                  +----->| Race (RaceBase     |<---------+
                         | modes, HUD,        |  network battle classes
                         | dynamics, cars,    |
                         | camera, sound)     |
                         +---------+----------+
                                   |
        +--------------------------v-----------------------------------+
        | Libraries: Polyphony PDI* helpers, Sony SDK, libc, libstdc++ |
        +--------------------------------------------------------------+
```

## Map by address

Numbers are functions matched / total and code bytes matched / total, from `progress/report.json` (16,686 of 31,128 functions;
27.4% of 5.31 MB of code). Matched functions are mostly small: half of the functions but a fifth of the bytes.

| range | subsystem | functions | code bytes |
|---|---|---|---|
| 0x100000-0x1241FF | start-up, static initialisation, game-mode menu glue | 298 / 628 | 46 / 144 KB (32%) |
| 0x124208-0x1B688F | native game-data classes (`m*` data model, save/memory card, options) | 1,081 / 2,025 | 269 / 583 KB (46%) |
| 0x1B6890-0x1D6FAF | EyeToy, logger, photo view | 485 / 808 | 50 / 129 KB (39%) |
| 0x1D6FB0-0x1FC4D7 | online glue (`mHttp`, `mDnas`, `mNetwork`) | 240 / 463 | 59 / 149 KB (39%) |
| 0x1FC4D8-0x2EA547 | UI framework (widgets, faces, events, actors) | 3,070 / 4,694 | 461 / 946 KB (49%) |
| 0x2EA548-0x32F027 | Adhoc VM | 1,122 / 1,634 | 138 / 272 KB (51%) |
| 0x32F028-0x44D40F | race: sessions, HUD, dynamics, cars, driver models | 3,368 / 6,995 | 131 / 1,139 KB (11%) |
| 0x44D410-0x4944FF | camera, car-data base, settings, engine sound, AI line | 800 / 1,916 | 31 / 283 KB (11%) |
| 0x494500-0x54DBB7 | network C stack (XML, GameSpy-style transport, online) | 941 / 3,692 | 47 / 737 KB (6%) |
| 0x54DBB8-0x596FA0 | streams, sockets, libc | 616 / 1,907 | 26 / 291 KB (9%) |
| 0x596FA0-0x617A14 | STL, libstdc++, Sony SDK, RTTI | 4,665 / 6,366 | 162 / 510 KB (32%) |

(`.data/.bss` are 0x617A80-0x6D5DFC.) The ranges come from `config/units.txt`: the named units are RTTI clusters, the `unit_*` ones are
code between them with no RTTI of their own.

## 1. Start-up and main loop

- `CORE.GT4` loads at 0x100000; the entry point 0x100008 is hand-written start-up code (clears registers, calls the SDK/C-runtime initialisers
  `func_005B7560`, `func_005ADF20`, `func_0048EF90`, then `func_00107F08`, then jumps to `func_005A3140`; splat marks it as a hand-written function).
- `func_00107F08` (92 bytes) looks like `main`: it calls the library initialiser `func_005BC588`, an init phase (`func_00107E88`, which reaches
  `func_00102308` and `func_00108BF8`), the main body `func_00108040` (1,240 bytes; it calls into the online unit `func_001DC8F0` and the
  UI/render setup, and ends with an indirect call), and a shutdown phase (`func_00107ED8`). All **inferred** from the call graph; none of the
  phases is matched yet.
- C++ static initialisation runs before that. 309 functions of the form `(init, prio)` build the global objects; 244 are matched and the rest are parked
  because of a delay-slot choice that C source cannot steer (gt4.md). One family of them registers every native class
  (see [script-engine.md](script-engine.md), section 3.1).
- The **game loop is in script**: the community documents `main.adc` in the volume's script folder as holding the game loop, and the engine side exposes per-frame
  objects to it (`mUpdateContext` with pad state, `mRenderContext` with pages, `mManager.loadProject` to switch menus). The native race loop
  (`RaceBase`) is entered when a script starts a race. Where the native frame loop and the vertical-sync wait live is **unknown**.

## 2. Script engine (Adhoc)

What: the interpreter for Gran Turismo's own scripting language, bytecode version 5 in GT4. Everything menu-like, every game mode flow, the garage, the shop,
the calendar and the race set-up are scripts; the engine runs them and offers about a thousand native calls.

- Classes: `RefCounter`, `hObject` and the value types (`hInt`, `hFloat`, `hString`, `hArray`...), `hModule`/`hClass`, the member classes
  (`hBuiltinMethod`, `hBuiltinFunction`, `hBuiltinAttribute`, `hScriptMethod`...), 37 `hInst` bytecode instruction classes, frames, threads, and `hADHOC`.
- Address range 0x2EA548-0x32F027 plus 135 registration functions spread through the program (each next to the class it exposes) and 244 static initialisers.
- Matched: 1,122 of 1,634 functions (51% of the bytes); registration functions 131 of 135 (the largest family, solved from a template); the interpreter
  loop itself is largely open.
- Connects to: everything. Natives are plain C++ methods wrapped as `hBuiltin*` members; scripts see the data model, UI, storage and network through them,
  and the UI tree itself is made of script-visible objects (`mWidget` is an `hModule`).

Detail: [script-engine.md](script-engine.md), classes in [classes.md](classes.md) sections 1-2.

## 3. Game data model (garage, records, options)

What: the persistent state of a career and the lookup of car/course data, exposed to scripts as native classes. The data itself (SpecDB tables, car
files) comes from the volume; the code here reads it and offers queries.

- Classes: `mCarData` (SpecDB car queries), `mCarGarage` (83 + 46 natives: the garage car's colours, parts, gear ratios, engine curves, brake controller,
  drivetrain), `mGarage`, `mGame` (47), `mOption`, `mRaceData` (event requirements), `mRaceRecord`, `mCourseRecord`, `mLicenseRecord` (+ `*Unit` entries),
  `mCalendar` (GT-mode calendar events), `mPresent`, `mUsedCar`, `mDatabase`, `mCourseData`, `mFavorite`, `mPlayList`, `mQuickWork`, `mRunViewer`,
  `mDemonstration`. In the executable also the namespaced `SPEC_DATABASE::*` reader (tables, label/string storage, car equipment, parts info, race spec)
  and `GranTurismo4::*` game objects (Option, Context, ChampionshipContext, UsedCar, Present, Calendar, Favorite, UserProfile, LicenseRecord...).
- Range: 0x124208-0x1B688F (units `mQuickWork` ... `mDatabase`, in alphabetical order), plus `CarDataBase` at 0x44FF48.
- Matched: 1,081 of 2,025 functions (46% of the bytes). The getter families (150-500 B each, ids 1-5, 13, 19 of tools/families.py) are templates waiting for a layout-aware tool.
- Connects to: scripts (main consumer), the save system (section 9), the race (`RaceInformation` objects are filled from these records) and the volume (SpecDB files under `specdb/`).

## 4. UI framework ("faces" and widgets)

What: a retained widget tree that scripts build from `.mproject`/`.mwidget` layouts and then drive. A widget is also a script module, so scripts attach
behaviour to it directly. "Faces" are the leaf widgets that draw something.

- Classes ([classes.md](classes.md) sections 7-10): `mWidget` (160 bytes) -> `mComposite` (containers, boxes, scroll windows) and the faces: `mTextFace`,
  `mImageFace`, `mFrameImageFace`, `mModelFace` (3D model in a menu), `mSceneViewFace` (a 3D scene view, 51 own methods), `mCarFace`, `mFlashFace` (Flash-style
  movies, running on a `strobe::*` runtime), `mMovieFace`, `mGraphFace`, `mInputTextFace`, `mListBox`/`mSelectBox`/`mSelectBar`, `mOptionMenu`, `mRootWindow`,
  `mPhotoRenderFace` (photo printing), `mSlideShowFace`, `mEyetoyFace`. Actors (`mMoveActor`, `mRotateActor`, `mFadeActor`, `mBlinkActor`...) animate widgets;
  `mTransition` does page changes; 24 event classes (button press/release, key, motion, enter/leave/focus, script/callback events) and `MEventFilter` route input.
  Readers (`MfloatReader`, `MstringReader`...), `mXml`/`mDomNode`, `mProject` and `mManager` turn layout XML into widgets.
- Platform side: `mRenderContext(PS2)` (7.5 KB, owns pages and drawing), `mUpdateContext(PS2)` (pad/analog input per frame), `mWindowContext(PS2)`, `mImagePS2`,
  `mMoviePS2`, `mFlashPS2`, `mModelSetPS2`.
- Range: 0x1FC4D8-0x2EA547 (a unit per class, mostly alphabetical); 180 `m*` units hold 2,000 of 3,416 functions matched (coverage-map.md, 20.5% by bytes there because the
  large faces are open).
- Connects to: the script VM (widgets are modules; `mCall` on a widget runs a native or script method), input (pad state), the render path, and the race HUD, which
  is a separate display hierarchy (section 5).

Unmatched hot spots: the ten `mSceneViewFace` event virtuals (one solved member each, differing in a flag bit and an event string), `mListBox`/`mSelectBox`
getter families, and the big text/slideshow faces.

## 5. Race: sessions, game modes, HUD

What: the one large non-scripted subsystem. A script chooses a mode, fills race information objects, and starts a `RaceBase` subclass; the native code
then runs the session (grid, lap logic, replay, results) with the simulation (section 6).

- Session classes ([classes.md](classes.md) sections 11-13): `RaceBase` (100 vtable slots), `RacePS2Base` (148), `RaceBasic`, `RaceBasicWithRaceDisplay`,
  `RaceSinglePlayer` and its modes `RaceArcade` (Single, Demo), `RaceChampionship`, `RaceFreePractice`, `RaceGTmode`, `RaceNetSinglePlayer`
  (`RaceNetRallyBattle`), `RacePhotoDevelop`, `RaceTrainingBase` (`RaceTraining`, `RaceMission`); `RaceSolitaire` with `RaceFreeRun`, `RaceLicense`,
  `RaceMachineTest`; `RacePhotoMode`; `RaceLanBattle`, `RaceNetBattle`, `RaceSplitBattle` (split screen). Parameter objects: `RaceInformation` and one
  subclass per mode; results `ResultArcade` / `ResultChampionship` / `ResultLicense` / `ResultLinkBattle`; entries `RaceEntryBase` / `RaceEntryCar`.
- HUD: `RaceDisplay` (56 own methods) plus 32 `RaceDisplayObjectBase` elements (speed, tachometer, boost, gear, shift lamp, lap/time/rank, minimap, fuel, tire wear,
  MTR and Prius panels, message/tooltip/music display) and event-driven messages (`RaceDisplay*Event`).
- Pause/photo: `RacePause`, `SimplePause`, `PhotoPause`, `RacePhotoModeCameraManager`, `PhotoModeInput`, `RaceInput`.
- Range: 0x32F028-0x44D40F (named units from `RaceSplitBattleBase` at 0x32F028 to `RaceInput` at 0x426800), plus the "race front end glue" cluster `unit_004271E8`
  (0x4271E8-0x44D3F0: camera, skinning, snapshot paths, mostly tiny accessors).
- Matched: 3,368 of 6,995 functions but only 11% of the bytes (131 of 1,139 KB); the race code is big functions, so this is the main open area.
- Connects to: scripts (set-up and results travel through `mRunViewer`/`mRaceData` and the information objects), the dynamics (section 6), cameras and sound (section 8),
  and the network for online/LAN battles.

## 6. Physics and vehicle simulation

What: the per-step simulation of cars (tyres, suspension, drivetrain, collisions), a conductor per game mode, plus the car's body model and the human
(driver/crew) model.

- Named classes: `DynamicsConductor` and its 7 + 2 subclasses (`...SinglePlayer`, `...FreePractice`, `...FreeRun`, `...License`, `...Training`, `...Mission`,
  `...MachineTest`, `...Battle2P`, `...BattleMP`) - conductors of the physics update per mode (**inferred**); `VehicleModel` / `RaceCarModel` (43 own
  methods); `CarGeometryBase` with `CarGeometry`, `NormalCarGeometry`, `SpecialCarGeometry`, `MTRGeometry` (four implementations of one 48-virtual interface);
  `RigidBodyManager`; `HumanModel` / `RaceDriverModel` / `RaceCrewModel`; `HandleSolverBase` and its Easy/Fixed/Free/SingleHanded solvers (arm placement on the steering
  wheel, **inferred**); `ComputeDriverPostureCaller`; `EnemyLineProcessorOld` (AI racing line, **inferred**); `CarIconMaker`, `ShowRoomCar`.
- The numeric core has **no RTTI**: unit_0034E9A0 (0x34E9A0-0x363B10, "Bound/Rebound" suspension strings, float math), unit_00364818 / unit_003F7150 / unit_00415E90
  (0x364818-0x4074F0, 0x415E90-0x426600: vehicle dynamics and VU-style math with no strings, scratchpad base 0x70002000 appears nearby). Together about 280 KB with 5% matched.
- Matched: low (the dynamics, geometry and driver-model classes have 375 of 533 RTTI-named functions matched, but those are the thin shells).
- Connects to: the race sessions above (each mode picks its conductor), car data (section 3, `CarDataBase`) for parameters, camera/sound (the engine sound reads vehicle state, **inferred**).

## 7. Car data, garage and SpecDB

Covered under section 3 for the script-facing side. The volume stores car specs in `specdb/` (`.dbt`, `.idi`, `.sdb`) and the code reads them with the
`SPEC_DATABASE::*` reader; car models, tyres, wheels and wings are separate `car/`, `tire/`, `wheel/`, `wing/` file sets rendered through `mCarModel(PS2)` (2,656 bytes), `RaceCarModel`
and the geometry classes (hub, *GT4 file structure*).

## 8. Rendering, camera, sound and media

- **Rendering**: there is no single "renderer" class in the RTTI; drawing is spread over `mRenderContextPS2`, the model/image/movie/flash objects, `PGLXshapeBuilder`
  (0x494500) and unnamed code (unit_0046A050 and the GS/VU-side helpers). Image and media codecs: `Jpeg2Sys::*` (decoder/encoder, Huffman tables), `Ipic`/`IpicArchive`
  (preview images), `mpegif` (0x54DBB8, MPEG decode), the `strobe::*` Flash runtime, `GT4_Motion::*` (motion callbacks: geometry, lighting, perspective, render). The low-level
  graphics path is **unknown** at this level of detail.
- **Camera**: `CameraBase` / `SceneCameraBase` (0x44F188, 9 virtuals), `DevelopCamera` (54 own methods, 0x371CA8), `RacePhotoModeCameraManager` (0x377C60) and the namespaced `CameraSys::*` family
  (follow, on-board, heli, pit-in, round, shot, photo cameras).
- **Sound**: `GTSOUNDINSTRUMENT` (0x462500), `GTSOUNDINSTRUMENTJAM`, `EngineSound` (0x391878), `FileInstrumentStream`, `DirectivityMicrophone` (0x39A6F8), `RaceBGMBase` / `RaceBGMPS2` /
  `RaceLicenseBGM`, script natives `MSound` (load, play, startMusic...) and `MMusic`, `SDDRV::*` sequencers, `PlayStation2::CustomSpeexPlayer` (voice). The data: `sound_gt/` (BGM, effects, sequences) and `carsound/` in the volume.
- **Scenes and effects**: `Concourse` / `LicenseConcourse` / `ScenePack` (showroom and pit scenes), `ParticleManager`, `SparkParticle`.
- Matched: camera/sound classes about half of the RTTI-named functions; the numeric DSP code is unnamed.

## 9. Save data, memory card and storage

`mMemoryCardManager` / `mMemoryCardFile` / `mMemoryCardPlayList` and `mStorage` (with `mStorageMC` for memory cards, `mStorageHD` for the hard disk) are the script-facing storage;
`GT4MC::*` names the save file kinds (game data, replay, replay best/demo/list, photo, film, picture, play list, slide show list, patch data, icon), `Serialize::*`
holds replay/ghost/track data and `SettingSerialize` (0x450208, 2,560 bytes) serialises settings. `mGameStats` / `mPlayerStats` (`pack`/`unpack`) are the save blocks. DNAS
signing on saves is reachable through `MMemoryCardFile.saveDnas` and `mDnas`.

## 10. File system and the VOL volume

The game reads its content from a `.VOL` volume (RoFS format: fake GT3-style TOC, real page-based TOC with binary-searchable nodes, optional inflate per file, documented in the
hub's *PS2 GT4 Volume/RoFS* page). In the executable: `RoFS2::Deflated::PageManager` / `NullPageManager` / `IInflator`, `PlayStation2::FileDevice*` (`FileDeviceRo`, `FileDeviceRo2`, `FileDeviceRo2ExDL`,
`FileDevicePipe`, `FileDevicePS2`, `FileDeviceRoInflator`), `PDISTD::File*` (file objects/streams, FAT12/FAT32 for memory/USB storage), `PlayStation2::UsbStorage*`, and script-visible
`hFileIO` / `hIO` (open/close/read/write) and `mStorage` (directory entries). The inflate code (zlib-style C++, "Deflated"/"Inflator") is in unit_0046A050 (0x46A050-0x4944B0, 10% matched).
Not yet traced: the code that opens the volume at boot and resolves paths (**unknown** location).

## 11. Network and online

Two layers. Script-facing: `mNetwork` (163 natives, 508 bytes: interface/network init, login, lobby channels, game list/create/join, buddy/ignore lists, account statistics, LAN games, race-menu
synchronisation, file transfer, instant messages, billing), `mNetConf(PS2)` (network configuration), `mHttp` (GET/POST, SVO login), `mDnas`, `mComm` (sockets), `mSession`. Race side:
`RaceLanBattle`, `RaceNetBattle`, `RaceNetRallyBattle`, `RaceInputLan`, `RaceLanControlManager`, `ResultLinkBattle`. Underneath: the C network stack at 0x494578-0x54DB98 (unit_00494578:
837 of 3,689 functions, 5% of 755 KB): an XML parser (xmlns, CDATA, ENTITY), a GameSpy-style transport (hash alphabet strings), SCEA online code; plus `PlayStation2::LibnetBase`,
`Netcnf`, `PDIRTIME::*` (online sessions, "RTIME"), `PDICOMM::Host`, and the socket/iostream library in 0x5547E8-0x57A058.
The original online services no longer exist, so this layer matters for completeness rather than behaviour. It is flat C with many tiny functions and is the fifth target listed in coverage-map.md.

## 12. Libraries

- **Polyphony helpers** (`PDISTD`, `PDIUSB`, `PDIRTIME`, `PDICOMM`, `pdiRiderman`): file, FIFO, allocator, inflate, FAT and USB stacks, session layer, bone/rider math.
- **Sony SDK** (PS2 `sce*` wrappers, IOP RPC such as the sceDbc call at 0x58FF90, kernel-call stubs at 0x58B138 and 0x5C1CE0, soft-float compare): built by another compiler build, about 270 functions
  that our compiler cannot match; the 36 assembly functions are listed in `config/asm_functions.txt`.
- **C and C++ runtime**: libc, libstdc++ 2.9x (`basic_string`, iostreams, `type_info`, exceptions classes `bad_alloc`...), SGI STL instantiations. 0x596FA0 and up; only the STL templates
  match with our flags (libraries free stack temporaries per statement). Memory/tag allocator and string helpers: [runtime-types.md](runtime-types.md).

## What is unknown or open

- The location and shape of the native frame loop, scheduler and interrupt handlers (vsync, DMA) - not identified.
- The interpreter's dispatch loop and call convention for natives in detail (see script-engine.md, Gaps).
- The 3D renderer: GS/VU1 packet building and the display-list code are not named; they sit in unnamed clusters.
- The physics model's equations: the code is float-only and unmatched (5%); the structure of the tyre/suspension model is unknown.
- Everything marked **inferred** above.
