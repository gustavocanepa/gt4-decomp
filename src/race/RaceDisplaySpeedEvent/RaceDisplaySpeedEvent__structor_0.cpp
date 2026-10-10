#include "gt4/RaceDisplaySpeedEvent.h"
extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplaySpeedEvent__vtable[];

extern "C" void RaceDisplaySpeedEvent__structor_0(struct RaceDisplaySpeedEvent *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = RaceDisplaySpeedEvent__vtable;
}
