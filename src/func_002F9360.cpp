extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002F91F8(void *obj, float arg1);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_002F9360(void *arg0, float fparg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x14, 4, "RefCounter");
    func_002F91F8(s0, fparg0);
    void *local = s0;
    func_00309348(s1, &local);
}
