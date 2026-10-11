#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6858_arg0 {
    char pad0[0xCC8];
    u32 unkCC8;
};

s32 func_005F6858(struct func_005F6858_arg0 *arg0) {
    return (u32) arg0->unkCC8 >= 2U;
}
