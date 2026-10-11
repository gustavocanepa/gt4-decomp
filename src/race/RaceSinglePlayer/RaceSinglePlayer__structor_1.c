#include "types.h"
#include "gt4/RaceSinglePlayer.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__delControl(void *, s32);                         /* extern */
s32 RaceBasicWithRaceDisplay__structor_1(void *, s32);             /* extern */
s32 SimplePause__structor_1(void *, s32);             /* extern */
s32 RaceInput__structor_2(s32, s32);                /* extern */
s32 func_0055FA30(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceSinglePlayer__vtable[];
void RaceSinglePlayer__structor_1(void *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x123CC;
    ((struct RaceSinglePlayer *)arg0)->unk64 = (s32)RaceSinglePlayer__vtable;
    GranTurismo4__GameObjectBase__delControl(arg0, temp_s1);
    RaceInput__structor_2(temp_s1, 2);
    func_0055FA30(arg0 + 0x1238C, 2);
    SimplePause__structor_1(arg0 + 0x12380, 2);
    RaceBasicWithRaceDisplay__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
