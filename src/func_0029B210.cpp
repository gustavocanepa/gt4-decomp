extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0029AF58(void *obj);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_0029B210(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x34, 4, "RefCounter");
    func_0029AF58(s0);
    void *local = s0;
    func_00309348(s1, &local);
}
