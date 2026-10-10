extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mMBox__structor_0(void *obj);
extern "C" void func_002009F8(void *arg0, void *arg1);

extern "C" void func_002B83A0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xCC, 4, "RefCounter");
    mMBox__structor_0(s0);
    void *local = s0;
    func_002009F8(s1, &local);
}
