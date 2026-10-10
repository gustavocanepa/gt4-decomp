#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601468_arg0 {
    char pad0[0x81CC];
    s32 unk81CC;
};

s32 func_00601468(struct func_00601468_arg0 *arg0) {
    return arg0->unk81CC;
}
