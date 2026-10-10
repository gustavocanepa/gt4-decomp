#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_005D2FB8_arg0 {
    char pad0[0x64];
    void *unk64;
};

s32 func_005D2FB8(struct func_005D2FB8_arg0 *arg0) {
    return M2C_FIELD(arg0->unk64, s32 *, -0x10);
}
