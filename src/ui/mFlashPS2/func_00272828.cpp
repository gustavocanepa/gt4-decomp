extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mFlashPS2__structor_0(void *obj);
extern "C" void func_00291018(void *arg0, void *arg1);

extern "C" void func_00272828(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x20, 4, "RefCounter");
    mFlashPS2__structor_0(s0);
    void *local = s0;
    func_00291018(s1, &local);
}
