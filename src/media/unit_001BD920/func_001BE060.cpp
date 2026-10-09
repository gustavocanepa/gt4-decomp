extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mEyetoyFacePS2__structor_0(void *obj);
extern "C" void func_00255088(void *arg0, void *arg1);

extern "C" void func_001BE060(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xAC, 4, "RefCounter");
    mEyetoyFacePS2__structor_0(s0);
    void *local = s0;
    func_00255088(s1, &local);
}
