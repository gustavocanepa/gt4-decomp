#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002B4998();                              /* extern */

struct func_002B2060_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

f32 func_002B2060(struct func_002B2060_arg0 *arg0) {
    if (arg0->unkB0 == 0) {
        return M2C_FIELD(func_002B4998(), f32 *, 0x18);
    }
    return M2C_FIELD(func_002B4998(), f32 *, 0x14);
}
