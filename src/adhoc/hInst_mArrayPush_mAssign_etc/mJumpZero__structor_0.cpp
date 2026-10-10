#include "gt4/mJumpZero.h"
typedef int s32;

extern void *mJumpZero__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mJumpZero__structor_0(struct mJumpZero *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mJumpZero__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
