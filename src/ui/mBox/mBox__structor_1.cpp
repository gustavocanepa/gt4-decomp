#include "gt4/mBox.h"
typedef int s32;

extern "C" void mComposite__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mBox__vtable;

extern "C" void mBox__structor_1(struct mBox *arg0, s32 arg1) {
    arg0->unk4_pvoid = &mBox__vtable;
    mComposite__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC0, 4, "RefCounter");
    }
}
