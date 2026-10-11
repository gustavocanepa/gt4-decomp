#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0038D0C0(s32);                           /* extern */
s32 DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();                                /* extern */
f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatAngleOffset(s32);                             /* extern */

f32 NormalCarGeometry__GetChairAngle(s32 arg0) {
    f32 var_f20;
    s32 temp_v0;

    temp_v0 = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
    if (temp_v0 != 0) {
        var_f20 = DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatAngleOffset(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    return M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x40) + var_f20;
}
