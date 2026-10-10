#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004452F8(void *, s32);                 /* extern */

struct RaceMachineTestInformation__virtual_12_temp_s2 {
    char pad0[0x178];
    s32 unk178;
};

struct RaceMachineTestInformation__virtual_12_arg1 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x342C];
    s32 unk3444;
};

void RaceMachineTestInformation__virtual_12(s32 arg0, void *arg1) {
    s32 temp_s0;
    struct RaceMachineTestInformation__virtual_12_temp_s2 *temp_s2;

    temp_s2 = arg1 + 0x20;
    temp_s0 = ((struct RaceMachineTestInformation__virtual_12_arg1 *)arg1)->unk14;
    func_004452F8(temp_s2, arg0 + 0x130);
    temp_s2->unk178 = (s32) (temp_s0 + 0x100);
    ((struct RaceMachineTestInformation__virtual_12_arg1 *)arg1)->unk3444 = 0;
}
