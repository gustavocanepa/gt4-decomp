#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043EAA0_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043EAA0(s32 arg0, s32 arg1) {
    M2C_FIELD(((((struct func_0043EAA0_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x161) = (s8) arg1;
    M2C_FIELD(((((struct func_0043EAA0_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x162) = (s8) arg1;
}
