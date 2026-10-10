#include "gt4/RaceBarMeter.h"
extern "C" void *RaceMeterBase__structor_1(void *arg0);
extern "C" char RaceBarMeter__vtable[];

extern "C" void RaceBarMeter__structor_0(struct RaceBarMeter *arg0)
{
    RaceMeterBase__structor_1(arg0);
    arg0->unk14 = RaceBarMeter__vtable;
}
