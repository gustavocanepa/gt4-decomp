extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mGame__structor_1(void *obj, void *arg1, void *arg2);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_0015F718(void *arg0, void *arg1, void *arg2) {
    void *s3 = arg0;
    void *s2 = arg1;
    void *s1 = arg2;
    void *s0 = func_00326750(0x18, 4, "RefCounter");
    mGame__structor_1(s0, s2, s1);
    void *local = s0;
    func_00309348(s3, &local);
}
