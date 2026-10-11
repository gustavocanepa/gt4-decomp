#include "types.h"
#include "gt4/RaceGTmodeInformation.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_00444190(s32);                         /* extern */

extern char RaceGTmodeInformation__vtable[];
s32 RaceGTmodeInformation__structor_0(void *arg0) {
    RaceInformation__structor_0();
    ((struct RaceGTmodeInformation *)arg0)->unk12C = (s32)RaceGTmodeInformation__vtable;
    func_00444190(arg0 + 0x130);
    ((struct RaceGTmodeInformation *)arg0)->unk118 = 6;
    ((struct RaceGTmodeInformation *)arg0)->unk2A8 = 0;
}
