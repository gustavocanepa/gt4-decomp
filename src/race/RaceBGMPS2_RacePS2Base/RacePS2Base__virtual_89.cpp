#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBase__virtual_89();                            /* extern */
s32 func_00399300(s32, s32);                /* extern */
s32 func_003D33C0(s32);                         /* extern */

void RacePS2Base__virtual_89(s32 arg0) {
    RaceBase__virtual_89();
    func_00399300(arg0 + 0xE170, 0);
    func_003D33C0(arg0 + 0x3628);
}
