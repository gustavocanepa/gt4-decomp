#include "gt4/mButtonReleaseEvent.h"
typedef int s32;

extern void *mButtonReleaseEvent__vtable;
extern "C" void *mWindowEvent__structor_0(void *);

extern "C" void *mButtonReleaseEvent__structor_2(struct mButtonReleaseEvent *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = mWindowEvent__structor_0(arg0);
    arg0->unk20 = arg3;
    arg0->unk24 = (void *)(arg4);
    arg0->unk28 = farg0;
    arg0->unk2C = farg1;
    arg0->unk4 = &mButtonReleaseEvent__vtable;
    return r0;
}
