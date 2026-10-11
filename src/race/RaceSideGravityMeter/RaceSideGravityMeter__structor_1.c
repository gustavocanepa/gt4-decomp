#include "types.h"
#include "gt4/RaceSideGravityMeter.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003AB390(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceSideGravityMeter__vtable[];
void RaceSideGravityMeter__structor_1(struct RaceSideGravityMeter *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk14 = (s32)RaceSideGravityMeter__vtable;
    arg0->unk28 = 0x80E3B896;
    arg0->unk18 = 0;
    func_003AB390(arg0);
}
