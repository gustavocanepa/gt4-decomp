#include "gt4/mJumpNotZero.h"
typedef int s32;

extern void *mJumpNotZero__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mJumpNotZero__structor_0(struct mJumpNotZero *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mJumpNotZero__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
