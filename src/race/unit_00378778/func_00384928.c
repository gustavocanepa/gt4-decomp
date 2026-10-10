#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00578598(s32);                             /* extern */

struct func_00384928_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00384928(struct func_00384928_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 var_f20;

    var_f20 = fparg1;
    if (var_f20 <= 0x0.0p+0f) {
        var_f20 = 0x1.3333320000000p-2f;
    }
    if (func_00578598(arg1) < var_f20) {
        arg0->unk4 = (f32) (((0x1.0000000000000p+1f * func_00578598(arg1)) - 0x1.0000000000000p+0f) * 0x1.0000000000000p+7f);
    }
    temp_f5 = arg0->unk0;
    temp_f4 = arg0->unk8;
    temp_f4_2 = temp_f4 + (((fparg0 * arg0->unkC * (arg0->unk4 - temp_f5)) + (temp_f4 * -0x1.4000000000000p+3f)) / 0x1.e000000000000p+5f);
    arg0->unk8 = temp_f4_2;
    arg0->unk0 = (f32) (temp_f5 + (temp_f4_2 / 0x1.e000000000000p+5f));
}
