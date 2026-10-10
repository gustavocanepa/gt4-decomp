extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mHBox__structor_0(void *obj);
extern "C" void func_002E90E8(void *arg0, void *arg1);

extern "C" void func_002A03D0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xD0, 4, "RefCounter");
    mHBox__structor_0(s0);
    void *local = s0;
    func_002E90E8(s1, &local);
}
