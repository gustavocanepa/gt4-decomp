typedef int s32;

extern "C" void mWindowContext__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mWindowContextPS2__vtable;

extern "C" void mWindowContextPS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mWindowContextPS2__vtable;
    mWindowContext__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x34, 4, "RefCounter");
    }
}
