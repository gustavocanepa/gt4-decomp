#include "gt4/mVBox.h"
typedef int s32;

extern void *mVBox__vtable;
extern "C" void mDBox__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mVBox__structor_1(struct mVBox *arg0, s32 arg1) {
    arg0->unk4 = &mVBox__vtable;
    mDBox__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xd0, 0x4, "RefCounter");
    }
}
