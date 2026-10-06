extern "C" void func_001CB790();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_001CB738(void *arg0, int arg1) {
    func_001CB790();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
