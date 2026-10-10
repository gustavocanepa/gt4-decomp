#include "gt4/mKeytopBox.h"
extern "C" void *mComposite__structor_0(void *arg0);
extern "C" char mKeytopBox__vtable[];

extern "C" void mKeytopBox__structor_0(struct mKeytopBox *arg0)
{
    mComposite__structor_0(arg0);
    arg0->unkB0 = 0;
    arg0->unk4 = mKeytopBox__vtable;
}
