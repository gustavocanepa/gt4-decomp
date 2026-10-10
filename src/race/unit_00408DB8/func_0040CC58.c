#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0040CC58_temp_a0 {
    char pad0[0x468];
    f32 unk468;
    char pad46C[0x1F8];
    f32 unk664;
    f32 unk668;
    f32 unk66C;
};

void func_0040CC58(s32 arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f5;
    struct func_0040CC58_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    temp_f5 = temp_a0->unk664;
    temp_f2 = temp_a0->unk668;
    temp_f0 = (((temp_a0->unk468 * 11.25f) - temp_f5) * 200.0f) - (temp_f2 * 20.0f);
    temp_a0->unk66C = temp_f0;
    temp_f2_2 = temp_f2 + (temp_f0 * 0.016666666f);
    temp_a0->unk668 = temp_f2_2;
    temp_a0->unk664 = (f32) (temp_f5 + (temp_f2_2 * 0.016666666f));
}
