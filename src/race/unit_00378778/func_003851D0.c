#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003851D0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_003851D0(struct func_003851D0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f6;

    temp_f6 = arg0->unk0;
    temp_f3 = arg0->unk8;
    arg0->unk4 = fparg0;
    temp_f3_2 = temp_f3 + ((((arg0->unkC * (fparg0 - temp_f6)) + (arg0->unk10 * temp_f3)) / 0x1.e000000000000p+5f) * arg0->unk14);
    arg0->unk8 = temp_f3_2;
    temp_f1 = temp_f6 + (temp_f3_2 / 0x1.e000000000000p+5f);
    arg0->unk0 = temp_f1;
    if (temp_f1 < 0x1.0624dc0000000p-10f) {
        arg0->unk0 = 0x1.0624dc0000000p-10f;
    }
    temp_f1_2 = arg0->unk18;
    temp_f2 = arg0->unk0 / temp_f6;
    if (temp_f2 < temp_f1_2) {
        arg0->unk0 = (f32) (temp_f6 * temp_f1_2);
    }
    temp_f0 = arg0->unk1C;
    if (temp_f0 < temp_f2) {
        arg0->unk0 = (f32) (temp_f6 * temp_f0);
    }
}
