#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004096F8();                                /* extern */

struct func_00409730_arg0 {
    char pad0[0x78];
    s32 unk78;
};

s32 func_00409730(struct func_00409730_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (func_004096F8() != 0) {
        var_v0 = arg0->unk78 != 0;
    }
    return var_v0;
}
