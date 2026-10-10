#include "types.h"
#include "gt4/RaceSinglePlayerInformation.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_003D6268(s32);                         /* extern */

extern char RaceSinglePlayerInformation__vtable[];
s32 RaceSinglePlayerInformation__structor_0(void *arg0) {
    RaceInformation__structor_0();
    ((struct RaceSinglePlayerInformation *)arg0)->unk12C = (s32)RaceSinglePlayerInformation__vtable;
    func_003D6268(arg0 + 0x130);
    ((struct RaceSinglePlayerInformation *)arg0)->unk118 = 6;
}
