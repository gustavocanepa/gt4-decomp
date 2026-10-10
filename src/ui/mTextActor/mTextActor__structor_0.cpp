#include "gt4/mTextActor.h"
typedef int s32;

extern void *mTextActor__vtable;
extern "C" void *mActor__structor_0(void *);

extern "C" void *mTextActor__structor_0(struct mTextActor *arg0) {
    void *r0 = mActor__structor_0(arg0);
    arg0->unk14 = 0x0;
    arg0->unk4 = &mTextActor__vtable;
    arg0->unk18 = 0x0;
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    return r0;
}
