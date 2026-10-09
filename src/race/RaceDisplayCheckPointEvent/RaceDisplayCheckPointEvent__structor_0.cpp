extern "C" void *RaceDisplayLapTimeEvent__structor_0(void *arg0);
extern "C" char RaceDisplayCheckPointEvent__vtable[];

extern "C" void RaceDisplayCheckPointEvent__structor_0(void *arg0)
{
    RaceDisplayLapTimeEvent__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = RaceDisplayCheckPointEvent__vtable;
    *(int *)((char *)arg0 + 0xC) = 0;
}
