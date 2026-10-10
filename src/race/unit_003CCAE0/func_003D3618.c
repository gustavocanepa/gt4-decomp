#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0057D738(f32);                             /* extern */

f32 func_003D3618(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = fparg0 - fparg2;
    return (temp_f22 - (fparg1 * func_0057D738(temp_f22 / fparg1))) + fparg2;
}
