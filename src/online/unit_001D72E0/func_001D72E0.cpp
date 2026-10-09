extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mHttp__structor_0(void *obj);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_001D72E0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x110, 4, "RefCounter");
    mHttp__structor_0(s0);
    void *local = s0;
    func_00309348(s1, &local);
}
