#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 LicenseConcourse__isCameraPeriod();                                /* extern */

struct func_00409778_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 LicenseConcourse__isAvailableFov(struct func_00409778_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (LicenseConcourse__isCameraPeriod() != 0) {
        var_v0 = arg0->unk7C != 0;
    }
    return var_v0;
}
