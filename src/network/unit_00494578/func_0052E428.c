#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_0052DD60();                              /* extern */

struct func_0052E428_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
};

struct func_0052E428_var_a0 {
    s32 unk0;
    void *unk4;
};

s32 func_0052E428(struct func_0052E428_arg0 *arg0) {
    s32 temp_v0_3;
    u32 temp_v0_2;
    u32 var_a1;
    void *temp_v0;
    void *var_a0;

    var_a0 = func_0052DD60();
    var_a1 = 0;
    if (var_a0 != NULL) {
        do {
            temp_v0 = var_a0 + ((((struct func_0052E428_var_a0 *)var_a0)->unk0 + 3) & ~3);
            var_a0 = ((struct func_0052E428_var_a0 *)var_a0)->unk4;
            temp_v0_2 = (temp_v0 - arg0->unk10) + 8;
            var_a1 = (var_a1 < temp_v0_2) ? temp_v0_2 : var_a1;
        } while (var_a0 != NULL);
    }
    temp_v0_3 = (var_a1 + 3) & ~3;
    arg0->unk4 = temp_v0_3;
    if (temp_v0_3 == arg0->unk8) {
        arg0->unk4 = 0;
    }
    return 0;
}
