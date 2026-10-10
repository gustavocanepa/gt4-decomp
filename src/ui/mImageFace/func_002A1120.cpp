extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mImageFace__structor_0(void *obj);
extern "C" void func_00284AE8(void *arg0, void *arg1);

extern "C" void func_002A1120(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xF0, 4, "RefCounter");
    mImageFace__structor_0(s0);
    void *local = s0;
    func_00284AE8(s1, &local);
}
