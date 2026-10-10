#include "gt4/mVBox.h"
typedef int s32;

extern void *mVBox__vtable;
extern "C" void *mDBox__structor_0(void *, s32);

extern "C" void *mVBox__structor_0(struct mVBox *arg0) {
    void *r0 = mDBox__structor_0(arg0, 0x0);
    arg0->unk4 = &mVBox__vtable;
    return r0;
}
