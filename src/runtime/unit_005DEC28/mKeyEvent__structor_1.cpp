#include "gt4/mKeyEvent.h"
typedef int s32;

extern "C" void mWindowEvent__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mKeyEvent__vtable;

extern "C" void mKeyEvent__structor_1(struct mKeyEvent *arg0, s32 arg1) {
    arg0->unk4 = &mKeyEvent__vtable;
    mWindowEvent__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x30, 4, "RefCounter");
    }
}
