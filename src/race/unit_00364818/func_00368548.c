#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00368548(f32 a, f32 b) {
    f32 t = (0x1.0AAAA8p+2f - b) / 0x1.0AAAA8p+2f;
    if (t < 0.0f) t = 0.0f;
    t *= 0x1.333332p-2f;
    return t + (1.0f - t) * a;
}
