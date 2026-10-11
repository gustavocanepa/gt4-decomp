#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0057D380(f32);
struct func_003793A8_arg0 {
    char pad0[0xC];
    f32 unkC;
};

s32 func_003793A8(struct func_003793A8_arg0 *arg0) {
    f32 r = func_0057D380(arg0->unkC * 0.5f * 0x1.921FB4p+1f / 180.0f);
    return 240.0f / (r + r);
}
