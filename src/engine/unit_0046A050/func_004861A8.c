#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004861A8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

f32 func_004861A8(struct func_004861A8_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = arg0->unk0;
    temp_f2_2 = arg0->unk8;
    temp_f4 = arg0->unk4;
    temp_f1 = (temp_f2_2 - arg0->unkC) * 3.0f;
    temp_f12 = (fparg0 - temp_f5) / (arg0->unk10 - temp_f5);
    temp_f2 = (temp_f4 - temp_f2_2) * 3.0f;
    return (((((((arg0->unk14 - temp_f4) + temp_f1) * temp_f12) + (temp_f2 - temp_f1)) * temp_f12) - temp_f2) * temp_f12) + temp_f4;
}
