#include "types.h"
#include "gt4/RaceBase.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

u8 RaceBase__getNumberOfLaps(struct RaceBase *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0->unk6C, void **, 0x70), u8 *, 0x43);
}
