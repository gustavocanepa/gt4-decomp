#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00469F08(void *, void *, s32);     /* extern */
void *func_00469FC8(void *, s32);                   /* extern */

struct func_0046BE70_arg0 {
    char pad0[0xC];
    s16 unkC;
};

f32 func_0046BE70(struct func_0046BE70_arg0 *arg0, s32 arg1) {
    s8 sp[0x10];
    f32 var_f0;

    var_f0 = 0.0f;
    if (arg0->unkC != 0) {
        func_00469F08(sp, arg0, 4);
        var_f0 = M2C_FIELD(func_00469FC8(sp, arg1), f32 *, 0x24);
    }
    return var_f0;
}
