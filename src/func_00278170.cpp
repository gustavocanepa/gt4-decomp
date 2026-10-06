extern "C" void func_001FEF20(void *arg0, void *arg1);
extern "C" void func_002781B8(void *arg0, void *arg1);

extern "C" void func_00278170(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FEF20(s0, &local);
    func_002781B8(s0, s1);
}
