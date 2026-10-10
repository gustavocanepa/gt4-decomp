#include "types.h"
#include "gt4/RaceBase.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 DynamicsConductor__CurrentTotalTime(s32);                             /* extern */

void RaceBase__raceEnd(struct RaceBase *arg0) {
    if ((u32) arg0->unkCC8 < 2U) {
        arg0->unkD1C = DynamicsConductor__CurrentTotalTime(M2C_FIELD(M2C_FIELD(*M2C_FIELD(M2C_FIELD(arg0->unk6C, void **, 0x60), void ***, 8), void **, 0x18), s32 *, 4));
    }
}
