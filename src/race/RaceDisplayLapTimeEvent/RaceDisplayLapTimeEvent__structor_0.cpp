#include "gt4/RaceDisplayLapTimeEvent.h"
extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplayLapTimeEvent__vtable[];

extern "C" void RaceDisplayLapTimeEvent__structor_0(struct RaceDisplayLapTimeEvent *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = RaceDisplayLapTimeEvent__vtable;
}
