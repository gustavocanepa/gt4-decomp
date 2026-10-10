#include "gt4/mJump.h"
typedef int s32;

extern void *mJump__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mJump__structor_0(struct mJump *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mJump__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
