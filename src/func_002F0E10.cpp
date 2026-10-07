extern "C" void func_00309348(void *arg0, void *arg1);
extern "C" void func_002F0E58(void *arg0, void *arg1);

extern "C" void func_002F0E10(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00309348(s0, &local);
    func_002F0E58(s0, s1);
}
