#include "types.h"
#include "gt4/RaceBasicWithRaceDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBasic__structor_0();                            /* extern */
s32 func_0038BB50(void *, s32);                 /* extern */
s32 RaceDisplay__structor_0(s32);                         /* extern */

extern char RaceBasicWithRaceDisplay__vtable[];
void RaceBasicWithRaceDisplay__structor_0(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xE440;
    RaceBasic__structor_0();
    ((struct RaceBasicWithRaceDisplay *)arg0)->unk64 = (s32)RaceBasicWithRaceDisplay__vtable;
    RaceDisplay__structor_0(temp_s1);
    func_0038BB50(arg0, temp_s1);
}
