#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00490FC8_arg0 {
    char pad0[0x4];
    s32 unk4;
    f32 unk8;
    char padC[0x4];
    f32 unk10;
};

void func_00490FC8(struct func_00490FC8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f0;
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 >= 2) {
        temp_f2 = arg0->unk8;
        temp_f1 = temp_f2 * 4.0f;
        var_f0 = temp_f2 + (((fparg0 - arg0->unk10) - fparg1) / (f32) (temp_v0 - 1));
        if (temp_f1 <= var_f0) {
            var_f0 = temp_f1;
        }
        arg0->unk8 = var_f0;
    }
}
