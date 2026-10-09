extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mJumpZero__structor_0(void *obj, void *arg1);
extern "C" void *func_002FB190(void *arg0, void *arg1);

extern "C" void *func_0031C7F0(void *arg0, void *arg1) {
    void *s2 = arg0;
    void *s1 = arg1;
    void *s0 = func_00326750(0xC, 4, "RefCounter");
    mJumpZero__structor_0(s0, s1);
    void *local = s0;
    return func_002FB190(s2, &local);
}
