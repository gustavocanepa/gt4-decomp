#include "types.h"
#include "gt4/hLocalVariable.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void hLocalVariable__assign(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0x14) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = ((struct hLocalVariable *)arg0)->unk14;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        ((struct hLocalVariable *)arg0)->unk14 = temp_s0;
    }
}
