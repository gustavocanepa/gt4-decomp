typedef int s32;

extern "C" void func_0030A908(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0066E6A8;

extern "C" void func_002B6688(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0066E6A8;
    func_0030A908(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
