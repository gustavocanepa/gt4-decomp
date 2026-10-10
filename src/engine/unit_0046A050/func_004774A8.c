#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00477460(void *);                          /* extern */

struct func_004774A8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_004774A8(struct func_004774A8_arg0 *arg0) {
    s32 var_v0;

    if (arg0->unk0 == 5) {
        return arg0->unk4;
    }
    var_v0 = 1;
    if (func_00477460(arg0) == 0.0f) {
        var_v0 = 0;
    }
    return var_v0;
}
