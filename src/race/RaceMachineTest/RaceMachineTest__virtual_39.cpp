#include "gt4/RaceMachineTest.h"
typedef int s32;

extern "C" void RaceBase__virtual_39(struct RaceMachineTest *arg0);
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceMachineTest__virtual_39(struct RaceMachineTest *arg0) {
    RaceBase__virtual_39(arg0);

    CarIconMaker__structor_1((char *)arg0 + 0xF140, arg0->unk6C);
}
