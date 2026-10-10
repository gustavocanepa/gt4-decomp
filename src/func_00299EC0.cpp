extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_002999C0(void *obj);
extern "C" void func_002A0CF0(void *arg0, void *arg1);

extern "C" void func_00299EC0(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x138, 4, "RefCounter");
    func_002999C0(s0);
    void *local = s0;
    func_002A0CF0(s1, &local);
}
