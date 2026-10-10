#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005F6418(s32, s32);                    /* extern */
s32 func_00603EC8();                            /* extern */

s32 func_0044F558(s32 arg0, s32 arg1) {
    func_00603EC8();
    func_005F6418(arg0 + 0x100, arg1 + 0x100);
    return arg0;
}
