extern "C" void func_001096D8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659AC0;

extern "C" void func_00101078(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_00659AC0;
    func_001096D8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
