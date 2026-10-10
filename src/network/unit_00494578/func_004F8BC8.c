#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F8BC8_var_a0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x1F8];
    s32 unk200;
};

s32 func_004F8BC8(void *arg0, s32 *arg1, s32 arg2) {
    s32 *var_a1;
    s32 var_a3;
    void *temp_v1;
    void *var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_v1 = var_a0 + (((struct func_004F8BC8_var_a0 *)var_a0)->unk200 * 0x10);
    var_a3 = 0;
    if (var_a0 != temp_v1) {
        do {
            if (((struct func_004F8BC8_var_a0 *)var_a0)->unk4 == arg2) {
                var_a3 += 1;
                *var_a1 = ((struct func_004F8BC8_var_a0 *)var_a0)->unk0;
                var_a1 += 1;
            }
            var_a0 += 0x10;
        } while (var_a0 != temp_v1);
    }
    return var_a3;
}
