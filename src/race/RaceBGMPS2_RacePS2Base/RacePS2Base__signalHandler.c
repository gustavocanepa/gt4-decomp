#include "types.h"
#include "gt4/RacePS2Base.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceBase__signalHandler();                                /* extern */

s32 RacePS2Base__signalHandler(struct RacePS2Base *arg0) {
    s32 (*temp_v0_2)(s32, s32);
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = RaceBase__signalHandler();
    temp_v0_2 = arg0->unkD84;
    temp_a0 = temp_v0;
    if (temp_v0_2 != NULL) {
        temp_v0_2(temp_a0, arg0->unkD88);
    }
    return temp_v0;
}
