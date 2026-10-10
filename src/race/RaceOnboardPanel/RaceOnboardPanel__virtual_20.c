#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct RaceOnboardPanel__virtual_20_temp_a3 {
    char pad0[0x54];
    s32 unk54;
};
struct RaceOnboardPanel__virtual_20_temp_a0 {
    char pad0[0x54];
    s32 unk54;
};

void RaceOnboardPanel__virtual_20(s32 arg0, s32 arg1) {
    s32 temp_a1;
    struct RaceOnboardPanel__virtual_20_temp_a0 *temp_a0;
    struct RaceOnboardPanel__virtual_20_temp_a3 *temp_a3;

    temp_a3 = arg0 + 0xA20;
    temp_a0 = arg0 + 0xA78;
    temp_a1 = (arg1 & 0xFF) << 0x10;
    temp_a3->unk54 = (s32) ((temp_a3->unk54 & 0xFF00FFFF) | temp_a1);
    temp_a0->unk54 = (s32) ((temp_a0->unk54 & 0xFF00FFFF) | temp_a1);
}
