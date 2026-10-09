extern "C" void func_002D4498(void *arg0, void *arg1);
extern "C" void func_002E4C20(void *arg0, void *arg1);

extern "C" void func_002E4BD8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002D4498(s0, &local);
    func_002E4C20(s0, s1);
}
