typedef int s32;

extern "C" void func_005F3118(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00678670;

extern "C" void func_00335A38(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &D_00678670;
    func_005F3118(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
