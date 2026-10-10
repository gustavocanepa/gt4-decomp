#include "types.h"
#include "gt4/RaceTooltipDisplay.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceMessageDisplay__structor_1(void *);                      /* extern */
s32 RaceEventDisplay__structor_1(void *);                      /* extern */
s32 func_003A9758(s32);                         /* extern */
s32 func_003ADF00(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceTooltipDisplay__vtable[];
void RaceTooltipDisplay__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceTooltipDisplay *)arg0)->unk14 = (s32)RaceTooltipDisplay__vtable;
    func_003A9758(arg0 + 0x20);
    RaceMessageDisplay__structor_1(arg0 + 0x3C);
    RaceEventDisplay__structor_1(arg0 + 0x18C);
    func_003ADF00(arg0);
}
