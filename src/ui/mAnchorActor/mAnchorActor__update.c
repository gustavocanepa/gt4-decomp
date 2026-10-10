#include "types.h"
#include "gt4/mAnchorActor.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 mWidget__getWindowX(s32);                             /* extern */
s32 mWidget__setWindowX(s32, f32);                    /* extern */
f32 mWidget__getWindowY(s32);                             /* extern */
s32 mWidget__setWindowY(s32, f32);                    /* extern */

s32 mAnchorActor__update(struct mAnchorActor *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    if (arg2 != 0) {
        temp_a0 = arg0->unk14;
        if (temp_a0 != 0) {
            if (arg0->unk20 != 0) {
                mWidget__setWindowX(arg2, mWidget__getWindowX(temp_a0) + arg0->unk18);
            }
            if (arg0->unk24 != 0) {
                mWidget__setWindowY(arg2, mWidget__getWindowY(arg0->unk14) + arg0->unk1C);
            }
        }
    }
}
