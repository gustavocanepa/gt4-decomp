#include "gt4/mWindowEvent.h"
typedef int s32;

extern "C" void mEvent__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mWindowEvent__vtable;

extern "C" void mWindowEvent__structor_1(struct mWindowEvent *arg0, s32 arg1) {
    arg0->unk4 = &mWindowEvent__vtable;
    mEvent__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x20, 4, "RefCounter");
    }
}
