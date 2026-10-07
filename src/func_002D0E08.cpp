typedef int s32;

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002D0D58(void *obj);
extern "C" void func_00204D00(void *arg0, void *arg1);

extern "C" void func_002D0E08(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0xB8, 4, "RefCounter");
    func_002D0D58(s0);
    void *local = s0;
    func_00204D00(s1, &local);
}
