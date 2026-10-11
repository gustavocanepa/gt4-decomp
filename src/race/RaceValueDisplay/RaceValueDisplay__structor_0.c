#include "types.h"
#include "gt4/RaceValueDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__structor_1();                            /* extern */
s32 RaceValueDisplay__setFont(void *, s32);             /* extern */

extern char RaceValueDisplay__vtable[];
extern char D_006A1460[];
void RaceValueDisplay__structor_0(struct RaceValueDisplay *arg0) {
    RaceValueDisplayBase__structor_1();
    arg0->unk88 = 0;
    arg0->unk8C = 0;
    arg0->unk14 = (s32)RaceValueDisplay__vtable;
    RaceValueDisplay__setFont(arg0, (s32)D_006A1460);
}
