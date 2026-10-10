#include "gt4/RaceRefuelMeter.h"
typedef int s32;

extern void *RaceRefuelMeter__vtable;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);

extern "C" void *RaceRefuelMeter__structor_1(struct RaceRefuelMeter *arg0) {
    void *r0 = RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk18 = 0x0;
    arg0->unk14 = &RaceRefuelMeter__vtable;
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk24 = 0x0;
    return r0;
}
