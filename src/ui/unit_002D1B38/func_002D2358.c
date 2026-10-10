#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);


struct func_002D2358_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x28];
    s32 unk30;
    f32 unk34;
};

s32 func_002D2358(struct func_002D2358_arg0 *arg0) {
    f32 var_f0;
    s32 temp_a0;

    temp_a0 = arg0->unk30;
    if (temp_a0 != 0) {
        if (arg0->unk4 != 0) {
            var_f0 = mWidget__getWindowX(temp_a0);
        } else {
            var_f0 = mWidget__getWindowY(temp_a0);
        }
        arg0->unk34 = var_f0;
    }
    return 1;
}
