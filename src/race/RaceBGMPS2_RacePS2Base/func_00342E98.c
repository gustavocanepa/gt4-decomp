#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00342E98(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s64 *, 0xCF58) = (s64) ((M2C_FIELD(arg0, s64 *, 0xCF58) & ~0xFF) | (arg1 & 0xFF));
    if (arg1 == 0) {
        M2C_FIELD(arg0, s8 *, 0xCF59) = -1;
    }
}
