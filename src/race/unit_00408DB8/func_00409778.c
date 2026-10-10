#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004096F8();                                /* extern */

struct func_00409778_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_00409778(struct func_00409778_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (func_004096F8() != 0) {
        var_v0 = arg0->unk7C != 0;
    }
    return var_v0;
}
