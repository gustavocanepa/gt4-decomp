#include "gt4/RaceReplayInformation.h"
typedef int s32;

extern "C" void RaceInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceReplayInformation__vtable;

extern "C" void RaceReplayInformation__structor_1(struct RaceReplayInformation *arg0, s32 arg1) {
    arg0->unk12C = &RaceReplayInformation__vtable;
    RaceInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
