#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004476F0_arg0 {
    char pad0[0x1E];
    u16 unk1E;
    char pad20[0x5A];
    u8 unk7A;
    u8 unk7B;
};

s32 func_004476F0(struct func_004476F0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = (arg0->unk7A * 0xEA60) + (arg0->unk7B * 0x3E8) + arg0->unk1E;
    return (temp_v0 == 0) ? 0x157529FF : temp_v0;
}
