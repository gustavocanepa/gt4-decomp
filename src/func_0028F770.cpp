extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0028F6C8(void *obj);
extern "C" void func_002009F8(void *arg0, void *arg1);

extern "C" void func_0028F770(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xC0, 4, "RefCounter");
    func_0028F6C8(s0);
    void *local = s0;
    func_002009F8(s1, &local);
}
