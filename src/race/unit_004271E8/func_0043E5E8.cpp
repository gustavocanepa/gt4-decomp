#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

struct func_0043E5E8_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_0043E5E8(s32 arg0, s32 arg1) {
    M2C_FIELD(((((struct func_0043E5E8_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x150) = (s8) arg1;
    M2C_FIELD(((((struct func_0043E5E8_arg0 *)arg0)->unk490 * 0x178) + arg0), s8 *, 0x151) = (s8) arg1;
}
