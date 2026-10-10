#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044A7F0();                            /* extern */
s32 func_0044A810(s32 *);                       /* extern */
s32 func_0044A8D0(s32 *, s32);                      /* extern */
s32 func_0044AA58(s32 *, s32, s32);                 /* extern */
s32 func_0044ABC0(s32 *, s32);                  /* extern */
s32 func_005A4724(s32, s32, s32);               /* extern */

s32 func_0044AB20(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 var_s1;

    func_0044A7F0();
    var_s1 = 0;
    temp_v0 = func_0044AA58(arg0, arg1, arg2);
    if (temp_v0 != -1) {
        var_s1 = 1;
        func_005A4724(arg3, func_0044A8D0(arg0, temp_v0), *arg0);
        func_0044ABC0(arg0, temp_v0);
    }
    func_0044A810(arg0);
    return var_s1;
}
