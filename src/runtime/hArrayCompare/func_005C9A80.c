#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005C9A80_arg0 {
    char pad0[0x4];
    s32 (*unk4)(s32, s32);
};

void func_005C9A80(struct func_005C9A80_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk4(arg1, arg2);
}
