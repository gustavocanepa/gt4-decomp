#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005769F0(s32);                         /* extern */
s32 func_00576A28(s32);                         /* extern */

struct func_0038A0D0_arg0 {
    char pad0[0xD14];
    s32 unkD14;
};

s32 func_0038A0D0(void *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0xCE4;
    func_005769F0(temp_s1);
    temp_s2 = ((struct func_0038A0D0_arg0 *)arg0)->unkD14;
    ((struct func_0038A0D0_arg0 *)arg0)->unkD14 = 0;
    func_00576A28(temp_s1);
    return temp_s2;
}
