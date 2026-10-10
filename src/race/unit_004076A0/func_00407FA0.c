#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00407FA0_arg0 {
    char pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

f32 func_00407FA0(struct func_00407FA0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f2;
    f32 var_f0;

    var_f0 = 0.0f;
    temp_f2 = arg0->unk18;
    if (temp_f2 != 0.0f) {
        var_f0 = -((arg0->unk14 * fparg0) + (arg0->unk1C * fparg1)) / temp_f2;
    }
    return var_f0;
}
