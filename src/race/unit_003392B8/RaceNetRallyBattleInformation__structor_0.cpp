extern "C" void *RaceNetSinglePlayerInformation__structor_0(void);
extern "C" char RaceNetRallyBattleInformation__vtable[];

extern "C" void RaceNetRallyBattleInformation__structor_0(void *arg0)
{
    RaceNetSinglePlayerInformation__structor_0();
    *(char **)((char *)arg0 + 0x12C) = RaceNetRallyBattleInformation__vtable;
}
