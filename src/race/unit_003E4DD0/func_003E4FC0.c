#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RigidBodyManager__remove(void *, s32 *, s32 *); /* extern */

struct func_003E4FC0_arg0 {
    char pad0[0x8];
    s32 *unk8;
};

void func_003E4FC0(struct func_003E4FC0_arg0 *arg0, s32 arg1) {
    s32 *temp_s0;
    s32 *var_a1;
    s32 *var_s2;

    var_a1 = arg0->unk8;
    var_s2 = NULL;
    if (var_a1 != NULL) {
        do {
            temp_s0 = *var_a1;
            if (var_a1 == arg1) {
                RigidBodyManager__remove(arg0, var_a1, var_s2);
            } else {
                var_s2 = var_a1;
            }
            var_a1 = temp_s0;
        } while (var_a1 != NULL);
    }
}
