#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0051DC58(s32);                             /* extern */
s32 func_0051DD50();                                /* extern */

s32 func_0051DD88(void) {
    s32 temp_v0;

    temp_v0 = func_0051DD50();
    return (func_0051DC58(temp_v0) == 0) ? 0 : temp_v0;
}
