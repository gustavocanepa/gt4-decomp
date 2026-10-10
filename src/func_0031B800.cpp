extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0031B748(void *obj, float arg1);
extern "C" void func_002FB190(void *arg0, void *arg1);

extern "C" void func_0031B800(void *arg0, float fparg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xC, 4, "RefCounter");
    func_0031B748(s0, fparg0);
    void *local = s0;
    func_002FB190(s1, &local);
}
