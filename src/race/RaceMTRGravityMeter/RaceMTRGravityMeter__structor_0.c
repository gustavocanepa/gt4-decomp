#include "types.h"
#include "gt4/RaceMTRGravityMeter.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003AC8C8(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceMTRGravityMeter__vtable[];
void RaceMTRGravityMeter__structor_0(struct RaceMTRGravityMeter *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = (s32)RaceMTRGravityMeter__vtable;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    func_003AC8C8(arg0);
}
