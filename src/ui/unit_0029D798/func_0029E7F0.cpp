extern "C" void func_00284B18(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_0029E7F0(void *arg0, int arg1) {
    func_00284B18(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
