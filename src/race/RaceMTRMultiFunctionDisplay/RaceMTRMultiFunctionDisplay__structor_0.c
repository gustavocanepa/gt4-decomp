#include "types.h"
#include "gt4/RaceMTRMultiFunctionDisplay.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003A9758(s32);                         /* extern */
s32 func_003AD580(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char RaceMTRMultiFunctionDisplay__vtable[];
void RaceMTRMultiFunctionDisplay__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceMTRMultiFunctionDisplay *)arg0)->unk14 = (s32)RaceMTRMultiFunctionDisplay__vtable;
    func_003A9758(arg0 + 0x20);
    func_003AD580(arg0);
}
