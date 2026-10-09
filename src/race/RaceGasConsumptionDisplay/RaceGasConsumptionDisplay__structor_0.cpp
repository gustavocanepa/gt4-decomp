extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char RaceGasConsumptionDisplay__vtable[];

extern "C" void RaceGasConsumptionDisplay__structor_0(void *arg0) {
    void *s0 = arg0;
    RaceValueDisplayBase__structor_1(s0);
    *(int *)((char *)s0 + 0x6C) = 0;
    *(int *)((char *)s0 + 0x68) = 0;
    *(void **)((char *)s0 + 0x14) = RaceGasConsumptionDisplay__vtable;
}
