extern "C" void func_001B9BE8(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_001BB248(void *arg0, int arg1) {
    func_001B9BE8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
