#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 Pitmen__Camera__isPitSequence(s32, s32);                    /* extern */
s32 Pitmen__isValid();                                /* extern */

void func_003D2730(s32 arg0, s32 arg1) {
    if (Pitmen__isValid() != 0) {
        Pitmen__Camera__isPitSequence(arg0 + 4, arg1);
    }
}
