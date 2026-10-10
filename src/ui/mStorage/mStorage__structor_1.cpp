#include "gt4/mStorage.h"
typedef int s32;

extern void *mStorage__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *mStorage__structor_1(struct mStorage *arg0, s32 arg1) {
    void *r0 = hObject__structor_0(arg0);
    arg0->unk4 = &mStorage__vtable;
    arg0->unk10_pvoid = (void *)(arg1);
    return r0;
}
