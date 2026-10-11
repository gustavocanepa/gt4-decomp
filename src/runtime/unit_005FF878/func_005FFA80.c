#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005FFA80_arg0 {
    char pad0[0x10];
    s128 unk10;
};

void func_005FFA80(struct func_005FFA80_arg0 *arg0, s128 *arg1) {
    arg0->unk10 = (s128) *arg1;
}
