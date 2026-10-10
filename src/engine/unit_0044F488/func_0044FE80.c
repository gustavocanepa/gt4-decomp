#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0044FC48(s32);                             /* extern */
f32 func_0044FE10();                                /* extern */

f32 func_0044FE80(s32 arg0) {
    f32 temp_f20;

    temp_f20 = func_0044FE10();
    return func_0044FC48(arg0) * temp_f20 * temp_f20;
}
