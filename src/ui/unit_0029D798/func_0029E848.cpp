extern "C" void func_00284AE8(void *arg0, void *arg1);
extern "C" void func_0029E890(void *arg0, void *arg1);

extern "C" void func_0029E848(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00284AE8(s0, &local);
    func_0029E890(s0, s1);
}
