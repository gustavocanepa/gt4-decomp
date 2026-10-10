#include "gt4/RaceDisplayMessageEvent.h"
extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplayMessageEvent__vtable[];

extern "C" void RaceDisplayMessageEvent__structor_0(struct RaceDisplayMessageEvent *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = RaceDisplayMessageEvent__vtable;
}
