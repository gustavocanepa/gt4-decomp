#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005EE300();                            /* extern */

s32 func_0030F7D8(s32 arg0, s32 arg1) {
    if (arg0 != arg1) {
        func_005EE300();
    }
    return arg0;
}
