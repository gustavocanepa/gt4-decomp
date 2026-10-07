typedef int s32;

extern "C" void func_003BB3D8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00683080;

extern "C" void func_003DD938(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x12C) = &D_00683080;
    func_003BB3D8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
