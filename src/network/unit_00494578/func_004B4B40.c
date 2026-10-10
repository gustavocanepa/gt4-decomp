#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004B4B40_arg0 {
    char pad0[0x858];
    s32 unk858;
};
struct func_004B4B40_temp_a0 {
    char pad0[0x234];
    s32 unk234;
};
struct func_004B4B40_var_a0 {
    s8 unk0;
    char pad1[0x3];
    s16 unk4;
    s16 unk6;
};

s32 func_004B4B40(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_a3;
    void *temp_a0;
    void *var_a0;

    temp_a0 = arg0 + ((1 - ((struct func_004B4B40_arg0 *)arg0)->unk858) * 0x41C);
    temp_v0 = ((struct func_004B4B40_temp_a0 *)temp_a0)->unk234;
    var_a3 = 0;
    if (temp_v0 > 0) {
        var_a0 = temp_a0 + 0x238;
        var_a2 = temp_v0;
        do {
            var_a2 -= 1;
            if (((struct func_004B4B40_var_a0 *)var_a0)->unk0 == arg1) {
                var_a3 += ((struct func_004B4B40_var_a0 *)var_a0)->unk6 - ((struct func_004B4B40_var_a0 *)var_a0)->unk4;
            }
            var_a0 += 8;
        } while (var_a2 != 0);
    }
    return var_a3;
}
