extern "C" void func_00485EE8();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_00485C50(void *arg0, int arg1) {
    func_00485EE8();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
