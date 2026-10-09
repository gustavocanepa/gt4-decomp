extern "C" void func_002009F8(void *arg0, void *arg1);
extern "C" void func_00192AA0(void *arg0, void *arg1);

extern "C" void func_00192A58(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_002009F8(s0, &local);
    func_00192AA0(s0, s1);
}
