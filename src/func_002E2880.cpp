extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002E1F38(void *obj);
extern "C" void func_001FEF20(void *arg0, void *arg1);

extern "C" void func_002E2880(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x44, 4, "RefCounter");
    func_002E1F38(s0);
    void *local = s0;
    func_001FEF20(s1, &local);
}
