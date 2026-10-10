#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0038A468(s32);
s32 func_00447280(s32);
struct func_003BE128_arg0 {
    char pad0[0x6C];
    void *unk6C;
};

void func_003BE128(s8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0xD68);
    s32 temp_v0;
    if ((*p ^ 0xF) == 0) {
        temp_v0 = func_0038A468(func_00447280(M2C_FIELD(((struct func_003BE128_arg0 *)arg0)->unk6C, s32 *, 0x70)));
        if (temp_v0 != 0) {
            *p = temp_v0;
        }
    }
}
