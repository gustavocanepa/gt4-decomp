extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void hException__structor_0(void *obj, void *arg1);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_002F5EC0(void *arg0, void *arg1) {
    void *s2 = arg0;
    void *s1 = arg1;
    void *s0 = func_00326750(0x14, 4, "RefCounter");
    hException__structor_0(s0, s1);
    void *local = s0;
    func_00309348(s2, &local);
}
