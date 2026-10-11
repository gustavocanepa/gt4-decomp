#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D1F0(f32);                             /* extern */

f32 func_0036EBE8(f32 fparg0, f32 fparg1, f32 fparg2) {
    return fparg0 - (func_0057D1F0((fparg0 * 0x1.921fb40000000p+1f) / 0x1.6800000000000p+7f) * (fparg1 * 0x1.0000000000000p-1f) * fparg2);
}
