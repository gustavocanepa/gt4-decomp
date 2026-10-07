extern "C" void func_003038E0(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_0032D9A0(void *arg0, int arg1) {
    func_003038E0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
