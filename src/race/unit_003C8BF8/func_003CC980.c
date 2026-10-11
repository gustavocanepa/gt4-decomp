#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_003CC980(f32 x) {
    f32 t = 1.0f - (x + x - 0x1.D2F1A8p-2f) / 0x1.7BE76Cp-2f;
    if (t < 0.0f) t = 0.0f;
    else if (t > 1.0f) t = 1.0f;
    return t;
}
