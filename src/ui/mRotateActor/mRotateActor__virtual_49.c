#include "types.h"
#include "gt4/mRotateActor.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 mActor__virtual_49();                            /* extern */
s32 func_00267D18(s32, f32);                    /* extern */

s32 mRotateActor__virtual_49(struct mRotateActor *arg0) {
    f32 temp_f0;

    if (arg0->unk14 != 0) {
        mActor__virtual_49();
        temp_f0 = arg0->unk18;
        arg0->unk20 = temp_f0;
        arg0->unk1C = temp_f0;
        func_00267D18(arg0->unk14, temp_f0);
    }
}
