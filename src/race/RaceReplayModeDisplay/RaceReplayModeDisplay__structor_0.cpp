#include "gt4/RaceReplayModeDisplay.h"
extern "C" void *RaceMessageDisplay__structor_1(void *arg0);
extern "C" char RaceReplayModeDisplay__vtable[];

extern "C" void RaceReplayModeDisplay__structor_0(struct RaceReplayModeDisplay *arg0)
{
    RaceMessageDisplay__structor_1(arg0);
    arg0->unk154 = 0;
    arg0->unk150 = 0;
    arg0->unk14 = RaceReplayModeDisplay__vtable;
}
