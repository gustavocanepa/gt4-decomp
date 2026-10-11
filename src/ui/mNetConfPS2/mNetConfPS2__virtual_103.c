#include "types.h"
#include "gt4/mNetConfPS2.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 mNetConfPS2__virtual_103(struct mNetConfPS2 *arg0) {
    return M2C_FIELD(arg0->unk268, s32 *, 0x60);
}
