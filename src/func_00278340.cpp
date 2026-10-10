extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002782F8(void *obj);
extern "C" void func_001FEF20(void *arg0, void *arg1);

extern "C" void func_00278340(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x28, 4, "RefCounter");
    func_002782F8(s0);
    void *local = s0;
    func_001FEF20(s1, &local);
}
