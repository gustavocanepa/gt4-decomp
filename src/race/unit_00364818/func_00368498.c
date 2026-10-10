#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003683A8(void *);
struct func_00368498_arg0 {
    char pad0[0x78C];
    f32 unk78C;
};

s32 func_00368498(struct func_00368498_arg0 *arg0) {
    if (func_003683A8(arg0) == 0) return 0;
    return arg0->unk78C * 8.0f + 0.5f;
}
