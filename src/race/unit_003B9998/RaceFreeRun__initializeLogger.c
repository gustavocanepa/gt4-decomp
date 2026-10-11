#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 DynamicsConductor__playbackOneLapReplay(s32, s32);                /* extern */
void *RaceSolitaire__getInputGhost(void *);                        /* extern */
s32 RaceSolitaire__initializeLogger();                            /* extern */

s32 RaceFreeRun__initializeLogger(struct RaceFreeRun *arg0) {
    RaceSolitaire__initializeLogger();
    DynamicsConductor__playbackOneLapReplay(arg0->unk70, 0);
    if (M2C_FIELD(RaceSolitaire__getInputGhost(arg0), s32 *, 0x1D0) == 0) {
        DynamicsConductor__playbackOneLapReplay(arg0->unk70, 1);
    }
}
