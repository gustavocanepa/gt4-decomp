#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0057CAB8();                                /* extern */
s32 func_0057CB80(s32, s32);                    /* extern */

s32 func_0057CC80(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = func_0057CAB8();
    if (var_v0 != 0) {
        func_0057CB80(arg0, arg1);
        var_v0 = 1;
    }
    return var_v0;
}
