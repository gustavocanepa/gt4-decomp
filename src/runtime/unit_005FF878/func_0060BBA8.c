#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00575DA0(s32 *);                   /* extern */

struct func_0060BBA8_arg0 {
    char pad0[0x4];
    s32 *unk4;
};

struct func_0060BBA8_temp_v0 {
    s32 *unk0;
};
struct func_0060BBA8_temp_v0_2 {
    char pad0[0x4];
    s32 *unk4;
};

void func_0060BBA8(struct func_0060BBA8_arg0 *arg0) {
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 *var_a0;
    s32 *var_s0;

    temp_v0 = arg0->unk4;
    var_s0 = ((struct func_0060BBA8_temp_v0 *)temp_v0)->unk0;
    if (var_s0 != temp_v0) {
        var_a0 = var_s0;
        do {
            var_s0 = *var_s0;
            func_00575DA0(var_a0);
            var_a0 = var_s0;
        } while (var_s0 != arg0->unk4);
    }
    M2C_FIELD(arg0->unk4, s32 **, 0) = arg0->unk4;
    temp_v0_2 = arg0->unk4;
    ((struct func_0060BBA8_temp_v0_2 *)temp_v0_2)->unk4 = temp_v0_2;
}
