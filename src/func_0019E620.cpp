typedef int s32;

extern "C" void func_0030A908(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0065DC68;

extern "C" void func_0019E620(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0065DC68;
    func_0030A908(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
