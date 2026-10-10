#include "gt4/mScaleBar.h"
typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mFBox__structor_1(void *, s32);

extern void *mScaleBar__vtable;

extern "C" void mScaleBar__structor_1(void *arg0, s32 arg1) {
    ((struct mScaleBar *)arg0)->unk4 = &mScaleBar__vtable;
    func_002F9B38((char *)arg0 + 0xFC, 2);
    func_002F9B38((char *)arg0 + 0xF8, 2);
    mFBox__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x108, 4, "RefCounter");
    }
}
