#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00447670_arg0 {
    char pad0[0x1A];
    u16 unk1A;
    char pad1C[0x5A];
    u8 unk76;
    u8 unk77;
};

s32 func_00447670(struct func_00447670_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = (arg0->unk76 * 0xEA60) + (arg0->unk77 * 0x3E8) + arg0->unk1A;
    return (temp_v0 == 0) ? 0x157529FF : temp_v0;
}
