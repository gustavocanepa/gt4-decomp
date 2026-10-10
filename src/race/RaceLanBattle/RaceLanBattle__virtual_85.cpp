#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Recorder__finish(s32);                         /* extern */
s32 RaceBase__virtual_85();                            /* extern */

void RaceLanBattle__virtual_85(s32 arg0) {
    RaceBase__virtual_85();
    AutomobileControlRecord__Recorder__finish(arg0 + 0xF260);
}
