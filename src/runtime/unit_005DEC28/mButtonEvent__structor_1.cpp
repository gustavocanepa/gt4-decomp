#include "gt4/mButtonEvent.h"
typedef int s32;

extern "C" void mWindowEvent__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mButtonEvent__vtable;

extern "C" void mButtonEvent__structor_1(struct mButtonEvent *arg0, s32 arg1) {
    arg0->unk4 = &mButtonEvent__vtable;
    mWindowEvent__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x30, 4, "RefCounter");
    }
}
