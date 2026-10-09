extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceFuelMeter__vtable;

extern "C" void RaceFuelMeter__structor_3(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x14) = &RaceFuelMeter__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
