/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005B0C28(s32);                     /* extern */
s32 func_005B9448(s32);                     /* extern */

extern char D_00657B68[];
void func_00590A88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    *(s32 *)D_00657B68 = 0;
    func_005B0C28(0x80000018);
    func_005B9448(0x80000014);
}
