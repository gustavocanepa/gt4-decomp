#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004EF330();                                /* extern */

struct func_004EF2F0_arg0 {
    char pad0[0x94];
    s32 unk94;
};

u32 func_004EF2F0(struct func_004EF2F0_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_004EF330();
    temp_v1 = (temp_v0 >= -1) ? temp_v0 : -1;
    arg0->unk94 = temp_v1;
    return (u32) ~temp_v1 >> 0x1F;
}
