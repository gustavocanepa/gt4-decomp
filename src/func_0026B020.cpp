extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0026AF78(void *obj, void *arg1, void *arg2);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_0026B020(void *arg0, void *arg1, void *arg2) {
    void *s3 = arg0;
    void *s2 = arg1;
    void *s1 = arg2;
    void *s0 = func_00326750(0x34, 4, "RefCounter");
    func_0026AF78(s0, s2, s1);
    void *local = s0;
    func_00309348(s3, &local);
}
