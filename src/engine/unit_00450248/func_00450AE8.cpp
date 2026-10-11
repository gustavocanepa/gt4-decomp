#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004583D0(s32);                         /* extern */
s32 func_00458688(s32, s32);                        /* extern */

void func_00450AE8(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_00458688(*arg1, arg2);
    *arg0 = temp_v0;
    func_004583D0(temp_v0);
}
