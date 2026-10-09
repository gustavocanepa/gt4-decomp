extern "C" void func_002D4498(void *arg0, void *arg1);
extern "C" void func_002D8B50(void *arg0, void *arg1);

extern "C" void func_002D8B08(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002D4498(s0, &local);
    func_002D8B50(s0, s1);
}
