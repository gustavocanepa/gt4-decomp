#include "types.h"
#include "gt4/ResultLinkBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0032A790(s32, s32);                /* extern */
s32 ResultArcade__virtual_01();                            /* extern */

void ResultLinkBattle__virtual_01(struct ResultLinkBattle *arg0) {
    f32 temp_f0;

    ResultArcade__virtual_01();
    arg0->unk504 = 0;
    temp_f0 = (f32) func_0032A790((s32)"RaceResultStartDelayForLoser", 0x14);
    arg0->unk508 = 1;
    arg0->unk500 = temp_f0;
}
