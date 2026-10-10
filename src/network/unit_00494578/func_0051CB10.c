#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */
void *func_0051DD88(s32);                           /* extern */
s32 func_0051E158(s32, s32, s32, void *, s32, s32); /* extern */
s32 func_00538F70(void *, s32);                 /* extern */

struct func_0051CB10_temp_v0 {
    char pad0[0x80];
    s32 unk80;
};

s32 func_0051CB10(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    s32 var_s2;
    s32 var_v0;
    struct func_0051CB10_temp_v0 *temp_v0;

    var_v0 = func_0051BE28();
    if (var_v0 == 0) {
        var_s2 = 2;
        temp_v0 = func_0051DD88(arg0);
        if (temp_v0 != NULL) {
            func_00538F70(sp, arg1 & 0xFFFF);
            var_s2 = func_0051E158(temp_v0->unk80, 0xE, 0xFFFF, sp, 2, 0);
        }
        func_0051BE60();
        var_v0 = var_s2;
    }
    return var_v0;
}
