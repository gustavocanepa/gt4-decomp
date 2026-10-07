extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0031DB28(void *obj, void *arg1, void *arg2);
extern "C" void func_003192D8(void *arg0, void *arg1);

extern "C" void func_0031DBF8(void *arg0, void *arg1, void *arg2) {
    void *s3 = arg0;
    void *s2 = arg1;
    void *s1 = arg2;
    void *s0 = func_00326750(0x10, 4, "RefCounter");
    func_0031DB28(s0, s2, s1);
    void *local = s0;
    func_003192D8(s3, &local);
}
