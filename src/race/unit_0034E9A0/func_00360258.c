#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00360258_temp_a0 {
    char pad0[0x89];
    u8 unk89;
    char pad8A[0x2A];
    f32 unkB4;
    f32 unkB8;
};

void func_00360258(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 fparg0, f32 fparg1) {
    struct func_00360258_temp_a0 *temp_a0;

    temp_a0 = arg0 + (arg1 * 0xEC) + 0x164;
    if (temp_a0->unk89 == arg2) {
        *arg3 = fparg0 * temp_a0->unkB4;
        *arg4 = fparg1 * temp_a0->unkB8;
    }
}
