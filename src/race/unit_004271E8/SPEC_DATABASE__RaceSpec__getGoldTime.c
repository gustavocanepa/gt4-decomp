#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004476B0_arg0 {
    char pad0[0x1C];
    u16 unk1C;
    char pad1E[0x5A];
    u8 unk78;
    u8 unk79;
};

s32 SPEC_DATABASE__RaceSpec__getGoldTime(struct func_004476B0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = (arg0->unk78 * 0xEA60) + (arg0->unk79 * 0x3E8) + arg0->unk1C;
    return (temp_v0 == 0) ? 0x157529FF : temp_v0;
}
