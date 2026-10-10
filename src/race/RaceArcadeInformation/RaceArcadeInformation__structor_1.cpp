#include "gt4/RaceArcadeInformation.h"
typedef int s32;

extern "C" void RaceSinglePlayerInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceArcadeInformation__vtable;

extern "C" void RaceArcadeInformation__structor_1(struct RaceArcadeInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceArcadeInformation__vtable;
    RaceSinglePlayerInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
