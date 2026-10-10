#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0051B8A8(void *, s32);                     /* extern */
s32 func_00531E60(void *, s32);                 /* extern */

struct func_00519880_arg1 {
    char pad0[0x104];
    s32 unk104;
    char pad108[0x48];
    s32 unk150;
};

struct func_00519880_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

void func_00519880(void *arg0, struct func_00519880_arg1 *arg1, s32 (*arg2)(s32, s32)) {
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_s0;
    s8 *var_v1;

    if ((arg1 != NULL) && (arg2 != NULL)) {
        ((struct func_00519880_arg0 *)arg0)->unk8 = 0x40;
        var_a0 = 7;
        ((struct func_00519880_arg0 *)arg0)->unkC = -1;
        var_v1 = arg0 + 7;
        ((struct func_00519880_arg0 *)arg0)->unk8 = (s32) arg1->unk150;
        do {
            var_a0 -= 1;
            *var_v1 = 0;
            var_v1 -= 1;
        } while (var_a0 >= 0);
        var_s0 = 0;
        if (arg1->unk150 > 0) {
            do {
                var_a1 = var_s0;
                if (func_0051B8A8(arg1, var_a1) != 0) {
                    temp_v0 = arg1->unk104;
                    if ((var_s0 != temp_v0) && (arg2(var_s0, temp_v0) != 0)) {
                        func_00531E60(arg0, var_s0);
                    }
                }
                var_s0 += 1;
            } while (var_s0 < arg1->unk150);
        }
    }
}
