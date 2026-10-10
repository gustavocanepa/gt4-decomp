#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00620204[];
void func_00427630(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = 1 << arg0;
    temp_v0 = *(s32 *)(s32)D_00620204 & ~temp_v1;
    *(s32 *)(s32)D_00620204 = (arg1 != 0) ? (temp_v0 | temp_v1) : temp_v0;
}
