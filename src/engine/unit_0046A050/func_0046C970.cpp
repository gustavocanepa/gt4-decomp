#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F300(s32, s32);                    /* extern */
s32 func_0046F378(s32, s32);                    /* extern */
s32 func_0046F400(s32, s32, s32);               /* extern */

void func_0046C970(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x85C;
    func_0046F378(temp_s1, 0xFFC4);
    func_0046F378(temp_s1, arg2 + 3);
    func_0046F300(temp_s1, (arg3 * 0x10) + arg4);
    func_0046F400(temp_s1, arg1, arg2);
}
