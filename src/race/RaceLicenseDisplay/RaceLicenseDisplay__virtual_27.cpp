#include "types.h"
#include "gt4/RaceLicenseDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035DF00(s32);                             /* extern */
s32 RaceDisplay__virtual_27(void *, s32);                 /* extern */

void RaceLicenseDisplay__virtual_27(void *arg0, s32 arg1) {
    if ((func_0035DF00(((struct RaceLicenseDisplay *)arg0)->unk10) <= 0) || (arg1 >= 3) || (arg1 <= 0)) {
        RaceDisplay__virtual_27(arg0, arg1);
    }
}
