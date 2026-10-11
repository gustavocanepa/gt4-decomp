#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3C68_arg0 {
    char pad0[0xCF60];
    s32 unkCF60;
};

void func_005F3C68(struct func_005F3C68_arg0 *arg0, s32 arg1) {
    arg0->unkCF60 = arg1;
}
