#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_001CAB50(void **arg0) {
    f32 x = M2C_FIELD(*arg0, f32 *, 0x24);
    s32 small = 1;
    if (!(x < 1.0f)) small = 0;
    if (small) return x;
    return 1.0f / x;
}
