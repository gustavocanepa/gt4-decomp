#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceFreeRun__structor_0(s32, s32);                /* extern */
s32 exception__structor_0(s32);                         /* extern */

s32 func_003B99A8(void) {
    s32 temp_v0;

    temp_v0 = exception__structor_0(0x246C0);
    RaceFreeRun__structor_0(temp_v0, 0);
    return temp_v0;
}
