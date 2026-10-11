#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004B38A0();                                /* extern */
s32 func_004B38F8(s32, s32);                    /* extern */
s32 func_004B3938(s32, s32);                    /* extern */

void func_0060B968(s32 arg0, s32 arg1) {
    if (func_004B38A0() != 0) {
        func_004B3938(arg0, arg1);
        return;
    }
    func_004B38F8(arg0, arg1);
}
