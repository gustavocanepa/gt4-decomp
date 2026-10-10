#include "types.h"
#include "gt4/RaceRichCountDisplay.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char RaceRichCountDisplay__vtable[];
s32 RaceValueDisplayBase__structor_1(void *);
void RaceDisplayObjectBase__setAlignment(void *, s32, s32);
void RaceRichCountDisplay__structor_0(struct RaceRichCountDisplay *arg0) {
    RaceValueDisplayBase__structor_1(arg0);
    arg0->unk68 = -1;
    arg0->unk14 = (s32)RaceRichCountDisplay__vtable;
    arg0->unk70 = 0x98967F;
    arg0->unk6C = 0;
    arg0->unk74 = 0;
    arg0->unk78 = 0;
    RaceDisplayObjectBase__setAlignment(arg0, 1, 0);
}
