#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00435E98(s32);                             /* extern */
s32 func_00438D70(s32);                             /* extern */
s32 func_00438FF8(s32);                             /* extern */
s32 func_004396E8(s32);                             /* extern */
s32 func_004398C8(s32);                             /* extern */
s32 func_0043A388(s32);                             /* extern */
s32 func_0043DAC8(s32);                             /* extern */

void func_00437428(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;

    temp_s0 = func_0043A388(0x11C0);
    temp_s0_2 = temp_s0 + func_00435E98(arg0 + 0x11C8);
    temp_s0_3 = temp_s0_2 + func_0043DAC8(arg0 + 0x11D0);
    temp_s0_4 = temp_s0_3 + func_00438D70(arg0 + 0x1344);
    temp_s0_5 = temp_s0_4 + func_004396E8(arg0 + 0x13F4);
    temp_s0_6 = temp_s0_5 + func_004398C8(arg0 + 0x1650);
    func_0043A388(temp_s0_6 + func_00438FF8(arg0 + 0x16A4));
}
