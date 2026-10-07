extern "C" void func_00578090(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689870;

extern "C" void func_005511B0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x38) = &D_00689870;
    func_00578090(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
