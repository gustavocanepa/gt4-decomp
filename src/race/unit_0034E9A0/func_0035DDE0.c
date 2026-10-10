#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0035DDB0(void);
extern s32 D_006244D8;
f32 func_0035DDE0(void) {
    f32 f = func_0035DDB0();
    if (D_006244D8 == 1) {
        f *= 0.625f;
    }
    return f;
}
