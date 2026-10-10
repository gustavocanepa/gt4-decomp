#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00434E08(s32);                         /* extern */

struct func_00435860_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

s32 func_00435860(void *arg0, s32 arg1) {
    s32 var_v0;

    func_00434E08(arg0 + (arg1 << 5) + 8);
    var_v0 = 0;
    if (((struct func_00435860_arg0 *)arg0)->unk81C8 == arg1) {
        ((struct func_00435860_arg0 *)arg0)->unk81C8 = -1;
        var_v0 = 1;
    }
    return var_v0;
}
