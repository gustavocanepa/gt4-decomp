#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00426B60_arg0 {
    char pad0[0x190];
    s32 unk190;
    char pad194[0x4];
    s32 unk198;
    char pad19C[0x24];
    s32 unk1C0;
};

s32 RaceInput__getExtendButtonDown(struct func_00426B60_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 1) {
        temp_v1 = arg0->unk190;
        return (arg0->unk1C0 ^ temp_v1) & temp_v1;
    }
    return 0;
}
