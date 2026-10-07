extern "C" void func_0038A708(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_005F3210(void *arg0, int arg1) {
    func_0038A708(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
