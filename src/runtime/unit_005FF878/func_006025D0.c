#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006025D0_arg0 {
    char pad0[0x7];
    u8 unk7;
};

s32 func_006025D0(struct func_006025D0_arg0 *arg0) {
    return arg0->unk7 != 0;
}
