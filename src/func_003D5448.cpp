extern "C" void func_003D54A0();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_003D5448(void *arg0, int arg1) {
    func_003D54A0();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
