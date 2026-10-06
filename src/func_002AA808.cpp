extern "C" void func_002A95E0(void *arg0, void *arg1);
extern "C" void func_002AA850(void *arg0, void *arg1);

extern "C" void func_002AA808(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A95E0(s0, &local);
    func_002AA850(s0, s1);
}
