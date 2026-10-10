#include "types.h"
#include "gt4/RaceLanBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBase__virtual_39();                            /* extern */
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */
s32 func_003DF970(void *, s32);                 /* extern */
s32 func_004FAF50(s32);                     /* extern */
s64 func_00578560();                                /* extern */

extern char D_00645570[];
void RaceLanBattle__virtual_39(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1F4D8;
    RaceBase__virtual_39();
    CarIconMaker__structor_1(temp_s1, ((struct RaceLanBattle *)arg0)->unk6C);
    func_003DF970(arg0 + 0x1F508, temp_s1);
    ((struct RaceLanBattle *)arg0)->unk1FA54 = 0;
    func_004FAF50((s32)D_00645570);
    ((struct RaceLanBattle *)arg0)->unkE460 = func_00578560();
    ((struct RaceLanBattle *)arg0)->unkE468 = 0;
}
