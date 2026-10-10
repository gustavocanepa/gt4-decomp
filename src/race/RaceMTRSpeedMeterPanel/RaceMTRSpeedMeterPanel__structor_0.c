#include "types.h"
#include "gt4/RaceMTRSpeedMeterPanel.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003ACED0(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceMTRSpeedMeterPanel__vtable[];
void RaceMTRSpeedMeterPanel__structor_0(struct RaceMTRSpeedMeterPanel *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = (s32)RaceMTRSpeedMeterPanel__vtable;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    func_003ACED0(arg0);
}
