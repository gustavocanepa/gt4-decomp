#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_005F3358(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg2 * 4) + arg0), s32 *, 0xAB8) = arg1;
}
