#include "gt4/mPipe.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_005DA8A0(void *arg0);
extern "C" char mPipe__vtable[];

extern "C" void *mPipe__structor_0(void *arg0)
{
    hObject__structor_0();
    ((struct mPipe *)arg0)->unk4 = mPipe__vtable;
    return func_005DA8A0((char *)arg0 + 0x10);
}
