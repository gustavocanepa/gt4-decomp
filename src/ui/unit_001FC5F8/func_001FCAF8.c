#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001FCAA0(void *);                          /* extern */

struct func_001FCAF8_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

s32 func_001FCAF8(struct func_001FCAF8_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a2;

    if (arg0->unk20 != 0) {
        return func_001FCAA0(arg0);
    }
    var_a2 = 0;
    if (arg0->unk18 == 0) {
        temp_a0 = arg0->unk10;
        temp_v0 = arg0->unk14 + 1;
        arg0->unk14 = temp_v0;
        if (temp_v0 >= temp_a0) {
            if (arg0->unk1C != 0) {
                arg0->unk14 = 0;
            } else {
                var_a2 = 1;
                arg0->unk14 = (s32) (temp_a0 - 1);
            }
        }
    }
    return var_a2;
}
