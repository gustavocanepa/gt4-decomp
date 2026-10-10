#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0044FC30(s32);                             /* extern */
f32 func_0044FDE0();                                /* extern */

f32 func_0044FE40(s32 arg0) {
    f32 temp_f20;

    temp_f20 = func_0044FDE0();
    return func_0044FC30(arg0) * temp_f20 * temp_f20;
}
