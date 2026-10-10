/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_0057CC80(s32, s32);                    /* extern */

void func_004AD368(s32 arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x10;
    func_00576788(temp_s1);
    func_0057CC80(arg0 + 0x40, arg1 + 0x3C);
    func_005767C0(temp_s1);
}
