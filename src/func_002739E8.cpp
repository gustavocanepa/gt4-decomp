extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00273928(void *obj);
extern "C" void func_0021B5A0(void *arg0, void *arg1);

extern "C" void func_002739E8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x10, 4, "RefCounter");
    func_00273928(s0);
    void *local = s0;
    func_0021B5A0(s1, &local);
}
