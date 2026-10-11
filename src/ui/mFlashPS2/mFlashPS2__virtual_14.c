#include "types.h"
#include "gt4/mFlashPS2.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004743D0(s32);                             /* extern */

f32 mFlashPS2__virtual_14(struct mFlashPS2 *arg0) {
    s32 temp_v0;

    if (arg0->unk1C == 0) {
        temp_v0 = arg0->unkC;
        if (temp_v0 != 0) {
            return func_004743D0(temp_v0);
        }
    }
    return 1.0f;
}
