#include "types.h"
#include "gt4/RaceBase.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00358440(s32);                             /* extern */

void RaceBase__virtual_79(struct RaceBase *arg0) {
    if ((u32) arg0->unkCC8 < 2U) {
        arg0->unkD1C = func_00358440(M2C_FIELD(M2C_FIELD(*M2C_FIELD(M2C_FIELD(arg0->unk6C, void **, 0x60), void ***, 8), void **, 0x18), s32 *, 4));
    }
}
