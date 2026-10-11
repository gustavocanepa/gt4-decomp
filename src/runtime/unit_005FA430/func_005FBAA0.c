#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FBAA0_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

s32 func_005FBAA0(struct func_005FBAA0_arg0 *arg0) {
    return arg0->unkD0 != 0;
}
