extern "C" void func_002009F8(void *arg0, void *arg1);
extern "C" void func_002B81A8(void *arg0, void *arg1);

extern "C" void func_002B8160(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002009F8(s0, &local);
    func_002B81A8(s0, s1);
}
