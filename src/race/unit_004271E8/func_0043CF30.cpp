#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F7150(s32, s32);                    /* extern */
s32 func_003F7160(s32, s32);                    /* extern */
s32 func_0043CBD8(s32, s32);                    /* extern */

void func_0043CF30(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x8C;
    func_003F7150(arg1, func_0043CBD8(temp_s0, 1));
    func_003F7160(arg1, func_0043CBD8(temp_s0, 2));
}
