#include "gt4/mFlashPS2.h"
typedef int s32;

extern void *mFlashPS2__vtable;
extern "C" void *mFlash__structor_0(void *);

extern "C" void *mFlashPS2__structor_0(struct mFlashPS2 *arg0) {
    void *r0 = mFlash__structor_0(arg0);
    arg0->unkC_pvoid = 0x0;
    arg0->unk4 = &mFlashPS2__vtable;
    arg0->unk10_pvoid = 0x0;
    arg0->unk14_pvoid = 0x0;
    arg0->unk18 = 0x0;
    arg0->unk1C_pvoid = 0x0;
    return r0;
}
