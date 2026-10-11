#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void **func_005019C8();                             /* extern */

void func_00501630(s32 arg0, s32 arg1, s32 arg2) {
    void **temp_v0;

    temp_v0 = func_005019C8();
    if (temp_v0 != NULL) {
        M2C_FIELD(*temp_v0, s32 *, 0x34) = arg2;
    }
}
