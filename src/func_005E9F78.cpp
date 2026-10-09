typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void func_00254758(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0066FFC0;

extern "C" void func_005E9F78(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0066FFC0;
    func_002F9B38((char *)arg0 + 0x20, 2);
    func_00254758(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x28, 4, "RefCounter");
    }
}
