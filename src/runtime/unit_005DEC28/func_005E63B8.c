#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E63B8_arg0 {
    char pad0[0xC8];
    s32 unkC8;
};

s32 func_005E63B8(struct func_005E63B8_arg0 *arg0) {
    return arg0->unkC8 & 1;
}
