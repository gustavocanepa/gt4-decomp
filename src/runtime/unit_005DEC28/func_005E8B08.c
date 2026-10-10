#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005E8B08_arg0 {
    char pad0[0x308];
    s32 unk308;
};

s32 func_005E8B08(struct func_005E8B08_arg0 *arg0) {
    return ((s32) arg0->unk308 >> 1) & 1;
}
