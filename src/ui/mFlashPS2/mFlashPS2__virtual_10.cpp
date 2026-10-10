#include "gt4/mFlashPS2.h"
typedef int s32;

extern "C" s32 mFlashPS2__virtual_10(struct mFlashPS2 *arg0) {
    s32 var_v1;

    if (arg0->unk1C != 0) {
        var_v1 = 0;
        if (arg0->unkC != 0) {
            if (arg0->unk10 != 0) {
                var_v1 = arg0->unk14 != 0;
            }
        }
        return var_v1;
    } else {
        return arg0->unkC != 0;
    }
}
