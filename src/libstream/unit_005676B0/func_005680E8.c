/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005680D8(s32);                         /* extern */
s32 func_00576090(s32);                     /* extern */
s32 func_005760A8(s32, s32);            /* extern */

extern char D_00655320[];
extern char D_00655340[];
void func_005680E8(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;

    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            var_s1 = 3;
            var_s0 = (s32)D_00655320;
            var_a0 = (s32)D_00655320;
            do {
                var_s0 += 8;
                var_s1 -= 1;
                func_005680D8(var_a0);
                var_a0 = var_s0;
            } while (var_s1 != -1);
        }
        if (arg1 == 0xFFFF) {
            if (arg0 == 1) {
                func_00576090((s32)D_00655340);
            }
            if (arg0 == 0) {
                func_005760A8((s32)D_00655340, 2);
            }
        }
    }
}
