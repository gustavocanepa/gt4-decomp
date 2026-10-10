#include "types.h"
#include "gt4/mAnchorActor.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0025B2B0(s32);                             /* extern */
s32 func_0025B2E0(s32, f32);                    /* extern */
f32 func_0025B310(s32);                             /* extern */
s32 func_0025B340(s32, f32);                    /* extern */

s32 mAnchorActor__virtual_52(struct mAnchorActor *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    if (arg2 != 0) {
        temp_a0 = arg0->unk14;
        if (temp_a0 != 0) {
            if (arg0->unk20 != 0) {
                func_0025B2E0(arg2, func_0025B2B0(temp_a0) + arg0->unk18);
            }
            if (arg0->unk24 != 0) {
                func_0025B340(arg2, func_0025B310(arg0->unk14) + arg0->unk1C);
            }
        }
    }
}
