#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00233D68_arg0 {
    char pad0[0xE8];
    s32 unkE8;
};

s32 func_00233D68(struct func_00233D68_arg0 *arg0) {
    return ((s32) arg0->unkE8 >> 5) & 1;
}
