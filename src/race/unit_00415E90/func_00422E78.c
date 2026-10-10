#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0059D2A0(f32);                             /* extern */

f32 *func_00422E78(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 var_f1;

    var_f1 = 0.0f;
    if ((fparg0 * fparg1) > 0.0f) {
        var_f1 = 1.5707963f - func_0059D2A0(((fparg2 + fparg3) - fparg4) / (2.0f * fparg0 * fparg1));
    }
    *arg0 = var_f1;
    return arg0;
}
