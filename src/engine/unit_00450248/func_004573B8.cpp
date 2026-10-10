#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00457300(s32, s32, s32);           /* extern */
s32 func_00457400();                            /* extern */

void func_004573B8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00457400();
        func_00457300(arg0, 1, arg1);
    }
}
