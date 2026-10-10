#include "types.h"
#include "gt4/RaceBase.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

u8 RaceBase__virtual_92(struct RaceBase *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0->unk6C, void **, 0x70), u8 *, 0x43);
}
