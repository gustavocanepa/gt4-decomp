extern "C" void func_00576060(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_005760A8(void *arg0, int arg1) {
    func_00576060(arg0, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
