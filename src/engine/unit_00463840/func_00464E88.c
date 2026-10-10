#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00464E88(f32 *p, f32 t) {
    f32 u;
    if (t <= 0.0f) return p[7];
    u = p[6] * t;
    if (1.0f <= u) return p[8];
    return p[7] + u * (p[8] - p[7]);

}
