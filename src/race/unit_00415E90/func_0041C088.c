#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041C088_arg0 {
    char pad0[0x60];
    s128 unk60;
};

void func_0041C088(struct func_0041C088_arg0 *arg0, s128 *arg1) {
    arg0->unk60 = (s128) *arg1;
}
