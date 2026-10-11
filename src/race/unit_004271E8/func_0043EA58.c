#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0043EA58_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043EA58(s32 arg0, s32 arg1) {
    M2C_FIELD(((((struct func_0043EA58_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x15F) = (s8) arg1;
    M2C_FIELD(((((struct func_0043EA58_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x160) = (s8) arg1;
}
