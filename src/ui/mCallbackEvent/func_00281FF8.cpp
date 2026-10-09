extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mCallbackEvent__structor_0(void *obj, void *arg1, void *arg2, void *arg3);
extern "C" void func_0028E348(void *arg0, void *arg1);

extern "C" void func_00281FF8(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *s4 = arg0;
    void *s3 = arg1;
    void *s2 = arg2;
    void *s1 = arg3;
    void *s0 = func_00326750(0x24, 4, "RefCounter");
    mCallbackEvent__structor_0(s0, s3, s2, s1);
    void *local = s0;
    func_0028E348(s4, &local);
}
