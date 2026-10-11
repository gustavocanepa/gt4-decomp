#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003852A0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_003852A0(struct func_003852A0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 var_f0;

    temp_f4 = arg0->unk0;
    temp_f12 = fparg0 * 0x1.4000000000000p+4f;
    arg0->unk4 = temp_f12;
    if (temp_f4 < temp_f12) {
        temp_f2 = arg0->unk8;
        temp_f2_2 = temp_f2 + ((((temp_f12 - temp_f4) * 0x1.4000000000000p+5f) + (temp_f2 * -0x1.4000000000000p+3f)) / 0x1.e000000000000p+5f);
        arg0->unk8 = temp_f2_2;
        if (temp_f2_2 <= -0x1.c200000000000p+9f) {
            arg0->unk8 = -0x1.c200000000000p+9f;
        }
        var_f0 = arg0->unk8;
        if (var_f0 >= 0x1.c200000000000p+9f) {
            arg0->unk8 = 0x1.c200000000000p+9f;
            var_f0 = 0x1.c200000000000p+9f;
        }
        arg0->unk0 = (f32) (temp_f4 + (var_f0 / 0x1.e000000000000p+5f));
        return;
    }
    temp_f0 = temp_f4 * 0x1.9999980000000p-1f;
    arg0->unk0 = temp_f0;
    if (temp_f0 < temp_f12) {
        arg0->unk0 = temp_f12;
    }
}
