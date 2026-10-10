#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003F12A0_arg0 {
    char pad0[0xF8BC];
    s32 unkF8BC;
};

s32 func_003F12A0(struct func_003F12A0_arg0 *arg0) {
    return arg0->unkF8BC;
}
