extern "C" void *RaceSolitaireInformation__structor_0(void);
extern "C" char RaceFreeRunInformation__vtable[];

extern "C" void RaceFreeRunInformation__structor_0(void *arg0)
{
    RaceSolitaireInformation__structor_0();
    *(char **)((char *)arg0 + 0x12C) = RaceFreeRunInformation__vtable;
}
