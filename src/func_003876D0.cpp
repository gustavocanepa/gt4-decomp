typedef int s32;

extern "C" void func_00386D28(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067C9F0;

extern "C" void func_003876D0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &D_0067C9F0;
    func_00386D28(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
