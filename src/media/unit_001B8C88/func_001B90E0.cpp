extern "C" void func_00255088(void *arg0, int *arg1);
extern "C" void func_001B9128(void *arg0, int arg1);

extern "C" void func_001B90E0(void *arg0, int arg1) {
    void *s0 = arg0;
    int s1 = arg1;
    int local = 0;
    func_00255088(s0, &local);
    func_001B9128(s0, s1);
}
