extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00132E90(void *obj, void *arg1);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_00132F48(void *arg0, void *arg1) {
    void *s2 = arg0;
    void *s1 = arg1;
    void *s0 = func_00326750(0x14, 4, "RefCounter");
    func_00132E90(s0, s1);
    void *local = s0;
    func_00309348(s2, &local);
}
