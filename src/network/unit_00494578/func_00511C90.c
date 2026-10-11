#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00511C90_arg0_unk18 {
    char pad0[0x48];
    s32 unk48;
};
struct func_00511C90_arg0 {
    char pad0[0x18];
    struct func_00511C90_arg0_unk18 *unk18;
    char pad1C[0x4];
    s32 unk20;
    void *unk24;
    s32 unk28;
    void *unk2C;
};
struct func_00511C90_var_a1 {
    char pad0[0x4];
    void *unk4;
    void *unk8;
};

struct func_00511C90_var_a0 {
    s32 unk0;
    void *unk4;
};

s32 func_00511C90(struct func_00511C90_arg0 *arg0) {
    s32 var_a2;
    s32 var_v0;
    void *temp_v0;
    void *temp_v1;
    void *var_a0;
    struct func_00511C90_var_a1 *var_a1;
    void *var_v1;

    var_v0 = 1;
    if (arg0 != NULL) {
        var_a1 = arg0->unk24;
        var_a2 = arg0->unk20;
        if (var_a1 != NULL) {
            var_a1 = var_a1->unk4;
        } else {
            temp_v1 = arg0->unk2C;
            if ((temp_v1 != NULL) || (arg0->unk28 != 0)) {
                arg0->unk28 = 0;
                var_a1 = temp_v1;
                arg0->unk2C = NULL;
            }
        }
        if ((var_a1 == NULL) && (var_a2 != 0)) {
            var_a0 = (var_a2 * 8) + arg0->unk18->unk48;
loop_9:
            var_a0 -= 8;
            var_a2 -= 1;
            if (((struct func_00511C90_var_a0 *)var_a0)->unk0 != 0) {
                var_a1 = ((struct func_00511C90_var_a0 *)var_a0)->unk4;
                var_v1 = var_a1->unk8;
                if (var_v1 != NULL) {
                    do {
                        var_a1 = var_v1;
                        temp_v0 = var_a1->unk8;
                        var_v1 = temp_v0;
                    } while (temp_v0 != NULL);
                }
            } else if (var_a1 == NULL) {
                if (var_a2 == 0) {

                } else {
                    goto loop_9;
                }
            }
        }
        arg0->unk20 = var_a2;
        arg0->unk24 = var_a1;
        var_v0 = (var_a1 != NULL) ? 0 : 4;
    }
    return var_v0;
}
