#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00535010(s32);                         /* extern */
s32 func_00536158(s32);                         /* extern */

s32 func_00535268(void) {
    s32 var_v0;

    var_v0 = func_00535010(0);
    if (var_v0 == 0) {
        var_v0 = func_00536158(0);
    }
    return var_v0;
}
