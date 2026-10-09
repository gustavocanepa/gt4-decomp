extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mPlayerStats__structor_1(void *obj);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_0019C4D0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x110, 4, "RefCounter");
    mPlayerStats__structor_1(s0);
    void *local = s0;
    func_00309348(s1, &local);
}
