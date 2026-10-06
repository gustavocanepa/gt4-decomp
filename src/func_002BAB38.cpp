extern "C" void func_00255088(void *arg0, void *arg1);
extern "C" void func_002BAB80(void *arg0, void *arg1);

extern "C" void func_002BAB38(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00255088(s0, &local);
    func_002BAB80(s0, s1);
}
