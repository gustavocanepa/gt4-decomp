typedef int s32;

extern "C" void mEvent__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mCrossingEvent__vtable;

extern "C" void mCrossingEvent__structor_3(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mCrossingEvent__vtable;
    mEvent__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x20, 4, "RefCounter");
    }
}
