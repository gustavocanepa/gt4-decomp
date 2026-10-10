#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00435860(void *, s32);                 /* extern */

struct func_00435710_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

void func_00435710(struct func_00435710_arg0 *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (var_s0 != arg0->unk81C8) {
            func_00435860(arg0, var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x3E8);
}
