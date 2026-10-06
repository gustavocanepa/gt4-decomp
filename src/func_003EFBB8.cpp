extern "C" void func_00575DA0(int arg);
extern "C" void func_005C1628(void *arg);

extern "C" void func_003EFBB8(void *arg0, int arg1) {
    func_00575DA0(*(int*)arg0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
