typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void func_0028F6F8(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00671D98;

extern "C" void func_002DD900(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00671D98;
    func_002F9B38((char *)arg0 + 0xC8, 2);
    func_0028F6F8(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x110, 4, "RefCounter");
    }
}
