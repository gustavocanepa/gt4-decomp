#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */

struct func_0052F538_temp_v0 {
    char pad0[0x48];
    s32 (*unk48)(s32, s32);
};

s32 func_0052F538(s32 *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    struct func_0052F538_temp_v0 *temp_v0;

    var_v0 = 0x17;
    if (arg1 != 0) {
        var_v0 = func_00535780(func_00536CF8());
        if (var_v0 == 0) {
            var_v0 = 0x17;
            if (arg0 != NULL) {
                temp_v0 = *(void **)0x64B4B4;
                if (temp_v0 != NULL) {
                    *arg0 = temp_v0->unk48(arg1, arg2);
                }
                var_v0 = func_00535780(func_00536D38());
            }
        }
    }
    return var_v0;
}
