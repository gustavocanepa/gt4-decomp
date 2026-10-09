extern "C" void func_001FEF20(void *arg0, void *arg1);
extern "C" void func_002B9878(void *arg0, void *arg1);

extern "C" void func_002B9830(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FEF20(s0, &local);
    func_002B9878(s0, s1);
}
