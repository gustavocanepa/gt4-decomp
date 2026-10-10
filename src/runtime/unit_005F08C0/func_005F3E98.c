#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3E98_arg0 {
    char pad0[0xE340];
    s32 unkE340;
};

void func_005F3E98(struct func_005F3E98_arg0 *arg0, s32 arg1) {
    arg0->unkE340 = arg1;
}
