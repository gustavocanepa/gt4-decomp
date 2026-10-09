extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplayLapTimeEvent__vtable[];

extern "C" void RaceDisplayLapTimeEvent__structor_0(void *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = RaceDisplayLapTimeEvent__vtable;
}
