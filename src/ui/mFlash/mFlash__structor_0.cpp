#include "gt4/mFlash.h"
extern "C" void *mData__structor_0(void *arg0);
extern "C" char mFlash__vtable[];

extern "C" void mFlash__structor_0(struct mFlash *arg0)
{
    mData__structor_0(arg0);
    arg0->unk8 = 0;
    arg0->unk4 = mFlash__vtable;
}
