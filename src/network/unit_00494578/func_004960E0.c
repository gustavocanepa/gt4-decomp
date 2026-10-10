#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00496058(f32, f32);                        /* extern */

struct func_004960E0_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
};

void func_004960E0(struct func_004960E0_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f22;

    temp_f22 = -fparg0;
    arg0->unk0 = func_00496058(temp_f22, fparg0);
    arg0->unk4 = func_00496058(-fparg1 * 0.5f, fparg1 * 0.5f);
    arg0->unk8 = func_00496058(temp_f22, fparg0);
    arg0->unkC = 1.0f;
    temp_f0 = func_00496058(-fparg2, fparg2);
    arg0->unk14 = fparg3;
    arg0->unk10 = temp_f0;
    temp_f0_2 = func_00496058(-fparg4, fparg4);
    arg0->unk1C = 0;
    arg0->unk18 = temp_f0_2;
}
