#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004628B0_arg0 {
    u8 pad0[0x14];
    void *unk14;
};

void func_004628B0(struct func_004628B0_arg0 *arg0) {
    arg0->unk14 = (void *) ((s32) arg0->unk14 + (s32) (arg0));
}
