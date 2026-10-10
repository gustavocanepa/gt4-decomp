#include "gt4/mHBox.h"
typedef int s32;

extern void *mHBox__vtable;
extern "C" void *mDBox__structor_0(void *, s32);

extern "C" void *mHBox__structor_0(struct mHBox *arg0) {
    void *r0 = mDBox__structor_0(arg0, 0x1);
    arg0->unk4 = &mHBox__vtable;
    return r0;
}
