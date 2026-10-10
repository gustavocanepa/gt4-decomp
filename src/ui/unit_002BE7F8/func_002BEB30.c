#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002BEB30_arg0 {
    char pad0[0x308];
    s32 unk308;
};

s32 func_002BEB30(struct func_002BEB30_arg0 *arg0) {
    return ((s32) arg0->unk308 >> 8) & 1;
}
