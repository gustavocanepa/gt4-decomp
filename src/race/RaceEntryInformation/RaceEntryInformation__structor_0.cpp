#include "gt4/RaceEntryInformation.h"
typedef int s32;

extern "C" s32 func_00444190(s32 arg0);
extern "C" char RaceEntryInformation__vtable[];

extern "C" void RaceEntryInformation__structor_0(struct RaceEntryInformation *arg0)
{
    func_00444190((s32)arg0);
    arg0->unk178 = 0;
    arg0->unk17C = RaceEntryInformation__vtable;
}
