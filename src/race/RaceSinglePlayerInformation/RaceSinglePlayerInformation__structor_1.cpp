#include "gt4/RaceSinglePlayerInformation.h"
typedef int s32;

extern void *RaceSinglePlayerInformation__vtable;
extern "C" void func_003D62A8(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceSinglePlayerInformation__structor_1(struct RaceSinglePlayerInformation *arg0, s32 arg1)
{
    arg0->unk12C_pvoid = &RaceSinglePlayerInformation__vtable;
    func_003D62A8(&arg0->unk130, 2);
    RaceInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
