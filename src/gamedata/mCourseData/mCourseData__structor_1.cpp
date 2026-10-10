#include "gt4/mCourseData.h"
typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mCourseData__vtable;

extern "C" void mCourseData__structor_1(struct mCourseData *arg0, s32 arg1) {
    arg0->unk4 = &mCourseData__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
