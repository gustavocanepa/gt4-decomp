extern "C" void func_0044CF90(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00683230;

extern "C" void func_003DE550(void *arg0, int arg1) {
    *(void **)arg0 = &D_00683230;
    func_0044CF90(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
