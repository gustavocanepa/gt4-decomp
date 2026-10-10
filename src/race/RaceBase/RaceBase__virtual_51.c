#include "types.h"
#include "gt4/RaceBase.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004486D8(s64);                             /* extern */

s32 RaceBase__virtual_51(struct RaceBase *arg0) {
    return (func_004486D8(M2C_FIELD(arg0->unk6C, s64 *, 0x68)) == 0) ? 0 : 3;
}
