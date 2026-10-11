#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006038A0_arg0 {
    char pad0[0xC];
    s32 *unkC;
};

s32 func_006038A0(struct func_006038A0_arg0 *arg0) {
    return *arg0->unkC;
}
