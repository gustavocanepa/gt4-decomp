#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0036FFC0(f32 *p, f32 x) {
    f32 k = p[7] * p[4] * p[2] / p[3];
    return p[2] * 0.5f + p[2] * (x - p[8]) / k;
}
