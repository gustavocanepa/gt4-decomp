extern "C" void func_002E90E8(void *arg0, void *arg1);
extern "C" void func_002A01E0(void *arg0, void *arg1);

extern "C" void func_002A0198(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002E90E8(s0, &local);
    func_002A01E0(s0, s1);
}
