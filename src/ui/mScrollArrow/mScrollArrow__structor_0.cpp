#include "gt4/mScrollArrow.h"
extern "C" void *mComposite__structor_0(void *arg0);
extern "C" char mScrollArrow__vtable[];

extern "C" void mScrollArrow__structor_0(struct mScrollArrow *arg0)
{
    mComposite__structor_0(arg0);
    arg0->unkB0 = 0;
    arg0->unk4 = mScrollArrow__vtable;
}
