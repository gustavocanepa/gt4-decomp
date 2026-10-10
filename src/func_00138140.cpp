extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00137F40(void *obj);
extern "C" void func_00255088(void *arg0, void *arg1);

extern "C" void func_00138140(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x2BC, 4, "RefCounter");
    func_00137F40(s0);
    void *local = s0;
    func_00255088(s1, &local);
}
