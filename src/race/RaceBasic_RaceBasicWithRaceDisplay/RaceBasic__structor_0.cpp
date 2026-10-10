#include "gt4/RaceBasic.h"
typedef int s32;

extern void *RaceBasic__vtable;
extern "C" void *RacePS2Base__structor_0(void *);

extern "C" void *RaceBasic__structor_0(struct RaceBasic *arg0) {
    void *r0 = RacePS2Base__structor_0(arg0);
    arg0->unkE400 = 0x0;
    arg0->unk64 = &RaceBasic__vtable;
    arg0->unkE404 = 0x0;
    arg0->unkE40C = 0x0;
    arg0->unkE414 = 0x0;
    arg0->unkE408 = 0x0;
    arg0->unkE410 = 0x0;
    arg0->unkE418 = 0x0;
    arg0->unkE41C = 0x0;
    arg0->unkE420 = 0x0;
    arg0->unkE424 = 0x0;
    return r0;
}
