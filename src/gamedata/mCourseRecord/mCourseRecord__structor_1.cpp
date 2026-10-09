typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mCourseRecord__vtable;

extern "C" void mCourseRecord__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mCourseRecord__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
