#include "gt4/mModelStream.h"
extern "C" void *mStream__structor_0(void *arg0);
extern "C" char mModelStream__vtable[];

extern "C" void mModelStream__structor_0(struct mModelStream *arg0)
{
    mStream__structor_0(arg0);
    arg0->unk28 = 0;
    arg0->unk4 = mModelStream__vtable;
}
