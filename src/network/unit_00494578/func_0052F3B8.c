#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */

struct func_0052F3B8_temp_v0 {
    char pad0[0xE4];
    s32 (*unkE4)(s32, s32);
};

s32 func_0052F3B8(s32 arg0, s32 arg1) {
    s32 temp_v0_2;
    s32 var_s2;
    s32 var_v0;
    struct func_0052F3B8_temp_v0 *temp_v0;

    var_s2 = 0x10;
    var_v0 = func_00535780(func_00536CF8());
    if (var_v0 == 0) {
        temp_v0 = *(void **)0x64B4B4;
        if (temp_v0 != NULL) {
            var_s2 = temp_v0->unkE4(arg0, arg1);
        }
        temp_v0_2 = func_00535780(func_00536D38());
        var_v0 = (temp_v0_2 == 0) ? var_s2 : temp_v0_2;
    }
    return var_v0;
}
