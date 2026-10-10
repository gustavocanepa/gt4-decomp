#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct RaceSimplePanel__virtual_20_temp_a3 {
    char pad0[0x54];
    s32 unk54;
};
struct RaceSimplePanel__virtual_20_temp_a0 {
    char pad0[0x54];
    s32 unk54;
};

void RaceSimplePanel__setAutomaticTransmission(s32 arg0, s32 arg1) {
    s32 temp_a1;
    struct RaceSimplePanel__virtual_20_temp_a0 *temp_a0;
    struct RaceSimplePanel__virtual_20_temp_a3 *temp_a3;

    temp_a3 = arg0 + 0x124;
    temp_a0 = arg0 + 0x17C;
    temp_a1 = (arg1 & 0xFF) << 0x10;
    temp_a3->unk54 = (s32) ((temp_a3->unk54 & 0xFF00FFFF) | temp_a1);
    temp_a0->unk54 = (s32) ((temp_a0->unk54 & 0xFF00FFFF) | temp_a1);
}
