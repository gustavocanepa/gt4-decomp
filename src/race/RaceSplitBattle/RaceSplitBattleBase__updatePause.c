/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceSplitBattleBase__update_display(s32, f32);                    /* extern */
s32 RaceBasic__updatePause();                                /* extern */

void RaceSplitBattleBase__updatePause(s32 arg0) {
    RaceBasic__updatePause();
    RaceSplitBattleBase__update_display(arg0, 0.0f);
}
