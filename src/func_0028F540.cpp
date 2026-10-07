extern "C" void func_002009F8(void *arg0, void *arg1);
extern "C" void func_0028F588(void *arg0, void *arg1);

extern "C" void func_0028F540(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002009F8(s0, &local);
    func_0028F588(s0, s1);
}
