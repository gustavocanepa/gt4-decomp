#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00538830(s32);                             /* extern */
s32 func_00538988();                                /* extern */
s32 func_00538B08(void *, s32);             /* extern */
void *func_00542928();                              /* extern */
s32 func_005429F0(s32, void *);                 /* extern */
void *func_00542A28(s32, s32);                      /* extern */
s32 func_005A4724(s32, s32, s32);           /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

struct func_00543008_var_s0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s32 func_00543008(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v0;
    void *var_s0;

    temp_v0 = func_00538988();
    var_v0 = -1;
    if (temp_v0 != 0) {
        var_s0 = func_00542A28(temp_v0, arg1);
        if (func_00538830(arg2) != 0) {
            if (var_s0 != NULL) {
                temp_a0 = ((struct func_00543008_var_s0 *)var_s0)->unkC;
                if (temp_a0 != 0) {
                    func_005A48D8(temp_a0, 0, 0x40);
                }
            }
        } else {
            if (var_s0 == NULL) {
                var_s0 = func_00542928();
                ((struct func_00543008_var_s0 *)var_s0)->unk8 = arg1;
                func_005429F0(temp_v0, var_s0);
            }
            if (((struct func_00543008_var_s0 *)var_s0)->unkC == 0) {
                func_00538B08(var_s0 + 0xC, 0x40);
            }
            func_005A4724(((struct func_00543008_var_s0 *)var_s0)->unkC, arg2, 0x40);
        }
        var_v0 = 0;
    }
    return var_v0;
}
