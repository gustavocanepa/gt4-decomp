#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0036D738(f32 x) {
    if (x < 0.0f) x = -x;
    x -= 0x1.A2E104p+5f;
    if (x < 0.0f) x = 0.0f;
    x = x / 0x1.A2E104p+9f + 1.0f;
    if (1.125f <= x) x = 1.125f;
    return x;
}
