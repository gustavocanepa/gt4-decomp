extern "C" void func_0033BA98(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067D298;

extern "C" void func_0038A708(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_0067D298;
    func_0033BA98(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
