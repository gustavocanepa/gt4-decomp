#include "gt4/RaceBase.h"
typedef int s32;
typedef float f32;

extern "C" void RaceBase__setAcceleratedTime(struct RaceBase *arg0, f32 fparg0) {
    s32 var_v0 = 1;
    if (fparg0 == 1.0f) {
        var_v0 = 0;
    }
    arg0->unkD38 = var_v0;
    arg0->unkD3C = fparg0;
}
