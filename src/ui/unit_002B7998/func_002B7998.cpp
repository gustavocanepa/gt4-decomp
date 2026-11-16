/*
 * Static initialisation and destruction of a translation unit (gcc's
 * __static_initialization_and_destruction_0, inferred): the 72 ids of the shared header (0..0x47),
 * one global with a constructor and destructor.
 *
 * The unit has one more destruction statement whose code does not survive optimisation; it
 * still decides the delay slot of the object-0x40 test (which 0xFFFF register cse keeps), so it
 * is kept as a call to a const function whose value is unused, which flow deletes after cse
 * (inferred: what the original statement was is unknown; see func_002E3100).
 */
#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern Obj D_00838468;
extern Obj D_00838470;
extern Obj D_00838478;
extern Obj D_00838480;
extern Obj D_00838488;
extern Obj D_00838490;
extern Obj D_00838498;
extern Obj D_008384A0;
extern Obj D_008384A8;
extern Obj D_008384B0;
extern Obj D_008384B8;
extern Obj D_008384C0;
extern Obj D_008384C8;
extern Obj D_008384D0;
extern Obj D_008384D8;
extern Obj D_008384E0;
extern Obj D_008384E8;
extern Obj D_008384F0;
extern Obj D_008384F8;
extern Obj D_00838500;
extern Obj D_00838508;
extern Obj D_00838510;
extern Obj D_00838518;
extern Obj D_00838520;
extern Obj D_00838528;
extern Obj D_00838530;
extern Obj D_00838538;
extern Obj D_00838540;
extern Obj D_00838548;
extern Obj D_00838550;
extern Obj D_00838558;
extern Obj D_00838560;
extern Obj D_00838568;
extern Obj D_00838570;
extern Obj D_00838578;
extern Obj D_00838580;
extern Obj D_00838588;
extern Obj D_00838590;
extern Obj D_00838598;
extern Obj D_008385A0;
extern Obj D_008385A8;
extern Obj D_008385B0;
extern Obj D_008385B8;
extern Obj D_008385C0;
extern Obj D_008385C8;
extern Obj D_008385D0;
extern Obj D_008385D8;
extern Obj D_008385E0;
extern Obj D_008385E8;
extern Obj D_008385F0;
extern Obj D_008385F8;
extern Obj D_00838600;
extern Obj D_00838608;
extern Obj D_00838610;
extern Obj D_00838618;
extern Obj D_00838620;
extern Obj D_00838628;
extern Obj D_00838630;
extern Obj D_00838638;
extern Obj D_00838640;
extern Obj D_00838648;
extern Obj D_00838650;
extern Obj D_00838658;
extern Obj D_00838660;
extern Obj D_00838668;
extern Obj D_00838670;
extern Obj D_00838678;
extern Obj D_00838680;
extern Obj D_00838688;
extern Obj D_00838690;
extern Obj D_00838698;
extern Obj D_008386A0;
extern char D_008386A8[];
extern "C" void func_00574D78(void *);
extern "C" void func_00574DA8(void *, s32);

extern "C" s32 released(void *self, s32 flags) __attribute__((const));
extern "C" void func_002B7998(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) ctor(&D_00838468, 0x0);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838470, 0x1);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838478, 0x2);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838480, 0x3);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838488, 0x4);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838490, 0x5);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838498, 0x6);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384A0, 0x7);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384A8, 0x8);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384B0, 0x9);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384B8, 0xa);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384C0, 0xb);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384C8, 0xc);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384D0, 0xd);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384D8, 0xe);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384E0, 0xf);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384E8, 0x10);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384F0, 0x11);
    if (prio == 0xFFFF && init == 1) ctor(&D_008384F8, 0x12);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838500, 0x13);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838508, 0x14);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838510, 0x15);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838518, 0x16);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838520, 0x17);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838528, 0x18);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838530, 0x19);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838538, 0x1a);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838540, 0x1b);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838548, 0x1c);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838550, 0x1d);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838558, 0x1e);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838560, 0x1f);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838568, 0x20);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838570, 0x21);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838578, 0x22);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838580, 0x23);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838588, 0x24);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838590, 0x25);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838598, 0x26);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385A0, 0x27);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385A8, 0x28);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385B0, 0x29);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385B8, 0x2a);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385C0, 0x2b);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385C8, 0x2c);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385D0, 0x2d);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385D8, 0x2e);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385E0, 0x2f);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385E8, 0x30);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385F0, 0x31);
    if (prio == 0xFFFF && init == 1) ctor(&D_008385F8, 0x32);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838600, 0x33);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838608, 0x34);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838610, 0x35);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838618, 0x36);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838620, 0x37);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838628, 0x38);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838630, 0x39);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838638, 0x3a);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838640, 0x3b);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838648, 0x3c);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838650, 0x3d);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838658, 0x3e);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838660, 0x3f);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838668, 0x40);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838670, 0x41);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838678, 0x42);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838680, 0x43);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838688, 0x44);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838690, 0x45);
    if (prio == 0xFFFF && init == 1) ctor(&D_00838698, 0x46);
    if (prio == 0xFFFF && init == 1) ctor(&D_008386A0, 0x47);
    if (prio == 0xFFFF && init == 1) func_00574D78(D_008386A8);
    if (prio == 0xFFFF && init == 0) func_00574DA8(D_008386A8, 0x2);
    if (prio == 0xFFFF && init == 0) released((void *)&D_008386A8, 2);
}
