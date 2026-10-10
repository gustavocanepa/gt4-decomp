#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0057B038_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_0057B038(struct func_0057B038_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;

    temp_f1 = arg0->unk0;
    arg0->unk0 = 0.0f;
    temp_f0 = arg0->unk4 + (temp_f1 * (fparg1 * 0.016666666f));
    temp_f0_2 = temp_f0 - (temp_f0 * (fparg0 * 0.016666666f));
    arg0->unk4 = temp_f0_2;
    arg0->unk8 = (f32) (arg0->unk8 + (temp_f0_2 * 0.016666666f));
    return arg0;
}
