#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00462868(void);
f32 func_00462DB0(s32, s32);
extern f32 D_006213D8;
extern f32 D_006213DC;
extern f32 D_0088F2D0;
f32 func_00391CD8(void) {
    f32 r = func_00462DB0(func_00462868(), 2);
    return D_006213D8 * D_006213DC * D_0088F2D0 * r;
}
