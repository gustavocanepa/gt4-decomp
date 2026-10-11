#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
#include "gt4/mRotateActor.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 mActor__initialize();                            /* extern */

s32 mRotateActor__initialize(struct mRotateActor *arg0) {
    f32 temp_f0;

    if (arg0->unk14 != 0) {
        mActor__initialize();
        temp_f0 = arg0->unk18;
        arg0->unk20 = temp_f0;
        arg0->unk1C = temp_f0;
        mWidget__setRotate(arg0->unk14, temp_f0);
    }
}
