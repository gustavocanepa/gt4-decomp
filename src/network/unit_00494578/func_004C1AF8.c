#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004C1AF8_var_a0 {
    char pad0[0x8];
    u16 unk8;
    char padA[0x2];
    void *unkC;
};

s32 func_004C1AF8(void *arg0) {
    s32 var_v1;
    u16 temp_v0;
    struct func_004C1AF8_var_a0 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (var_a0 != NULL) {
        do {
            temp_v0 = var_a0->unk8;
            var_a0 = var_a0->unkC;
            var_v1 += temp_v0;
        } while (var_a0 != NULL);
    }
    return var_v1;
}
