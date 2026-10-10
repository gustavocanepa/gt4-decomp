#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00344E98();                                /* extern */

struct func_00344EC8_arg0 {
    char pad0[0x554];
    f32 unk554;
};

f32 func_00344EC8(void *arg0, f32 fparg0) {
    f32 temp_f20;
    s32 temp_v0;

    temp_v0 = func_00344E98();
    temp_f20 = fparg0 + ((struct func_00344EC8_arg0 *)arg0)->unk554;
    return (M2C_FIELD(((temp_v0 * 4) + arg0), f32 *, 0x930) * temp_f20) + (M2C_FIELD(((temp_v0 * 0x34) + arg0), f32 *, 0x7CC) * (1.0f - temp_f20));
}
