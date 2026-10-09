extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mChaseActor__structor_0(void *obj);
extern "C" void func_001FEF20(void *arg0, void *arg1);

extern "C" void func_00284158(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x34, 4, "RefCounter");
    mChaseActor__structor_0(s0);
    void *local = s0;
    func_001FEF20(s1, &local);
}
