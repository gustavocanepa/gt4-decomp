#include "gt4/mAnchorActor.h"
typedef int s32;

extern void *mAnchorActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mAnchorActor__structor_0(struct mAnchorActor *arg0) {
    void *r0 = mActor__structor_0(arg0);
    arg0->unk4 = &mAnchorActor__vtable;
    arg0->unk14_pvoid = 0x0;
    arg0->unk18_pvoid = 0x0;
    arg0->unk1C_pvoid = 0x0;
    arg0->unk20_pvoid = (void *)(0x1);
    arg0->unk24_pvoid = (void *)(0x1);
    return r0;
}
