extern "C" void func_002A9610(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_002AB508(void *arg0, int arg1) {
    func_002A9610(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
