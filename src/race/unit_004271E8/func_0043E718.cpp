#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy
#include "m2c_macros.h"

struct func_0043E718_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043E718(s32 arg0, s32 arg1) {
    M2C_FIELD(((((struct func_0043E718_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x154) = (s8) arg1;
    M2C_FIELD(((((struct func_0043E718_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x155) = (s8) arg1;
}
