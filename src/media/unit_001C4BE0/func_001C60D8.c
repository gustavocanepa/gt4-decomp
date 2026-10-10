#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_001C60D8_arg2 {
    f32 unk0;
    f32 unk4;
};
struct func_001C60D8_arg0 {
    f32 unk0;
    f32 unk4;
};
struct func_001C60D8_arg3 {
    f32 unk0;
    f32 unk4;
};

void func_001C60D8(struct func_001C60D8_arg0 *arg0, f32 *arg1, struct func_001C60D8_arg2 *arg2, struct func_001C60D8_arg3 *arg3, s32 arg4, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f12;

    var_f12 = fparg0;
    if (arg4 != 0) {
        var_f12 = 0x1.0000000000000p+0f - var_f12;
    }
    var_f0 = (((fparg1 / fparg2) - 0x1.0000000000000p+0f) * var_f12) + 0x1.0000000000000p+0f;
    if (var_f0 < 0x1.0000000000000p+0f) {
        var_f0 = 0x1.0000000000000p+0f;
    }
    temp_f1 = arg2->unk0;
    arg0->unk0 = (f32) (((arg3->unk0 - temp_f1) * var_f12) + temp_f1);
    temp_f1_2 = arg2->unk4;
    arg0->unk4 = (f32) (((arg3->unk4 - temp_f1_2) * var_f12) + temp_f1_2);
    *arg1 = fparg1 / var_f0;
}
