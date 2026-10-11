#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00622F4C[];
s32 func_00123768(s32 arg0, s8 arg1) {
    M2C_FIELD(*(void **)D_00622F4C, s8 *, 0x3A358) = arg1;
}
