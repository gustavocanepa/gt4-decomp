#include "gt4/RaceMachineTestInformation.h"
typedef int s32;

extern void *RaceMachineTestInformation__vtable;
extern "C" void func_003D62A8(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceMachineTestInformation__structor_1(struct RaceMachineTestInformation *arg0, s32 arg1)
{
    arg0->unk12C_pvoid = &RaceMachineTestInformation__vtable;
    func_003D62A8(&arg0->unk130, 2);
    RaceInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
