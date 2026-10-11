#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomobileDeviceConfig__setFFBlevel(s32, s32);                    /* extern */
s32 AutomobileDeviceConfig__setFFBassist(s32, s32);                    /* extern */
s32 func_0043CBD8(s32, s32);                    /* extern */

void func_0043CF30(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x8C;
    AutomobileDeviceConfig__setFFBlevel(arg1, func_0043CBD8(temp_s0, 1));
    AutomobileDeviceConfig__setFFBassist(arg1, func_0043CBD8(temp_s0, 2));
}
