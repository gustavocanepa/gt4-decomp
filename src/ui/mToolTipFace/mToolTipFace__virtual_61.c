#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 MboolReader__structor_7(s32, s32);                        /* extern */
s32 mSlideShowFace__virtual_61();                                /* extern */

s32 mToolTipFace__virtual_61(s32 arg0, s32 arg1) {
    if (mSlideShowFace__virtual_61() != 0) {
        return 1;
    }
    return MboolReader__structor_7(arg0 + 0xA0, arg1) != 0;
}
