#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_003C9F98(s32);                             /* extern */
s32 Pitmen__getMotion(s32);                             /* extern */
s32 func_00429870(s32, s32);                        /* extern */

void func_003CCAE0(s32 arg0) {
    s32 *var_s1;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s2;

    var_s1 = (s32 *)(arg0 + 0x38C4);
    var_s2 = 0;
    do {
        temp_s0 = Pitmen__getMotion(arg0);
        temp_v0 = func_00429870(temp_s0, func_003C9F98(var_s2));
        var_s2 += 1;
        *var_s1 = (temp_v0 < 0) ? 0 : temp_v0;
        var_s1 = (s32 *)((char *)var_s1 + 0xAA4);
    } while (var_s2 < 6);
}

}
