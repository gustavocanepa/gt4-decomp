extern "C" void func_00254088(void *arg0, void *arg1);
extern "C" void func_002CE588(void *arg0, void *arg1);

extern "C" void func_002CE540(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00254088(s0, &local);
    func_002CE588(s0, s1);
}
