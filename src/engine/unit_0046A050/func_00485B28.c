#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004859A0(void *, s32);                     /* extern */
s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_00485B28_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_00485B28(struct func_00485B28_arg0 *arg0, s32 arg1, s32 (*arg2)(s64)) {
    s32 temp_v0;
    s32 var_s0;

    func_00576788();
    var_s0 = 0;
    temp_v0 = func_004859A0(arg0, arg1);
    if (temp_v0 >= 0) {
        var_s0 = 1;
        arg2(M2C_FIELD(((temp_v0 * 0x10) + arg0->unk30), s64 *, 8));
    }
    func_005767C0(arg0);
    return var_s0;
}
