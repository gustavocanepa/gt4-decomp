#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBase__soundStop();                            /* extern */
s32 RaceCourseSound__playStop(s32, s32);                /* extern */
s32 Pitmen__stopSound(s32);                         /* extern */

void RacePS2Base__soundStop(s32 arg0) {
    RaceBase__soundStop();
    RaceCourseSound__playStop(arg0 + 0xE170, 0);
    Pitmen__stopSound(arg0 + 0x3628);
}
