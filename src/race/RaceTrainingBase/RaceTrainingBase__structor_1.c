#include "types.h"
#include "gt4/RaceTrainingBase.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RacePause__structor_1(s32, s32);                /* extern */
s32 RaceSinglePlayer__structor_1(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceTrainingBase__vtable[];
void RaceTrainingBase__structor_1(void *arg0, s32 arg1) {
    ((struct RaceTrainingBase *)arg0)->unk64 = (s32)RaceTrainingBase__vtable;
    RacePause__structor_1(arg0 + 0x125C0, 2);
    RaceSinglePlayer__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
