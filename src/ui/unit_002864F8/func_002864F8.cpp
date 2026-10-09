typedef int s32;

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mColorFace__structor_0(void *obj);
extern "C" void func_00255088(void *arg0, void *arg1);

extern "C" void func_002864F8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xB8, 4, "RefCounter");
    mColorFace__structor_0(s0);
    void *local = s0;
    func_00255088(s1, &local);
}
