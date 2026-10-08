extern "C" void func_00231460(void *arg0, void *arg1);
extern "C" void func_00231A50(void *arg0, void *arg1);

extern "C" void func_00231C10(void *arg0) {
    void *s0 = arg0;
    int local;

    func_00231460(&local, s0);
    func_00231A50(s0, &local);
}
