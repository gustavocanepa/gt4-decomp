#include "gt4/mSelectBar.h"
typedef int s32;

extern "C" void func_00575DA0(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void mScrollable__structor_1(void *, s32);

extern void *mSelectBar__vtable;

extern "C" void mSelectBar__structor_1(struct mSelectBar *arg0, s32 arg1) {
    arg0->unk4 = &mSelectBar__vtable;
    void *p = arg0->unkF0;
    if (p != 0) {
        arg0->unkF0 = 0;
        func_00575DA0(p);
    }
    mScrollable__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xF8, 4, "RefCounter");
    }
}
