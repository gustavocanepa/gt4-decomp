extern "C" void func_001B9BB8(void *arg0, void *arg1);
extern "C" void func_001BB2E8(void *arg0, void *arg1);

extern "C" void func_001BB2A0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001B9BB8(s0, &local);
    func_001BB2E8(s0, s1);
}
