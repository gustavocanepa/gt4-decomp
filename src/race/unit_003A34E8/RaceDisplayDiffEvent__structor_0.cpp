#include "gt4/RaceDisplayDiffEvent.h"
extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplayDiffEvent__vtable[];

extern "C" void RaceDisplayDiffEvent__structor_0(struct RaceDisplayDiffEvent *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = RaceDisplayDiffEvent__vtable;
}
