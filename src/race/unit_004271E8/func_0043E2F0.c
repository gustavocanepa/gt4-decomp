#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043E2F0_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043E2F0(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(((((((struct func_0043E2F0_arg0 *)arg0)->unk490 * 0xBC) + arg1) * 2) + arg0), s16 *, 0x118) = arg2;
}
