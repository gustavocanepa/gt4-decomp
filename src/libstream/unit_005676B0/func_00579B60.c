#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00579780();                                /* extern */
s32 func_00579A48(s32);                             /* extern */
s32 func_00579BA0(s32, s32);                    /* extern */

void func_00579B60(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_00579780();
    func_00579BA0(temp_s1, func_00579A48(arg0 + 4));
}
