#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043EE10_arg0 {
    char pad0[0x490];
    s32 unk490;
};

u8 func_0043EE10(void *arg0) {
    return M2C_FIELD(((((struct func_0043EE10_arg0 *)arg0)->unk490 * 0x178) + arg0), u8 *, 0x150);
}
