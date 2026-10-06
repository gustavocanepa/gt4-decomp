extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00272760(void *obj);
extern "C" void func_00291018(void *arg0, void *arg1);

extern "C" void func_00272828(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x20, 4, "RefCounter");
    func_00272760(s0);
    void *local = s0;
    func_00291018(s1, &local);
}
