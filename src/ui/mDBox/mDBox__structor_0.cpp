#include "gt4/mDBox.h"
typedef int s32;

extern void *mDBox__vtable;
extern "C" void *mBox__structor_0(void *);

extern "C" void *mDBox__structor_0(struct mDBox *arg0, s32 arg1) {
    void *r0 = mBox__structor_0(arg0);
    arg0->unk4 = &mDBox__vtable;
    arg0->unkCC = 0x0;
    arg0->unkC0 = 0x0;
    arg0->unkC8 = 0x0;
    arg0->unkC4 = (void *)(arg1);
    return r0;
}
