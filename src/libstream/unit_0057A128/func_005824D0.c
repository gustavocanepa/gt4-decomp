#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00582438();                                /* extern */

s32 func_005824D0(void) {
    s32 temp_v0;

    temp_v0 = func_00582438();
    return (~temp_v0 == 0) ? 0 : temp_v0;
}
