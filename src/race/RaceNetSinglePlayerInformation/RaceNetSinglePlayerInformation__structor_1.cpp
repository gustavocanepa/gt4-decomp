typedef int s32;

extern "C" void RaceSinglePlayerInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceNetSinglePlayerInformation__vtable;

extern "C" void RaceNetSinglePlayerInformation__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &RaceNetSinglePlayerInformation__vtable;
    RaceSinglePlayerInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
