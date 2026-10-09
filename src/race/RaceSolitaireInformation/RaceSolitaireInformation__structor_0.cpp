extern "C" void *RaceInformation__structor_0(void *arg0);
extern "C" void *func_003D6268(void *arg0);
extern "C" char RaceSolitaireInformation__vtable[];

extern "C" void *RaceSolitaireInformation__structor_0(void *arg0)
{
    RaceInformation__structor_0(arg0);
    *(void **)((char *)arg0 + 0x12C) = RaceSolitaireInformation__vtable;
    return func_003D6268((char *)arg0 + 0x130);
}
