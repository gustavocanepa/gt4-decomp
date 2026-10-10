#include "types.h"
#include "gt4/RaceLicenseDisplay.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 DynamicsConductor__GetNumberOfPylonsToBeTouched(s32);                             /* extern */
s32 RaceDisplay__set_automobile_message(void *, s32);                 /* extern */

void RaceLicenseDisplay__set_automobile_message(void *arg0, s32 arg1) {
    if ((DynamicsConductor__GetNumberOfPylonsToBeTouched(((struct RaceLicenseDisplay *)arg0)->unk10) <= 0) || (arg1 >= 3) || (arg1 <= 0)) {
        RaceDisplay__set_automobile_message(arg0, arg1);
    }
}
