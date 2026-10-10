#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003447F8(f32);                             /* extern */
f32 func_00344918(void *, f32);                     /* extern */

struct func_00344A08_arg0 {
    char pad0[0x554];
    f32 unk554;
};

f32 func_00344A08(struct func_00344A08_arg0 *arg0, f32 fparg0) {
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f0;

    temp_f20 = fparg0 + arg0->unk554;
    temp_f21 = func_003447F8(temp_f20);
    var_f0 = temp_f21 - func_00344918(arg0, temp_f20);
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
