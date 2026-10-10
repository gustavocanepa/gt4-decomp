#include "gt4/mGpb.h"
extern "C" void *hObject__structor_0(void);
extern "C" void *func_0048F270(void *arg0);
extern "C" char mGpb__vtable[];

extern "C" void *mGpb__structor_0(void *arg0)
{
    hObject__structor_0();
    ((struct mGpb *)arg0)->unk4 = mGpb__vtable;
    return func_0048F270((char *)arg0 + 0x10);
}
