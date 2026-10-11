#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00426AF8(s32);                             /* extern */

struct func_003D95A0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[0x78];
    s32 unk9C;
};

void func_003D95A0(struct func_003D95A0_arg0 *arg0, s32 arg1) {
    if (((arg0->unk1C == 0) || (arg0->unk20 != 0)) && (func_00426AF8(arg1) & 0x8003)) {
        arg0->unk9C = 3;
    }
}
