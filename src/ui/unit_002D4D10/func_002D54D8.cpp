extern "C" void func_002D4498(void *arg0, void *arg1);
extern "C" void func_002D5520(void *arg0, void *arg1);

extern "C" void func_002D54D8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002D4498(s0, &local);
    func_002D5520(s0, s1);
}
