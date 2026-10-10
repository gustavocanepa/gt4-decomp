#include "types.h"
#include "gt4/RaceArcadeDemo.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceArcade__structor_0();                            /* extern */
s32 RacePause__structor_0(s32);                         /* extern */

extern char RaceArcadeDemo__vtable[];
void RaceArcadeDemo__structor_0(void *arg0) {
    RaceArcade__structor_0();
    ((struct RaceArcadeDemo *)arg0)->unk64 = (s32)RaceArcadeDemo__vtable;
    RacePause__structor_0(arg0 + 0x24100);
}
