#include "gt4/mKeyReleaseEvent.h"
typedef int s32;

extern void *mKeyReleaseEvent__vtable;
extern "C" void *mWindowEvent__structor_0(void *);

extern "C" void *mKeyReleaseEvent__structor_4(struct mKeyReleaseEvent *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = mWindowEvent__structor_0(arg0);
    arg0->unk20 = (void *)(arg3);
    arg0->unk24 = (void *)(arg4);
    arg0->unk28 = farg0;
    arg0->unk2C = farg1;
    arg0->unk4 = &mKeyReleaseEvent__vtable;
    return r0;
}
