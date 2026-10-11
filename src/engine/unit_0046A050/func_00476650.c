#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00476630(s32);                             /* extern */
s32 func_0057F260();                                /* extern */
s32 func_005A609C(s32, s32);                    /* extern */

s32 func_00476650(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_00476630(func_0057F260());
    func_005A609C(temp_v0 + 2, arg0);
    return temp_v0;
}
