#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Manager__load(s32, s32, s32);           /* extern */
void *RaceSolitaire__getInputGhost();                              /* extern */

struct RaceFreeRun__virtual_63_temp_v0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

void RaceSolitaire__loadGhostInputs(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = RaceSolitaire__getInputGhost();
    AutomobileControlRecord__Manager__load(temp_v0 + 0xD4, arg1 + 0x1AA4, 1);
    ((struct RaceFreeRun__virtual_63_temp_v0 *)temp_v0)->unk1D0 = 0;
}
