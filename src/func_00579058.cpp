struct S { char pad[0xC]; char lock[1]; };

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_0057CB00(S *arg0, void *arg1);

extern "C" void func_00579058(S *arg0, void *arg1) {
    void *lock = &arg0->lock;
    func_00576788(lock);
    func_0057CB00(arg0, arg1);
    func_005767C0(lock);
}
