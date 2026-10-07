typedef int s32;

extern "C" void func_0034C020(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00679CE8;

extern "C" void func_005F4D68(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x10140) = &D_00679CE8;
    func_0034C020(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
