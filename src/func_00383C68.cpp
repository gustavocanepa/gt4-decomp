extern "C" void *func_00378AE0(void *arg0);
extern "C" void func_00378C50(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067B1D8;

extern "C" void func_00383C68(void *arg0) {
    void *r = func_00378AE0(arg0);
    *(void **)arg0 = &D_0067B1D8;
    (void)r;
}

extern "C" void func_00380DD8(void *arg0, int arg1) {
    *(void **)arg0 = &D_0067B1D8;
    func_00378C50(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
