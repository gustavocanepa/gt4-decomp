extern "C" void RaceResultBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *ResultChampionship__vtable;

extern "C" void ResultChampionship__structor_2(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &ResultChampionship__vtable;
    RaceResultBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
