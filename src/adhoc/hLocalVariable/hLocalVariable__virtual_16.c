#include "types.h"
#include "gt4/hLocalVariable.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void hLocalVariable__virtual_16(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg1 != (arg0 + 0x14)) {
        temp_s0 = ((struct hLocalVariable *)arg0)->unk14;
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
