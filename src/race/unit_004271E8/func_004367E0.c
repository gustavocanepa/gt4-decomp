#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0048ED30(s32);                             /* extern */

struct func_004367E0_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_004367E0(struct func_004367E0_arg0 *arg0, s32 arg1) {
    arg0->unkC = func_0048ED30(arg1);
}
