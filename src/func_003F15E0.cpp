extern "C" void func_003D5DF8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00685168;

extern "C" void func_003F15E0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_00685168;
    func_003D5DF8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
