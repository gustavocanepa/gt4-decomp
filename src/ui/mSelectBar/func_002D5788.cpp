extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mSelectBar__structor_0(void *obj);
extern "C" void func_002D4498(void *arg0, void *arg1);

extern "C" void func_002D5788(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xF8, 4, "RefCounter");
    mSelectBar__structor_0(s0);
    void *local = s0;
    func_002D4498(s1, &local);
}
