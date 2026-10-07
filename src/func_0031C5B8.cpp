typedef int s32;

extern "C" void func_00328450(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00674120;

extern "C" void func_0031C5B8(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00674120;
    func_00328450(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
