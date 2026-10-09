extern "C" void func_00255088(void *arg0, void *arg1);
extern "C" void func_0012B538(void *arg0, void *arg1);

extern "C" void func_0012B4F0(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00255088(s0, &local);
    func_0012B538(s0, s1);
}
