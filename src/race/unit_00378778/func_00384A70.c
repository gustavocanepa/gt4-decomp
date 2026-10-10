#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00578598(s32);                             /* extern */

struct func_00384A70_arg0 {
    f32 unk0;
    f32 unk4;
};

void func_00384A70(struct func_00384A70_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 var_f20;

    var_f20 = fparg1;
    if (var_f20 <= 0x0.0p+0f) {
        var_f20 = 0x1.3333320000000p-2f;
    }
    if (func_00578598(arg1) < var_f20) {
        arg0->unk4 = (f32) ((0x1.0000000000000p+1f * func_00578598(arg1)) - 0x1.0000000000000p+0f);
    }
    temp_f0 = arg0->unk0;
    arg0->unk0 = (f32) (((arg0->unk4 - temp_f0) * fparg0 * 0x1.9999960000000p-2f) + temp_f0);
}
