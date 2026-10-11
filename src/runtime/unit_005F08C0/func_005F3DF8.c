#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F3DF8_arg0 {
    char pad0[0xE330];
    s32 unkE330;
};

void func_005F3DF8(struct func_005F3DF8_arg0 *arg0, s32 arg1) {
    arg0->unkE330 = arg1;
}
