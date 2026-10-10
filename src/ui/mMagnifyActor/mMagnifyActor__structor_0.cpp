#include "gt4/mMagnifyActor.h"
typedef int s32;

extern void *mMagnifyActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mMagnifyActor__structor_0(struct mMagnifyActor *arg0) {
    void *r0 = mActor__structor_0(arg0);
    arg0->unk4 = &mMagnifyActor__vtable;
    arg0->unk18 = 1.0000000298f;
    arg0->unk14 = 0x0;
    arg0->unk2C = 0x0;
    arg0->unk30 = 0x0;
    arg0->unk34 = 0.0166666661389f;
    return r0;
}
