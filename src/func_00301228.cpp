extern "C" void func_00324470(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_00301228(void *arg0, int arg1) {
    func_00324470(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
