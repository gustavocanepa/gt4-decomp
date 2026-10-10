#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003FDD60(s32, void *, s32);            /* extern */

struct func_00370CC0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xE0];
    s32 unkE8;
};

s32 func_00370CC0(void *arg0) {
    s32 temp_v0;
    s32 var_v1;

    var_v1 = 0;
    if (((struct func_00370CC0_arg0 *)arg0)->unkE8 >= 0) {
        temp_v0 = ((struct func_00370CC0_arg0 *)arg0)->unk4;
        if (temp_v0 != 0) {
            var_v1 = func_003FDD60(temp_v0, arg0 + 0x60, 0) ^ 1;
        }
    }
    return var_v1;
}
