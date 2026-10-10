#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0057F260(s32);                             /* extern */
s32 func_005A609C(void *, s32);                 /* extern */

struct func_0042FD00_arg0 {
    char pad0[0xA68];
    s32 unkA68;
};

void func_0042FD00(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0057F260(arg1);
    temp_v0_2 = ((struct func_0042FD00_arg0 *)arg0)->unkA68;
    if ((temp_v0 + temp_v0_2) < 0xFF) {
        func_005A609C(arg0 + temp_v0_2 + 0xA6C, arg1);
        ((struct func_0042FD00_arg0 *)arg0)->unkA68 = (s32) (((struct func_0042FD00_arg0 *)arg0)->unkA68 + temp_v0 + 1);
    }
}
