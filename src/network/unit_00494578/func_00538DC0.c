#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00538C68();                                /* extern */

struct func_00538DC0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00538DC0(struct func_00538DC0_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0x64;
    if (arg0 != NULL) {
        if (arg0->unk0 != 0) {
            var_v0 = func_00538C68();
            if (var_v0 == 0) {
                arg0->unk0 = 0;
                goto block_4;
            }
        } else {
block_4:
            arg0->unk4 = 0;
            var_v0 = 0;
        }
    }
    return var_v0;
}
