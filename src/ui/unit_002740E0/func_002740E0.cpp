extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mMoviePS2__structor_0(void *obj);
extern "C" void func_0021D7F8(void *arg0, void *arg1);

extern "C" void func_002740E0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x14, 4, "RefCounter");
    mMoviePS2__structor_0(s0);
    void *local = s0;
    func_0021D7F8(s1, &local);
}
