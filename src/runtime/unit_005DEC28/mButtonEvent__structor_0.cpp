#include "gt4/mButtonEvent.h"
typedef int s32;

extern void *mButtonEvent__vtable;
extern "C" void *mWindowEvent__structor_0(void *);

extern "C" void *mButtonEvent__structor_0(struct mButtonEvent *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = mWindowEvent__structor_0(arg0);
    arg0->unk2C = farg1;
    arg0->unk20 = arg3;
    arg0->unk24 = (void *)(arg4);
    arg0->unk28 = farg0;
    arg0->unk4 = &mButtonEvent__vtable;
    return r0;
}
