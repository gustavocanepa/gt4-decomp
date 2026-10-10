#include "types.h"
#include "gt4/RaceArcadeDemo.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 DynamicsConductorSinglePlayer__structor_2(void *, s32);             /* extern */
s32 RacePause__structor_1(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceArcadeDemo__vtable[];
void RaceArcadeDemo__structor_1(void *arg0, s32 arg1) {
    ((struct RaceArcadeDemo *)arg0)->unk64 = (s32)RaceArcadeDemo__vtable;
    RacePause__structor_1(arg0 + 0x24100, 2);
    DynamicsConductorSinglePlayer__structor_2(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
