#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003CBCB0(s32, s32);                    /* extern */
s32 func_003CC7B0();                                /* extern */

void func_003D2730(s32 arg0, s32 arg1) {
    if (func_003CC7B0() != 0) {
        func_003CBCB0(arg0 + 4, arg1);
    }
}
