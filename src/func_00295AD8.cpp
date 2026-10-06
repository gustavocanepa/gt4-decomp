extern "C" void func_002A0CF0(void *arg0, void *arg1);
extern "C" void func_00295B20(void *arg0, void *arg1);

extern "C" void func_00295AD8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002A0CF0(s0, &local);
    func_00295B20(s0, s1);
}
