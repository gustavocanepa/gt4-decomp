#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0057D008(f32);                             /* extern */

void func_003FFC68(f32 *arg0, f32 *arg1, f32 fparg0) {
    f32 temp_f0;

    temp_f0 = (0x1.0000000000000p+1f * func_0057D008(0x1.0000000000000p+0f / (0x1.0000000000000p+1f * fparg0 * 0x1.0000000000000p-4f))) / 0x1.1df4680000000p-6f;
    *arg0 = temp_f0;
    if (temp_f0 <= 0x1.0000000000000p+1f) {
        *arg0 = 0x1.0000000000000p+1f;
    }
    if (*arg0 >= 0x1.4ccccc0000000p+6f) {
        *arg0 = 0x1.4ccccc0000000p+6f;
    }
    *arg1 = 0x1.4ccccc0000000p+6f;
}
