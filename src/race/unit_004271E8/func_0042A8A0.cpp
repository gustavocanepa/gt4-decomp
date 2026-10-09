extern "C" void func_0042A5F0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00686900;

extern "C" void func_0042A8A0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_00686900;
    func_0042A5F0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
