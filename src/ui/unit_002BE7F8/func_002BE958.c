#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002BE958_arg0 {
    char pad0[0x308];
    s32 unk308;
};

s32 func_002BE958(struct func_002BE958_arg0 *arg0) {
    return ((s32) arg0->unk308 >> 4) & 1;
}
