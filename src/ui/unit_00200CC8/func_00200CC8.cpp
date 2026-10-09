extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mBox__structor_0(void *obj);
extern "C" void func_00204D00(void *arg0, void *arg1);

extern "C" void func_00200CC8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xC0, 4, "RefCounter");
    mBox__structor_0(s0);
    void *local = s0;
    func_00204D00(s1, &local);
}
