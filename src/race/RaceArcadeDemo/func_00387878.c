#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceArcadeDemo__structor_0(s32);                         /* extern */
s32 exception__structor_0(s32);                         /* extern */

s32 func_00387878(void) {
    s32 temp_v0;

    temp_v0 = exception__structor_0(0x24140);
    RaceArcadeDemo__structor_0(temp_v0);
    return temp_v0;
}
