#include "gt4/RaceDisplayInformationEvent.h"
extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplayInformationEvent__vtable[];

extern "C" void RaceDisplayInformationEvent__structor_0(struct RaceDisplayInformationEvent *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = RaceDisplayInformationEvent__vtable;
}
