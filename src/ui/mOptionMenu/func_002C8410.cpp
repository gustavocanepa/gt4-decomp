#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868(s32);                             /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_00265D98(s32);                             /* extern */
s32 func_00265F10(s32, s32);                /* extern */
s32 func_00265FF0(s32, s32);                /* extern */

struct func_002C8410_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

void func_002C8410(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s0;

    temp_a0 = ((struct func_002C8410_arg0 *)arg0)->unkC4;
    if (temp_a0 != 0) {
        var_s0 = func_00206868(temp_a0);
        if (var_s0 != 0) {
            do {
                if (func_00265D98(var_s0) == 0) {
                    func_00265FF0(var_s0, 0);
                    func_00265F10(var_s0, 1);
                }
                var_s0 = func_0025C300(var_s0);
            } while (var_s0 != 0);
        }
    }
    if (arg1 != 0) {
        func_00265FF0(arg1, 1);
    }
}
