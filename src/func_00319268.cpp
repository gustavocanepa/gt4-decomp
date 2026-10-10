extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00318ED8(void *obj);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_00319268(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x4C, 4, "RefCounter");
    func_00318ED8(s0);
    void *local = s0;
    func_00309348(s1, &local);
}
