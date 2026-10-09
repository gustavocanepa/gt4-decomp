extern "C" void func_00407470();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_004072F0(void *arg0, int arg1) {
    func_00407470();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
