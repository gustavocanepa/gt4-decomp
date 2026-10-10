#include "types.h"
#include "gt4/RaceOdometer.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A4248(void *, s32);             /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceOdometer__vtable[];
void RaceOdometer__structor_1(struct RaceOdometer *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk14 = (s32)RaceOdometer__vtable;
    func_003A4248(arg0, 6);
}
