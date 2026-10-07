extern "C" void func_0020FCE0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00667528;

extern "C" void func_005DEC28(void *arg0, int arg1) {
    *(void **)arg0 = &D_00667528;
    func_0020FCE0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
