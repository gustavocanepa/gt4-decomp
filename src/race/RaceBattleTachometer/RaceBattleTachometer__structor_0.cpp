#include "gt4/RaceBattleTachometer.h"
extern "C" void *RaceBarMeter__structor_0(void *arg0);
extern "C" char RaceBattleTachometer__vtable[];

extern "C" void RaceBattleTachometer__structor_0(struct RaceBattleTachometer *arg0)
{
    RaceBarMeter__structor_0(arg0);
    arg0->unk14 = RaceBattleTachometer__vtable;
}
