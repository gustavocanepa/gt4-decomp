extern "C" void func_00444210(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_003D62A8(void *arg0, int arg1) {
    func_00444210(arg0, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
