extern "C" void func_001FEF20(void *arg0, void *arg1);
extern "C" void func_0020B3E0(void *arg0, void *arg1);

extern "C" void func_0020B398(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FEF20(s0, &local);
    func_0020B3E0(s0, s1);
}
