#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F67F8_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

s32 func_005F67F8(struct func_005F67F8_arg0 *arg0) {
    return arg0->unkCC8 == 0;
}
