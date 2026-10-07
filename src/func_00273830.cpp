extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002735C8(void *obj);
extern "C" void func_002106E0(void *arg0, void *arg1);

extern "C" void func_00273830(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x24, 4, "RefCounter");
    func_002735C8(s0);
    void *local = s0;
    func_002106E0(s1, &local);
}
