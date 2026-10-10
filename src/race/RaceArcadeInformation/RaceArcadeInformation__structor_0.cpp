#include "gt4/RaceArcadeInformation.h"
extern "C" void *RaceSinglePlayerInformation__structor_0(void);
extern "C" char RaceArcadeInformation__vtable[];

extern "C" void RaceArcadeInformation__structor_0(struct RaceArcadeInformation *arg0)
{
    RaceSinglePlayerInformation__structor_0();
    arg0->unk12C = RaceArcadeInformation__vtable;
}
