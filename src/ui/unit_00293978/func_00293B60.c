#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00293B60_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

s32 func_00293B60(struct func_00293B60_arg0 *arg0) {
    return ((s32) arg0->unkB4 >> 4) & 1;
}
