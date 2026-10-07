extern "C" void func_0028B1B0(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_0028D8F0(void *arg0, int arg1) {
    func_0028B1B0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
