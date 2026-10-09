typedef int s32;

extern "C" void mData__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mFlash__vtable;

extern "C" void mFlash__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mFlash__vtable;
    mData__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
