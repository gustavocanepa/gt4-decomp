#include "types.h"
#include "gt4/RaceNetBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__virtual_107(void *, s32);                 /* extern */
s32 func_003D8AB0(s32);                             /* extern */

s32 RaceNetBattle__virtual_107(struct RaceNetBattle *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unkE424;
    if ((temp_v0 == 0) || (func_003D8AB0(temp_v0) == 0)) {
        RacePS2Base__virtual_107(arg0, arg1);
    }
}
