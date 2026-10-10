#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F0948(void *, s32);                         /* extern */
s32 func_004F8820(void *, s32);                     /* extern */
s32 func_0052E6D8();                                /* extern */

struct func_004F08B8_arg0 {
    char pad0[0x3F3C];
    s32 unk3F3C;
};

s32 func_004F08B8(struct func_004F08B8_arg0 *arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = arg0->unk3F3C;
    if (temp_v0 != 0) {
        func_004F0948(arg0, temp_v0);
        arg0->unk3F3C = 0;
    }
    var_v0 = func_0052E6D8();
    if (var_v0 != 0) {
        var_v0 = func_004F8820(arg0, var_v0);
    }
    return var_v0;
}
