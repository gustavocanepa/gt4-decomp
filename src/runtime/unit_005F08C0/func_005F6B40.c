#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6B40_arg0 {
    char pad0[0xE410];
    s32 unkE410;
};

void func_005F6B40(struct func_005F6B40_arg0 *arg0, s32 arg1) {
    arg0->unkE410 = arg1;
}
