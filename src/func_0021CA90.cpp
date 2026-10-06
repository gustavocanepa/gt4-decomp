extern "C" void func_001FC3A8(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_0021CA90(void *arg0, int arg1) {
    func_001FC3A8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
