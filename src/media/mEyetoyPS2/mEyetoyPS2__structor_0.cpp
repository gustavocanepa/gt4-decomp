#include "gt4/mEyetoyPS2.h"
typedef int s32;

extern void *mEyetoyPS2__vtable;
extern "C" void *mEyetoy__structor_0(void *);

extern "C" void *mEyetoyPS2__structor_0(struct mEyetoyPS2 *arg0) {
    void *r0 = mEyetoy__structor_0(arg0);
    arg0->unk10_pvoid = 0x0;
    arg0->unk4 = &mEyetoyPS2__vtable;
    arg0->unk14_pvoid = 0x0;
    arg0->unk18_pvoid = 0x0;
    arg0->unk1C_pvoid = 0x0;
    return r0;
}
