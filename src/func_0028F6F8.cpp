typedef int s32;

extern "C" void func_00200C50(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0066AF28;

extern "C" void func_0028F6F8(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0066AF28;
    func_00200C50(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC0, 4, "RefCounter");
    }
}
