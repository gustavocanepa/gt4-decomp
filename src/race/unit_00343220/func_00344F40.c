#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00344E98();                                /* extern */

struct func_00344F40_arg0 {
    char pad0[0x554];
    f32 unk554;
};

f32 func_00344F40(void *arg0, f32 fparg0) {
    f32 temp_f20;
    s32 temp_v0;
    void *temp_s0;

    temp_v0 = func_00344E98();
    temp_f20 = fparg0 + ((struct func_00344F40_arg0 *)arg0)->unk554;
    temp_s0 = arg0 + 0x10;
    return (M2C_FIELD(((temp_v0 * 4) + temp_s0), f32 *, 0x930) * temp_f20) + (M2C_FIELD(((temp_v0 * 0x34) + temp_s0), f32 *, 0x7C0) * (1.0f - temp_f20));
}
