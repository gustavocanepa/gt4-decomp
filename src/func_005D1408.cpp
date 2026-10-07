extern "C" void func_001CC060(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006615F8;

extern "C" void func_005D1408(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4C) = &D_006615F8;
    func_001CC060(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
