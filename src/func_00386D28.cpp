typedef int s32;

extern "C" void func_003D5AF8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067C478;

extern "C" void func_00386D28(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &D_0067C478;
    func_003D5AF8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
