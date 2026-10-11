/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_005CA5F0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_005CA5F0(struct func_005CA5F0_arg0 *arg0, u32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 temp_a0;
    s32 temp_a2;

    temp_a2 = arg1 * 0x54;
    if (arg1 < 4U) {
        temp_a0 = temp_a2 + 0x10;
        M2C_FIELD((arg0->unk4 + temp_a0), f32 *, 8) = fparg0;
        M2C_FIELD((temp_a2 + arg0->unk4), f32 *, 0x1C) = fparg1;
        M2C_FIELD((temp_a2 + arg0->unk4), f32 *, 0x20) = fparg2;
        M2C_FIELD((arg0->unk4 + temp_a0), s32 *, 4) = 1;
    }
}
