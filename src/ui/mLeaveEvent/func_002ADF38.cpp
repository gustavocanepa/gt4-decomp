extern "C" void func_0028B180(void *arg0, void *arg1);
extern "C" void func_002ADF80(void *arg0, void *arg1);

extern "C" void func_002ADF38(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_0028B180(s0, &local);
    func_002ADF80(s0, s1);
}
