#include "types.h"
#include "gt4/NormalCarGeometry.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0038CDE8(void *, f32);                     /* extern */
f32 *func_0038D0C0();                               /* extern */

f32 NormalCarGeometry__GetSteeringWheelCenter_X(struct NormalCarGeometry *arg0, f32 fparg0) {
    f32 *temp_s0;

    if (arg0->unk4 == 0) {
        return *func_0038D0C0();
    }
    temp_s0 = func_0038D0C0();
    return *temp_s0 + func_0038CDE8(arg0, fparg0);
}
