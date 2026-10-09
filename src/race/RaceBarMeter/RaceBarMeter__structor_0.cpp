extern "C" void *RaceMeterBase__structor_1(void *arg0);
extern "C" char RaceBarMeter__vtable[];

extern "C" void RaceBarMeter__structor_0(void *arg0)
{
    RaceMeterBase__structor_1(arg0);
    *(void **)((char *)arg0 + 0x14) = RaceBarMeter__vtable;
}
