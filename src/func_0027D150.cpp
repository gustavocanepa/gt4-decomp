typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void func_00204F50(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_00668F18;

extern "C" void func_0027D150(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_00668F18;
    func_002F9B38((char *)arg0 + 0xB0, 2);
    func_00204F50(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xB4, 4, "RefCounter");
    }
}
