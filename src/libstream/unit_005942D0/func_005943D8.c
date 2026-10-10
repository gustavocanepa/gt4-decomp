/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ios::is_open.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005943D8(s32 **arg0) {
    s32 *temp_v0;
    s32 var_a0;

    temp_v0 = *arg0;
    var_a0 = 0;
    if (temp_v0 != NULL) {
        var_a0 = (*temp_v0 & 0xC) != 0xC;
    }
    return var_a0;
}
