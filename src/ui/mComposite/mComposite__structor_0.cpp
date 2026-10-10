#include "gt4/mComposite.h"
typedef int s32;

extern void *mComposite__vtable;
extern "C" void *mWidget__structor_0(void *);

extern "C" void *mComposite__structor_0(struct mComposite *arg0) {
    void *r0 = mWidget__structor_0(arg0);
    arg0->unkA0 = 0x0;
    arg0->unk4 = &mComposite__vtable;
    arg0->unkA4 = 0x0;
    arg0->unkA8 = 0x0;
    arg0->unkAC = 0x0;
    return r0;
}
