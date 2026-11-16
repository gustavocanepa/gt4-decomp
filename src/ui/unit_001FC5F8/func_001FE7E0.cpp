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
extern Obj D_00829A40;
extern Obj D_00829A48;
extern Obj D_00829A50;
extern Obj D_00829A58;
extern Obj D_00829A60;
extern Obj D_00829A68;
extern Obj D_00829A70;
extern Obj D_00829A78;
extern Obj D_00829A80;
extern Obj D_00829A88;
extern Obj D_00829A90;
extern Obj D_00829A98;
extern Obj D_00829AA0;
extern Obj D_00829AA8;
extern Obj D_00829AB0;
extern Obj D_00829AB8;
extern Obj D_00829AC0;
extern Obj D_00829AC8;
extern Obj D_00829AD0;
extern Obj D_00829AD8;
extern Obj D_00829AE0;
extern Obj D_00829AE8;
extern Obj D_00829AF0;
extern Obj D_00829AF8;
extern Obj D_00829B00;
extern Obj D_00829B08;
extern Obj D_00829B10;
extern Obj D_00829B18;
extern Obj D_00829B20;
extern Obj D_00829B28;
extern Obj D_00829B30;
extern Obj D_00829B38;
extern Obj D_00829B40;
extern Obj D_00829B48;
extern Obj D_00829B50;
extern Obj D_00829B58;
extern Obj D_00829B60;
extern Obj D_00829B68;
extern Obj D_00829B70;
extern Obj D_00829B78;
extern Obj D_00829B80;
extern Obj D_00829B88;
extern Obj D_00829B90;
extern Obj D_00829B98;
extern Obj D_00829BA0;
extern Obj D_00829BA8;
extern Obj D_00829BB0;
extern Obj D_00829BB8;
extern Obj D_00829BC0;
extern Obj D_00829BC8;
extern Obj D_00829BD0;
extern Obj D_00829BD8;
extern Obj D_00829BE0;
extern Obj D_00829BE8;
extern Obj D_00829BF0;
extern Obj D_00829BF8;
extern Obj D_00829C00;
extern Obj D_00829C08;
extern Obj D_00829C10;
extern Obj D_00829C18;
extern Obj D_00829C20;
extern Obj D_00829C28;
extern Obj D_00829C30;
extern Obj D_00829C38;
extern Obj D_00829C40;
extern Obj D_00829C48;
extern Obj D_00829C50;
extern Obj D_00829C58;
extern Obj D_00829C60;
extern Obj D_00829C68;
extern Obj D_00829C70;
extern Obj D_00829C78;
extern char D_00618E40[];
extern "C" void func_001FD2A8(void *);
extern "C" void func_001FD2F8(void *, s32) throw();

extern "C" s32 released(void *self, s32 flags) __attribute__((const));
extern "C" void func_001FE7E0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A40, 0x0);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A48, 0x1);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A50, 0x2);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A58, 0x3);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A60, 0x4);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A68, 0x5);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A70, 0x6);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A78, 0x7);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A80, 0x8);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A88, 0x9);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A90, 0xa);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829A98, 0xb);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AA0, 0xc);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AA8, 0xd);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AB0, 0xe);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AB8, 0xf);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AC0, 0x10);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AC8, 0x11);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AD0, 0x12);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AD8, 0x13);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AE0, 0x14);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AE8, 0x15);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AF0, 0x16);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829AF8, 0x17);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B00, 0x18);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B08, 0x19);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B10, 0x1a);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B18, 0x1b);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B20, 0x1c);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B28, 0x1d);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B30, 0x1e);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B38, 0x1f);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B40, 0x20);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B48, 0x21);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B50, 0x22);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B58, 0x23);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B60, 0x24);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B68, 0x25);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B70, 0x26);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B78, 0x27);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B80, 0x28);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B88, 0x29);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B90, 0x2a);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829B98, 0x2b);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BA0, 0x2c);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BA8, 0x2d);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BB0, 0x2e);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BB8, 0x2f);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BC0, 0x30);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BC8, 0x31);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BD0, 0x32);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BD8, 0x33);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BE0, 0x34);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BE8, 0x35);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BF0, 0x36);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829BF8, 0x37);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C00, 0x38);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C08, 0x39);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C10, 0x3a);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C18, 0x3b);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C20, 0x3c);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C28, 0x3d);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C30, 0x3e);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C38, 0x3f);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C40, 0x40);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C48, 0x41);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C50, 0x42);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C58, 0x43);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C60, 0x44);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C68, 0x45);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C70, 0x46);
    if (prio == 0xFFFF && init == 1) ctor(&D_00829C78, 0x47);
    if (prio == 0xFFFF && init == 1) func_001FD2A8(D_00618E40);
    if (prio == 0xFFFF && init == 0) func_001FD2F8(D_00618E40, 0x2);
    if (prio == 0xFFFF && init == 0) released((void *)&D_00618E40, 2);
}
