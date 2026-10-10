#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F34B0_arg0 {
    char pad0[0xE44C];
    s32 unkE44C;
};

void func_005F34B0(struct func_005F34B0_arg0 *arg0, s32 arg1) {
    arg0->unkE44C = arg1;
}
