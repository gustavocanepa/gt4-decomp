#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00577F80();                            /* extern */

s32 func_00578660(u32 arg0) {
    if (arg0 >= 0x100U) {
        func_00577F80();
        return 0;
    }
    return arg0 | (*(s32 *)(0x874950 + (arg0 * 4)) << 8);
}
