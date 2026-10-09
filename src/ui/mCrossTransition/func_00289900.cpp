extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mCrossTransition__structor_0(void *obj);
extern "C" void func_0024C7D8(void *arg0, void *arg1);

extern "C" void func_00289900(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x40, 4, "RefCounter");
    mCrossTransition__structor_0(s0);
    void *local = s0;
    func_0024C7D8(s1, &local);
}
