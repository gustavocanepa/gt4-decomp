#include "gt4/RaceBase.h"
typedef int s32;

extern "C" void RaceBase__setReplayEndingFrames(struct RaceBase *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 == -1) {
        arg1 = 5;
    }
    temp_v0 = arg1 * 0x3C;
    arg0->unkD5C = temp_v0;
    arg0->unkD58 = temp_v0 + 1;
}
