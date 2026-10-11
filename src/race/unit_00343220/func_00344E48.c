#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00344E48(s8 *arg0, s32 arg1, f32 fparg0) {
    f32 t = fparg0 + *(f32 *)(arg0 + 0x554);
    f32 a = *(f32 *)(arg0 + arg1 * 4 + 0x910);
    s8 *e = arg0 + arg1 * 0xEC;
    return a * t + *(f32 *)(e + 0x188) * (1.0f - t);
}
