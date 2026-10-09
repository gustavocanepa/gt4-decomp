extern "C" void func_00204D00(void *arg0, void *arg1);
extern "C" void func_002D4568(void *arg0, void *arg1);

extern "C" void func_002D4520(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00204D00(s0, &local);
    func_002D4568(s0, s1);
}
