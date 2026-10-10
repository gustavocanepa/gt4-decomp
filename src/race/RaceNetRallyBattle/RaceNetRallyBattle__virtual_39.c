#include "types.h"
#include "gt4/RaceNetRallyBattle.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceBase__virtual_39();                            /* extern */
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */

void RaceNetRallyBattle__virtual_39(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x22708;
    RaceBase__virtual_39();
    CarIconMaker__structor_1(temp_s1, ((struct RaceNetRallyBattle *)arg0)->unk6C);
    ((struct RaceNetRallyBattle *)arg0)->unkE448 = temp_s1;
}
