extern "C" void func_001CB240();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_001CB1E8(void *arg0, int arg1) {
    func_001CB240();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
