#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868(s32);                             /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_00265FF0(s32, s32);                /* extern */
s32 func_00266088();                                /* extern */

void func_002D73C8(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1;

    if (func_00266088() != 0) {
        var_s1 = 0;
        var_s0 = func_00206868(arg0);
        if (var_s0 != 0) {
            do {
                if (var_s1 == arg1) {
                    func_00265FF0(var_s0, 0);
                }
                if (var_s1 == arg2) {
                    func_00265FF0(var_s0, 1);
                }
                var_s1 += 1;
                var_s0 = func_0025C300(var_s0);
            } while (var_s0 != 0);
        }
    }
}
