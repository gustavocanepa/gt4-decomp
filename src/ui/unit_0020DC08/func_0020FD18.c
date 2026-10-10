#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0020FD18_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0020FD18(struct func_0020FD18_arg0 *arg0) {
    arg0->unk20 = (s32) (arg0->unk20 + 1);
}
