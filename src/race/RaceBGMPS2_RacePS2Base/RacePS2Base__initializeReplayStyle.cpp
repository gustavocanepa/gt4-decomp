#include "gt4/RacePS2Base.h"
typedef int s32;

struct Obj;
extern "C" void RaceBase__setReplayStartingFrames(Obj *arg0, s32 arg1);

extern "C" void RacePS2Base__initializeReplayStyle(struct RacePS2Base *arg0) {
    arg0->unkCF4C_s32 = 0;
    RaceBase__setReplayStartingFrames((Obj *)arg0, 2);
}
