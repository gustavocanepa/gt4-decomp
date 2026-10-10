#include "types.h"
#include "gt4/mBlurFace.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mWidget__structor_0();                            /* extern */

extern char mBlurFace__vtable[];
void mBlurFace__structor_0(struct mBlurFace *arg0) {
    mWidget__structor_0();
    arg0->unkA4 = 0;
    arg0->unkA0 = 0;
    arg0->unk4 = (s32)mBlurFace__vtable;
}
