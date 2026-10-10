#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0035FFB0_temp_a0 {
    char pad0[0x89];
    u8 unk89;
    char pad8A[0x2A];
    f32 unkB4;
    f32 unkB8;
};

void func_0035FFB0(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 temp_v1;
    struct func_0035FFB0_temp_a0 *temp_a0;

    temp_a0 = arg0 + (arg1 * 0xEC) + 0x164;
    temp_v1 = temp_a0->unk89;
    if ((s32) temp_v1 < 0xA) {
        if (((s32) temp_v1 < 7) && (temp_v1 != 0)) {
            return;
        }
        goto block_6;
    }
    if (temp_v1 == 0xC) {
block_6:
        *arg2 = fparg0 * temp_a0->unkB4;
        *arg3 = fparg1 * temp_a0->unkB8;
    }
}
