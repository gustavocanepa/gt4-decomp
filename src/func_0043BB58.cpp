extern "C" void func_004383F8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688210;

extern "C" void func_0043BB58(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &D_00688210;
    func_004383F8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
