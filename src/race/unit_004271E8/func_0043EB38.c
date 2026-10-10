#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043EB38_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043EB38(void *arg0, s8 arg1) {
    M2C_FIELD(((((struct func_0043EB38_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x16F) = arg1;
}
