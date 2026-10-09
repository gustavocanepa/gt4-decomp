typedef int s32;

extern "C" void RaceSinglePlayerInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceTrainingInformation__vtable;

extern "C" void RaceTrainingInformation__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &RaceTrainingInformation__vtable;
    RaceSinglePlayerInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
