#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FBA70_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

s32 func_005FBA70(struct func_005FBA70_arg0 *arg0) {
    return arg0->unkC4 != 0;
}
