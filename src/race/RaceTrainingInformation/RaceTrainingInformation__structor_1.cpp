#include "gt4/RaceTrainingInformation.h"
typedef int s32;

extern "C" void RaceSinglePlayerInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceTrainingInformation__vtable;

extern "C" void RaceTrainingInformation__structor_1(struct RaceTrainingInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceTrainingInformation__vtable;
    RaceSinglePlayerInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
