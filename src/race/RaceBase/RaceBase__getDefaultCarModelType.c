#include "types.h"
#include "gt4/RaceBase.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 SPEC_DATABASE__GetLightEffect(s64);                             /* extern */

s32 RaceBase__getDefaultCarModelType(struct RaceBase *arg0) {
    return (SPEC_DATABASE__GetLightEffect(M2C_FIELD(arg0->unk6C, s64 *, 0x68)) == 0) ? 0 : 3;
}
