typedef int s32;

extern "C" void func_003E9A40(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00680640;

extern "C" void func_003B9928(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &D_00680640;
    func_003E9A40(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
