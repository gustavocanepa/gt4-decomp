#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002BEAD0_arg0 {
    char pad0[0x308];
    s32 unk308;
};

s32 func_002BEAD0(struct func_002BEAD0_arg0 *arg0) {
    return ((s32) arg0->unk308 >> 6) & 1;
}
