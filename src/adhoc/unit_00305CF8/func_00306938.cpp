extern "C" int func_003166B8(int arg1);
extern "C" void func_00306800(void *arg0, int *arg1, void *arg2);

extern "C" void func_00306938(void *arg0, int arg1, void *arg2) {
    void *s1 = arg0;
    void *s0 = arg2;
    int local = func_003166B8(arg1);
    func_00306800(s1, &local, s0);
}
