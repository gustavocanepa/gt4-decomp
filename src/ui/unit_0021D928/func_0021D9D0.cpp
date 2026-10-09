extern "C" void func_002A0CF0(void *arg0, void *arg1);
extern "C" void func_0021DA18(void *arg0, void *arg1);

extern "C" void func_0021D9D0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A0CF0(s0, &local);
    func_0021DA18(s0, s1);
}
