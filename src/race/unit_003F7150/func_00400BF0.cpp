extern "C" void func_00378C50(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00686148;

extern "C" void func_00400BF0(void *arg0, int arg1) {
    *(void **)arg0 = &D_00686148;
    func_00378C50(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
