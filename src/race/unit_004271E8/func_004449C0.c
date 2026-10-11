#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00444A88();                                /* extern */
s32 func_00444B88(s32);                             /* extern */
s32 func_00444C08(s32);                             /* extern */
s32 func_00444CA0(s32);                             /* extern */
s32 func_00444D38(s32);                             /* extern */
s32 func_00444DD0(s32);                             /* extern */
s32 func_00444FE0(s32);                             /* extern */
s32 func_004450D8(s32);                             /* extern */
s32 func_004451A0(s32);                             /* extern */
s32 func_00445220(s32);                             /* extern */
s32 func_00445230(s32);                             /* extern */

s32 func_004449C0(s32 arg0) {
    s32 var_v0;

    var_v0 = func_00444A88();
    if (var_v0 != 0) {
        var_v0 = func_00444B88(arg0);
        if (var_v0 != 0) {
            var_v0 = func_00444C08(arg0);
            if (var_v0 != 0) {
                var_v0 = func_00444CA0(arg0);
                if (var_v0 != 0) {
                    var_v0 = func_00444D38(arg0);
                    if (var_v0 != 0) {
                        var_v0 = func_00444DD0(arg0);
                        if (var_v0 != 0) {
                            var_v0 = func_00444FE0(arg0);
                            if (var_v0 != 0) {
                                var_v0 = func_004450D8(arg0);
                                if (var_v0 != 0) {
                                    var_v0 = func_004451A0(arg0);
                                    if (var_v0 != 0) {
                                        var_v0 = func_00445220(arg0);
                                        if (var_v0 != 0) {
                                            var_v0 = func_00445230(arg0) != 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return var_v0;
}
