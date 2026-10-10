#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0C88();                                /* extern */
s32 func_004F0CD0(s32, s32);                /* extern */

void func_004FEEA0(s32 arg0) {
    if (func_004F0C88() != 0) {
        func_004F0CD0(arg0, 0x3C);
    }
}
