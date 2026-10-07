extern "C" void func_005BFAC8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0068A370;

extern "C" void func_006169C0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_0068A370;
    func_005BFAC8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
