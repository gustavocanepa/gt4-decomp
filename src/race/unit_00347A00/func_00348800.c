#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00348800(f32 x) {
    x = x * 0x1.E8EC90p+1f;
    if (x > 1.0f) x = 1.0f;
    else if (x < -1.0f) x = -1.0f;
    return x;

}
