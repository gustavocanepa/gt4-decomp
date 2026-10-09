typedef int s32;

extern "C" void PauseBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *SimplePause__vtable;

extern "C" void SimplePause__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x8) = &SimplePause__vtable;
    PauseBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
