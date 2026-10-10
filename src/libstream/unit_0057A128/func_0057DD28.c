#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057DC60(void *, s32);                 /* extern */
s32 func_0057DCA0(void *, s32);             /* extern */
s32 func_0057DD08(void *, s32);             /* extern */
s32 func_0057DE48(void *, s32, s32);                /* extern */

s32 func_0057DD28(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    s32 temp_s0;

    func_0057DC60(sp, arg0);
    temp_s0 = func_0057DE48(sp, arg1, arg2);
    func_0057DD08(sp, 0);
    func_0057DCA0(sp, 2);
    return temp_s0;
}
