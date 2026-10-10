#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_0059D2A0();                                /* extern */

void func_00422CC0(f32 *arg0, f32 *arg1) {
    f32 temp_f0;

    temp_f0 = func_0059D2A0();
    *arg0 = temp_f0;
    *arg1 = 1.5707963f - temp_f0;
}
