extern "C" void func_003DE798(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00683128;

extern "C" void func_003DEBD0(void *arg0, int arg1) {
    *(void **)arg0 = &D_00683128;
    func_003DE798(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
