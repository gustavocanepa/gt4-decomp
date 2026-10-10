#include "gt4/RaceMTRGravityMeter.h"
extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceMTRGravityMeter__vtable;

extern "C" void RaceMTRGravityMeter__structor_1(struct RaceMTRGravityMeter *arg0, int arg1) {
    arg0->unk14_pvoid = &RaceMTRGravityMeter__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
