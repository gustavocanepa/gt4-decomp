extern "C" void *RaceSinglePlayerInformation__structor_0(void);
extern "C" char RaceArcadeInformation__vtable[];

extern "C" void RaceArcadeInformation__structor_0(void *arg0)
{
    RaceSinglePlayerInformation__structor_0();
    *(char **)((char *)arg0 + 0x12C) = RaceArcadeInformation__vtable;
}
