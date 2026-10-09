extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00307CA0(void *obj, void *arg1, void *arg2, void *arg3);
extern "C" void func_00324440(void *arg0, void *arg1);

extern "C" void func_00307D90(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *s4 = arg0;
    void *s3 = arg1;
    void *s2 = arg2;
    void *s1 = arg3;
    void *s0 = func_00326750(0x1C, 4, "RefCounter");
    func_00307CA0(s0, s3, s2, s1);
    void *local = s0;
    func_00324440(s4, &local);
}
