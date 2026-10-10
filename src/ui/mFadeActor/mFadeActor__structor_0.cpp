#include "gt4/mFadeActor.h"
typedef int s32;

extern void *mFadeActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mFadeActor__structor_0(struct mFadeActor *arg0) {
    void *r0 = mActor__structor_0(arg0);
    arg0->unk4 = &mFadeActor__vtable;
    arg0->unk24 = 0.0333333322778f;
    arg0->unk14 = 0x0;
    arg0->unk18 = 0x0;
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk28 = 0x0;
    arg0->unk2C = 0x0;
    arg0->unk30 = 0x0;
    arg0->unk34 = 0x0;
    arg0->unk38 = 0x0;
    arg0->unk3C = 0x0;
    return r0;
}
