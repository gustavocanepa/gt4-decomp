extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mLocalizedText__structor_0(void *obj);
extern "C" void func_00328738(void *arg0, void *arg1);

extern "C" void func_002B70B8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x10, 4, "RefCounter");
    mLocalizedText__structor_0(s0);
    void *local = s0;
    func_00328738(s1, &local);
}
