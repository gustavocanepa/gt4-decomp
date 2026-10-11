#include "types.h"
#include "gt4/RaceMachineTestInformation.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_003D6268(s32);                         /* extern */

extern char RaceMachineTestInformation__vtable[];
s32 RaceMachineTestInformation__structor_0(void *arg0) {
    RaceInformation__structor_0();
    ((struct RaceMachineTestInformation *)arg0)->unk12C = (s32)RaceMachineTestInformation__vtable;
    func_003D6268(arg0 + 0x130);
    ((struct RaceMachineTestInformation *)arg0)->unk118 = 2;
}
