#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003CC7B0();                                /* extern */

s32 func_003CC878(void **arg0) {
    s32 var_v0;

    var_v0 = func_003CC7B0();
    if (var_v0 != 0) {
        var_v0 = M2C_FIELD(M2C_FIELD(*arg0, void **, 4), s32 *, 4);
    }
    return var_v0;
}
