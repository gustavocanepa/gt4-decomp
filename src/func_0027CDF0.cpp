extern "C" void func_00204D00(void *arg0, void *arg1);
extern "C" void func_0027CE38(void *arg0, void *arg1);

extern "C" void func_0027CDF0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00204D00(s0, &local);
    func_0027CE38(s0, s1);
}
