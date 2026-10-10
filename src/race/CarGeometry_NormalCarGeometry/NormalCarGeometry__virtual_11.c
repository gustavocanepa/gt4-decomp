#include "types.h"
#include "gt4/NormalCarGeometry.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_0038CE98(void *, f32);                     /* extern */
void *func_0038D0C0();                              /* extern */

struct NormalCarGeometry__virtual_11_temp_s0 {
    char pad0[0x4];
    f32 unk4;
};

f32 NormalCarGeometry__virtual_11(struct NormalCarGeometry *arg0, f32 fparg0) {
    struct NormalCarGeometry__virtual_11_temp_s0 *temp_s0;

    if (arg0->unk4 == 0) {
        return M2C_FIELD(func_0038D0C0(), f32 *, 4);
    }
    temp_s0 = func_0038D0C0();
    return temp_s0->unk4 + func_0038CE98(arg0, fparg0);
}
