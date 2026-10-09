extern "C" void func_00204D00(void *arg0, void *arg1);
extern "C" void func_002AC068(void *arg0, void *arg1);

extern "C" void func_002AC020(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00204D00(s0, &local);
    func_002AC068(s0, s1);
}
