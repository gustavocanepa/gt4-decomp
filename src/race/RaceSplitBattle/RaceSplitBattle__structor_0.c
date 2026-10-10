#include "types.h"
#include "gt4/RaceSplitBattle.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceSplitBattleBase__structor_0();                            /* extern */
s32 func_0038BB50(void *, s32);                 /* extern */
s32 RaceSplitDisplay__structor_0(s32);                         /* extern */

extern char RaceSplitBattle__vtable[];
void RaceSplitBattle__structor_0(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x26D80;
    RaceSplitBattleBase__structor_0();
    ((struct RaceSplitBattle *)arg0)->unk64 = (s32)RaceSplitBattle__vtable;
    RaceSplitDisplay__structor_0(temp_s1);
    func_0038BB50(arg0, temp_s1);
}
