#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_0052DD60();                              /* extern */

struct func_0052E3B8_arg0 {
    u32 unk0;
    char pad4[0x4];
    u32 unk8;
    char padC[0x4];
    s32 unk10;
};

struct func_0052E3B8_var_a0 {
    char pad0[0x4];
    void *unk4;
};

s32 func_0052E3B8(struct func_0052E3B8_arg0 *arg0) {
    u32 temp_v1;
    u32 var_s0;
    void *var_a0;
    void *var_a1;

    var_s0 = arg0->unk8;
    var_a0 = func_0052DD60();
    if (var_a0 != NULL) {
        do {
            temp_v1 = var_a0 - arg0->unk10;
            var_a1 = NULL;
            var_s0 = (temp_v1 < var_s0) ? temp_v1 : var_s0;
            if (var_a0 != NULL) {
                var_a1 = ((struct func_0052E3B8_var_a0 *)var_a0)->unk4;
            }
            var_a0 = var_a1;
        } while (var_a0 != NULL);
    }
    arg0->unk0 = var_s0;
    return 0;
}
