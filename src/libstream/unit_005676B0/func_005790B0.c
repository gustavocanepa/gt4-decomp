/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_0057CB28(s32, s32, s32);               /* extern */

void func_005790B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xC;
    func_00576788(temp_s2);
    func_0057CB28(arg0, arg1, arg2);
    func_005767C0(temp_s2);
}
