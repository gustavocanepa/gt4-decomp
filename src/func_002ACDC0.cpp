extern "C" void func_00204D00(void *arg0, void *arg1);
extern "C" void func_002ACE08(void *arg0, void *arg1);

extern "C" void func_002ACDC0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00204D00(s0, &local);
    func_002ACE08(s0, s1);
}
