#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FBF60_arg0 {
    char pad0[0x198];
    s32 unk198;
};

u32 func_005FBF60(struct func_005FBF60_arg0 *arg0) {
    return (u32) ~arg0->unk198 >> 0x1F;
}
