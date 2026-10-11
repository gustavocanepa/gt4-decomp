#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003B6A00(s32, s32, s32);               /* extern */
s32 func_003BB930(s32, void *, s32);            /* extern */

struct func_003C0C60_arg0 {
    char pad0[0x60];
    void *unk60;
};

void func_003C0C60(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((arg1 * 4) + M2C_FIELD(((struct func_003C0C60_arg0 *)arg0)->unk60, s32 *, 8));
    func_003B6A00(temp_s0, arg2, arg3);
    func_003BB930(temp_s0 + 0x119C, arg0 + 0x928, arg2);
}
