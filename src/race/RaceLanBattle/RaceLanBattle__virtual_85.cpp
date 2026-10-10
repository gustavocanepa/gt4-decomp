#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00346498(s32);                         /* extern */
s32 RaceBase__virtual_85();                            /* extern */

void RaceLanBattle__virtual_85(s32 arg0) {
    RaceBase__virtual_85();
    func_00346498(arg0 + 0xF260);
}
