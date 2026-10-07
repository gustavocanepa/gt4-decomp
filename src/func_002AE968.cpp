extern "C" void func_002D44C8(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_002AE968(void *arg0, int arg1) {
    func_002D44C8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
