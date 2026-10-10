#include "gt4/mScrollPinch.h"
extern "C" void *mComposite__structor_0(void *arg0);
extern "C" char mScrollPinch__vtable[];

extern "C" void mScrollPinch__structor_0(struct mScrollPinch *arg0)
{
    mComposite__structor_0(arg0);
    arg0->unkB0 = 0;
    arg0->unk4 = mScrollPinch__vtable;
}
