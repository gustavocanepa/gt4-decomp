#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_002E57D8(s32 arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = *arg1 + arg3;
    *arg1 = temp_v0;
    if (temp_v0 >= arg2) {
        *arg1 = temp_v0 - arg2;
    }
    temp_v0_2 = *arg1;
    if (temp_v0_2 < 0) {
        *arg1 = temp_v0_2 + arg2;
    }
}
