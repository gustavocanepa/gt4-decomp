extern "C" void func_00309348(void *arg0, void *arg1);
extern "C" void func_002F5548(void *arg0, void *arg1);

extern "C" void func_002F5500(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00309348(s0, &local);
    func_002F5548(s0, s1);
}
