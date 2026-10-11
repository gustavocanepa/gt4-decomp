#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043EFC8_arg0 {
    char pad0[0x490];
    s32 unk490;
};

u16 func_0043EFC8(void *arg0) {
    return M2C_FIELD(((((struct func_0043EFC8_arg0 *)arg0)->unk490 * 0x178) + arg0), u16 *, 0x146);
}
