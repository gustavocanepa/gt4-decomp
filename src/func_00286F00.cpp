extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00286EA0(void *obj);
extern "C" void func_0024C7D8(void *arg0, void *arg1);

extern "C" void func_00286F00(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x38, 4, "RefCounter");
    func_00286EA0(s0);
    void *local = s0;
    func_0024C7D8(s1, &local);
}
