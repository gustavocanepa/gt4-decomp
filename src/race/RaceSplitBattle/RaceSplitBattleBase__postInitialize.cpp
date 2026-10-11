#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 RaceBase__postInitialize();                            /* extern */
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */
s32 func_003DF970(void *, s32);                 /* extern */

struct RaceSplitBattle__virtual_39_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void RaceSplitBattleBase__postInitialize(char *arg0) {
    s32 temp_s1;

    temp_s1 = (s32)(arg0 + 0x1E988);
    RaceBase__postInitialize();
    CarIconMaker__structor_1(temp_s1, ((struct RaceSplitBattle__virtual_39_arg0 *)arg0)->unk6C);
    func_003DF970(arg0 + 0x1E9B8, temp_s1);
}

}
