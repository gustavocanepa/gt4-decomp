#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00613C88_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

s32 func_00613C88(struct func_00613C88_arg0 *arg0) {
    return arg0->unk14 - arg0->unk8;
}
