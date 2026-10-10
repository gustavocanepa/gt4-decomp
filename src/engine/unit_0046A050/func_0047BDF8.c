#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00477460(s32);                             /* extern */
s32 func_00480FA0(void *, s32);                 /* extern */
f32 func_0059D2A0(f32);                             /* extern */

struct func_0047BDF8_arg1 {
    char pad0[0x8];
    s32 unk8;
};

f32 func_0047BDF8(s32 arg0, struct func_0047BDF8_arg1 *arg1) {
    f32 var_f20;

    if (arg0 != 0) {
        var_f20 = func_00477460(arg1->unk8 - 8);
    } else {
        var_f20 = 0.0f;
    }
    func_00480FA0(arg1, arg0);
    return 1.5707963f - func_0059D2A0(var_f20);
}
