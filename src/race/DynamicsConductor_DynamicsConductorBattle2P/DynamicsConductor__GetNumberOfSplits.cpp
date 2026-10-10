#include "gt4/DynamicsConductorBattle2P.h"
typedef int s32;

extern "C" s32 RaceCourse__getCheckPointCount(s32 arg0, s32 arg1);

extern "C" s32 DynamicsConductor__GetNumberOfSplits(struct DynamicsConductorBattle2P *arg0) {
    s32 temp_v0;

    temp_v0 = RaceCourse__getCheckPointCount(arg0->unkCBD8, 0) + 1;
    return (temp_v0 >= 0x11) ? 0x10 : temp_v0;
}
