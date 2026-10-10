#include "types.h"
#include "gt4/RaceSpeedDisplay.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__structor_1();                            /* extern */

extern char RaceSpeedDisplay__vtable[];
s32 RaceSpeedDisplay__structor_0(struct RaceSpeedDisplay *arg0) {
    RaceValueDisplayBase__structor_1();
    arg0->unk14 = (s32)RaceSpeedDisplay__vtable;
    arg0->unk68 = -0x1.0000000000000p+0f;
    arg0->unk6C = 0;
}
