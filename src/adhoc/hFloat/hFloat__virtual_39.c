#include "types.h"
#include "gt4/hFloat.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void hFloat__virtual_39(struct hFloat *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_s0;
    s32 temp_v0;

    arg0->unk10 = (f32) (arg0->unk10 - 1.0f);
    if (arg1 != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = *arg1;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *arg1 = temp_s0;
    }
}
