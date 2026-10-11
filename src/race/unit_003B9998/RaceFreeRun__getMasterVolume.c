#include "types.h"
#include "gt4/RaceFreeRun.h"
void *memcpy(void *, const void *, unsigned int);

f32 RacePS2Base__getMasterVolume();                                /* extern */

f32 RaceFreeRun__getMasterVolume(struct RaceFreeRun *arg0) {
    f32 var_f1;

    var_f1 = RacePS2Base__getMasterVolume();
    if (arg0->unkD58 > 0) {
        var_f1 *= arg0->unkCF4C;
    }
    return var_f1;
}
