#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00335DD8(void *, s32);                 /* extern */
s32 func_00427028(void *);                      /* extern */

struct func_00337A18_var_s0 {
    char pad0[0x198];
    s32 unk198;
};

void func_00337A18(s32 arg0) {
    s32 var_s1;
    void *temp_a0;
    void *var_s0;

    var_s0 = arg0 + 0xE50C;
    var_s1 = 5;
    do {
        var_s1 -= 1;
        func_00335DD8(var_s0, ((struct func_00337A18_var_s0 *)var_s0)->unk198 != 0);
        temp_a0 = var_s0;
        var_s0 += 0x214;
        func_00427028(temp_a0);
    } while (var_s1 >= 0);
}
