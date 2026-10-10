#include "types.h"
#include "gt4/NormalCarGeometry.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_0038CF38(void *, f32);                     /* extern */
s32 func_0038D0C0(void *);                          /* extern */
s32 DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();                                /* extern */
f32 func_0044F9E0(s32);                             /* extern */

f32 NormalCarGeometry__GetStepPosition_Z(struct NormalCarGeometry *arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
    if (temp_v0 != 0) {
        var_f20 = func_0044F9E0(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    if (arg0->unk4 == 0) {
        return M2C_FIELD(((arg1 * 0xC) + func_0038D0C0(arg0)), f32 *, 0x24) + var_f20;
    }
    temp_s0 = func_0038D0C0(arg0);
    return M2C_FIELD(((arg1 * 0xC) + temp_s0), f32 *, 0x24) + func_0038CF38(arg0, fparg0);
}
