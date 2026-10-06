extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_0021B398(void *obj);
extern "C" void func_0028BBD8(void *arg0, void *arg1);

extern "C" void func_0021B480(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x24, 4, "RefCounter");
    func_0021B398(s0);
    void *local = s0;
    func_0028BBD8(s1, &local);
}
