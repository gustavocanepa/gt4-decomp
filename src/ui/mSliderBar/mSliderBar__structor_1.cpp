typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void mFBox__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mSliderBar__vtable;

extern "C" void mSliderBar__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mSliderBar__vtable;
    func_002F9B38((char *)arg0 + 0xC8, 2);
    mFBox__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x110, 4, "RefCounter");
    }
}
