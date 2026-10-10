#include "gt4/mKeyboardBox.h"
typedef int s32;

extern "C" void func_002A5DC0(void *arg0, s32 arg1);
extern "C" void mComposite__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mKeyboardBox__vtable;

extern "C" void mKeyboardBox__structor_1(void *arg0, s32 arg1) {
    ((struct mKeyboardBox *)arg0)->unk4_pvoid = &mKeyboardBox__vtable;
    func_002A5DC0((char *)arg0 + 0xB0, 2);
    mComposite__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xB4, 4, "RefCounter");
    }
}
