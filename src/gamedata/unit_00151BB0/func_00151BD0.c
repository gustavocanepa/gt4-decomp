#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00151818(s32, void *);                 /* extern */
s32 func_00154B08(void *, s32);             /* extern */
s32 func_001575A8(void *);                      /* extern */

s32 func_00151BD0(s32 arg0) {
    s8 sp[0x10];
    func_001575A8(sp);
    func_00151818(arg0, sp);
    func_00154B08(sp, 2);
    return arg0;
}
