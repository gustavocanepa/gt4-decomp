#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0020FD28_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0020FD28(struct func_0020FD28_arg0 *arg0) {
    arg0->unk20 = (s32) (arg0->unk20 - 1);
}
