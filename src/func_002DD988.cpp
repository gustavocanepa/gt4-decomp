extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002DD820(void *obj);
extern "C" void func_0028F4B8(void *arg0, void *arg1);

extern "C" void func_002DD988(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x110, 4, "RefCounter");
    func_002DD820(s0);
    void *local = s0;
    func_0028F4B8(s1, &local);
}
