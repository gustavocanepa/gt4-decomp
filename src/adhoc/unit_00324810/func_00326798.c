#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00329498();                            /* extern */
s32 func_00575DA0();                            /* extern */

void func_00326798(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        if (arg2 == 4) {
            func_00329498();
            return;
        }
        func_00575DA0();
    }
}
