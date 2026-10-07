extern "C" void func_00255088(void *arg0, void *arg1);
extern "C" void func_001BCF90(void *arg0, void *arg1);

extern "C" void func_001BCF48(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00255088(s0, &local);
    func_001BCF90(s0, s1);
}
