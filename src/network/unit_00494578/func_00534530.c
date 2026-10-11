#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00534530(s32 arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != 0) {
        func_005A48D8((void *) arg0, 0, 0x20);
        *(s32 *)arg0 = 1;
        var_v0 = 0;
    }
    return var_v0;
}
