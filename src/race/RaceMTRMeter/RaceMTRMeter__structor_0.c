#include "types.h"
#include "gt4/RaceMTRMeter.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A9608(s32);                         /* extern */
s32 func_003ABB40(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceMTRMeter__vtable[];
void RaceMTRMeter__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceMTRMeter *)arg0)->unk14 = (s32)RaceMTRMeter__vtable;
    func_003A9608(arg0 + 0x4C);
    ((struct RaceMTRMeter *)arg0)->unk18 = 0;
    ((struct RaceMTRMeter *)arg0)->unk1C = 0;
    ((struct RaceMTRMeter *)arg0)->unk20 = 0;
    ((struct RaceMTRMeter *)arg0)->unk24 = 0;
    ((struct RaceMTRMeter *)arg0)->unk28 = 0;
    ((struct RaceMTRMeter *)arg0)->unk2C = 0;
    ((struct RaceMTRMeter *)arg0)->unk6C = 0;
    func_003ABB40(arg0);
}
