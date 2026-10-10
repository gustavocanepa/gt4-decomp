extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void mScriptWatcher__structor_0(void *obj);
extern "C" void func_00254088(void *arg0, void *arg1);

extern "C" void func_002CEAC8(void *arg0) {
    void *s1 = arg0;
    void *s0 = func_00326750(0x28, 4, "RefCounter");
    mScriptWatcher__structor_0(s0);
    void *local = s0;
    func_00254088(s1, &local);
}
