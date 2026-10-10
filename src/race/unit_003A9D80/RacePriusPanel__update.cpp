#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__update(s32);                         /* extern */
s32 Oscillator__update(s32);                         /* extern */
s32 RacePriusHybridDisplay__update(s32, f32);                    /* extern */

void RacePriusPanel__update(s32 arg0, f32 fparg0) {
    Oscillator__update(arg0 + 0x22C);
    RaceValueDisplayBase__update(arg0 + 0x74);
    RaceValueDisplayBase__update(arg0 + 0xE0);
    RacePriusHybridDisplay__update(arg0 + 0x150, fparg0);
}
