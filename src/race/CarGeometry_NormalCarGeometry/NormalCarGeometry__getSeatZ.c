#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_0038CF38(s32, f32);                        /* extern */
void *func_0038D0C0(s32);                           /* extern */
s32 DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();                                /* extern */
f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatOffsetZ(s32);                             /* extern */

struct func_0038D238_temp_s0 {
    char pad0[0x3C];
    f32 unk3C;
};

f32 NormalCarGeometry__getSeatZ(s32 arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;
    s32 temp_v0;
    struct func_0038D238_temp_s0 *temp_s0;

    temp_v0 = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
    if (temp_v0 != 0) {
        var_f20 = DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatOffsetZ(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    if (arg1 != 0) {
        return M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x3C) + var_f20;
    }
    temp_s0 = func_0038D0C0(arg0);
    return temp_s0->unk3C + func_0038CF38(arg0, fparg0);
}
