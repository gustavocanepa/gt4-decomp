#include "types.h"
#include "gt4/mScrollPinch.h"
void *memcpy(void *, const void *, unsigned int);

s32 mWidget__onMotion();                            /* extern */
s32 mScrollWindow__onHPinchMotion(s32, s32, s32);                   /* extern */
s32 mScrollWindow__onVPinchMotion(s32, s32, s32);                   /* extern */

s32 mScrollPinch__onMotion(struct mScrollPinch *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    mWidget__onMotion();
    temp_a0 = arg0->unkB0;
    if (temp_a0 != 0) {
        if (arg0->unkB4 != 0) {
            return mScrollWindow__onHPinchMotion(temp_a0, arg1, arg2);
        }
        return mScrollWindow__onVPinchMotion(temp_a0, arg1, arg2);
    }
    return 0;
}
