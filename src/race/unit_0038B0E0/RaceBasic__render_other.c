#include "types.h"
#include "gt4/RaceNetBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__render_other(void *, s32);                 /* extern */
s32 RaceMonitor__isFullScreenMode(s32);                             /* extern */

s32 RaceBasic__render_other(struct RaceNetBattle *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unkE424;
    if ((temp_v0 == 0) || (RaceMonitor__isFullScreenMode(temp_v0) == 0)) {
        RacePS2Base__render_other(arg0, arg1);
    }
}
