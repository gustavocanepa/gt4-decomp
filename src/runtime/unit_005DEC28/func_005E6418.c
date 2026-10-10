#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E6418_arg0 {
    char pad0[0xC8];
    s32 unkC8;
};

s32 func_005E6418(struct func_005E6418_arg0 *arg0) {
    return ((s32) arg0->unkC8 >> 2) & 1;
}
