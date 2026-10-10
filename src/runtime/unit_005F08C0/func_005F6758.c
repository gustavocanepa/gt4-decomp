#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F6758_arg0 {
    char pad0[0xCC8];
    u32 unkCC8;
};

s32 func_005F6758(struct func_005F6758_arg0 *arg0) {
    return (u32) arg0->unkCC8 < 2U;
}
