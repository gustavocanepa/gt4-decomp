extern "C" void func_00611108();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_006110B0(void *arg0, int arg1) {
    func_00611108();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
