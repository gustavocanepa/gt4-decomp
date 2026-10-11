#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005769F0(s32);                         /* extern */
s32 func_00576A28(s32);                         /* extern */

struct func_0038A158_arg0 {
    char pad0[0xD18];
    s32 unkD18;
};

s32 RaceBase__getSignal(void *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0xCE4;
    func_005769F0(temp_s1);
    temp_s2 = ((struct func_0038A158_arg0 *)arg0)->unkD18;
    ((struct func_0038A158_arg0 *)arg0)->unkD18 = 0;
    func_00576A28(temp_s1);
    return temp_s2;
}
