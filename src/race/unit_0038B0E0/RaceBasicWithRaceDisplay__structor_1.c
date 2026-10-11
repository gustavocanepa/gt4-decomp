#include "types.h"
#include "gt4/RaceBasicWithRaceDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBasic__structor_1(void *, s32);             /* extern */
s32 RaceABMonitor__structor_0(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceBasicWithRaceDisplay__vtable[];
void RaceBasicWithRaceDisplay__structor_1(void *arg0, s32 arg1) {
    ((struct RaceBasicWithRaceDisplay *)arg0)->unk64 = (s32)RaceBasicWithRaceDisplay__vtable;
    RaceABMonitor__structor_0(arg0 + 0xE440, 2);
    RaceBasic__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
