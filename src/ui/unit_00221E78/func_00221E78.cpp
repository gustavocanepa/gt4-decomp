extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mNetConfPS2__structor_0(void *obj);
extern "C" void func_00309348(void *arg0, void *arg1);

extern "C" void func_00221E78(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x470, 4, "RefCounter");
    mNetConfPS2__structor_0(s0);
    void *local = s0;
    func_00309348(s1, &local);
}
