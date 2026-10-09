extern "C" void func_0055F4C0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689C38;

extern "C" void func_00564BA8(void *arg0, int arg1) {
    *(void **)arg0 = &D_00689C38;
    func_0055F4C0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
