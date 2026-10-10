#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0047D170(s32);                             /* extern */
s32 func_00480FA0(s32, s32);                    /* extern */

struct func_0047C528_arg0 {
    s32 unk0;
    f32 unk4;
};

void *func_0047C528(struct func_0047C528_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f0;

    func_00480FA0(arg3, arg2);
    var_f0 = -1.0f;
    if (arg1 != 0) {
        var_f0 = (f32) func_0047D170(arg1);
    }
    arg0->unk4 = var_f0;
    arg0->unk0 = 6;
    return arg0;
}
