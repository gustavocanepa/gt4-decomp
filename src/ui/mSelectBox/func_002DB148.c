#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0025C1E8(s32);                             /* extern */
s32 func_00266088();                                /* extern */
s32 func_002DB300(s32, s32);                    /* extern */

s32 func_002DB148(s32 arg0) {
    if (func_00266088() != 0) {
        func_002DB300(arg0, func_0025C1E8(arg0));
    }
}
