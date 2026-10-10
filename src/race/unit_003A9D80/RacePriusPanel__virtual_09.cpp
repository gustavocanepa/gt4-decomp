#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceValueDisplay__virtual_03(s32);                         /* extern */
s32 func_003A9640(s32);                         /* extern */
s32 RacePriusHybridDisplay__virtual_09(s32, f32);                    /* extern */

void RacePriusPanel__virtual_09(s32 arg0, f32 fparg0) {
    func_003A9640(arg0 + 0x22C);
    RaceValueDisplay__virtual_03(arg0 + 0x74);
    RaceValueDisplay__virtual_03(arg0 + 0xE0);
    RacePriusHybridDisplay__virtual_09(arg0 + 0x150, fparg0);
}
