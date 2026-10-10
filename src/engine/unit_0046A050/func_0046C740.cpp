#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F378(s32, s32);                    /* extern */
s32 func_0046F400(s32, s32, s32);               /* extern */

void func_0046C740(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x85C;
    func_0046F378(temp_s0, 0xFFFE);
    func_0046F378(temp_s0, arg2 + 2);
    func_0046F400(temp_s0, arg1, arg2);
}
