#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00355D80(void);
extern f32 D_008438F8;
extern f32 D_008438FC;
f32 func_00356168(void) {
    f32 x = func_00355D80();
    if (D_008438FC <= x) return 1.0f;
    if (x <= D_008438F8) return 0.0f;
    return (x - D_008438F8) / (D_008438FC - D_008438F8);
}
