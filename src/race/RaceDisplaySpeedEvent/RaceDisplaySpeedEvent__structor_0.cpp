extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char RaceDisplaySpeedEvent__vtable[];

extern "C" void RaceDisplaySpeedEvent__structor_0(void *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = RaceDisplaySpeedEvent__vtable;
}
