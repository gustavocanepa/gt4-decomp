#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00605148_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void func_00605148(struct func_00605148_arg0 *arg0, s32 arg1) {
    arg0->unk14 = arg1;
    arg0->unk18 = 1;
}
