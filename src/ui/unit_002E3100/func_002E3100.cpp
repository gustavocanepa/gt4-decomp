/*
 * Static initialisation and destruction of a ui translation unit (gcc's
 * __static_initialization_and_destruction_0, inferred): the 72 ids of the shared header
 * (0..0x47), the unit's registration with func_00325010 (callbacks func_002E2128/2150/2178),
 * then ten RGBA colours built with func_00203148 and destroyed in reverse order with
 * func_00203118.
 *
 * The unit has one more destruction statement whose code does not survive optimisation; it still
 * decides which statement's 0xFFFF register cse keeps for the last priority test (the second
 * `ori $s1, 0xFFFF`), so it is kept here as a call to a const function whose value is unused,
 * which flow deletes after cse (inferred: what the original statement was is unknown).
 */
#include "types.h"

struct Id { s32 v; };
static inline void construct(Id *const self, s32 n) { self->v = n; }

struct Color { f32 r; f32 g; f32 b; f32 a; };

extern "C" Id D_0083B3D8;
extern "C" Id D_0083B3E0;
extern "C" Id D_0083B3E8;
extern "C" Id D_0083B3F0;
extern "C" Id D_0083B3F8;
extern "C" Id D_0083B400;
extern "C" Id D_0083B408;
extern "C" Id D_0083B410;
extern "C" Id D_0083B418;
extern "C" Id D_0083B420;
extern "C" Id D_0083B428;
extern "C" Id D_0083B430;
extern "C" Id D_0083B438;
extern "C" Id D_0083B440;
extern "C" Id D_0083B448;
extern "C" Id D_0083B450;
extern "C" Id D_0083B458;
extern "C" Id D_0083B460;
extern "C" Id D_0083B468;
extern "C" Id D_0083B470;
extern "C" Id D_0083B478;
extern "C" Id D_0083B480;
extern "C" Id D_0083B488;
extern "C" Id D_0083B490;
extern "C" Id D_0083B498;
extern "C" Id D_0083B4A0;
extern "C" Id D_0083B4A8;
extern "C" Id D_0083B4B0;
extern "C" Id D_0083B4B8;
extern "C" Id D_0083B4C0;
extern "C" Id D_0083B4C8;
extern "C" Id D_0083B4D0;
extern "C" Id D_0083B4D8;
extern "C" Id D_0083B4E0;
extern "C" Id D_0083B4E8;
extern "C" Id D_0083B4F0;
extern "C" Id D_0083B4F8;
extern "C" Id D_0083B500;
extern "C" Id D_0083B508;
extern "C" Id D_0083B510;
extern "C" Id D_0083B518;
extern "C" Id D_0083B520;
extern "C" Id D_0083B528;
extern "C" Id D_0083B530;
extern "C" Id D_0083B538;
extern "C" Id D_0083B540;
extern "C" Id D_0083B548;
extern "C" Id D_0083B550;
extern "C" Id D_0083B558;
extern "C" Id D_0083B560;
extern "C" Id D_0083B568;
extern "C" Id D_0083B570;
extern "C" Id D_0083B578;
extern "C" Id D_0083B580;
extern "C" Id D_0083B588;
extern "C" Id D_0083B590;
extern "C" Id D_0083B598;
extern "C" Id D_0083B5A0;
extern "C" Id D_0083B5A8;
extern "C" Id D_0083B5B0;
extern "C" Id D_0083B5B8;
extern "C" Id D_0083B5C0;
extern "C" Id D_0083B5C8;
extern "C" Id D_0083B5D0;
extern "C" Id D_0083B5D8;
extern "C" Id D_0083B5E0;
extern "C" Id D_0083B5E8;
extern "C" Id D_0083B5F0;
extern "C" Id D_0083B5F8;
extern "C" Id D_0083B600;
extern "C" Id D_0083B608;
extern "C" Id D_0083B610;

extern "C" Color D_0083B618;
extern "C" Color D_0083B628;
extern "C" Color D_0083B638;
extern "C" Color D_0083B648;
extern "C" Color D_0083B658;
extern "C" Color D_0083B668;
extern "C" Color D_0083B678;
extern "C" Color D_0083B688;
extern "C" Color D_0083B698;
extern "C" Color D_0083B6A8;

extern "C" char D_00619A80[];
extern "C" char D_0069D0A0[];

extern "C" void func_002E2128(void);
extern "C" void func_002E2150(void);
extern "C" void func_002E2178(void);
extern "C" void func_00325010(void *info, void *name, s32 size, void (*init)(void), void (*start)(void),
                              void (*finish)(void));
extern "C" void func_00203148(Color *self, f32 r, f32 g, f32 b, f32 a);
extern "C" void func_00203118(Color *self, s32 flags);
extern "C" s32 released(void *self, s32 flags) __attribute__((const));

extern "C" void func_002E3100(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) construct(&D_0083B3D8, 0x0);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B3E0, 0x1);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B3E8, 0x2);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B3F0, 0x3);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B3F8, 0x4);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B400, 0x5);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B408, 0x6);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B410, 0x7);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B418, 0x8);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B420, 0x9);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B428, 0xa);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B430, 0xb);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B438, 0xc);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B440, 0xd);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B448, 0xe);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B450, 0xf);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B458, 0x10);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B460, 0x11);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B468, 0x12);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B470, 0x13);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B478, 0x14);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B480, 0x15);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B488, 0x16);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B490, 0x17);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B498, 0x18);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4A0, 0x19);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4A8, 0x1a);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4B0, 0x1b);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4B8, 0x1c);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4C0, 0x1d);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4C8, 0x1e);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4D0, 0x1f);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4D8, 0x20);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4E0, 0x21);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4E8, 0x22);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4F0, 0x23);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B4F8, 0x24);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B500, 0x25);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B508, 0x26);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B510, 0x27);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B518, 0x28);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B520, 0x29);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B528, 0x2a);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B530, 0x2b);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B538, 0x2c);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B540, 0x2d);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B548, 0x2e);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B550, 0x2f);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B558, 0x30);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B560, 0x31);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B568, 0x32);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B570, 0x33);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B578, 0x34);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B580, 0x35);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B588, 0x36);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B590, 0x37);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B598, 0x38);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5A0, 0x39);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5A8, 0x3a);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5B0, 0x3b);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5B8, 0x3c);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5C0, 0x3d);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5C8, 0x3e);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5D0, 0x3f);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5D8, 0x40);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5E0, 0x41);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5E8, 0x42);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5F0, 0x43);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B5F8, 0x44);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B600, 0x45);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B608, 0x46);
    if (prio == 0xFFFF && init == 1) construct(&D_0083B610, 0x47);
    if (prio == 0xFFFF && init == 1)
        func_00325010(D_00619A80, D_0069D0A0, 0x44, func_002E2128, func_002E2150, func_002E2178);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B618, 1.0f, 1.0f, 1.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B628, 1.0f, 1.0f, 1.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B638, 0x1.cdd2fp-1f, 0x1.0d013ap-1f, 0.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B648, 0.5f, 0.5f, 0.5f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B658, 0.0f, 0.0f, 0.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B668, 1.0f, 1.0f, 1.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B678, 0x1.cdd2fp-2f, 0x1.0d013ap-2f, 0.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B688, 0.25f, 0.25f, 0.25f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B698, 0.0f, 0.0f, 0.0f, 1.0f);
    if (prio == 0xFFFF && init == 1) func_00203148(&D_0083B6A8, 0.5f, 0.5f, 0.5f, 1.0f);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B6A8, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B698, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B688, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B678, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B668, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B658, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B648, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B638, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B628, 2);
    if (prio == 0xFFFF && init == 0) func_00203118(&D_0083B618, 2);
    if (prio == 0xFFFF && init == 0) released(D_00619A80, 2);
}
