#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00233D38_arg0 {
    char pad0[0xE8];
    s32 unkE8;
};

s32 func_00233D38(struct func_00233D38_arg0 *arg0) {
    return ((s32) arg0->unkE8 >> 4) & 1;
}
