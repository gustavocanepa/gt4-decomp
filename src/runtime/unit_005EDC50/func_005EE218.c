#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005EE300(s32);                         /* extern */

s32 func_005EE218(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0 + 0x10;
    if (temp_v0 != arg1) {
        func_005EE300(temp_v0);
    }
}
