#include "types.h"
#include "gt4/mScrollPinch.h"
void *memcpy(void *, const void *, unsigned int);

s32 mSceneViewFace__virtual_77();                            /* extern */
s32 func_002D2DE0(s32, s32, s32);                   /* extern */
s32 func_002D2F28(s32, s32, s32);                   /* extern */

s32 mScrollPinch__virtual_77(struct mScrollPinch *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    mSceneViewFace__virtual_77();
    temp_a0 = arg0->unkB0;
    if (temp_a0 != 0) {
        if (arg0->unkB4 != 0) {
            return func_002D2DE0(temp_a0, arg1, arg2);
        }
        return func_002D2F28(temp_a0, arg1, arg2);
    }
    return 0;
}
