#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00194CE0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00194CE0(struct func_00194CE0_arg0 *arg0, f32 fparg0) {
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 var_f12;
    f32 var_f12_2;

    var_f12 = 2.0f * (fparg0 - 0.5f);
    if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    var_f12_2 = var_f12 * var_f12;
    if (var_f12_2 > 1.0f) {
        var_f12_2 = 1.0f;
    }
    temp_f4 = arg0->unk0;
    temp_f7 = arg0->unk4;
    temp_f5 = arg0->unk8;
    temp_f6 = arg0->unkC;
    temp_f4_2 = temp_f4 + ((1.0f - temp_f4) * var_f12_2);
    arg0->unk0 = temp_f4_2;
    arg0->unk4 = (f32) (temp_f7 + ((1.0f - temp_f7) * var_f12_2));
    arg0->unk8 = (f32) (temp_f5 + ((1.0f - temp_f5) * var_f12_2));
    arg0->unkC = (f32) (temp_f6 + ((1.0f - temp_f6) * var_f12_2));
    if (temp_f4_2 > 1.0f) {
        arg0->unk0 = 1.0f;
    }
    if (arg0->unk4 > 1.0f) {
        arg0->unk4 = 1.0f;
    }
    if (arg0->unk8 > 1.0f) {
        arg0->unk8 = 1.0f;
    }
    if (arg0->unkC > 1.0f) {
        arg0->unkC = 1.0f;
    }
}
