typedef int s32;

extern "C" void func_003C6538(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00681B60;

extern "C" void func_003C3A08(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x8) = &D_00681B60;
    func_003C6538(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
