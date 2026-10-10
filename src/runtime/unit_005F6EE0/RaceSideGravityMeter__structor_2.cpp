#include "gt4/RaceSideGravityMeter.h"
extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceSideGravityMeter__vtable;

extern "C" void RaceSideGravityMeter__structor_2(struct RaceSideGravityMeter *arg0, int arg1) {
    arg0->unk14_pvoid = &RaceSideGravityMeter__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
