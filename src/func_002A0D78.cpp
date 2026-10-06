extern "C" void func_00284AE8(void *arg0, void *arg1);
extern "C" void func_002A0DC0(void *arg0, void *arg1);

extern "C" void func_002A0D78(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00284AE8(s0, &local);
    func_002A0DC0(s0, s1);
}
