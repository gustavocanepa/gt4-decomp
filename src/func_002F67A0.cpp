extern "C" void func_002FEA80(void *arg0, void *arg1);
extern "C" void func_002F67E8(void *arg0, void *arg1);

extern "C" void func_002F67A0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002FEA80(s0, &local);
    func_002F67E8(s0, s1);
}
