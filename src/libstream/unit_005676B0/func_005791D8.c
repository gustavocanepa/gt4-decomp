#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_0057CC10(s32);                             /* extern */

s32 func_005791D8(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = arg0 + 0xC;
    func_00576788(temp_s1);
    temp_s0 = func_0057CC10(arg0);
    func_005767C0(temp_s1);
    return temp_s0;
}
