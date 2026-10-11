#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3C88_arg0 {
    char pad0[0xCF64];
    s32 unkCF64;
};

void func_005F3C88(struct func_005F3C88_arg0 *arg0, s32 arg1) {
    arg0->unkCF64 = arg1;
}
