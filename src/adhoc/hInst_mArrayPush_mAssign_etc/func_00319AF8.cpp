extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mAssign__structor_0(void *obj);
extern "C" void *func_002FB190(void *arg0, void *arg1);

extern "C" void *func_00319AF8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x8, 4, "RefCounter");
    mAssign__structor_0(s0);
    void *local = s0;
    return func_002FB190(s1, &local);
}
