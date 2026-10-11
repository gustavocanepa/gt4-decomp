#include "types.h"
#include "gt4/RacePS2Base.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceBase__replayStart();                            /* extern */

void RacePS2Base__replayStart(struct RacePS2Base *arg0) {
    RaceBase__replayStart();
    if (arg0->unkCF54 == 0.0f) {
        arg0->unkCF54 = 1.0f;
    }
}
