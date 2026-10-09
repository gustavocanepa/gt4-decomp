extern "C" void RaceEntryBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00679880;

extern "C" void func_0033B840(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_00679880;
    RaceEntryBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
