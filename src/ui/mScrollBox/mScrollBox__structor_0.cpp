#include "gt4/mScrollBox.h"
typedef int s32;

extern void *mScrollBox__vtable;
extern "C" void *mComposite__structor_0(void *);

extern "C" void *mScrollBox__structor_0(struct mScrollBox *arg0) {
    void *r0 = mComposite__structor_0(arg0);
    arg0->unkB0 = 0x0;
    arg0->unk4 = &mScrollBox__vtable;
    arg0->unkB4_pvoid = 0x0;
    arg0->unkB8_pvoid = 0x0;
    arg0->unkBC_pvoid = 0x0;
    return r0;
}
