#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6BE0_arg0 {
    char pad0[0xE40C];
    s32 unkE40C;
};

s32 func_005F6BE0(struct func_005F6BE0_arg0 *arg0) {
    return arg0->unkE40C;
}
