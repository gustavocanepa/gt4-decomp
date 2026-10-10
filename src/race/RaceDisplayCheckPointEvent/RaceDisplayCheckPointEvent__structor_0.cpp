#include "gt4/RaceDisplayCheckPointEvent.h"
extern "C" void *RaceDisplayLapTimeEvent__structor_0(void *arg0);
extern "C" char RaceDisplayCheckPointEvent__vtable[];

extern "C" void RaceDisplayCheckPointEvent__structor_0(struct RaceDisplayCheckPointEvent *arg0)
{
    RaceDisplayLapTimeEvent__structor_0(arg0);
    arg0->unk4 = RaceDisplayCheckPointEvent__vtable;
    arg0->unkC = 0;
}
