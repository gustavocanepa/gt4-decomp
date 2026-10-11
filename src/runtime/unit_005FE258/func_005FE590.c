#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FE590_arg0 {
    char pad0[0xF0F8];
    s32 unkF0F8;
};

s32 func_005FE590(struct func_005FE590_arg0 *arg0) {
    return arg0->unkF0F8;
}
