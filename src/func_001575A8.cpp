extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00154CF8(void *obj);
extern "C" void func_00151800(void *arg0, void *arg1);

extern "C" void func_001575A8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xA60, 4, "RefCounter");
    func_00154CF8(s0);
    void *local = s0;
    func_00151800(s1, &local);
}
