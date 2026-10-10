extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mToolTipFace__structor_0(void *obj);
extern "C" void func_00255088(void *arg0, void *arg1);

extern "C" void func_00248FF8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x154, 4, "RefCounter");
    mToolTipFace__structor_0(s0);
    void *local = s0;
    func_00255088(s1, &local);
}
