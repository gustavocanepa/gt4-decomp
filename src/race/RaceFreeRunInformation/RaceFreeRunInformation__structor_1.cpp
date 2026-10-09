typedef int s32;

extern "C" void RaceSolitaireInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceFreeRunInformation__vtable;

extern "C" void RaceFreeRunInformation__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &RaceFreeRunInformation__vtable;
    RaceSolitaireInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
