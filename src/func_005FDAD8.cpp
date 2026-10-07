extern "C" void func_004574A0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006829D0;

extern "C" void func_005FDAD8(void *arg0, int arg1) {
    *(void **)arg0 = &D_006829D0;
    func_004574A0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
