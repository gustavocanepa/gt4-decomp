#include "gt4/mTransition.h"
typedef int s32;

extern void *mTransition__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *mTransition__structor_0(struct mTransition *arg0) {
    void *r0 = hObject__structor_0(arg0);
    arg0->unk4 = &mTransition__vtable;
    arg0->unk1C = 0x0;
    arg0->unk10 = 0x0;
    arg0->unk14 = (void *)(0x3);
    arg0->unk18_pvoid = (void *)(0x3);
    return r0;
}
