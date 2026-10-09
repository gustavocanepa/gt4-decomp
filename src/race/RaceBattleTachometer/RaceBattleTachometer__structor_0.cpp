extern "C" void *RaceBarMeter__structor_0(void *arg0);
extern "C" char RaceBattleTachometer__vtable[];

extern "C" void RaceBattleTachometer__structor_0(void *arg0)
{
    RaceBarMeter__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = RaceBattleTachometer__vtable;
}
