extern "C" void func_00309348(void *arg0, void *arg1);
extern "C" void func_001B1DD0(void *arg0, void *arg1);

extern "C" void func_001B1D88(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00309348(s0, &local);
    func_001B1DD0(s0, s1);
}
