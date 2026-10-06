extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0031F0B8(void *obj);
extern "C" void *func_002FB1A8(void *arg0, void *arg1);

extern "C" void *func_0031F160(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x8, 4, "RefCounter");
    func_0031F0B8(s0);
    void *local = s0;
    return func_002FB1A8(s1, &local);
}
