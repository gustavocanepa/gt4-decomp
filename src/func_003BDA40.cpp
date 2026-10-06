extern "C" void func_00572148(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_003BDA40(void *arg0, int arg1) {
    func_00572148(arg0, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
