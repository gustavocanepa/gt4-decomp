#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D008(f32, f32);                        /* extern */

f32 func_0037E908(f32 fparg0, f32 fparg1) {
    f32 temp_f13;

    temp_f13 = (0x1.0000000000000p+1f * fparg1) / ((fparg0 * ((((fparg0 * 0x1.b6db600000000p-2f) + -0x1.b6db600000000p-2f) * fparg0) + 0x1.0000000000000p+0f) * 0x1.4000000000000p+3f) + 0x1.8000000000000p+0f);
    return (0x1.0000000000000p+1f * func_0057D008(0x1.0000000000000p+0f / temp_f13, temp_f13)) / 0x1.1df4680000000p-6f;
}
